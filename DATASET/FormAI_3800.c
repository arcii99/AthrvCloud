//FormAI DATASET v1.0 Category: Time Travel Simulator ; Style: irregular
#include <stdio.h>
#include <time.h>
#include <stdlib.h>

int main() {
  int start_year, end_year, current_year;
  int start_month, end_month, current_month;
  int start_day, end_day, current_day;
  int time_travel_years, time_travel_months, time_travel_days;
  int travel_direction;
  
  // Get user input for start and end dates
  printf("Enter the date you want to start time travel from\n");
  printf("Year (in 4 digits): ");
  scanf("%d", &start_year);
  printf("Month (in digits): ");
  scanf("%d", &start_month);
  printf("Day (in digits): ");
  scanf("%d", &start_day);
  
  printf("\nEnter the date you want to travel to\n");
  printf("Year (in 4 digits): ");
  scanf("%d", &end_year);
  printf("Month (in digits): ");
  scanf("%d", &end_month);
  printf("Day (in digits): ");
  scanf("%d", &end_day);
  
  // Determine direction of travel
  if (start_year > end_year) {
    travel_direction = -1;
  } else if (start_year < end_year) {
    travel_direction = 1;
  } else {
    if (start_month > end_month) {
      travel_direction = -1;
    } else if (start_month < end_month) {
      travel_direction = 1;
    } else {
      if (start_day > end_day) {
        travel_direction = -1;
      } else if (start_day < end_day) {
        travel_direction = 1;
      } else {
        printf("\nYou are already at the desired date!\n");
        return 0;
      }
    }
  }
  
  // Initialize current date
  current_year = start_year;
  current_month = start_month;
  current_day = start_day;
  
  // Start time travel simulation loop
  printf("\nOkay, you are now time travelling from %02d-%02d-%04d to %02d-%02d-%04d.\n", start_day, start_month, start_year, end_day, end_month, end_year);
  printf("\n.\n.\n.\n");
  printf("ZOOOMMM!\n\n");
  
  while (current_year != end_year || current_month != end_month || current_day != end_day) {
    // Update date variables based on direction of travel
    if (travel_direction == 1) {
      // Travelling forward in time
      if (current_day == 31 && (current_month == 1 || current_month == 3 || current_month == 5 || current_month == 7 || current_month == 8 || current_month == 10 || current_month == 12)) {
        current_day = 1;
        if (current_month == 12) {
          current_year++;
          current_month = 1;
        } else {
          current_month++;
        }
      } else if ((current_day == 30 && current_month == 4) || (current_day == 30 && current_month == 6) || (current_day == 30 && current_month == 9) || (current_day == 30 && current_month == 11)) {
        current_day = 1;
        current_month++;
      } else if (current_day == 28 && current_month == 2) {
        if ((current_year % 4 == 0 && current_year % 100 != 0) || current_year % 400 == 0) {
          current_day++;
        } else {
          current_day = 1;
          current_month++;
        }
      } else {
        current_day++;
      }
    } else {
      // Travelling backwards in time
      if (current_day == 1 && (current_month == 2 || current_month == 4 || current_month == 6 || current_month == 8 || current_month == 9 || current_month == 11 || current_month == 1)) {
        if (current_month == 1) {
          current_year--;
          current_month = 12;
        } else {
          current_month--;
        }
        current_day = 31;
      } else if (current_day == 1 && (current_month == 5 || current_month == 7 || current_month == 10 || current_month == 12)) {
        current_month--;
        current_day = 30;
      } else if (current_day == 1 && current_month == 3) {
        if ((current_year % 4 == 0 && current_year % 100 != 0) || current_year % 400 == 0) {
          current_day = 29;
          current_month--;
        } else {
          current_day = 28;
          current_month--;
        }
      } else {
        current_day--;
      }
    }
    
    // Delay execution for added effect
    int rand_num = rand() % 100000;
    for (int i = 0; i < rand_num; i++);
    
    // Print updated date
    printf("Date: %02d-%02d-%04d\n", current_day, current_month, current_year);
  }
  
  printf("\nCongratulations, you have successfully time travelled to your destination!\n");
  
  return 0;
}