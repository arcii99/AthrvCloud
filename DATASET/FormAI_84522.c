//FormAI DATASET v1.0 Category: Temperature monitor ; Style: brave
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_TEMP 100
#define MIN_TEMP 0

int main(void) {
  int current_temp = 25;

  srand(time(NULL)); // used to generate random numbers based on time
  printf("Welcome to the Brave Temperature Monitor!\n");

  while (1) { // infinite loop
    int new_temp = (rand() % (MAX_TEMP - MIN_TEMP + 1)) + MIN_TEMP; // generates a random temperature between the maximum and minimum temperature
    int temp_difference = new_temp - current_temp;

    if (temp_difference > 10) { // if the temperature difference is greater than 10 degrees
      printf("WARNING: Temperature has increased drastically by %d degrees!\n", temp_difference);
    } else if (temp_difference < -10) { // if the temperature difference is less than -10 degrees
      printf("WARNING: Temperature has decreased drastically by %d degrees!\n", temp_difference);
    } else if (temp_difference > 0) { // if the temperature has increased
      printf("Temperature has increased by %d degrees. New temperature is %d\n", temp_difference, new_temp);
    } else if (temp_difference < 0) { // if the temperature has decreased
      printf("Temperature has decreased by %d degrees. New temperature is %d\n", abs(temp_difference), new_temp);
    } else { // if the temperature has not changed
      printf("Temperature remains at %d\n", current_temp);
    }

    current_temp = new_temp; // sets the new temperature as the current temperature

    sleep(2); // waits for 2 seconds before generating a new temperature
  }

  return 0;
}