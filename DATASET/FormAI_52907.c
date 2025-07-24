//FormAI DATASET v1.0 Category: Natural Language Date Converter ; Style: creative
#include <stdio.h>
#include <string.h>

int main(void) {
  char input[50];
  int day, month, year;
  char monthName[10];

  printf("Welcome to the Natural Language Date Converter!\n");
  printf("----------------------------------------------\n");
  printf("Please enter a date in natural language format (e.g. January 1, 2022): ");
  fgets(input, 50, stdin);

  sscanf(input, "%s %d, %d", monthName, &day, &year);

  if (strcmp(monthName, "January") == 0) {
    month = 1;
  } else if (strcmp(monthName, "February") == 0) {
    month = 2;
  } else if (strcmp(monthName, "March") == 0) {
    month = 3;
  } else if (strcmp(monthName, "April") == 0) {
    month = 4;
  } else if (strcmp(monthName, "May") == 0) {
    month = 5;
  } else if (strcmp(monthName, "June") == 0) {
    month = 6;
  } else if (strcmp(monthName, "July") == 0) {
    month = 7;
  } else if (strcmp(monthName, "August") == 0) {
    month = 8;
  } else if (strcmp(monthName, "September") == 0) {
    month = 9;
  } else if (strcmp(monthName, "October") == 0) {
    month = 10;
  } else if (strcmp(monthName, "November") == 0) {
    month = 11;
  } else if (strcmp(monthName, "December") == 0) {
    month = 12;
  } else {
    printf("Invalid month name\n");
    return 1;
  }

  printf("The converted date is: %02d/%02d/%04d\n", month, day, year);

  return 0;
}