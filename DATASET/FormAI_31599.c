//FormAI DATASET v1.0 Category: Temperature Converter ; Style: safe
#include <stdio.h>

float celsius_to_fahrenheit(float celsius);

float celsius_to_kelvin(float celsius);

int main() {
    float celsius;
    printf("Enter temperature in Celsius: ");
    scanf("%f", &celsius);
    printf("%.2f degrees Celsius is equal to %.2f degrees Fahrenheit\n", celsius, celsius_to_fahrenheit(celsius));
    printf("%.2f degrees Celsius is equal to %.2f Kelvin\n", celsius, celsius_to_kelvin(celsius));
    return 0;
}

float celsius_to_fahrenheit(float celsius) {
    float fahrenheit = (celsius * 9 / 5) + 32;
    return fahrenheit;
}

float celsius_to_kelvin(float celsius) {
    float kelvin = celsius + 273.15;
    return kelvin;
}