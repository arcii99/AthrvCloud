//FormAI DATASET v1.0 Category: Temperature monitor ; Style: detailed
#include <stdio.h>
#include <stdlib.h>

int main()
{
    float temperature;

    printf("Enter temperature in Celsius: ");
    scanf("%f", &temperature);

    if (temperature < -273.15)
    {
        printf("Error: Temperature below absolute zero!");
    }
    else
    {
        float fahrenheit = (temperature * 1.8) + 32;
        float kelvin = temperature + 273.15;

        printf("Temperature in Fahrenheit: %.2f\n", fahrenheit);
        printf("Temperature in Kelvin: %.2f\n", kelvin);

        if (temperature <= 0)
        {
            printf("It's freezing cold.\n");
        }
        else if (temperature > 0 && temperature <= 15)
        {
            printf("It's a bit chilly.\n");
        }
        else if (temperature > 15 && temperature <= 25)
        {
            printf("It's a comfortable temperature.\n");
        }
        else
        {
            printf("It's quite hot out!\n");
        }
    }
    return 0;
}