//FormAI DATASET v1.0 Category: Temperature Converter ; Style: visionary
#include <stdio.h>

int main() {
    double celsius, fahrenheit;

    printf("Enter temperature in Celsius: ");
    scanf("%lf", &celsius);

    // Convert Celsius to Fahrenheit
    fahrenheit = (celsius * 1.8) + 32;

    // Display the result
    printf("%.2lf Celsius is equivalent to %.2lf Fahrenheit.", celsius, fahrenheit);

    return 0;
}