//FormAI DATASET v1.0 Category: Time Travel Simulator ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>

int main(void) {
  time_t current_time;
  char* c_time_string;
  struct tm* tm;
  int count_down;

  printf("Welcome to the time travel simulator!\n");

  printf("Please enter the number of years you wish to travel: ");
  scanf("%d", &count_down);

  printf("Initializing time travel sequence...\n");
  sleep(2); // wait for 2 seconds

  printf("3...\n");
  sleep(1); // wait for 1 second
  printf("2...\n");
  sleep(1); // wait for 1 second
  printf("1...\n");
  sleep(1); // wait for 1 second
  printf("Blast off!\n");
  sleep(2); // wait for 2 seconds

  current_time = time(NULL); // get current time in seconds
  tm = localtime(&current_time); // convert current time to struct tm
  tm->tm_year -= count_down; // subtract years from current year
  current_time = mktime(tm); // convert struct tm back to time_t

  printf("You have traveled %d years into the past!\n", count_down);
  printf("The current time is now: ");

  c_time_string = ctime(&current_time); // convert time_t to string
  printf("%s", c_time_string);

  return 0;
}