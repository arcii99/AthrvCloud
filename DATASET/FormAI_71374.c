//FormAI DATASET v1.0 Category: Unit converter ; Style: optimized
#include <stdio.h>

// Convert Celsius to Fahrenheit
float celsiusToFahrenheit(float celsius) {
    return (celsius *  9/5) + 32;
}

// Convert Fahrenheit to Celsius
float FahrenheitToCelsius(float fahrenheit) {
    return (fahrenheit - 32) * 5/9;
}

int main() {
    int choice;
    float temperature;

    printf("Please select an option:\n");
    printf("1. Celsius to Fahrenheit\n");
    printf("2. Fahrenheit to Celsius\n");
    scanf("%d", &choice);

    if (choice == 1) {
        printf("Enter Celsius temperature: ");
        scanf("%f", &temperature);
        printf("%.2f C = %.2f F", temperature, celsiusToFahrenheit(temperature));
    } else if (choice == 2) {
        printf("Enter Fahrenheit temperature: ");
        scanf("%f", &temperature);
        printf("%.2f F = %.2f C", temperature, FahrenheitToCelsius(temperature));
    } else {
        printf("Invalid option selected.");
    }

    return 0;
}