//FormAI DATASET v1.0 Category: Temperature Converter ; Style: rigorous
#include <stdio.h>

// function to convert Celsius to Fahrenheit
float celsiusToFahrenheit(float celsius) {
    float fahrenheit = (celsius * (9.0/5.0)) + 32.0;
    return fahrenheit;
}

// function to convert Fahrenheit to Celsius
float fahrenheitToCelsius(float fahrenheit) {
    float celsius = (fahrenheit - 32.0) * (5.0/9.0);
    return celsius;
}

int main() {
    float temperature;
    int choice;

    printf("Choose conversion type:\n");
    printf("1. Celsius to Fahrenheit\n2. Fahrenheit to Celsius\n");
    scanf("%d", &choice);

    switch(choice) {
        case 1:
            printf("Enter temperature in Celsius: ");
            scanf("%f", &temperature);
            printf("%.2f Celsius = %.2f Fahrenheit", temperature, celsiusToFahrenheit(temperature));
            break;
        case 2:
            printf("Enter temperature in Fahrenheit: ");
            scanf("%f", &temperature);
            printf("%.2f Fahrenheit = %.2f Celsius", temperature, fahrenheitToCelsius(temperature));
            break;
        default:
            printf("Invalid choice");
    }

    return 0;
}