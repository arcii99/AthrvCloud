//FormAI DATASET v1.0 Category: Unit converter ; Style: grateful
#include<stdio.h>

int main()
{
    int input_choice;
    float input_value, result;

    printf("Welcome to the Grateful Unit Converter!\n");
    printf("Please select the type of unit you want to convert:\n");
    printf("1: Distance - Kilometers to Miles\n");
    printf("2: Weight - Kilograms to Pounds\n");
    printf("3: Temperature - Celsius to Fahrenheit\n");
    scanf("%d", &input_choice); // get user input for choice of conversion

    switch(input_choice)
    {
        case 1:
            printf("You have selected Distance Conversion - Kilometers to Miles.\n");
            printf("Please enter the value you want to convert in kilometers: ");
            scanf("%f", &input_value); // get user input for distance in kilometers
            result = input_value * 0.621371; // conversion formula
            printf("%.2f kilometers is equal to %.2f miles.\n", input_value, result);
            break;

        case 2:
            printf("You have selected Weight Conversion - Kilograms to Pounds.\n");
            printf("Please enter the value you want to convert in kilograms: ");
            scanf("%f", &input_value); // get user input for weight in kilograms
            result = input_value * 2.20462; // conversion formula
            printf("%.2f kilograms is equal to %.2f pounds.\n", input_value, result);
            break;

        case 3:
            printf("You have selected Temperature Conversion - Celsius to Fahrenheit.\n");
            printf("Please enter the value you want to convert in Celsius: ");
            scanf("%f", &input_value); // get user input for temperature in Celsius
            result = (input_value * 1.8) + 32; // conversion formula
            printf("%.2f Celsius is equal to %.2f Fahrenheit.\n", input_value, result);
            break;

        default:
            printf("Invalid choice. Please select a valid type of unit conversion.\n");
            break;
    }

    printf("Thanks for using the Grateful Unit Converter!\n");

    return 0;
}