//FormAI DATASET v1.0 Category: Temperature monitor ; Style: multivariable
#include <stdio.h>

int main() {
    double currentTemp;
    double maxTemp = -273; // Lowest possible temperature in Celsius
    double minTemp = 100000; // Arbitrarily high initial value

    for(int i = 0; i < 24; i++) {
        printf("Enter temperature at hour %d: ", i+1);
        scanf("%lf", &currentTemp);

        // Check if temperature input is valid
        if(currentTemp < -273 || currentTemp > 100000) {
            printf("Invalid temperature input. Please enter a temperature between -273 and 100000 Celsius.\n");
            i--; // Decrement i to ensure input for this hour is requested again
            continue;
        }

        // Update maximum and minimum temperatures
        if(currentTemp > maxTemp) {
            maxTemp = currentTemp;
        }
        if(currentTemp < minTemp) {
            minTemp = currentTemp;
        }
    }

    printf("Maximum temperature: %.2lf Celsius\n", maxTemp);
    printf("Minimum temperature: %.2lf Celsius\n", minTemp);

    return 0;
}