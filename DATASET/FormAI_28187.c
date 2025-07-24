//FormAI DATASET v1.0 Category: Natural Language Date Converter ; Style: lively
#include <stdio.h>

int main() {
  int day, month, year;

  // Get input from user
  printf("Enter the date in the format DD/MM/YYYY: ");
  scanf("%d/%d/%d", &day, &month, &year);

  // Check for valid input
  if (day < 1 || day > 31 || month < 1 || month > 12 || year < 0) {
    printf("Invalid date entered!\n");
    return 1;
  }

  // Calculate number of days in each month
  int days_in_month[] = {31, 28 + (year % 4 == 0 && year % 100 != 0 || year % 400 == 0), 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

  // Calculate number of days from beginning of year
  int days_from_start = 0;
  for (int i = 0; i < month - 1; i++) {
    days_from_start += days_in_month[i];
  }
  days_from_start += day;

  // Output result
  printf("The date %02d/%02d/%d is the %dth day of the year.\n", day, month, year, days_from_start);

  return 0;
}