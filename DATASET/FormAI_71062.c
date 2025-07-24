//FormAI DATASET v1.0 Category: Temperature Converter ; Style: future-proof
#include <stdio.h>

int main()
{
    // Declare variables
    float celsius, fahrenheit;

    // Prompt user for input
    printf("Enter temperature in Celsius: ");
    scanf("%f", &celsius);

    // Convert celsius to fahrenheit
    fahrenheit = (celsius * 1.8) + 32;

    // Display result
    printf("%.2f Celsius = %.2f Fahrenheit\n", celsius, fahrenheit);

    return 0;
}