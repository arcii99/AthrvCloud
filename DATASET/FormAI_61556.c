//FormAI DATASET v1.0 Category: Temperature monitor ; Style: detailed
#include <stdio.h>

// Function to convert Celsius to Fahrenheit
float celsiusToFahrenheit(float celsius) {
    return (celsius * 9/5) + 32;
}

int main() {
    float temperature;
    printf("Enter temperature in Celsius: ");
    scanf("%f", &temperature);
    
    printf("\nCelsius: %.2f", temperature);
    printf("\nFahrenheit: %.2f", celsiusToFahrenheit(temperature));
    
    return 0;
}