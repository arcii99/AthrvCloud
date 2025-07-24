//FormAI DATASET v1.0 Category: Temperature monitor ; Style: post-apocalyptic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {

    srand(time(NULL)); // seed the random number generator with the current time

    int temperature = 0;
    int tempChange = 0;

    printf("Welcome to the Post-Apocalyptic C Temperature Monitor\n\n");

    while(1) { // infinite loop

        printf("Current Temperature: %d degrees Celsius\n", temperature);

        // generate a random number between -5 and 5 to simulate temperature fluctuations
        tempChange = (rand() % 11) - 5;

        temperature += tempChange;

        // check if temperature goes below freezing
        if(temperature < 0) {
            printf("WARNING: Temperature has dropped below freezing!\n");
            printf("Please take necessary precautions to keep warm.\n");
        }

        // check if temperature goes above boiling point
        if(temperature > 100) {
            printf("WARNING: Temperature has exceeded boiling point!\n");
            printf("Please take necessary precautions to cool down.\n");
        }

        // sleep for 1 second before updating temperature
        sleep(1);
    }

    return 0;
}