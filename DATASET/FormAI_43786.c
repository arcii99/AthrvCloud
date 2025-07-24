//FormAI DATASET v1.0 Category: Date and time ; Style: relaxed
#include <stdio.h>
#include <time.h>

int main() {
  // Get current time
  time_t now = time(NULL);
  
  // Convert time to local time
  struct tm *local = localtime(&now);
  
  // Print current date and time
  printf("Today's date and time is: %s\n", asctime(local));
  
  // Print only the date in a custom format
  printf("Today is %02d/%02d/%04d\n", local->tm_mday, local->tm_mon + 1, local->tm_year + 1900);
  
  // Print only the time in a custom format
  printf("The current time is %02d:%02d:%02d\n", local->tm_hour, local->tm_min, local->tm_sec);
  
  // Calculate a future date and time
  struct tm future = *local;
  future.tm_year += 1;
  future.tm_mday -= 10;
  mktime(&future);
  
  // Print the future date and time in a custom format
  printf("A year from now, 10 days before today, it will be %02d/%02d/%04d %02d:%02d:%02d\n",
         future.tm_mday, future.tm_mon + 1, future.tm_year + 1900,
         future.tm_hour, future.tm_min, future.tm_sec);
  
  return 0;
}