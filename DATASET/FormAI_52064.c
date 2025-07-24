//FormAI DATASET v1.0 Category: Date and time ; Style: innovative
#include <stdio.h>
#include <time.h>

int main() {
  time_t t;
  struct tm *now;
  
  time(&t);
  now = localtime(&t);
  
  printf("Today's date is %d/%d/%d\n", now->tm_mday, now->tm_mon + 1, now->tm_year + 1900);
  
  printf("Current time is %02d:%02d:%02d\n", now->tm_hour, now->tm_min, now->tm_sec);
  
  printf("Let's add 5 hours to the current time:\n");
  
  now->tm_hour += 5;
  mktime(now);
  
  printf("New time is %02d:%02d:%02d\n", now->tm_hour, now->tm_min, now->tm_sec);
  
  printf("Let's subtract 2 days from the current date:\n");
  
  now->tm_mday -= 2;
  mktime(now);
  
  printf("New date is %d/%d/%d\n", now->tm_mday, now->tm_mon + 1, now->tm_year + 1900);
  
  return 0;
}