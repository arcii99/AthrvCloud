//FormAI DATASET v1.0 Category: Temperature Converter ; Style: Dennis Ritchie
#include <stdio.h>

float convert_to_fahrenheit(float celsius);

int main() {
    float celsius, fahrenheit;
    printf("Enter temperature in Celsius: ");
    scanf("%f", &celsius);

    fahrenheit = convert_to_fahrenheit(celsius);

    printf("%.2f Celsius = %.2f Fahrenheit", celsius, fahrenheit);
    return 0;
}

float convert_to_fahrenheit(float celsius) {
    return (celsius * 1.8) + 32;
}