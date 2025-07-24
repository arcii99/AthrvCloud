//FormAI DATASET v1.0 Category: Temperature Converter ; Style: post-apocalyptic
#include <stdio.h>

int main() {
    float temperature_celsius, temperature_fahrenheit;

    printf("Enter temperature in Celsius: ");
    scanf("%f", &temperature_celsius);

    // Fahrenheit conversion
    temperature_fahrenheit = (temperature_celsius * 1.8) + 32;

    printf("Temperature in Fahrenheit: %0.2f", temperature_fahrenheit);

    return 0;
}