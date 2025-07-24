//FormAI DATASET v1.0 Category: Temperature Converter ; Style: lively
#include <stdio.h>

int main() {
    float temperature;
    char unit;

    printf("Enter the temperature and unit (C/F): ");
    scanf("%f %c", &temperature, &unit);

    if (unit == 'C') {
        // Convert from Celsius to Fahrenheit
        float fahrenheit = temperature * 1.8 + 32;
        printf("%.2f C = %.2f F\n", temperature, fahrenheit);
    } else if (unit == 'F') {
        // Convert from Fahrenheit to Celsius
        float celsius = (temperature - 32) / 1.8;
        printf("%.2f F = %.2f C\n", temperature, celsius);
    } else {
        printf("Invalid unit. Please enter C or F.\n");
    }

    return 0;
}