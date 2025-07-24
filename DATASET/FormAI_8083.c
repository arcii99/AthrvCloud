//FormAI DATASET v1.0 Category: Unit converter ; Style: future-proof
#include <stdio.h>

// Function to convert temperature from Celsius to Fahrenheit
double celsiusToFahrenheit(double celsius) {
    return (celsius * 1.8) + 32;
}

// Function to convert temperature from Fahrenheit to Celsius
double fahrenheitToCelsius(double fahrenheit) {
    return (fahrenheit - 32) / 1.8;
}

// Function to convert distance from kilometers to miles
double kilometersToMiles(double kilometers) {
    return kilometers * 0.621371;
}

// Function to convert distance from miles to kilometers
double milesToKilometers(double miles) {
    return miles * 1.60934;
}

int main() {
    int option;
    double input, output;
    
    printf("Welcome to the Unit Converter\n");
    printf("1. Celsius to Fahrenheit\n");
    printf("2. Fahrenheit to Celsius\n");
    printf("3. Kilometers to Miles\n");
    printf("4. Miles to Kilometers\n");
    printf("Enter your choice: ");
    scanf("%d", &option);
    
    switch(option) {
        case 1:
            printf("Enter temperature in Celsius: ");
            scanf("%lf", &input);
            output = celsiusToFahrenheit(input);
            printf("%lf Celsius = %lf Fahrenheit\n", input, output);
            break;
        case 2:
            printf("Enter temperature in Fahrenheit: ");
            scanf("%lf", &input);
            output = fahrenheitToCelsius(input);
            printf("%lf Fahrenheit = %lf Celsius\n", input, output);
            break;
        case 3:
            printf("Enter distance in kilometers: ");
            scanf("%lf", &input);
            output = kilometersToMiles(input);
            printf("%lf kilometers = %lf miles\n", input, output);
            break;
        case 4:
            printf("Enter distance in miles: ");
            scanf("%lf", &input);
            output = milesToKilometers(input);
            printf("%lf miles = %lf kilometers\n", input, output);
            break;
        default:
            printf("Invalid option\n");
    }

    return 0;
}