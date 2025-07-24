//FormAI DATASET v1.0 Category: Temperature Converter ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>

int main() {

    float Celsius, Fahrenheit;

    printf("Enter temperature in Celsius: ");
    scanf("%f", &Celsius);

    Fahrenheit = (Celsius * 9 / 5) + 32;

    printf("Celsius: %.2f\n", Celsius);
    printf("Fahrenheit: %.2f\n", Fahrenheit);

    return 0;
}