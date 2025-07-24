//FormAI DATASET v1.0 Category: Temperature monitor ; Style: genious
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

// define the maximum and minimum temperature
#define MAX_TEMP 120
#define MIN_TEMP -20

// generate a random temperature between -20 and 120 degrees
int generateTemp() {
    int temp = rand() % (MAX_TEMP - MIN_TEMP + 1) + MIN_TEMP;
    return temp;
}

int main() {
    srand(time(NULL)); // seed random generator with current time

    int currentTemp = generateTemp(); // start with a random temperature
    bool isRising = true; // temperature is initially rising
    int highTemp = currentTemp; // initialize high temperature to the current temperature
    int lowTemp = currentTemp; // initialize low temperature to the current temperature
    int count = 0; // initialize counter to 0

    printf("Welcome to the Temperature Monitor!\n");
    printf("The current temperature is %d degrees Celsius.\n", currentTemp);

    while (count < 10) { // continue loop until 10 temperature readings have been taken
        if (isRising == true) {
            currentTemp += rand() % 6 + 1; // increase temperature by a random value between 1 and 6
        } else {
            currentTemp -= rand() % 6 + 1; // decrease temperature by a random value between 1 and 6
        }

        if (currentTemp >= MAX_TEMP) { // if temperature exceeds maximum, set to maximum and start decrementing
            currentTemp = MAX_TEMP;
            isRising = false; // start decrementing temperature
        } else if (currentTemp <= MIN_TEMP) { // if temperature falls below minimum, set to minimum and start incrementing
            currentTemp = MIN_TEMP;
            isRising = true; // start incrementing temperature
        }

        // check for new high and low temperatures
        if (currentTemp > highTemp) {
            highTemp = currentTemp;
        } else if (currentTemp < lowTemp) {
            lowTemp = currentTemp;
        }

        printf("Temperature reading #%d: %d degrees Celsius\n", count+1, currentTemp);
        count++; // increment counter
    }

    printf("The highest temperature recorded was %d degrees Celsius.\n", highTemp);
    printf("The lowest temperature recorded was %d degrees Celsius.\n", lowTemp);

    return 0;
}