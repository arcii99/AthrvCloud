//FormAI DATASET v1.0 Category: Date and time ; Style: curious
#include <stdio.h>
#include <time.h>

// Define the number of seconds in a day
#define SECONDS_IN_DAY 86400

int main() {
  time_t current_time = time(NULL);
  struct tm *local_time = localtime(&current_time);

  // Get user input for year, month and day
  int year, month, day;
  printf("Enter year (yyyy): ");
  scanf("%d", &year);
  printf("Enter month (mm): ");
  scanf("%d", &month);
  printf("Enter day (dd): ");
  scanf("%d", &day);
  
  struct tm date = {.tm_year = year-1900, .tm_mon = month-1, .tm_mday = day};

  // Get the total seconds between the current time and the given date
  time_t difference = difftime(mktime(local_time), mktime(&date));
  
  if (difference < 0) {
    puts("The date you entered is in the future!");
    return 1;
  }

  // Calculate the number of days between the current time and the given date
  int days = (int) difference / SECONDS_IN_DAY;

  // Calculate the time left over from the days calculation
  int seconds_left = (int) difference % SECONDS_IN_DAY;

  // Calculate hours, minutes, and seconds
  int hours = seconds_left / 3600;
  int minutes = (seconds_left % 3600) / 60;
  int seconds = (seconds_left % 3600) % 60;

  // Print out the time difference in a curious way
  printf("The time difference between now and %d-%02d-%02d is:\n", year, month, day);
  if (days > 0) printf("%d day%s ", days, days > 1 ? "s" : "");
  if (hours > 0) printf("%d hour%s ", hours, hours > 1 ? "s" : "");
  if (minutes > 0) printf("%d minute%s ", minutes, minutes > 1 ? "s" : "");
  printf("%d second%s\n", seconds, seconds > 1 ? "s" : "");
  return 0;
}