//FormAI DATASET v1.0 Category: Date and time ; Style: synchronous
#include <stdio.h>
#include <time.h>

int main() {
  // Get current date/time in seconds and adjust for timezone
  time_t rawtime = time(NULL);
  struct tm *timeinfo = localtime(&rawtime);
  
  // Print current date and time
  printf("Current date and time: %s", asctime(timeinfo));
  
  // Print current year, month, and day
  printf("Current year: %d\n", 1900 + timeinfo->tm_year);
  printf("Current month: %d\n", 1 + timeinfo->tm_mon);
  printf("Current day: %d\n", timeinfo->tm_mday);
  
  // Prompt user for birth year, month, and day
  int birth_year, birth_month, birth_day;
  printf("Enter your birth year: ");
  scanf("%d", &birth_year);
  printf("Enter your birth month (1-12): ");
  scanf("%d", &birth_month);
  printf("Enter your birth day (1-31): ");
  scanf("%d", &birth_day);
  
  // Calculate age in years, months, and days
  int age_years = timeinfo->tm_year - (birth_year - 1900);
  int age_months = timeinfo->tm_mon - (birth_month - 1);
  int age_days = timeinfo->tm_mday - birth_day;
  
  // Adjust for negative values and calculate remainder
  if (age_days < 0) {
    age_months--;
    age_days += 30;
  }
  if (age_months < 0) {
    age_years--;
    age_months += 12;
  }
  
  // Print age in years, months, and days
  printf("Your age: %d years, %d months, %d days\n", age_years, age_months, age_days);
  
  return 0;
}