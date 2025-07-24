//FormAI DATASET v1.0 Category: Temperature Converter ; Style: statistical
#include <stdio.h>

float toCelsius(float fahrenheit) {
    return (fahrenheit - 32.0) * 5.0 / 9.0;
}

float toFahrenheit(float celsius) {
    return celsius * 9.0 / 5.0 + 32.0;
}

int main() {
    float temperature;
    char scale;

    printf("Enter a temperature: ");
    scanf("%f %c", &temperature, &scale);

    if (scale == 'C' || scale == 'c') {
        printf("%.2f%c = %.2fF\n", temperature, scale, toFahrenheit(temperature));
    } else if (scale == 'F' || scale == 'f') {
        printf("%.2f%c = %.2fC\n", temperature, scale, toCelsius(temperature));
    } else {
        printf("Invalid scale: %c\n", scale);
    }

    return 0;
}