//FormAI DATASET v1.0 Category: Date and time ; Style: minimalist
#include <stdio.h>
#include <time.h>

int main() {
  time_t currentTime;
  struct tm *timeInfo;
  char timeString[9];

  time(&currentTime);
  timeInfo = localtime(&currentTime);

  strftime(timeString, sizeof(timeString), "%H:%M:%S", timeInfo);
  printf("Current Time: %s\n", timeString);

  return 0;
}