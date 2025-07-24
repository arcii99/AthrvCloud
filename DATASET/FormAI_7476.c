//FormAI DATASET v1.0 Category: Time Travel Simulator ; Style: grateful
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
  time_t currentTime;
  struct tm *timeInfo;
  char timeString[9];
  
  time(&currentTime);
  timeInfo = localtime(&currentTime);
  
  strftime(timeString, sizeof(timeString), "%H:%M:%S", timeInfo);
  printf("Welcome to the C Time Travel Simulator!\n");
  
  if((timeInfo -> tm_hour) >= 0 && (timeInfo -> tm_hour) < 12) {
    printf("It's currently %s. Good morning time traveler!\n", timeString);
  } else if((timeInfo -> tm_hour) >= 12 && (timeInfo -> tm_hour) < 18) {
    printf("It's currently %s. Good afternoon time traveler!\n", timeString);
  } else {
    printf("It's currently %s. Good evening time traveler!\n", timeString);
  }
  
  printf("Please enter the number of years you would like to travel through time: ");
  int numYears;
  scanf("%d", &numYears);
  
  if(numYears < 0) {
    printf("Error: Cannot travel through negative time.\n");
    return 1;
  }
  
  currentTime -= 60*60*24*365*numYears;
  timeInfo = localtime(&currentTime);
  strftime(timeString, sizeof(timeString), "%H:%M:%S", timeInfo);
  
  if((timeInfo -> tm_year) + 1900 < 1900) {
    printf("Error: Cannot travel back to before 1900.\n");
    return 1;
  }
  
  printf("You have successfully traveled back %d years! It's now %s.\n", numYears, timeString);
  
  return 0;
}