//FormAI DATASET v1.0 Category: Temperature monitor ; Style: modular
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// function to generate random temperature between 0 and 100
int getRandomTemp() {
    return rand() % 101;
}

// function to display the current temperature
void displayTemperature(int temp) {
    printf("Current temperature: %d degrees Celsius\n", temp);
}

// function to check if temperature is within normal range (15-25 degrees Celsius)
int isWithinNormalRange(int temp) {
    if (temp >= 15 && temp <= 25) {
        return 1;
    }
    return 0;
}

// main function to run the temperature monitor program
int main() {
    srand(time(NULL)); // seed the random number generator with current time
    int currentTemp = getRandomTemp(); // get initial random temperature
    displayTemperature(currentTemp); // display current temperature

    // check if current temperature is within normal range and alert user if not
    if (!isWithinNormalRange(currentTemp)) {
        printf("WARNING: Temperature is outside normal range!\n");
    }

    // simulate temperature changes every 10 seconds for 5 minutes (30 times)
    for (int i = 0; i < 30; i++) {
        sleep(10); // wait for 10 seconds
        int tempChange = getRandomTemp() - 50; // get random temperature change between -50 and 50
        currentTemp += tempChange; // apply temperature change to current temperature
        displayTemperature(currentTemp); // display new current temperature

        // check if new current temperature is within normal range and alert user if not
        if (!isWithinNormalRange(currentTemp)) {
            printf("WARNING: Temperature is outside normal range!\n");
        }
    }

    printf("Temperature monitoring complete.\n");

    return 0;
}