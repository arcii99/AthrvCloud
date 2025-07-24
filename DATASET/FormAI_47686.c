//FormAI DATASET v1.0 Category: Temperature Converter ; Style: automated
#include <stdio.h>

float convertCelsiusToFahrenheit(float celsius) {
    return (celsius * 9 / 5) + 32;
}

float convertCelsiusToKelvin(float celsius) {
    return celsius + 273.15;
}

int main() {

    float temperatureCelsius;

    printf("Enter temperature in Celsius: ");
    scanf("%f", &temperatureCelsius);

    float temperatureFahrenheit = convertCelsiusToFahrenheit(temperatureCelsius);
    float temperatureKelvin = convertCelsiusToKelvin(temperatureCelsius);

    printf("%.2f degree Celsius is equivalent to:\n", temperatureCelsius);
    printf("%.2f degree Fahrenheit\n", temperatureFahrenheit);
    printf("%.2f Kelvin\n", temperatureKelvin);

    return 0;
}