//FormAI DATASET v1.0 Category: Temperature Converter ; Style: decentralized
#include <stdio.h>

// Function to convert Celsius to Fahrenheit
float celsius2fahrenheit(float celsius) {
    return (celsius * 9.0 / 5.0) + 32.0;
}

// Function to convert Celsius to Kelvin
float celsius2kelvin(float celsius) {
    return celsius + 273.15;
}

int main() {
    float celsius, fahrenheit, kelvin;
    
    // Get the temperature in Celsius from the user
    printf("Enter the temperature in Celsius: ");
    scanf("%f", &celsius);
    
    // Convert Celsius to Fahrenheit and Kelvin
    fahrenheit = celsius2fahrenheit(celsius);
    kelvin = celsius2kelvin(celsius);
    
    // Display the converted temperatures
    printf("%.2f Celsius = %.2f Fahrenheit\n", celsius, fahrenheit);
    printf("%.2f Celsius = %.2f Kelvin", celsius, kelvin);
    
    return 0;
}