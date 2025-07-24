//FormAI DATASET v1.0 Category: Date and time ; Style: relaxed
#include <stdio.h>
#include <time.h>

int main() {
  time_t rawtime;
  struct tm * timeinfo;

  time(&rawtime);
  timeinfo = localtime(&rawtime);

  printf("Current date and time: %s", asctime(timeinfo));
  
  //Adding 10 days to the current date
  timeinfo->tm_mday += 10;
  mktime(timeinfo);
  
  printf("Date after 10 days: %s", asctime(timeinfo));
  
  //Calculating difference between two dates
  struct tm date1 = {0, 0, 0, 14, 2, 2021 - 1900};
  struct tm date2 = {0, 0, 0, 24, 2, 2021 - 1900};

  time_t time1 = mktime(&date1);
  time_t time2 = mktime(&date2);

  double seconds = difftime(time2, time1);
  double days = seconds / (24 * 3600);

  printf("Number of days between %s and %s is %.0f\n", asctime(&date1), asctime(&date2), days);

  return 0;
}