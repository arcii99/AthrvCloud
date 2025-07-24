//FormAI DATASET v1.0 Category: Temperature monitor ; Style: standalone
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MIN_TEMP -273.15 // Absolute zero temperature in Celsius

bool is_valid_temperature(float temp) {
    return temp >= MIN_TEMP;
}

int main() {
    float temperature;
    printf("Enter the temperature in Celsius: ");
    scanf("%f", &temperature);

    if (!is_valid_temperature(temperature)) {
        printf("Invalid temperature value! The temperature must be greater than or equal to %.2f degrees Celsius.\n", MIN_TEMP);
        return EXIT_FAILURE;
    }

    printf("The temperature is %.2f degrees Celsius.\n", temperature);

    if (temperature < 0) {
        printf("Warning: The temperature is below freezing point.\n");
    } else if (temperature > 100) {
        printf("Warning: The temperature is above boiling point.\n");
    } else {
        printf("The temperature is within normal range.\n");
    }

    return EXIT_SUCCESS;
}