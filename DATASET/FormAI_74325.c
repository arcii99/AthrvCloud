//FormAI DATASET v1.0 Category: Unit converter ; Style: detailed
#include <stdio.h>

// Function to convert Celsius to Fahrenheit
double celsiusToFahrenheit(double celsius) {
    double fahrenheit = (celsius * 1.8) + 32;
    return fahrenheit;
}

// Function to convert Fahrenheit to Celsius
double fahrenheitToCelsius(double fahrenheit) {
    double celsius = (fahrenheit - 32) / 1.8;
    return celsius;
}

int main() {
    int choice;
    double value;
    printf("Welcome to C Unit Converter! \n");

    // Display Menu
    printf("\nChoose an option: \n");
    printf("1. Celsius to Fahrenheit \n");
    printf("2. Fahrenheit to Celsius \n");
    printf("Enter your choice: ");
    scanf("%d", &choice);

    switch(choice) {
        case 1: // Celsius to Fahrenheit
            printf("Enter the value in Celsius: ");
            scanf("%lf", &value);
            printf("%.2lfC = %.2lfF", value, celsiusToFahrenheit(value));
            break;
        case 2: // Fahrenheit to Celsius
            printf("Enter the value in Fahrenheit: ");
            scanf("%lf", &value);
            printf("%.2lfF = %.2lfC", value, fahrenheitToCelsius(value));
            break;
        default: // Invalid choice
            printf("Invalid choice! Please choose option 1 or 2");
    }

    return 0;
}