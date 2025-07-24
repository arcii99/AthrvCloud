//FormAI DATASET v1.0 Category: System event logger ; Style: random
#include <stdio.h>
#include <time.h>
#include <syslog.h>

void logEvent(const char *message) {

  time_t currentTime;
  struct tm *localTime;
  char reportTime[80];
  time(&currentTime);
  localTime = localtime(&currentTime);

  strftime(reportTime, sizeof(reportTime), "%Y-%m-%d %H:%M:%S", localTime);

  openlog("myEventLogger", LOG_PID|LOG_CONS, LOG_USER);
  syslog(LOG_INFO, "[%s] %s\n", reportTime, message);
  closelog();

}

int main() {
  char message[100];
  printf("Enter the message: ");
  fgets(message, 100, stdin);
  logEvent(message);

  return 0;
}