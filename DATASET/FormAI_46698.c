//FormAI DATASET v1.0 Category: Temperature Converter ; Style: modular
#include <stdio.h>

// Function to convert Celsius to Fahrenheit
float celsiusToFahrenheit(float celsius) {
    return (celsius * 9 / 5) + 32;
}

// Function to convert Fahrenheit to Celsius
float fahrenheitToCelsius(float fahrenheit) {
    return (fahrenheit - 32) * 5 / 9;
}

int main() {
    int choice;
    float temperature, result;
    printf("Temperature Converter\n");
    printf("1. Celsius to Fahrenheit\n");
    printf("2. Fahrenheit to Celsius\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);
    
    switch(choice) {
        case 1:
            printf("Enter temperature in Celsius: ");
            scanf("%f", &temperature);
            result = celsiusToFahrenheit(temperature);
            printf("%.2f C = %.2f F", temperature, result);
            break;
        case 2:
            printf("Enter temperature in Fahrenheit: ");
            scanf("%f", &temperature);
            result = fahrenheitToCelsius(temperature);
            printf("%.2f F = %.2f C", temperature, result);
            break;
        default:
            printf("Invalid choice!");
    }
    
    return 0;
}