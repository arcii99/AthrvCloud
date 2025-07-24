//FormAI DATASET v1.0 Category: Natural Language Date Converter ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int convert_month(char month[]) {
  if (strcmp(month, "January") == 0) {
    return 1;
  }
  else if (strcmp(month, "February") == 0) {
    return 2;
  }
  else if (strcmp(month, "March") == 0) {
    return 3;
  }
  else if (strcmp(month, "April") == 0) {
    return 4;
  }
  else if (strcmp(month, "May") == 0) {
    return 5;
  }
  else if (strcmp(month, "June") == 0) {
    return 6;
  }
  else if (strcmp(month, "July") == 0) {
    return 7;
  }
  else if (strcmp(month, "August") == 0) {
    return 8;
  }
  else if (strcmp(month, "September") == 0) {
    return 9;
  }
  else if (strcmp(month, "October") == 0) {
    return 10;
  }
  else if (strcmp(month, "November") == 0) {
    return 11;
  }
  else if (strcmp(month, "December") == 0) {
    return 12;
  }
  else {
    return -1;
  }
}

void convert_date(char date[]) {
  char day[3], month[10], year[5];
  int day_int, month_int, year_int;

  // Break down the input date into day, month, and year
  strncpy(day, date, 2);
  day[2] = '\0';
  strncpy(month, date+3, 3);
  month[3] = '\0';
  strncpy(year, date+7, 4);
  year[4] = '\0';

  // Convert the month from string to integer
  month_int = convert_month(month);

  // Convert the day and year from string to integer
  day_int = strtol(day, NULL, 10);
  year_int = strtol(year, NULL, 10);

  // Print out the converted date
  printf("%02d/%02d/%04d\n", month_int, day_int, year_int);
}

int main() {
  char date[11];
  printf("Enter a date in the format MM/DD/YYYY: ");
  fgets(date, 11, stdin);

  // Remove the newline character from the end of the date string
  date[strcspn(date, "\n")] = 0;

  convert_date(date);

  return 0;
}