//FormAI DATASET v1.0 Category: Temperature Converter ; Style: detailed
#include <stdio.h>

// Function to convert Celsius to Fahrenheit
float celsiusToFahrenheit(float celsius) {
    return (celsius * 1.8) + 32;
}

// Function to convert Celsius to Kelvin
float celsiusToKelvin(float celsius) {
    return celsius + 273.15;
}

int main() {
    float celsius;

    // Ask user to enter temperature in Celsius
    printf("Enter temperature in Celsius: ");
    scanf("%f", &celsius);

    // Convert Celsius to Fahrenheit and print the result
    float fahrenheit = celsiusToFahrenheit(celsius);
    printf("%.2f Celsius = %.2f Fahrenheit\n", celsius, fahrenheit);

    // Convert Celsius to Kelvin and print the result
    float kelvin = celsiusToKelvin(celsius);
    printf("%.2f Celsius = %.2f Kelvin\n", celsius, kelvin);

    return 0;
}