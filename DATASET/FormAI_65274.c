//FormAI DATASET v1.0 Category: Time Travel Simulator ; Style: invasive
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
  // set seed for random number generation
  srand(time(NULL));

  // declare variables
  int year, month, day, hour, minute, second;

  // get current date and time
  time_t now;
  time(&now);
  struct tm *local = localtime(&now);

  // print current date and time
  printf("Current date and time: %s", asctime(local));

  // generate random date in the past
  year = 1000 + rand() % 1019;
  month = rand() % 12 + 1;
  if (month == 2) {
    if (year % 4 == 0 && (year % 100 != 0 || year % 400 == 0)) {
      day = rand() % 29 + 1;
    } else {
      day = rand() % 28 + 1;
    }
  } else if (month == 4 || month == 6 || month == 9 || month == 11) {
    day = rand() % 30 + 1;
  } else {
    day = rand() % 31 + 1;
  }
  hour = rand() % 24;
  minute = rand() % 60;
  second = rand() % 60;

  // set time travel date and time
  struct tm travel = {0};
  travel.tm_year = year - 1900;
  travel.tm_mon = month - 1;
  travel.tm_mday = day;
  travel.tm_hour = hour;
  travel.tm_min = minute;
  travel.tm_sec = second;
  time_t travel_time = mktime(&travel);

  // print time travel date and time
  printf("Time travel date and time: %s", asctime(&travel));

  // travel through time
  printf("Press Enter to travel through time.");
  while (getchar() != '\n');
  time(&now);
  printf("You have arrived at your destination date and time: %s", asctime(local));

  return 0;
}