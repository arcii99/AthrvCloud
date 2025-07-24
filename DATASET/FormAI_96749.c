//FormAI DATASET v1.0 Category: Time Travel Simulator ; Style: Dennis Ritchie
#include <stdio.h>
#include <time.h>

int main() {
  time_t current_time = time(NULL);
  struct tm *tm = localtime(&current_time);

  printf("Welcome to the Time Travel Simulator\n\n");
  printf("Please enter a year between 2021 and 2100: ");
  int year;
  scanf("%d", &year);

  if(year < 2021 || year > 2100) {
    printf("Error! Invalid year\n");
    return 1;
  }

  tm->tm_year = year - 1900;
  time_t time_travel = mktime(tm);

  printf("\nYou have travelled to the year %d\n\n", year);
  printf("Today's date is: %s", ctime(&current_time));
  printf("In this time period, the date is: %s", ctime(&time_travel));

  return 0;
}