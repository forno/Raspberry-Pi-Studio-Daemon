extern "C"
{

#include <syslog.h>
#include <wiringPi.h>

}

namespace
{

constexpr auto read_pin {0};

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
      syslog(LOG_INFO, "Studio is closed");
      // send Close to LINE
    } else {
      syslog(LOG_INFO, "Studio is open");
      // send Open to LINE
    }

    last_value = value;
  }
}
