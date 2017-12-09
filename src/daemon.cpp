namespace
{

constexpr auto read_pin {0};
constexpr auto token {
#include "token"
};

}

#include <sstream>

extern "C" {
#include <syslog.h>
#include <wiringPi.h>
}

namespace
{

enum class StudioState
{
  open,
  close
};

void notify(const StudioState& state);

}

extern "C"
[[noreturn]]
void run_daemon(const char* executable_name)
{
  wiringPiSetup();
  pinMode(read_pin, INPUT);
  openlog(executable_name, LOG_PID, LOG_DAEMON);

  auto last_value {digitalRead(read_pin)};
  while (true) {
    auto value {digitalRead(read_pin)};
    if (last_value == value)
      continue;

    if (value != LOW) {
      syslog(LOG_INFO, "Studio is open");
      notify(StudioState::open);
    } else {
      syslog(LOG_INFO, "Studio is closed");
      notify(StudioState::close);
    }

    last_value = value;
  }
}

namespace
{

void notify(const StudioState& state)
{
  std::ostringstream oss;
  oss << "curl -X POST -H 'Authorization: Bearer " << token << "' -F 'message=";
  switch (state) {
  case StudioState::open:
    oss << "Studio is open.";
    break;
  case StudioState::close:
    oss << "Studio is closed.";
  }
  oss << "' https://notify-api.line.me/api/notify";
  std::system(oss.str().c_str());
}

}
