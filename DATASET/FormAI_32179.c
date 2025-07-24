//FormAI DATASET v1.0 Category: Temperature Converter ; Style: calm
#include <stdio.h>

float convertToFahrenheit(float celsius) {
    float fahrenheit = (celsius * 9/5) + 32;
    return fahrenheit;
}

float convertToKelvin(float celsius) {
    float kelvin = celsius + 273.15;
    return kelvin;
}

int main() {
    float celsius;
    printf("Enter temperature in Celsius: ");
    scanf("%f", &celsius);

    printf("%.2f Celsius is %.2f Fahrenheit\n", celsius, convertToFahrenheit(celsius));
    printf("%.2f Celsius is %.2f Kelvin\n", celsius, convertToKelvin(celsius));

    return 0;
}