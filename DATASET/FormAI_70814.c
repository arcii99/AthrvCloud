//FormAI DATASET v1.0 Category: Temperature monitor ; Style: mind-bending
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    srand(time(NULL)); // initialize random seed

    float temperature = 25.0; // starting temperature
    float random = 0.0; // variable to store random temperature fluctuations
    int count = 0; // variable to keep count of temperature fluctuations

    printf("Temperature Monitor: \n");

    while (temperature > 0.0) { // keep running until temperature drops below 0
        random = (rand() % 100) / 10.0 - 5.0; // generate random fluctuation between -5 and 5 degrees
        temperature += random; // add random fluctuation to temperature
        count++;

        printf("Temperature: %.1f C\n", temperature); // print current temperature

        if (temperature >= 30.0) { // if temperature goes above 30 degrees
            printf("Warning: Temperature is getting too high!\n");
        }

        if (temperature <= 10.0) { // if temperature goes below 10 degrees
            printf("Warning: Temperature is getting too low!\n");
        }

        if (count == 10) { // every 10 fluctuations
            printf("Resetting system...\n"); // reset system
            temperature = 25.0; // reset temperature to 25 degrees
            count = 0; // reset count to 0
        }
    }

    printf("Temperature has dropped below 0, shutting down system...\n");

    return 0;
}