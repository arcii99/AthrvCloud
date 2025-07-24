//FormAI DATASET v1.0 Category: Date and time ; Style: portable
#include <stdio.h>
#include <time.h>

int main() {
  time_t t = time(NULL);
  struct tm *tm = localtime(&t);

  printf("Current Date and Time: %04d/%02d/%02d %02d:%02d:%02d\n",
         tm->tm_year + 1900, tm->tm_mon + 1, tm->tm_mday,
         tm->tm_hour, tm->tm_min, tm->tm_sec);

  // Add 7 days
  t += 7 * 24 * 3600;
  tm = localtime(&t);

  printf("Date and Time after 1 week: %04d/%02d/%02d %02d:%02d:%02d\n",
         tm->tm_year + 1900, tm->tm_mon + 1, tm->tm_mday,
         tm->tm_hour, tm->tm_min, tm->tm_sec);

  // Add 1 month
  t += (time_t)30 * 24 * 3600; // Assume a month has 30 days
  tm = localtime(&t);

  printf("Date and Time after 1 month: %04d/%02d/%02d %02d:%02d:%02d\n",
         tm->tm_year + 1900, tm->tm_mon + 1, tm->tm_mday,
         tm->tm_hour, tm->tm_min, tm->tm_sec);

  // Subtract 3 hours
  t -= 3 * 3600;
  tm = localtime(&t);

  printf("Date and Time after -3 hours: %04d/%02d/%02d %02d:%02d:%02d\n",
         tm->tm_year + 1900, tm->tm_mon + 1, tm->tm_mday,
         tm->tm_hour, tm->tm_min, tm->tm_sec);

  return 0;
}