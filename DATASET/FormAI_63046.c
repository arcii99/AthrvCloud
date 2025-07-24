//FormAI DATASET v1.0 Category: Temperature monitor ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void) {
    float temperature;
    time_t t;

    // Initialize random number generator
    srand((unsigned) time(&t));

    while(1) {
        temperature = (float)rand()/(float)(RAND_MAX/100); // Generate random temperature between 0 and 100
        printf("The current temperature is %.2f degrees Celsius.\n", temperature);
        if (temperature > 25.0) { // Check if temperature is too high
            printf("WARNING: Temperature is too high!\n");
        }
        sleep(5); // Sleep for 5 seconds before checking again
    }

    return 0;
}