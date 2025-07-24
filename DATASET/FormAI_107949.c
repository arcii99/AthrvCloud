//FormAI DATASET v1.0 Category: Temperature Converter ; Style: Dennis Ritchie
#include <stdio.h>

/* Function declarations */
float celsiusToFahrenheit(float celsius);
float celsiusToKelvin(float celsius);

int main() {
    float celsius;
    printf("Enter temperature in Celsius: ");
    scanf("%f", &celsius);

    float fahrenheit = celsiusToFahrenheit(celsius);
    float kelvin = celsiusToKelvin(celsius);

    // Display the converted temperatures
    printf("%.2f Celsius = %.2f Fahrenheit\n", celsius, fahrenheit);
    printf("%.2f Celsius = %.2f Kelvin\n", celsius, kelvin);

    return 0;
}

/* Function definitions */
float celsiusToFahrenheit(float celsius) {
    float fahrenheit = (celsius * 9/5) + 32;
    return fahrenheit;
}

float celsiusToKelvin(float celsius) {
    float kelvin = celsius + 273.15;
    return kelvin;
}