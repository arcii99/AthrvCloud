//FormAI DATASET v1.0 Category: Temperature Converter ; Style: post-apocalyptic
#include <stdio.h>

// function to convert Celsius to Fahrenheit
float convertCtoF(float celsius)
{
    float fahrenheit = (celsius * 9 / 5) + 32;
    return fahrenheit;
}

// function to convert Fahrenheit to Celsius
float convertFtoC(float fahrenheit)
{
    float celsius = (fahrenheit - 32) * 5 / 9;
    return celsius;
}

int main()
{
    printf("Welcome to the temperature converter program.\n");
    printf("Please select an option to convert:\n");
    printf("1. Celsius to Fahrenheit\n");
    printf("2. Fahrenheit to Celsius\n");

    int option;
    scanf("%d", &option);

    float temperature;
    printf("Please enter the temperature: ");

    scanf("%f", &temperature);

    switch (option)
    {
    case 1:
        printf("%.1f degrees Celsius is equivalent to %.1f degrees Fahrenheit.\n", temperature, convertCtoF(temperature));
        break;
    case 2:
        printf("%.1f degrees Fahrenheit is equivalent to %.1f degrees Celsius.\n", temperature, convertFtoC(temperature));
        break;
    default:
        printf("Invalid option selected.\n");
        break;
    }

    printf("Thank you for using the temperature converter program.\n");

    return 0;
}