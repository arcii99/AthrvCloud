//FormAI DATASET v1.0 Category: Temperature Converter ; Style: cheerful
#include <stdio.h>

// Function to convert Celsius to Fahrenheit
double celsiusToFahrenheit(double celsius) {
    return (celsius * 9.0 / 5.0) + 32.0;
}

// Function to convert Celsius to Kelvin
double celsiusToKelvin(double celsius) {
    return celsius + 273.15;
}

int main() {
    double celsius, fahrenheit, kelvin;
    char choice;

    printf("Welcome to the Celsius Converter!\n");

    do {
        // Asking for user input
        printf("\nEnter the temperature in Celsius: ");
        scanf("%lf", &celsius);

        // Converting Celsius to Fahrenheit and Kelvin
        fahrenheit = celsiusToFahrenheit(celsius);
        kelvin = celsiusToKelvin(celsius);

        // Printing the converted temperatures
        printf("\n%.2lf degrees Celsius is:\n", celsius);
        printf("%.2lf degrees Fahrenheit\n", fahrenheit);
        printf("%.2lf Kelvin\n", kelvin);

        // Asking if user wants to convert another temperature
        printf("\nDo you want to convert another temperature? (y/n): ");
        scanf(" %c", &choice);

    } while (choice == 'y' || choice == 'Y');

    printf("\nThank you for using the Celsius Converter! Goodbye!\n");

    return 0;
}