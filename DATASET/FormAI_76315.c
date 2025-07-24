//FormAI DATASET v1.0 Category: Time Travel Simulator ; Style: beginner-friendly
#include <stdio.h>
#include <time.h>

int main(){
  time_t current_time;
  struct tm * time_info;
  char time_str[100];

  // get the current time
  time(&current_time);

  // get the time details
  time_info = localtime(&current_time);

  strftime(time_str, sizeof(time_str), "%Y-%m-%d %H:%M:%S", time_info);

  printf("Welcome to the Time Travel Simulator!\n\n");
  printf("The current date and time is: %s\n", time_str);
  printf("Enter the number of years you would like to travel back in time: ");

  int years_to_travel;
  scanf("%d", &years_to_travel);

  // update the time information
  time_info->tm_year -= years_to_travel;
  mktime(time_info);

  // format the updated time into a string
  strftime(time_str, sizeof(time_str), "%Y-%m-%d %H:%M:%S", time_info);

  printf("\nTravelling back %d years...\n\n", years_to_travel);
  printf("You have arrived in the year %d\n", time_info->tm_year + 1900);
  printf("The date and time is now %s\n", time_str);

  return 0;
}