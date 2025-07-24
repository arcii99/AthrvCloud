//FormAI DATASET v1.0 Category: Unit converter ; Style: optimized
#include <stdio.h>
#include <stdlib.h>

// Convert Celsius to Fahrenheit
double celsiusToFahrenheit(double celsius) {
    return (celsius * 1.8) + 32;
}

// Convert Fahrenheit to Celsius
double fahrenheitToCelsius(double fahrenheit) {
    return (fahrenheit - 32) / 1.8;
}

// Convert Miles to Kilometers
double milesToKilometers(double miles) {
    return miles * 1.609;
}

// Convert Kilometers to Miles
double kilometersToMiles(double kilometers) {
    return kilometers / 1.609;
}

// Convert Pounds to Kilograms
double poundsToKilograms(double pounds) {
    return pounds * 0.453592;
}

// Convert Kilograms to Pounds
double kilogramsToPounds(double kilograms) {
    return kilograms / 0.453592;
}

int main() {
    int option;
    double input;

    do {
        printf("Please select an option:\n");
        printf("1. Celsius to Fahrenheit\n");
        printf("2. Fahrenheit to Celsius\n");
        printf("3. Miles to Kilometers\n");
        printf("4. Kilometers to Miles\n");
        printf("5. Pounds to Kilograms\n");
        printf("6. Kilograms to Pounds\n");
        printf("0. Exit\n");
        printf("Option: ");
        scanf("%d", &option);

        switch (option) {
            case 1:
                printf("Enter Celsius temperature: ");
                scanf("%lf", &input);
                printf("%.2lf Celsius = %.2lf Fahrenheit\n", input, celsiusToFahrenheit(input));
                break;
            case 2:
                printf("Enter Fahrenheit temperature: ");
                scanf("%lf", &input);
                printf("%.2lf Fahrenheit = %.2lf Celsius\n", input, fahrenheitToCelsius(input));
                break;
            case 3:
                printf("Enter distance in miles: ");
                scanf("%lf", &input);
                printf("%.2lf miles = %.2lf kilometers\n", input, milesToKilometers(input));
                break;
            case 4:
                printf("Enter distance in kilometers: ");
                scanf("%lf", &input);
                printf("%.2lf kilometers = %.2lf miles\n", input, kilometersToMiles(input));
                break;
            case 5:
                printf("Enter weight in pounds: ");
                scanf("%lf", &input);
                printf("%.2lf pounds = %.2lf kilograms\n", input, poundsToKilograms(input));
                break;
            case 6:
                printf("Enter weight in kilograms: ");
                scanf("%lf", &input);
                printf("%.2lf kilograms = %.2lf pounds\n", input, kilogramsToPounds(input));
                break;
            case 0:
                printf("Goodbye!\n");
                break;
            default:
                printf("Invalid option. Please try again.\n");
                break;
        }

        printf("\n");
    } while (option != 0);

    return 0;
}