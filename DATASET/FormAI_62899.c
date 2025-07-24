//FormAI DATASET v1.0 Category: Temperature monitor ; Style: lively
#include <stdio.h>

int main() {
    float temperature;

    printf("Welcome to Temperature Monitor\n");

    while (1) {
        printf("Enter the temperature in Celsius: ");
        scanf("%f", &temperature);

        if (temperature < -273.15) {
            printf("Invalid temperature. Please enter a valid temperature.\n");
        } else {
            float fahrenheit = (temperature * 9 / 5) + 32;
            float kelvin = temperature + 273.15;

            printf("\nTemperature: %.2f Celsius\n", temperature);
            printf("Temperature: %.2f Fahrenheit\n", fahrenheit);
            printf("Temperature: %.2f Kelvin\n\n", kelvin);
        }
    }

    return 0;
}