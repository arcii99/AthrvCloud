//FormAI DATASET v1.0 Category: Temperature Converter ; Style: happy
#include <stdio.h>

int main()
{
    int choice; float temp, convertedTemp;

    printf("Welcome to the Happy Temperature Converter!\n\n");

    printf("Please choose an option:\n");
    printf("1. Celsius to Fahrenheit\n");
    printf("2. Fahrenheit to Celsius\n");

    scanf("%d", &choice);

    if(choice == 1)
    {
        printf("Enter the temperature in Celsius: ");
        scanf("%f", &temp);

        convertedTemp = (temp * 9/5) + 32;

        printf("\nResult: %0.2f°C = %0.2f°F\n", temp, convertedTemp);
        printf("Voila, now that's a hot temperature!\n");
    }
    else if(choice == 2)
    {
        printf("Enter the temperature in Fahrenheit: ");
        scanf("%f", &temp);

        convertedTemp = (temp - 32) * 5/9;

        printf("\nResult: %0.2f°F = %0.2f°C\n", temp, convertedTemp);
        printf("Brrr... that's a chilly temperature!\n");
    }
    else
    {
        printf("Invalid option selected! Please choose 1 or 2.\n");
    }

    printf("Thank you for using our Happy Temperature Converter!\nKeep smiling and stay happy!\n");

    return 0;
}