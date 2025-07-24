//FormAI DATASET v1.0 Category: Temperature Converter ; Style: rigorous
#include <stdio.h>

float celsiusToFahrenheit(float celsius);
float celsiusToKelvin(float celsius);

int main() {
    float celsius;
    printf("Enter temperature in Celsius: ");
    scanf("%f", &celsius);
    
    float fahrenheit = celsiusToFahrenheit(celsius);
    printf("%.2f°C is equal to %.2f°F\n", celsius, fahrenheit);
    
    float kelvin = celsiusToKelvin(celsius);
    printf("%.2f°C is equal to %.2fK\n", celsius, kelvin);
    
    return 0;
}

float celsiusToFahrenheit(float celsius) {
    return (celsius * 9/5) + 32;
}

float celsiusToKelvin(float celsius) {
    return celsius + 273.15;
}