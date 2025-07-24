//FormAI DATASET v1.0 Category: Temperature Converter ; Style: authentic
#include <stdio.h>

float fahrenheitToCelsius(float fahrenheit);
float celsiusToFahrenheit(float celsius);

int main() {
    float temperature;
    char unit;

    printf("Enter temperature: ");
    scanf("%f %c", &temperature, &unit);

    if (unit == 'F' || unit == 'f') {
        float celsius = fahrenheitToCelsius(temperature);
        printf("Celsius: %.2f\n", celsius);
    } else if (unit == 'C' || unit == 'c') {
        float fahrenheit = celsiusToFahrenheit(temperature);
        printf("Fahrenheit: %.2f\n", fahrenheit);
    } else {
        printf("Invalid unit. Please enter either 'C' or 'F'.\n");
    }

    return 0;
}

float fahrenheitToCelsius(float fahrenheit) {
    return (fahrenheit - 32) * 5 / 9;
}

float celsiusToFahrenheit(float celsius) {
    return (celsius * 9 / 5) + 32;
}