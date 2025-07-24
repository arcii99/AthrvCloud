//FormAI DATASET v1.0 Category: Natural Language Date Converter ; Style: multivariable
#include <stdio.h>

int main() {
  //Variable declarations
  int date, year, month, day;

  //User input for date in format: ddmmyyyy
  printf("Enter a date (ddmmyyyy): ");
  scanf("%d", &date);

  //Conversion of date to separate day, month and year
  year = date % 10000;
  month = (date / 10000) % 100;
  day = date / 1000000;

  //Printing the original date and the converted separate values
  printf("The original date is: %d\n", date);
  printf("The day is: %d\n", day);
  printf("The month is: %d\n", month);
  printf("The year is: %d\n", year);

  //Determining and printing the corresponding month name
  switch (month) {
    case 1:
      printf("The month is January\n");
      break;
    case 2:
      printf("The month is February\n");
      break;
    case 3:
      printf("The month is March\n");
      break;
    case 4:
      printf("The month is April\n");
      break;
    case 5:
      printf("The month is May\n");
      break;
    case 6:
      printf("The month is June\n");
      break;
    case 7:
      printf("The month is July\n");
      break;
    case 8:
      printf("The month is August\n");
      break;
    case 9:
      printf("The month is September\n");
      break;
    case 10:
      printf("The month is October\n");
      break;
    case 11:
      printf("The month is November\n");
      break;
    case 12:
      printf("The month is December\n");
      break;
    default:
      printf("Invalid month input\n");
  }

  return 0;
}