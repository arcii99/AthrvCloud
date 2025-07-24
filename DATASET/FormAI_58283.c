//FormAI DATASET v1.0 Category: Temperature Converter ; Style: synchronous
#include <stdio.h>

float convertToFahrenheit(float celsius) {
    return (celsius * 9 / 5) + 32;
}

float convertToKelvin(float celsius) {
    return celsius + 273.15;
}

int main() {
    float celsius;
    printf("Enter temperature in Celsius: ");
    scanf("%f", &celsius);
    printf("%.2fC is equivalent to %.2fF and %.2fK\n", celsius, convertToFahrenheit(celsius), convertToKelvin(celsius));
    return 0;
}