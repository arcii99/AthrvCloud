//FormAI DATASET v1.0 Category: Temperature Converter ; Style: mathematical
#include <stdio.h>

int main()
{
    float celsius, fahrenheit;
    int choice;

    printf("Temperature Converter\n");
    printf("=====================\n");
    printf("Enter 1 to convert Celsius to Fahrenheit\n");
    printf("Enter 2 to convert Fahrenheit to Celsius\n");

    printf("\nEnter your choice: ");
    scanf("%d", &choice);

    if(choice == 1)
    {
        printf("\nEnter temperature in Celsius: ");
        scanf("%f", &celsius);

        fahrenheit = (celsius * 1.8) + 32;

        printf("%.2f C = %.2f F\n", celsius, fahrenheit);
    }
    else if(choice == 2)
    {
        printf("\nEnter temperature in Fahrenheit: ");
        scanf("%f", &fahrenheit);

        celsius = (fahrenheit - 32) / 1.8;

        printf("%.2f F = %.2f C\n", fahrenheit, celsius);
    }
    else
    {
        printf("\nInvalid choice!");
    }

    return 0;
}