//FormAI DATASET v1.0 Category: Temperature Converter ; Style: accurate
#include <stdio.h>

// Function to convert Celsius to Fahrenheit
float celsiusToFahrenheit(float celsius) {
    return (celsius * 9 / 5) + 32;
}

// Function to convert Celsius to Kelvin
float celsiusToKelvin(float celsius) {
    return celsius + 273.15;
}

int main() {
    float celsius;

    printf("Enter temperature in Celsius: ");
    scanf("%f", &celsius);

    printf("\n%.2f Celsius is equal to %.2f Fahrenheit\n", celsius, celsiusToFahrenheit(celsius));
    printf("%.2f Celsius is equal to %.2f Kelvin\n", celsius, celsiusToKelvin(celsius));
    
    return 0;
}