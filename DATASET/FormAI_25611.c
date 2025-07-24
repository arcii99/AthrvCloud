//FormAI DATASET v1.0 Category: Temperature monitor ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MIN_TEMP 0
#define MAX_TEMP 100
#define TEMPERATURE_SAMPLES 10

int main() {
    int temperature[TEMPERATURE_SAMPLES];
    int total_temperature = 0;
    float average_temperature = 0;

    /* Seed the random number generator */
    srand(time(NULL));

    /* Generate random temperature samples */
    printf("Temperature Samples:\n");
    for(int i=0; i<TEMPERATURE_SAMPLES; i++) {
        temperature[i] = (rand() % (MAX_TEMP-MIN_TEMP+1)) + MIN_TEMP;
        printf("Sample %d: %dC\n", i+1, temperature[i]);
        total_temperature += temperature[i];
    }

    /* Calculate the average temperature */
    average_temperature = (float) total_temperature / TEMPERATURE_SAMPLES;

    /* Display the average temperature */
    printf("Average Temperature: %.2fC\n", average_temperature);

    return 0;
}