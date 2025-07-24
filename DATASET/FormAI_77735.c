//FormAI DATASET v1.0 Category: Temperature Converter ; Style: rigorous
#include <stdio.h>

float convertToFahrenheit(float celsius) {
    return (celsius * 1.8) + 32;
}

float convertToKelvin(float celsius) {
    return celsius + 273.15;
}

int main() {
    float celsius, fahrenheit, kelvin;

    printf("Enter temperature in Celsius: ");
    scanf("%f", &celsius);

    fahrenheit = convertToFahrenheit(celsius);
    kelvin = convertToKelvin(celsius);

    printf("%.2f Celsius = %.2f Fahrenheit\n", celsius, fahrenheit);
    printf("%.2f Celsius = %.2f Kelvin\n", celsius, kelvin);

    return 0;
}