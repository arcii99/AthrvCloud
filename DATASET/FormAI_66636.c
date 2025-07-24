//FormAI DATASET v1.0 Category: Traffic Flow Simulation ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
  int hour = 8, minute = 0, day = 1; // starting time and day
  int car_count = 0;
  srand(time(NULL)); // for random number generation
  printf("Welcome to the Traffic Flow Simulation!\n");

  while (day <= 5) { // loop for five days
    printf("\nDay %d:\n", day);
    while (hour < 18) { // loop for the duration of one work day
      printf("%02d:%02d - ", hour, minute);
      if (rand() % 10 < 7) { // 70% chance of a car passing by
        printf("Car %d passed by\n", ++car_count);
      } else {
        printf("No cars passed by\n");
      }
      if (++minute == 60) { // increment hours and minutes
        hour++;
        minute = 0;
      }
    }
    hour = 8; // reset time for next day
    minute = 0;
    day++;
  }

  printf("\nSimulation complete! %d cars passed by.\n", car_count);

  return 0;
}