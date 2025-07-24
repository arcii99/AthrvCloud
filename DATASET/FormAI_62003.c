//FormAI DATASET v1.0 Category: Temperature monitor ; Style: unmistakable
#include <stdio.h>

// Function to convert Celsius to Fahrenheit
double celsiusToFahrenheit(double celsius) {
    return (celsius * 1.8) + 32;
}

int main() {
    double temperatureCelsius;
    
    printf("Enter temperature in Celsius: ");
    scanf("%lf", &temperatureCelsius);
    
    printf("Temperature in Celsius: %.2lf\n", temperatureCelsius);
    printf("Temperature in Fahrenheit: %.2lf\n", celsiusToFahrenheit(temperatureCelsius));
    
    return 0;
}