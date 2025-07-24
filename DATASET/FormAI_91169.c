//FormAI DATASET v1.0 Category: Temperature Converter ; Style: retro
#include <stdio.h>

int main()
{
    float celsius, fahrenheit;
    printf("Enter temperature in Celsius: ");
    scanf("%f", &celsius);
    // Conversion formula from Celsius to Fahrenheit
    fahrenheit = (celsius * 9 / 5) + 32;
    printf("%.2f Celsius = %.2f Fahrenheit\n", celsius, fahrenheit);
    return 0;
}