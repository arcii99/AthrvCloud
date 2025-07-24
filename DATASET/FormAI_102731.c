//FormAI DATASET v1.0 Category: Date and time ; Style: innovative
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
  int year, month, day, hour, minute, second;
  time_t rawtime;
  struct tm * timeinfo;

  time(&rawtime);  // get current time
  timeinfo = localtime(&rawtime);  // convert it to local time

  year = timeinfo->tm_year + 1900;
  month = timeinfo->tm_mon + 1;
  day = timeinfo->tm_mday;

  printf("Today's date is: %d-%d-%d\n", year, month, day);

  // prompting user for input
  printf("Enter the hour in 24 hour format (0-23): ");
  scanf("%d", &hour);
  printf("Enter the minute (0-59): ");
  scanf("%d", &minute);
  printf("Enter the second (0-59): ");
  scanf("%d", &second);

  // input validation
  if (hour < 0 || hour > 23 || minute < 0 || minute > 59 || second < 0 || second > 59)
  {
    printf("Invalid input! Exiting program...\n");
    return 0;
  }

  // setting the entered time
  timeinfo->tm_hour = hour;
  timeinfo->tm_min = minute;
  timeinfo->tm_sec = second;
  rawtime = mktime(timeinfo);

  // getting the formatted time
  char buffer[80];
  strftime(buffer, 80, "%Y-%m-%d %H:%M:%S %Z", timeinfo);

  printf("The entered time is: %s\n", buffer);

  return 0;
}