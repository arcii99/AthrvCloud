//FormAI DATASET v1.0 Category: Temperature Converter ; Style: ultraprecise
#include <stdio.h>

int main() {

    float celsius, fahrenheit, kelvin;

    printf("Enter temperature in Celsius: ");
    scanf("%f", &celsius);

    // Celsius to Fahrenheit conversion
    fahrenheit = (celsius * 1.8) + 32;

    // Celsius to Kelvin conversion
    kelvin = celsius + 273.15;

    printf("%.2f Celsius is equal to %.2f Fahrenheit and %.2f Kelvin.\n", celsius, fahrenheit, kelvin);

    return 0;
}