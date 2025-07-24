//FormAI DATASET v1.0 Category: Temperature monitor ; Style: happy
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main() {

    int temperature, max_temp = -273, min_temp = 1000, avg_temp = 0, count = 0;
    float standard_deviation = 0;

    printf("Welcome to the C Temperature Monitor!\n\n");

    while (1) {
        printf("Enter temperature (in Celsius) or -999 to exit: ");
        scanf("%d", &temperature);

        if (temperature == -999)
            break;

        if (temperature < -273 || temperature > 1000) {
            printf("Invalid temperature. Please enter a value in the range -273 to 1000.\n\n");
            continue;
        }
        max_temp = fmax(max_temp, temperature);
        min_temp = fmin(min_temp, temperature);
        avg_temp += temperature;
        count++;
        double delta = temperature - avg_temp/(double)count;
        standard_deviation += delta*delta;
    }

    if (count > 0) {
        avg_temp /= count;
        printf("\nStats:\n");
        printf("Maximum temperature: %dC\n", max_temp);
        printf("Minimum temperature: %dC\n", min_temp);
        printf("Average temperature: %dC\n", avg_temp);
        standard_deviation = sqrt(standard_deviation/count);
        printf("Standard deviation: %.2fC\n", standard_deviation);
    }
    else {
        printf("\nNo temperature data entered.\n");
    }

    printf("Exiting C Temperature Monitor. Have a great day!\n");

    return 0;
}