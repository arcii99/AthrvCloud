//FormAI DATASET v1.0 Category: Temperature Converter ; Style: secure
#include<stdio.h>

int main()
{
    float celsius, fahrenheit;

    // Get the temperature in Celsius
    printf("Enter temperature in Celsius: ");
    scanf("%f", &celsius);

    // Convert Celsius to Fahrenheit
    fahrenheit = (celsius * 1.8) + 32;

    // Print the result
    printf("%.2f Celsius is equal to %.2f Fahrenheit\n", celsius, fahrenheit);

    return 0;
}