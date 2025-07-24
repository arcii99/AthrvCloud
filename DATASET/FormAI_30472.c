//FormAI DATASET v1.0 Category: Temperature monitor ; Style: systematic
#include <stdio.h>

int main() 
{
    float celsius, fahrenheit;

    printf("Enter temperature in Celsius: ");
    scanf("%f", &celsius);

    // Convert celsius to fahrenheit
    fahrenheit = (celsius * 9 / 5) + 32;

    printf("\nTemperature in Fahrenheit: %.2f°F\n", fahrenheit);

    // Check if temperature is below freezing point or above boiling point
    if (celsius <= 0) 
    {
        printf("\nTemperature is below freezing point!\n");
    } 
    else if (celsius >= 100) 
    {
        printf("\nTemperature is above boiling point!\n");
    } 
    else 
    {
        printf("Temperature is within normal range.\n");
    }

    return 0;
}