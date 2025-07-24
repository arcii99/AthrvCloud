//FormAI DATASET v1.0 Category: Time Travel Simulator ; Style: high level of detail
#include <stdio.h>
#include <time.h>

int main() {
  struct tm starting_time = {0};
  struct tm current_time;
  time_t starting_timestamp, current_timestamp;
  
  // Set starting date and time
  starting_time.tm_year = 50;
  starting_time.tm_mon = 0;
  starting_time.tm_mday = 1;
  starting_time.tm_hour = 0;
  starting_time.tm_min = 0;
  starting_time.tm_sec = 0;

  // Convert starting time to timestamp
  starting_timestamp = mktime(&starting_time);

  printf("Welcome to the Time Travel Simulator!\n\n");
  printf("Enter a positive integer number of years to travel through time: ");
  int years_to_travel;
  scanf("%d", &years_to_travel);

  // Calculate current timestamp
  current_timestamp = starting_timestamp + (years_to_travel * 31536000); // 31536000 seconds in a year

  // Convert current timestamp to current time struct
  current_time = *localtime(&current_timestamp);

  printf("\n...Calculating...\n\n");
  printf("You have successfully traveled %d years through time!\n", years_to_travel);
  printf("The current date and time is: %02d/%02d/%04d %02d:%02d:%02d\n",
         current_time.tm_mday, current_time.tm_mon+1, current_time.tm_year+1900,
         current_time.tm_hour, current_time.tm_min, current_time.tm_sec);

  return 0;
}