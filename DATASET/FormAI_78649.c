//FormAI DATASET v1.0 Category: Date and time ; Style: relaxed
#include <stdio.h>
#include <time.h>

int main() {
  time_t t = time(NULL);
  struct tm tm = *localtime(&t);

  printf("Current date and time: %02d/%02d/%04d %02d:%02d:%02d\n", 
         tm.tm_mday, tm.tm_mon + 1, tm.tm_year + 1900, tm.tm_hour, tm.tm_min, tm.tm_sec);

  // Add 1 month
  tm.tm_mon++;
  mktime(&tm);

  printf("One month later: %02d/%02d/%04d %02d:%02d:%02d\n", 
         tm.tm_mday, tm.tm_mon + 1, tm.tm_year + 1900, tm.tm_hour, tm.tm_min, tm.tm_sec);

  // Subtract 1 hour
  tm.tm_hour--;
  mktime(&tm);

  printf("One hour earlier: %02d/%02d/%04d %02d:%02d:%02d\n", 
         tm.tm_mday, tm.tm_mon + 1, tm.tm_year + 1900, tm.tm_hour, tm.tm_min, tm.tm_sec);

  // Add 2 weeks
  tm.tm_mday += 14;
  mktime(&tm);

  printf("Two weeks later: %02d/%02d/%04d %02d:%02d:%02d\n", 
         tm.tm_mday, tm.tm_mon + 1, tm.tm_year + 1900, tm.tm_hour, tm.tm_min, tm.tm_sec);

  return 0;
}