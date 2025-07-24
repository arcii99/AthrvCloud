//FormAI DATASET v1.0 Category: Temperature Converter ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>

// Decentralized function to convert Celsius to Fahrenheit
double celsiusToFahrenheit(double temperature) {
    return (temperature * 1.8) + 32;
}

// Decentralized function to convert Celsius to Kelvin
double celsiusToKelvin(double temperature) {
    return temperature + 273.15;
}

int main() {
    int choice; // User's choice of conversion
    double tempCelsius, tempConverted;

    printf("Welcome to the temperature converter!\n\n");

    // Prompt user for temperature in Celsius
    printf("Enter the temperature in Celsius: ");
    scanf("%lf", &tempCelsius);

    // Print conversion menu
    printf("\nChoose a conversion:\n");
    printf("1. Celsius to Fahrenheit\n");
    printf("2. Celsius to Kelvin\n");
    printf("Enter your choice (1 or 2): ");
    scanf("%d", &choice);

    // Convert temperature and print result
    switch(choice) {
        case 1:
            tempConverted = celsiusToFahrenheit(tempCelsius);
            printf("\n%.2lf degrees Celsius is %.2lf degrees Fahrenheit.\n", tempCelsius, tempConverted);
            break;
        case 2:
            tempConverted = celsiusToKelvin(tempCelsius);
            printf("\n%.2lf degrees Celsius is %.2lf Kelvin.\n", tempCelsius, tempConverted);
            break;
        default:
            printf("\nInvalid choice.\n");
    }

    return 0;
}