//FormAI DATASET v1.0 Category: Temperature Converter ; Style: statistical
#include<stdio.h>
#include<stdlib.h>

int main()
{
    float fahrenheit, celsius;
    int choice;

    printf("\nTemperature Converter\n");
    printf("\n1. Celsius to Fahrenheit\n");
    printf("2. Fahrenheit to Celsius\n");
    printf("3. Exit\n");
    printf("\nEnter your choice: ");
    scanf("%d", &choice);

    switch(choice)
    {
        case 1:
            printf("\nEnter temperature in Celsius: ");
            scanf("%f", &celsius);
            fahrenheit = (celsius * 9/5) + 32;
            printf("\nTemperature in Fahrenheit: %.2f F\n", fahrenheit);
            break;

        case 2:
            printf("\nEnter temperature in Fahrenheit: ");
            scanf("%f", &fahrenheit);
            celsius = (fahrenheit - 32) * 5/9;
            printf("\nTemperature in Celsius: %.2f C\n", celsius);
            break;

        case 3:
            printf("\nExiting...\n");
            exit(0);

        default:
            printf("\nInvalid Choice! Try Again.\n");
            break;
    }

    main();
    return 0;
}