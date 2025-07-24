//FormAI DATASET v1.0 Category: Temperature Converter ; Style: excited
#include <stdio.h>
#include <stdlib.h>

int main()
{
    int choice;
    float temp, result;

    printf("\n\t\tWelcome to Temperature Converter!\n\n");
    printf("1. Celsius to Fahrenheit\n");
    printf("2. Fahrenheit to Celsius\n");
    printf("3. Exit\n");

    do {
        printf("\nEnter your choice (1, 2 or 3): ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                printf("\nEnter temperature in Celsius: ");
                scanf("%f", &temp);
                result = (temp * 9/5) + 32;
                printf("\n %.2f Celsius = %.2f Fahrenheit \n", temp, result);
                break;

            case 2:
                printf("\nEnter temperature in Fahrenheit: ");
                scanf("%f", &temp);
                result = (temp - 32) * 5/9;
                printf("\n %.2f Fahrenheit = %.2f Celsius \n", temp, result);
                break;

            case 3:
                printf("\nExiting...\n");
                exit(0);
                break;

            default:
                printf("\nInvalid input!\n");
        }
    } while(choice != 3);

    return 0;
}