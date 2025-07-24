//FormAI DATASET v1.0 Category: Temperature Converter ; Style: modular
#include <stdio.h>

// Function to convert Celsius to Fahrenheit
float celsiusToFahrenheit(float celsius) {
    float fahrenheit = (celsius * 1.8) + 32.0;
    return fahrenheit;
}

// Function to convert Fahrenheit to Celsius
float fahrenheitToCelsius(float fahrenheit) {
    float celsius = (fahrenheit - 32.0) / 1.8;
    return celsius;
}

int main() {
    int choice;
    float temperature, result;
    
    printf("Temperature Converter\n");
    printf("=====================\n\n");
    
    // Display menu
    printf("1. Celsius to Fahrenheit\n");
    printf("2. Fahrenheit to Celsius\n");
    printf("Enter choice (1/2): ");
    scanf("%d", &choice);
    
    // Get temperature from user
    printf("\nEnter temperature: ");
    scanf("%f", &temperature);
    
    // Convert temperature based on choice
    switch (choice) {
        case 1:
            result = celsiusToFahrenheit(temperature);
            printf("\n%.2f Celsius = %.2f Fahrenheit\n", temperature, result);
            break;
        case 2:
            result = fahrenheitToCelsius(temperature);
            printf("\n%.2f Fahrenheit = %.2f Celsius\n", temperature, result);
            break;
        default:
            printf("\nInvalid choice\n");
            break;
    }
    
    return 0;
}