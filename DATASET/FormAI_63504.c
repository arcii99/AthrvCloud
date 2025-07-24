//FormAI DATASET v1.0 Category: Temperature Converter ; Style: scalable
#include <stdio.h>

float celsius_to_fahrenheit(float celsius);

int main() {
    float celsius;
    printf("Enter temperature in Celsius: ");
    scanf("%f", &celsius);
    float fahrenheit = celsius_to_fahrenheit(celsius);
    printf("%.2f Celsius is equal to %.2f Fahrenheit", celsius, fahrenheit);
    return 0;
}

float celsius_to_fahrenheit(float celsius) {
    return (celsius * 9 / 5) + 32;
}