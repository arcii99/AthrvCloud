//FormAI DATASET v1.0 Category: Smart home automation ; Style: post-apocalyptic
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

int main() {
    srand(time(0)); // seed for randomization

    // defining variables for the various levels of the home
    bool isMainOn = false;
    int mainTemp = rand() % 100;
    bool isUpperOn = false;
    int upperTemp = rand() % 100;
    bool isLowerOn = false;
    int lowerTemp = rand() % 100;

    // loop for checking home levels and updating temperatures
    while (true) {
        // check and adjust main level
        if (!isMainOn) {
            printf("Main level is off. Turning on...\n");
            isMainOn = true;
        }
        if (mainTemp > 80) {
            printf("Main level temperature is too high (%d). Turning on air conditioner...\n", mainTemp);
        } else if (mainTemp < 60) {
            printf("Main level temperature is too low (%d). Turning on heater...\n", mainTemp);
        } else {
            printf("Main level temperature is optimal (%d)...\n", mainTemp);
        }
        mainTemp += rand() % 10 - 5; // adjust temperature randomly

        // check and adjust upper level
        if (!isUpperOn && rand() % 10 < 5) { // 50% chance of turning on
            printf("Upper level is off. Turning on...\n");
            isUpperOn = true;
        }
        if (isUpperOn && upperTemp > 90) {
            printf("Upper level temperature is too high (%d). Turning off...\n", upperTemp);
            isUpperOn = false;
        } else if (isUpperOn && upperTemp < 70) {
            printf("Upper level temperature is too low (%d). Turning on heater...\n", upperTemp);
        } else if (isUpperOn) {
            printf("Upper level temperature is optimal (%d)...\n", upperTemp);
        }
        upperTemp += rand() % 10 - 5;

        // check and adjust lower level
        if (!isLowerOn && rand() % 10 < 5) { // 50% chance of turning on
            printf("Lower level is off. Turning on...\n");
            isLowerOn = true;
        }
        if (isLowerOn && lowerTemp > 100) {
            printf("Lower level temperature is too high (%d). Turning off...\n", lowerTemp);
            isLowerOn = false;
        } else if (isLowerOn && lowerTemp < 80) {
            printf("Lower level temperature is too low (%d). Turning on heater...\n", lowerTemp);
        } else if (isLowerOn) {
            printf("Lower level temperature is optimal (%d)...\n", lowerTemp);
        }
        lowerTemp += rand() % 10 - 5;

        // delay for realism
        printf("\n");
        for (int i = 0; i < 5; i++) {
            printf(". ");
            fflush(stdout);
            sleep(1);
        }
        printf("\n\n");
    }

    return 0;
}