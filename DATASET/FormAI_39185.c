//FormAI DATASET v1.0 Category: Temperature Converter ; Style: standalone
#include <stdio.h>
#include <stdlib.h>

// Convert Celsius to Fahrenheit
double cToF(double celsius) {
    double fahrenheit = (celsius * 9 / 5) + 32;
    return fahrenheit;
}

// Convert Fahrenheit to Celsius
double fToC(double fahrenheit) {
    double celsius = (fahrenheit - 32) * 5 / 9;
    return celsius;
}

int main() {
    double temperature;
    char choice;

    printf("Please select the conversion you would like to make:\n");
    printf("'C' to convert Celsius to Fahrenheit.\n");
    printf("'F' to convert Fahrenheit to Celsius.\n");
    scanf("%c", &choice);

    switch (choice) {
        case 'C':
        case 'c':
            printf("Enter the temperature in Celsius: ");
            scanf("%lf", &temperature);
            printf("%.2f C = %.2f F\n", temperature, cToF(temperature));
            break;
        case 'F':
        case 'f':
            printf("Enter the temperature in Fahrenheit: ");
            scanf("%lf", &temperature);
            printf("%.2f F = %.2f C\n", temperature, fToC(temperature));
            break;
        default:
            printf("Invalid choice. Please select 'C' or 'F'.\n");
    }

    return 0;
}