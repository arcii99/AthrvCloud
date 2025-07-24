//FormAI DATASET v1.0 Category: Temperature Converter ; Style: multivariable
#include <stdio.h>

float toFahrenheit(float celsius) {
    return (celsius * 9 / 5) + 32;
}

float toKelvin(float celsius) {
    return celsius + 273.15;
}

int main() {
    float celsius;
    printf("Enter temperature in Celsius: ");
    scanf("%f", &celsius);
    
    float fahrenheit = toFahrenheit(celsius);
    float kelvin = toKelvin(celsius);
    
    printf("Celsius: %.2f\n", celsius);
    printf("Fahrenheit: %.2f\n", fahrenheit);
    printf("Kelvin: %.2f\n", kelvin);
    
    return 0;
}