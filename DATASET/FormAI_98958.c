//FormAI DATASET v1.0 Category: Temperature Converter ; Style: optimized
#include <stdio.h>

float celsius_to_fahrenheit(float celsius);
float celsius_to_kelvin(float celsius);

int main() {
    float celsius;
    printf("Enter temperature in Celsius: ");
    scanf("%f", &celsius);

    float fahrenheit = celsius_to_fahrenheit(celsius);
    float kelvin = celsius_to_kelvin(celsius);

    printf("%.2f degrees Celsius is equivalent to:\n", celsius);
    printf("%.2f degrees Fahrenheit\n", fahrenheit);
    printf("%.2f Kelvin\n", kelvin);

    return 0;
}

float celsius_to_fahrenheit(float celsius) {
    return (celsius * 9 / 5) + 32;
}

float celsius_to_kelvin(float celsius) {
    return celsius + 273.15;
}