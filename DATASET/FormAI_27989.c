//FormAI DATASET v1.0 Category: Date and time ; Style: curious
#include <stdio.h>
#include <time.h>

int main() {
  printf("Welcome to the Curious Time Program!\n");

  // get current time
  time_t current_time;
  time(&current_time);

  // print current time
  printf("Current Time: %s", ctime(&current_time));

  // get user input for year, month, and day
  int year, month, day;
  printf("Please enter a year: ");
  scanf("%d", &year);
  
  printf("Please enter a month: ");
  scanf("%d", &month);
  
  printf("Please enter a day: ");
  scanf("%d", &day);

  // create struct tm to represent desired date
  struct tm desired_date = {
    .tm_year = year - 1900, // years since 1900
    .tm_mon = month - 1, // months are 0-indexed
    .tm_mday = day
  };

  // convert struct tm to a time_t
  time_t desired_time = mktime(&desired_date);

  // check if desired date is in the future or past
  if (difftime(desired_time, current_time) > 0) {
    printf("The desired date is in the future!\n");
  } else if (difftime(desired_time, current_time) < 0) {
    printf("The desired date is in the past!\n");
  } else {
    printf("The desired date is today!\n");
  }

  printf("Thanks for using the Curious Time Program!\n");
  return 0;
}