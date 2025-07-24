//FormAI DATASET v1.0 Category: Natural Language Date Converter ; Style: multivariable
#include <stdio.h>

int convert_date(int day, int month, int year);

int main() {
  int day, month, year, result;

  printf("Enter a date in the format DD/MM/YYYY: ");
  scanf("%d/%d/%d", &day, &month, &year);

  result = convert_date(day, month, year);

  if (result == 1) {
    printf("Invalid date.\n");
  } else {
    printf("The date is: %d\n", result);
  }

  return 0;
}

int convert_date(int day, int month, int year) {
  int result;

  // Check for valid day
  if (day < 1 || day > 31) {
    return 1;
  }

  // Check for valid month
  if (month < 1 || month > 12) {
    return 1;
  }

  // Check for valid year
  if (year < 1900 || year > 2100) {
    return 1;
  }

  // Calculate the date in the format YYYYMMDD
  result = year * 10000 + month * 100 + day;

  return result;
}