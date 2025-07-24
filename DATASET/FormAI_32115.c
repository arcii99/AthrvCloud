//FormAI DATASET v1.0 Category: Temperature Converter ; Style: modular
#include <stdio.h>

void convertToF(float celsius);
void convertToK(float celsius);

int main() {
    float celsius;
    printf("Enter the temperature in Celsius: ");
    scanf("%f", &celsius);

    convertToF(celsius);
    convertToK(celsius);

    return 0;
}

void convertToF(float celsius) {
    float fahrenheit = (celsius * 9/5) + 32;
    printf("%.2f Celsius is equal to %.2f Fahrenheit\n", celsius, fahrenheit);
}

void convertToK(float celsius) {
    float kelvin = celsius + 273.15;
    printf("%.2f Celsius is equal to %.2f Kelvin\n", celsius, kelvin);
}