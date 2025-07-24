//FormAI DATASET v1.0 Category: Temperature Converter ; Style: invasive
#include <stdio.h>
#include <stdlib.h>

float convert_to_fahrenheit(float celsius);
float convert_to_kelvin(float celsius);

int main()
{
    float celsius, fahrenheit, kelvin;
    char choice;

    do
    {
        system("cls");

        printf("    Celsius to Fahrenheit and Kelvin Converter\n\n");
        printf("Enter the temperature in Celsius: ");
        scanf("%f", &celsius);

        fahrenheit = convert_to_fahrenheit(celsius);
        kelvin = convert_to_kelvin(celsius);

        printf("\n%f Celsius = %f Fahrenheit\n", celsius, fahrenheit);
        printf("%f Celsius = %f Kelvin\n\n", celsius, kelvin);

        printf("Do you want to convert another temperature? (Y/N): ");
        scanf(" %c", &choice);

    } while (choice == 'y' || choice == 'Y');

    return 0;
}

float convert_to_fahrenheit(float celsius)
{
    float fahrenheit = ((9 * celsius) / 5) + 32;
    return fahrenheit;
}

float convert_to_kelvin(float celsius)
{
    float kelvin = celsius + 273.15;
    return kelvin;
}