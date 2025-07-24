//FormAI DATASET v1.0 Category: Temperature Converter ; Style: scalable
#include <stdio.h>

void printMenu() {
    printf("Please choose an option:\n");
    printf("1. Celsius to Fahrenheit conversion\n");
    printf("2. Fahrenheit to Celsius conversion\n");
    printf("3. Exit program\n");
}

double convertCelsiusToFahrenheit(double celsius) {
    return (celsius * 1.8) + 32.0;
}

double convertFahrenheitToCelsius(double fahrenheit) {
    return (fahrenheit - 32.0) / 1.8;
}

int main() {
    int choice;
    double temperature;

    while (1) {
        printMenu();
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the temperature in Celsius: ");
                scanf("%lf", &temperature);
                printf("%.2lf°C is %.2lf°F\n", temperature, convertCelsiusToFahrenheit(temperature));
                break;
            case 2:
                printf("Enter the temperature in Fahrenheit: ");
                scanf("%lf", &temperature);
                printf("%.2lf°F is %.2lf°C\n", temperature, convertFahrenheitToCelsius(temperature));
                break;
            case 3:
                printf("Exiting program...\n");
                return 0;
            default:
                printf("Invalid choice. Please try again.\n");
                break;
        }
    }

    return 0;
}