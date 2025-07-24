//FormAI DATASET v1.0 Category: Temperature Converter ; Style: systematic
#include<stdio.h>

// Function to convert Celsius to Fahrenheit
float celsiusToFahrenheit(float celsius) {
    float fahrenheit = (celsius * 9 / 5) + 32;
    return fahrenheit;
}

// Function to convert Celsius to Kelvin
float celsiusToKelvin(float celsius) {
    float kelvin = celsius + 273.15;
    return kelvin;
}

int main() {
    float celsius, fahrenheit, kelvin;
    
    printf("Enter temperature in Celsius: ");
    scanf("%f", &celsius); // Read temperature in Celsius from user
    
    // Convert temperature to Fahrenheit and Kelvin using functions
    fahrenheit = celsiusToFahrenheit(celsius);
    kelvin = celsiusToKelvin(celsius);
    
    // Display converted temperatures
    printf("%.2f Celsius = %.2f Fahrenheit\n", celsius, fahrenheit);
    printf("%.2f Celsius = %.2f Kelvin\n", celsius, kelvin);
    
    return 0;
}