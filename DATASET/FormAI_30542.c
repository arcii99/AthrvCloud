//FormAI DATASET v1.0 Category: Date and time ; Style: single-threaded
#include <stdio.h>
#include <time.h>

int main(void) {
  time_t current_time;
  struct tm * time_info;
  char time_str[100];

  // Get current time
  current_time = time(NULL);

  // Format time string
  time_info = localtime(&current_time);
  strftime(time_str, sizeof(time_str), "%Y-%m-%d %H:%M:%S", time_info);

  // Print formatted time string
  printf("Current date and time: %s\n", time_str);

  return 0;
}