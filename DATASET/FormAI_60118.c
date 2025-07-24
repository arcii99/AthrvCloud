//FormAI DATASET v1.0 Category: Date and time ; Style: minimalist
#include <stdio.h>
#include <time.h>

int main() {
  time_t current_time;
  char* c_time_string;
  
  /* Obtain current time */
  current_time = time(NULL);
  
  /* Convert to local time */
  c_time_string = ctime(&current_time);
  
  /* Print to console */
  printf("Current time is: %s", c_time_string);
  
  /* Convert to struct tm for further processing */
  struct tm* time_info;
  time_info = localtime(&current_time);
  
  /* Display date and time components separately */
  printf("Current date and time components:\n");
  printf("Year: %d\n", time_info->tm_year + 1900);
  printf("Month: %d\n", time_info->tm_mon + 1);
  printf("Day: %d\n", time_info->tm_mday);
  printf("Hour: %d\n", time_info->tm_hour);
  printf("Minute: %d\n", time_info->tm_min);
  printf("Second: %d\n", time_info->tm_sec);
  
  /* Create a specific date and time */
  struct tm specific_time;
  specific_time.tm_year = 2022 - 1900;
  specific_time.tm_mon = 9 - 1;
  specific_time.tm_mday = 25;
  specific_time.tm_hour = 13;
  specific_time.tm_min = 30;
  specific_time.tm_sec = 0;
  
  time_t specific_time_epoch = mktime(&specific_time);
  
  /* Convert to local time */
  char* specific_c_time_string;
  specific_c_time_string = ctime(&specific_time_epoch);
  
  /* Print to console */
  printf("Specific time is: %s", specific_c_time_string);
  
  return 0;
}