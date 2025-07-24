//FormAI DATASET v1.0 Category: Temperature Converter ; Style: single-threaded
#include <stdio.h>

float convertToFahrenheit(float celsius);

int main() {
    float celsius, fahrenheit;
    printf("Enter temperature in Celsius: ");
    scanf("%f", &celsius);

    fahrenheit = convertToFahrenheit(celsius);

    printf("%.2f Celsius = %.2f Fahrenheit\n", celsius, fahrenheit);

    return 0;
}

float convertToFahrenheit(float celsius) {
    return (celsius * 9/5) + 32;
}