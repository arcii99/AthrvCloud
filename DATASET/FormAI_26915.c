//FormAI DATASET v1.0 Category: Date and time ; Style: lively
#include <stdio.h>
#include <time.h>

int main() {

  time_t my_time = time(NULL); // declare a time variable and assign it the current time
  struct tm* time_info = localtime(&my_time); // convert the time variable to a structure

  printf("Today is %d/%d/%d\n", time_info->tm_mday, time_info->tm_mon + 1, time_info->tm_year + 1900); // print today's date in dd/mm/yyyy format
  printf("The current time is %02d:%02d:%02d\n", time_info->tm_hour, time_info->tm_min, time_info->tm_sec); // print the current time in hh:mm:ss format

  printf("\nLet's see an example of how to use mktime() function...\n");
  printf("Enter your birth date (dd/mm/yyyy): ");
  int day, month, year;
  scanf("%d/%d/%d", &day, &month, &year); // ask user for their birth date

  struct tm time_struct = {0}; // initialize a time struct variable to all zeros
  time_struct.tm_year = year - 1900; // fill the struct with user's birth date
  time_struct.tm_mon = month - 1;
  time_struct.tm_mday = day;

  time_t birth_time = mktime(&time_struct); // convert the time struct variable to a time variable

  double seconds_since_birth = difftime(my_time, birth_time); // calculate the time difference between now and the user's birth

  printf("\nYou have been alive for %.0f seconds!\n", seconds_since_birth); // print the result

  return 0; // end of program
}