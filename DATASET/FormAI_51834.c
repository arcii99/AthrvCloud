//FormAI DATASET v1.0 Category: Time Travel Simulator ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
  time_t current_time;
  struct tm *local_time;
  int hours_forward;

  // Get the current time
  current_time = time(NULL);

  // Convert current time to local time
  local_time = localtime(&current_time);

  // Ask user how many hours forward to travel
  printf("How many hours forward would you like to travel? ");
  scanf("%d", &hours_forward);

  // Calculate the future time
  local_time->tm_hour += hours_forward;
  mktime(local_time);

  // Print the future time
  printf("The time %d hours from now will be: %02d:%02d:%02d\n", hours_forward, local_time->tm_hour, local_time->tm_min, local_time->tm_sec);

  return 0;
}