//FormAI DATASET v1.0 Category: Temperature Converter ; Style: realistic
#include <stdio.h>

int main() {
    float temp_celsius, temp_fahrenheit;

    printf("Enter temperature in Celsius: ");
    scanf("%f", &temp_celsius);

    // Calculating temperature in Fahrenheit
    temp_fahrenheit = (temp_celsius * 9/5) + 32;

    printf("%.2f°C is %.2f°F\n", temp_celsius, temp_fahrenheit);

    return 0;
}