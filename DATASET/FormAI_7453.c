//FormAI DATASET v1.0 Category: Date and time ; Style: bold
#include <stdio.h>
#include <time.h>

int main() {
  time_t rawtime;
  struct tm * timeinfo;
  char buffer[80];

  time(&rawtime);
  timeinfo = localtime(&rawtime);

  strftime(buffer, sizeof(buffer), "Today is %A, %B %d %Y.\nThe current time is %I:%M %p.", timeinfo);
  printf("\033[1m%s\033[0m\n", buffer);

  return 0;
}