//FormAI DATASET v1.0 Category: Temperature Converter ; Style: protected
#include <stdio.h>

//Function to convert Celsius to Fahrenheit
double celsiusToFahrenheit(double celsius) {
    return (celsius * 1.8) + 32;
}

//Function to convert Fahrenheit to Celsius
double fahrenheitToCelsius(double fahrenheit) {
    return (fahrenheit - 32) / 1.8;
}

int main() {
    int choice;
    double temperature;

    printf("Choose from the following options:\n1. Celsius to Fahrenheit\n2. Fahrenheit to Celsius\n");
    scanf("%d", &choice);

    switch (choice) {
        case 1: //Celsius to Fahrenheit
            printf("Enter temperature in Celsius: ");
            scanf("%lf", &temperature);
            printf("%.2lf Celsius is equal to %.2lf Fahrenheit\n", temperature, celsiusToFahrenheit(temperature));
            break;

        case 2: //Fahrenheit to Celsius
            printf("Enter temperature in Fahrenheit: ");
            scanf("%lf", &temperature);
            printf("%.2lf Fahrenheit is equal to %.2lf Celsius\n", temperature, fahrenheitToCelsius(temperature));
            break;

        default:
            printf("Invalid choice. Choose either 1 or 2.");
            break;
    }

    return 0;
}