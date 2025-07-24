//FormAI DATASET v1.0 Category: Time Travel Simulator ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
  time_t now, future;
  struct tm *timeinfo;
  int year, month, day, hour, minute, second;
  
  /* Get current localtime */
  time(&now);
  timeinfo = localtime(&now);

  printf("Welcome to the Time Travel Simulator!\n\n");
  printf("Enter a future date and time (YYYY/MM/DD hh:mm:ss): ");
  scanf("%d/%d/%d %d:%d:%d", &year, &month, &day, &hour, &minute, &second);

  /* Set future time */
  timeinfo->tm_year = year - 1900;
  timeinfo->tm_mon = month - 1;
  timeinfo->tm_mday = day;
  timeinfo->tm_hour = hour;
  timeinfo->tm_min = minute;
  timeinfo->tm_sec = second;
  future = mktime(timeinfo);

  /* Calculate time difference */
  int diff = (int)difftime(future, now);

  printf("\nTravelling to %d/%d/%d %d:%d:%d...\n\n", year, month, day, hour, minute, second);

  /* Countdown */
  while(diff > 0) {
    printf("\r%d seconds remain", diff);
    fflush(stdout);
    diff -= 1;
    sleep(1);
  }

  printf("\n\nYou have arrived in the future!\n");

  return 0;
}