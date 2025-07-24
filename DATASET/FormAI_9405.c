//FormAI DATASET v1.0 Category: Temperature Converter ; Style: protected
#include <stdio.h>

float celsius_to_fahrenheit(float celsius);
float celsius_to_kelvin(float celsius);

int main() {
    float celsius, fahrenheit, kelvin;
    printf("Enter temperature in Celsius: ");
    scanf("%f", &celsius);

    // Convert Celsius to Fahrenheit
    fahrenheit = celsius_to_fahrenheit(celsius);

    // Convert Celsius to Kelvin
    kelvin = celsius_to_kelvin(celsius);

    // Display the results
    printf("Temperature in Celsius: %.2f\n", celsius);
    printf("Temperature in Fahrenheit: %.2f\n", fahrenheit);
    printf("Temperature in Kelvin: %.2f\n", kelvin);

    return 0;
}

// Function to convert Celsius to Fahrenheit
float celsius_to_fahrenheit(float celsius) {
    return (celsius * 9 / 5) + 32;
}

// Function to convert Celsius to Kelvin
float celsius_to_kelvin(float celsius) {
    return celsius + 273.15;
}