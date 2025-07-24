//FormAI DATASET v1.0 Category: Temperature Converter ; Style: all-encompassing
#include <stdio.h>

float convertCelsiusToFahrenheit(float celsius) {
    return (celsius * (9.0/5.0)) + 32.0;
}

float convertFahrenheitToCelsius(float fahrenheit) {
    return (fahrenheit - 32.0) * (5.0/9.0);
}

int main() {
    int choice;
    float temperature;

    printf("Enter a temperature value: ");
    scanf("%f", &temperature);
    printf("Enter the scale to convert:\n1. Celsius to Fahrenheit\n2. Fahrenheit to Celsius\n");
    scanf("%d", &choice);

    switch(choice) {
        case 1:
            printf("%.2f Celsius is equal to %.2f Fahrenheit", temperature, convertCelsiusToFahrenheit(temperature));
            break;
        case 2:
            printf("%.2f Fahrenheit is equal to %.2f Celsius", temperature, convertFahrenheitToCelsius(temperature));
            break;
        default:
            printf("Invalid choice");
            break;
    }

    return 0;
}