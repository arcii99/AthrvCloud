//FormAI DATASET v1.0 Category: System event logger ; Style: peaceful
#include <stdio.h>
#include <time.h>

void logEvent(char* eventType, char* description) {
  time_t t = time(NULL);
  struct tm tm = *localtime(&t);

  printf("%02d-%02d-%04d %02d:%02d:%02d | %10s | %s\n",
    tm.tm_mday, tm.tm_mon + 1, tm.tm_year + 1900,
    tm.tm_hour, tm.tm_min, tm.tm_sec, eventType, description);
}

int main() {
  logEvent("INFO", "Starting program");

  // Some code here...
  
  logEvent("WARNING", "Memory consumption is high");
  
  // Some more code here...
  
  logEvent("ERROR", "Program crashed");
  
  return 0;
}