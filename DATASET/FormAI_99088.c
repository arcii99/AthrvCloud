//FormAI DATASET v1.0 Category: Temperature Converter ; Style: standalone
#include <stdio.h>

/* Function to convert celsius to fahrenheit */
double celsius_to_fahrenheit(double temperature) {
    double fahrenheit = ((9 * temperature) / 5) + 32;
    return fahrenheit;
}

/* Function to convert fahrenheit to celsius */
double fahrenheit_to_celsius(double temperature) {
    double celsius = (5 * (temperature - 32)) / 9;
    return celsius;
}

int main() {
    int choice;
    double temperature;

    printf("Temperature Converter\n");
    printf("=====================\n");
    printf("1. Celsius to Fahrenheit\n");
    printf("2. Fahrenheit to Celsius\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);

    switch (choice) {
        case 1:
            printf("Enter temperature in Celsius: ");
            scanf("%lf", &temperature);
            printf("%.2lf°C is equal to %.2lf°F", temperature, celsius_to_fahrenheit(temperature));
            break;
        case 2:
            printf("Enter temperature in Fahrenheit: ");
            scanf("%lf", &temperature);
            printf("%.2lf°F is equal to %.2lf°C", temperature, fahrenheit_to_celsius(temperature));
            break;
        default:
            printf("Invalid choice!");
    }

    return 0;
}