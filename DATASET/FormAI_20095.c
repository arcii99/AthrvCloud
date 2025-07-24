//FormAI DATASET v1.0 Category: Natural Language Date Converter ; Style: future-proof
#include <stdio.h>
#include <string.h>
#include <time.h>

int main() {
  char input[100]; // buffer to hold user input
  char month[4], day[3], year[5];

  // get user input
  printf("Enter a date in natural language (e.g. January 1st, 2022): ");
  fgets(input, sizeof(input), stdin);

  // parse user input to get month, day, and year
  sscanf(input, "%s %s, %s", month, day, year);

  // remove any suffixes from day (e.g. "st", "nd", "rd", "th")
  day[strlen(day) - 2] = '\0';

  // convert month from string to number
  struct tm date = { 0 };
  char *months[] = { "January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December" };
  for (int i = 0; i < 12; i++) {
    if (strcmp(month, months[i]) == 0) {
      date.tm_mon = i;
      break;
    }
  }

  // set day and year
  date.tm_mday = atoi(day);
  date.tm_year = atoi(year) - 1900; // years count from 1900 in struct tm

  // convert struct tm to time_t
  time_t t = mktime(&date);

  // format and print standard date string
  printf("%s", ctime(&t));

  return 0;
}