//FormAI DATASET v1.0 Category: Temperature Converter ; Style: portable
#include <stdio.h>

float celsiusToFahrenheit(float celsius);
float celsiusToKelvin(float celsius);

int main() {
    float celsius;

    printf("Enter temperature in Celsius: ");
    scanf("%f", &celsius);

    printf("Temperature in Fahrenheit: %.2f F\n", celsiusToFahrenheit(celsius));
    printf("Temperature in Kelvin: %.2f K\n", celsiusToKelvin(celsius));

    return 0;
}

float celsiusToFahrenheit(float celsius) {
    return (celsius * 1.8) + 32;
}

float celsiusToKelvin(float celsius) {
    return celsius + 273.15;
}