//FormAI DATASET v1.0 Category: Natural Language Date Converter ; Style: minimalist
#include <stdio.h>

int main() {
  int day, month, year;
  int julian_day;

  printf("Enter date in the format DD/MM/YYYY: ");
  scanf("%d/%d/%d", &day, &month, &year);

  // Error checking
  if (day > 31 || month > 12 || year < 0) {
    printf("Invalid date entered. Please try again.\n");
    return 1;
  }

  // Determine if it is a leap year
  int leap_year = 0;
  if ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0)) {
    leap_year = 1;
  }

  // Calculate the Julian day
  switch (month) {
    case 1: julian_day = day; break;
    case 2: julian_day = 31 + day; break;
    case 3: julian_day = 59 + leap_year + day; break;
    case 4: julian_day = 90 + leap_year + day; break;
    case 5: julian_day = 120 + leap_year + day; break;
    case 6: julian_day = 151 + leap_year + day; break;
    case 7: julian_day = 181 + leap_year + day; break;
    case 8: julian_day = 212 + leap_year + day; break;
    case 9: julian_day = 243 + leap_year + day; break;
    case 10: julian_day = 273 + leap_year + day; break;
    case 11: julian_day = 304 + leap_year + day; break;
    case 12: julian_day = 334 + leap_year + day; break;
  }

  // Output the result
  printf("The Julian day for %d/%d/%d is %d.\n", day, month, year, julian_day);

  return 0;
}