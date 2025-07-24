//FormAI DATASET v1.0 Category: Temperature Converter ; Style: mind-bending
#include<stdio.h>

int main()
{
    printf("Welcome to the Temperature Converter!\n");

    float temperature;
    char scale;
    float converted_temperature;

    printf("Enter the temperature: ");
    scanf("%f", &temperature);

    printf("Enter the scale (F or C): ");
    scanf(" %c", &scale);

    if(scale == 'F')
    {
        converted_temperature = (temperature - 32) * (5.0 / 9.0);
        printf("%.2f F is equal to %.2f C.\n", temperature, converted_temperature);
    }
    else if(scale == 'C')
    {
        converted_temperature = (temperature * (9.0 / 5.0)) + 32;
        printf("%.2f C is equal to %.2f F.\n", temperature, converted_temperature);
    }
    else
    {
        printf("Invalid scale entered.\n");
    }

    printf("Thank you for using the Temperature Converter!\n");

    return 0;
}