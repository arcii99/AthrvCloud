//FormAI DATASET v1.0 Category: Unit converter ; Style: lively
#include <stdio.h>

// Function to convert Celsius to Fahrenheit
float celsiusToFahrenheit(float celsius) {
    float fahrenheit = (celsius * 9/5) + 32;
    return fahrenheit;
}

// Function to convert Fahrenheit to Celsius
float fahrenheitToCelsius(float fahrenheit) {
    float celsius = (fahrenheit - 32) * 5/9;
    return celsius;
}

int main() {
    int choice;
    float temperature;
    
    printf("\n*** Welcome to the Temperature Unit Converter ***\n");
    printf("\n1. Celsius to Fahrenheit\n");
    printf("2. Fahrenheit to Celsius\n");
    printf("\nEnter your choice: ");
    scanf("%d", &choice);
    
    switch(choice) {
        case 1:
            printf("\nEnter the temperature in Celsius: ");
            scanf("%f", &temperature);
            printf("%.2f Celsius is equal to %.2f Fahrenheit", temperature, celsiusToFahrenheit(temperature));
            break;
        case 2:
            printf("\nEnter the temperature in Fahrenheit: ");
            scanf("%f", &temperature);
            printf("%.2f Fahrenheit is equal to %.2f Celsius", temperature, fahrenheitToCelsius(temperature));
            break;
        default:
            printf("\nInvalid choice. Please enter either 1 or 2.");
    }
    
    return 0;
}