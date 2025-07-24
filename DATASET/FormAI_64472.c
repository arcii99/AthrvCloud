//FormAI DATASET v1.0 Category: Time Travel Simulator ; Style: authentic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
  time_t current_time;
  struct tm * current_tm;
  char input_date[20];
  int future_years;
  struct tm future_tm;
  time_t future_time;
  
  // Get current time
  time(&current_time);
  current_tm = localtime(&current_time);
  
  // Ask for date input and validate format
  printf("Enter a date in the format YYYY/MM/DD: ");
  fgets(input_date, 20, stdin);
  if(sscanf(input_date, "%d/%d/%d", &future_tm.tm_year, &future_tm.tm_mon, &future_tm.tm_mday) != 3) {
    printf("\nInvalid date format. Please use the format YYYY/MM/DD.\n");
    return 1;
  }
  
  // Convert date to seconds since epoch
  future_tm.tm_year -= 1900;
  future_tm.tm_mon -= 1;
  future_tm.tm_hour = 0;
  future_tm.tm_min = 0;
  future_tm.tm_sec = 0;
  future_time = mktime(&future_tm);
  
  // Determine how many years in the future
  future_years = (int) ((future_time - current_time) / 31556952);
  
  // Return date and years in the future
  printf("\nYou have traveled to the date %s.\n", input_date);
  printf("You have traveled %d years into the future.\n\n", future_years);
  
  return 0;
}