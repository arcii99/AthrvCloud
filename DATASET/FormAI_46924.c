//FormAI DATASET v1.0 Category: Unit converter ; Style: calm
#include <stdio.h>

// Function to convert Celsius to Fahrenheit
float celsiusToFahrenheit(float celsius) {
    float fahrenheit = (celsius * 9/5) + 32; // formula to convert
    return fahrenheit;
}

// Function to convert Fahrenheit to Celsius
float fahrenheitToCelsius(float fahrenheit) {
    float celsius = (fahrenheit - 32) * 5/9; // formula to convert
    return celsius;
}

int main() {
    int choice; // variable to store the user's choice
    float temperature; // variable to store the temperature value

    // menu to display the user's options
    printf("-----Temperature Conversion Menu-----\n");
    printf("1. Celsius to Fahrenheit\n");
    printf("2. Fahrenheit to Celsius\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);

    switch(choice) {
        case 1: // Celsius to Fahrenheit conversion
            printf("Enter the temperature value in Celsius: ");
            scanf("%f", &temperature);
            printf("%.2f Celsius = %.2f Fahrenheit\n", temperature, celsiusToFahrenheit(temperature));
            break;
        case 2: // Fahrenheit to Celsius conversion
            printf("Enter the temperature value in Fahrenheit: ");
            scanf("%f", &temperature);
            printf("%.2f Fahrenheit = %.2f Celsius\n", temperature, fahrenheitToCelsius(temperature));
            break;
        default: // if user enters an invalid choice
            printf("Invalid choice entered!\n");
    }
    return 0;
}