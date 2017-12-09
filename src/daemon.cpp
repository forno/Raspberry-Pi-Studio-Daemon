#include <chrono>
#include <thread>

extern "C"
{

#include <syslog.h>

}

extern "C"
void run_daemon(const char* executable_name)
{
  openlog(executable_name, LOG_PID, LOG_DAEMON);
  while (true) {
    syslog(LOG_INFO, "Daemon test");
    std::this_thread::sleep_for(std::chrono::seconds{15});
  }
}
