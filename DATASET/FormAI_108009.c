//FormAI DATASET v1.0 Category: Temperature Converter ; Style: authentic
#include <stdio.h>

int main() {
    float temp_celsius, temp_fahrenheit;

    printf("Enter temperature in Celsius: ");
    scanf("%f", &temp_celsius);

    temp_fahrenheit = (temp_celsius * 9 / 5) + 32;

    printf("%.2fC is equivalent to %.2fF\n", temp_celsius, temp_fahrenheit);

    return 0;
}