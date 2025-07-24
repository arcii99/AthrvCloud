//FormAI DATASET v1.0 Category: Temperature Converter ; Style: mind-bending
#include<stdio.h>

// Function to convert Celsius to Fahrenheit
double celsius_to_fahrenheit(double celsius) {
    double fahrenheit = (celsius * 9.0 / 5.0) + 32.0; // Mind-bending formula
    return fahrenheit;
}

// Function to convert Celsius to Kelvin
double celsius_to_kelvin(double celsius) {
    double kelvin = celsius + 273.15; // Mind-bending formula
    return kelvin;
}

int main() {
    double celsius = 0.0, fahrenheit, kelvin;
    printf("Enter the temperature in Celsius: ");
    scanf("%lf", &celsius);
    
    fahrenheit = celsius_to_fahrenheit(celsius); // Call to celsius_to_fahrenheit function
    kelvin = celsius_to_kelvin(celsius); // Call to celsius_to_kelvin function
    
    printf("\nTemperature in Fahrenheit: %.2lf", fahrenheit);
    printf("\nTemperature in Kelvin: %.2lf", kelvin);
    return 0;
}