//FormAI DATASET v1.0 Category: Temperature Converter ; Style: enthusiastic
#include <stdio.h>

int main() {
    float celsius, fahrenheit;

    printf("Enter temperature in Celsius: ");
    scanf("%f", &celsius);

    fahrenheit = (1.8 * celsius) + 32;

    printf("\n%.2f degrees Celsius is equal to %.2f degrees Fahrenheit.\n", celsius, fahrenheit);

    return 0;
}