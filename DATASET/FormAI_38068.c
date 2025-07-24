//FormAI DATASET v1.0 Category: Temperature Converter ; Style: all-encompassing
#include <stdio.h>

/* Converts Celsius to Fahrenheit */
float celsius_to_fahrenheit(float celsius) {
    return (celsius * 9.0 / 5.0) + 32.0;
}

/* Converts Celsius to Kelvin */
float celsius_to_kelvin(float celsius) {
    return celsius + 273.15;
}

/* Main function */
int main(int argc, char *argv[]) {
    float celsius;
    printf("Enter temperature in Celsius: ");
    scanf("%f", &celsius);

    float fahrenheit = celsius_to_fahrenheit(celsius);
    printf("%.2f Celsius is %.2f Fahrenheit\n", celsius, fahrenheit);

    float kelvin = celsius_to_kelvin(celsius);
    printf("%.2f Celsius is %.2f Kelvin\n", celsius, kelvin);

    return 0;
}