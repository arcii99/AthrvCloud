//FormAI DATASET v1.0 Category: Traffic Light Controller ; Style: Donald Knuth
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/* This function generates a random number between two integers */
int generateRandomNumber(int min, int max) {
    int randomNumber = (rand() % (max - min + 1)) + min;
    return randomNumber;
}

/* Program entry point */
int main() {
    int timeInterval = 10; // The time interval in seconds for each color
    int counter = 0; // The counter for the time interval
    int redLight = 1; // The state of the red light: 1 for on, 0 for off
    int yellowLight = 0; // The state of the yellow light: 1 for on, 0 for off
    int greenLight = 0; // The state of the green light: 1 for on, 0 for off

    srand(time(0)); // Initialize random seed

    /* Loop forever */
    while (1) {

        /* Increment counter */
        counter++;

        /* Switch light color when time interval is up */
        if (counter >= timeInterval) {

            /* Turn off all lights */
            redLight = 0;
            yellowLight = 0;
            greenLight = 0;

            /* Generate a random number to determine the next light color */
            int randomNumber = generateRandomNumber(1, 3);

            /* Set the next light color */
            switch (randomNumber) {
                case 1: // Red light
                    redLight = 1;
                    break;
                case 2: // Yellow light
                    yellowLight = 1;
                    break;
                case 3: // Green light
                    greenLight = 1;
                    break;
            }

            /* Reset counter */
            counter = 0;
        }

        /* Display the current light color */
        printf("Red Light: %d, Yellow Light: %d, Green Light: %d\n", redLight, yellowLight, greenLight);

        /* Wait for one second */
        sleep(1);
    }

    return 0;
}