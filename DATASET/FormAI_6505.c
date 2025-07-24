//FormAI DATASET v1.0 Category: Time Travel Simulator ; Style: complete
#include <stdio.h>
#include <time.h>

int main() {
  time_t current_time;
  struct tm * time_info;
  char time_string[100];

  printf("Welcome to the Time Travel Simulator!\n");
  printf("Enter a date and time in the format 'YYYY-MM-DD HH:MM:SS': ");

  // read user input
  scanf("%s", time_string);

  // convert string to time structure
  time_info = malloc(sizeof(struct tm));
  strptime(time_string, "%Y-%m-%d %H:%M:%S", time_info);

  // convert time structure to unix timestamp
  current_time = mktime(time_info);

  // print current time
  printf("Your current time is: %s", ctime(&current_time));

  // ask user how many seconds to travel
  int seconds_to_travel;
  printf("How many seconds into the future or past would you like to travel? ");
  scanf("%d", &seconds_to_travel);

  // add/subtract seconds to travel
  current_time += seconds_to_travel;

  // print travel time
  printf("Your travel time is: %s", ctime(&current_time));

  free(time_info);
  return 0;
}