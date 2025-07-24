//FormAI DATASET v1.0 Category: Time Travel Simulator ; Style: scientific
#include <stdio.h>

int main() {
  int currentYear, travelYear, yearsTraveled, leapYears = 0;
  printf("Enter the current year: ");
  scanf("%d", &currentYear);
  printf("Enter the year you want to travel to: ");
  scanf("%d", &travelYear);
  
  // Calculate the number of years traveled
  yearsTraveled = travelYear - currentYear;
  
  // Calculate the number of leap years traveled
  for (int year = currentYear; year <= travelYear; year++) {
    if (year % 4 == 0) {
      if (year % 100 == 0) {
        if (year % 400 == 0) {
          leapYears++;
        }
      } else {
        leapYears++;
      }
    }
  }
  
  // Print the results
  printf("You have traveled %d years.\n", yearsTraveled);
  printf("You have traveled through %d leap years.\n", leapYears);
  
  return 0;
}