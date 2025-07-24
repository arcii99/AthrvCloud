//FormAI DATASET v1.0 Category: Time Travel Simulator ; Style: careful
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void timeTravel(int year) {
  struct tm timeinfo = {0};
  timeinfo.tm_year = year - 1900;
  mktime(&timeinfo);
  
  char buffer[80];
  strftime(buffer, 80, "%Y-%m-%d %H:%M:%S", &timeinfo);
  
  printf("You have traveled to: %s\n", buffer);
}

int main() {
  time_t current_time = time(NULL);
  struct tm *timeinfo = localtime(&current_time);

  printf("Welcome to the Time Travel Simulator!\n");
  printf("Today's date is: %s\n", asctime(timeinfo));
  
  int input_year;
  printf("Enter the year you would like to travel to: ");
  scanf("%d", &input_year);
  
  if (input_year < 1900) {
    printf("Invalid year entered. Please enter a year after 1900.\n");
    return 1;
  }
  
  printf("Initiating time travel...\n\n");
  
  // Pause for dramatic effect
  system("sleep 2");
  
  timeTravel(input_year);
  
  printf("\nThank you for using the Time Travel Simulator! Goodbye.\n");
  
  return 0;
}