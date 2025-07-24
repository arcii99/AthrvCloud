//FormAI DATASET v1.0 Category: Unit converter ; Style: Alan Touring
#include <stdio.h>

int main()
{
    int choice;     
    float value, result;

    printf("Welcome to the Converter Bot!\n");
    printf("Please choose an option from the menu below:\n");
    printf("1. Celsius to Fahrenheit\n");
    printf("2. Feet to Meters\n");
    printf("3. Pounds to Kilograms\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);

    switch(choice)
    {
        case 1: //Celsius to Fahrenheit
            printf("Enter temperature in Celsius: ");
            scanf("%f", &value);
            result = (value * 9 / 5) + 32;
            printf("The temperature in Fahrenheit is: %.2f\n", result);
            break;
        case 2: //Feet to Meters
            printf("Enter length in Feet: ");
            scanf("%f", &value);
            result = value / 3.281;
            printf("The length in Meters is: %.2f\n", result);
            break;
        case 3: //Pounds to Kilograms
            printf("Enter weight in Pounds: ");
            scanf("%f", &value);
            result = value * 0.453592;
            printf("The weight in Kilograms is: %.2f\n", result);
            break;
        default:
            printf("Invalid choice. Please try again.\n");
            break;
    }

    return 0;
}