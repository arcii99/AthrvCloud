//FormAI DATASET v1.0 Category: Temperature Converter ; Style: modular
#include <stdio.h>

double convertToFahrenheit(double celsius);
double convertToKelvin(double celsius);

int main() {
    double celsius, fahrenheit, kelvin;
    printf("Enter temperature in Celsius: ");
    scanf("%lf", &celsius);

    fahrenheit = convertToFahrenheit(celsius);
    kelvin = convertToKelvin(celsius);

    printf("%.2lf Celsius = %.2lf Fahrenheit\n", celsius, fahrenheit);
    printf("%.2lf Celsius = %.2lf Kelvin\n", celsius, kelvin);

    return 0;
}

double convertToFahrenheit(double celsius) {
    return (celsius * 9 / 5) + 32;
}

double convertToKelvin(double celsius) {
    return celsius + 273.15;
}