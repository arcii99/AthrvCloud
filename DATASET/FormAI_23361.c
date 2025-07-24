//FormAI DATASET v1.0 Category: Temperature monitor ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_TEMP 100 // maximum temperature limit
#define MIN_TEMP 0 // minimum temperature limit

int main() {
    float temperature; // variable to store the current temperature

    while (1) { // continuously monitor the temperature
        printf("Enter the current temperature: ");
        scanf("%f", &temperature);

        if (temperature >= MIN_TEMP && temperature <= MAX_TEMP) { // check if temperature is within limits
            printf("Temperature is within limits!\n");
        }
        else { // temperature is outside the limits
            printf("Temperature is outside the limits!\n");

            if (temperature < MIN_TEMP) { // temperature is too low
                printf("WARNING: Temperature is too low, turn up the heating!\n");
            }
            else { // temperature is too high
                printf("WARNING: Temperature is too high, turn down the heating!\n");
            }
        }

        // wait for 1 second before checking the temperature again
        for (int i = 0; i < 1000000; i++) {
            // do nothing
        }
    }

    return 0;
}