//FormAI DATASET v1.0 Category: Time Travel Simulator ; Style: automated
#include <stdio.h>
#include <time.h>

int main() {
  time_t current_time;
  struct tm* time_info;
  char time_str[50];

  printf("Welcome to the Time Travel Simulator!\n");
  printf("Enter a year to travel to (from 1900 to present day): ");
  int year_choice;
  scanf("%d", &year_choice);

  // Get current time
  current_time = time(NULL);
  time_info = localtime(&current_time);

  // Get current year
  int current_year = time_info->tm_year + 1900;

  // Calculate years to travel
  int years_to_travel = year_choice - current_year;

  if (years_to_travel < 0) {
    printf("Sorry, we cannot travel back in time.\n");
  } else {
    printf("Traveling %d years into the future...\n", years_to_travel);

    // Add years to time
    time_info->tm_year += years_to_travel;
    current_time = mktime(time_info);

    // Convert to string
    strftime(time_str, sizeof(time_str), "%a %b %d %H:%M:%S %Y", time_info);

    printf("Arrived at: %s\n", time_str);
  }

  return 0;
}