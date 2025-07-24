//FormAI DATASET v1.0 Category: Unit converter ; Style: enthusiastic
#include <stdio.h>

// Function to convert Celsius to Fahrenheit
float celsiusToFahrenheit(float celsius) {
    float fahrenheit = (celsius * 1.8) + 32;
    return fahrenheit;
}

// Function to convert Fahrenheit to Celsius
float fahrenheitToCelsius(float fahrenheit) {
    float celsius = (fahrenheit - 32) / 1.8;
    return celsius;
}

int main() {
    float temperature, convertedTemperature;
    int choice;

    // Displaying the menu
    printf("Select the option:\n");
    printf("1. Celsius to Fahrenheit\n");
    printf("2. Fahrenheit to Celsius\n");
    scanf("%d", &choice);

    // Taking temperature input from user
    printf("Enter the temperature: ");
    scanf("%f", &temperature);

    // Converting temperature
    if (choice == 1) {
        convertedTemperature = celsiusToFahrenheit(temperature);
        printf("%.2f Celsius is equal to %.2f Fahrenheit.", temperature, convertedTemperature);
    } else if (choice == 2) {
        convertedTemperature = fahrenheitToCelsius(temperature);
        printf("%.2f Fahrenheit is equal to %.2f Celsius.", temperature, convertedTemperature);
    } else {
        printf("Invalid option selected.");
    }

    return 0;
}