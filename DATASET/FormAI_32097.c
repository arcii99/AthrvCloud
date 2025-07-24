//FormAI DATASET v1.0 Category: Temperature monitor ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>
#include <unistd.h>

#define MAX_TEMPERATURE 45
#define MIN_TEMPERATURE 15
#define INTERVAL 2
#define MINUTE_LIMIT 5

int main(void) {
  // initialize variables
  int temperature = MIN_TEMPERATURE;
  int previousTemperature = MIN_TEMPERATURE;
  int minutesCounter = 0;
  bool increaseTemp = true;
  
  // start the loop
  while (true) {
    // generate random temperature
    srand(time(NULL)); 
    int changeTemp = rand() % 5;
    if (increaseTemp) {
      temperature += changeTemp;
    } else {
      temperature -= changeTemp;
    }

    // limit temperature to the range
    if (temperature > MAX_TEMPERATURE) {
      temperature = MAX_TEMPERATURE;
      increaseTemp = false;
    } else if (temperature < MIN_TEMPERATURE) {
      temperature = MIN_TEMPERATURE;
      increaseTemp = true;
    }

    // print the temperature every INTERVAL minutes
    if (minutesCounter == MINUTE_LIMIT) {
      printf("Current temperature: %d\n", temperature);
      // check the temperature difference
      if (abs(temperature - previousTemperature) >= 5) {
        printf("Temperature changed too much! Abort program.\n");
        break;
      } else {
        previousTemperature = temperature;
        minutesCounter = 0;
      }
    }

    // sleep for INTERVAL minutes
    sleep(INTERVAL * 60);
    minutesCounter += INTERVAL;
  }

  return 0;
}