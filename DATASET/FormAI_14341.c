//FormAI DATASET v1.0 Category: Temperature Converter ; Style: scientific
#include <stdio.h>

float convertToFahrenheit(float celsius) {
    return (celsius * 9/5) + 32;
}

float convertToKelvin(float celsius) {
    return celsius + 273.15;
}

int main() {
    float celsius;
    printf("Enter temperature in Celsius: ");
    scanf("%f", &celsius);

    float fahrenheit = convertToFahrenheit(celsius);
    float kelvin = convertToKelvin(celsius);

    printf("\n%.2f Celsius is %.2f Fahrenheit\n", celsius, fahrenheit);
    printf("%.2f Celsius is %.2f Kelvin\n", celsius, kelvin);

    return 0;
}