//FormAI DATASET v1.0 Category: Temperature Converter ; Style: high level of detail
#include <stdio.h>

// Function to convert Celsius to Fahrenheit
float celsiusToFahrenheit(float celsius) {
    float fahrenheit = (celsius * 9/5) + 32;
    return fahrenheit;
}

// Function to convert Celsius to Kelvin
float celsiusToKelvin(float celsius) {
    float kelvin = celsius + 273.15;
    return kelvin;
}

int main() {
    float celsius;
    printf("Enter temperature in Celsius: ");
    scanf("%f", &celsius);

    // Convert Celsius to Fahrenheit and Kelvin
    float fahrenheit = celsiusToFahrenheit(celsius);
    float kelvin = celsiusToKelvin(celsius);

    // Display the converted temperatures
    printf("\nTemperature in Fahrenheit: %.2f°F", fahrenheit);
    printf("\nTemperature in Kelvin: %.2fK", kelvin);

    return 0; 
}