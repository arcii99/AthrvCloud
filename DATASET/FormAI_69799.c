//FormAI DATASET v1.0 Category: Unit converter ; Style: romantic
#include<stdio.h>

int main()
{
    float temp, converted_temp;
    int choice;

    printf("Welcome to the Temperature Conversion Program \n\n");

    do
    {
        printf("Please select an option: \n");
        printf("1. Convert Celsius to Fahrenheit\n");
        printf("2. Convert Fahrenheit to Celsius\n");
        printf("3. Exit Program\n");
        scanf("%d", &choice);

        switch (choice)
        {
            case 1:
                printf("Enter the temperature in Celsius : ");
                scanf("%f", &temp);
                converted_temp = ((9.0/5.0) * temp) + 32.0;
                printf("%.2f Celsius is equal to %.2f Fahrenheit\n", temp, converted_temp);
                break;
            case 2:
                printf("Enter the temperature in Fahrenheit : ");
                scanf("%f", &temp);
                converted_temp = (5.0/9.0) * (temp - 32.0);
                printf("%.2f Fahrenheit is equal to %.2f Celsius\n", temp, converted_temp);
                break;
            case 3:
                printf("Thank you for using the program!");
                break;
            default:
                printf("Invalid input! Please select between 1-3.\n");
                break;
        }

    } while (choice != 3);

    return 0;
}