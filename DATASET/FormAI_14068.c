//FormAI DATASET v1.0 Category: Temperature Converter ; Style: single-threaded
#include <stdio.h>

int main() {
    float celsius, fahrenheit;

    printf("Enter temperature in Celsius: ");
    scanf("%f", &celsius);

    fahrenheit = (celsius * 1.8) + 32;

    printf("%.2f Celsius is equivalent to %.2f Fahrenheit.", celsius, fahrenheit);

    return 0;
}