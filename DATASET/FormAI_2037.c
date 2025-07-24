//FormAI DATASET v1.0 Category: Time Travel Simulator ; Style: safe
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
  time_t present_time, future_time;
  struct tm* future_tm;
  char time_str[64];

  // Get the present time
  present_time = time(NULL);

  // Set the future time to exactly one year ahead of present time
  future_time = present_time + 60 * 60 * 24 * 365;
  future_tm = localtime(&future_time);

  // Print the future time in a readable format
  strftime(time_str, sizeof(time_str), "%A, %B %d, %Y %H:%M:%S", future_tm);
  printf("You have successfully time traveled to: %s\n", time_str);

  // Perform some action for time travelers
  printf("Welcome to the future! Here is what has changed:\n");
  printf("* Flying cars are the norm\n");
  printf("* Robots everywhere\n");
  printf("* Teleportation is possible\n");

  return 0;
}