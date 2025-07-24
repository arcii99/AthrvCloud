//FormAI DATASET v1.0 Category: Temperature Converter ; Style: portable
#include <stdio.h>

float convert_to_fahrenheit(float celsius);
float convert_to_kelvin(float celsius);

int main() {
    float celsius;
    printf("Enter temperature in Celsius: ");
    scanf("%f", &celsius);

    float fahrenheit = convert_to_fahrenheit(celsius);
    float kelvin = convert_to_kelvin(celsius);

    printf("%.2f degrees Celsius is equal to %.2f degrees Fahrenheit\n", celsius, fahrenheit);
    printf("%.2f degrees Celsius is equal to %.2f degrees Kelvin\n", celsius, kelvin);

    return 0;
}

float convert_to_fahrenheit(float celsius) {
    return (celsius * (9.0/5.0)) + 32;
}

float convert_to_kelvin(float celsius) {
    return celsius + 273.15;
}