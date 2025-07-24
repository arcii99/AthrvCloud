//FormAI DATASET v1.0 Category: Temperature Converter ; Style: detailed
#include <stdio.h>

int main()
{
    float celsius, fahrenheit;

    printf("Enter temperature in Celsius: ");
    scanf("%f", &celsius);

    // Convert Celsius to Fahrenheit
    fahrenheit = (celsius * 9 / 5) + 32;

    printf("%.2f Celsius is equal to %.2f Fahrenheit", celsius, fahrenheit);

    return 0;
}