//FormAI DATASET v1.0 Category: Temperature Converter ; Style: visionary
#include <stdio.h>

int main()
{
    float temp_celsius, temp_fahrenheit;
    int choice;

    printf("Welcome to Temperature Converter Program!\n");
    printf("-----------------------------------------\n");
    printf("Please select your choice:\n");
    printf("1. Celsius to Fahrenheit\n");
    printf("2. Fahrenheit to Celsius\n");
    scanf("%d", &choice);

    switch (choice)
    {
        case 1:
            printf("\nEnter temperature in Celsius: ");
            scanf("%f", &temp_celsius);
            temp_fahrenheit = (temp_celsius * 9/5) + 32;
            printf("\n%f Celsius is equal to %f Fahrenheit.\n", temp_celsius, temp_fahrenheit);
            break;
        case 2:
            printf("\nEnter temperature in Fahrenheit: ");
            scanf("%f", &temp_fahrenheit);
            temp_celsius = (temp_fahrenheit - 32) * 5/9;
            printf("\n%f Fahrenheit is equal to %f Celsius.\n", temp_fahrenheit, temp_celsius);
            break;
        default:
            printf("\nInvalid choice entered.");
            break;
    }

    return 0;
}