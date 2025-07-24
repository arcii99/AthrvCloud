//FormAI DATASET v1.0 Category: Temperature Converter ; Style: optimized
#include <stdio.h>

float get_fahrenheit(float celsius) {
    return (celsius * 9 / 5) + 32;
}

float get_kelvin(float celsius) {
    return celsius + 273.15;
}

int main() {

    printf("Welcome to the Temperature Converter!\n");

    float celsius;
    printf("Please enter the temperature in Celsius: ");
    scanf("%f", &celsius);

    float fahrenheit = get_fahrenheit(celsius);
    printf("%.2f Celsius is equal to %.2f Fahrenheit\n", celsius, fahrenheit);

    float kelvin = get_kelvin(celsius);
    printf("%.2f Celsius is equal to %.2f Kelvin\n", celsius, kelvin);

    return 0;
}