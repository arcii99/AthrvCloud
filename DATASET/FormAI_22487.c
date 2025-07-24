//FormAI DATASET v1.0 Category: Temperature Converter ; Style: expert-level
#include <stdio.h>

float celsiusToFahrenheit(float celsius);
float celsiusToKelvin(float celsius);

int main(void) {
    float celsius, fahrenheit, kelvin;

    printf("Enter temperature in Celsius: ");
    scanf("%f", &celsius);

    fahrenheit = celsiusToFahrenheit(celsius);
    kelvin = celsiusToKelvin(celsius);

    printf("%.2f Celsius = %.2f Fahrenheit\n", celsius, fahrenheit);
    printf("%.2f Celsius = %.2f Kelvin", celsius, kelvin);

    return 0;
}

float celsiusToFahrenheit(float celsius) {
    float fahrenheit;

    fahrenheit = (celsius * 9 / 5) + 32;

    return fahrenheit;
}

float celsiusToKelvin(float celsius) {
    float kelvin;

    kelvin = celsius + 273.15;

    return kelvin;
}