//FormAI DATASET v1.0 Category: Unit converter ; Style: lively
#include <stdio.h>

int main()
{
    int choice;
    float value, result;

    printf("Welcome to the C Unit Converter!\n");
    printf("Please select the unit you would like to convert:\n");
    printf("1. Celsius to Fahrenheit\n");
    printf("2. Inches to Centimeters\n");
    printf("3. Pounds to Kilograms\n");

    scanf("%d", &choice);

    switch (choice)
    {
        case 1:
            printf("You have selected Celsius to Fahrenheit.\n");
            printf("Please enter the value in Celsius: ");
            scanf("%f", &value);
            result = (value * 1.8) + 32;
            printf("%.2f Celsius is %.2f Fahrenheit.\n", value, result);
            break;

        case 2:
            printf("You have selected Inches to Centimeters.\n");
            printf("Please enter the value in Inches: ");
            scanf("%f", &value);
            result = value * 2.54;
            printf("%.2f Inches is %.2f Centimeters.\n", value, result);
            break;

        case 3:
            printf("You have selected Pounds to Kilograms.\n");
            printf("Please enter the value in Pounds: ");
            scanf("%f", &value);
            result = value * 0.45359237;
            printf("%.2f Pounds is %.2f Kilograms.\n", value, result);
            break;

        default:
            printf("Invalid choice.\n");
            break;
    }

    return 0;
}