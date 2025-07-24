//FormAI DATASET v1.0 Category: Temperature Converter ; Style: future-proof
#include <stdio.h>

// Function to convert Celsius to Fahrenheit
double celsiusToFahrenheit(double celsius) {
    return (celsius * 9/5) + 32;
}

// Function to convert Celsius to Kelvin
double celsiusToKelvin(double celsius) {
    return celsius + 273.15;
}

int main() {
    double celsius;
    printf("Enter temperature in Celsius: ");
    scanf("%lf", &celsius);

    // Convert Celsius to Fahrenheit and Kelvin
    double fahrenheit = celsiusToFahrenheit(celsius);
    double kelvin = celsiusToKelvin(celsius);

    printf("%.2f degrees Celsius is %.2f degrees Fahrenheit\n", celsius, fahrenheit);
    printf("%.2f degrees Celsius is %.2f degrees Kelvin\n", celsius, kelvin);

    return 0;
}