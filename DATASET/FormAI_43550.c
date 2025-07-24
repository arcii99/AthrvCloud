//FormAI DATASET v1.0 Category: Temperature Converter ; Style: intelligent
#include <stdio.h>

int main()
{
    float celsius, fahrenheit;

    printf("Enter temperature in Celsius: ");
    scanf("%f", &celsius);

    // Convert temperature to Fahrenheit
    fahrenheit = (celsius * 9 / 5) + 32;

    printf("%.2f Celsius is equal to %.2f Fahrenheit", celsius, fahrenheit);

    return 0;
}