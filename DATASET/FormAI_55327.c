//FormAI DATASET v1.0 Category: Temperature Converter ; Style: Linus Torvalds
/* Linus Torvalds style Temperature Converter */

#include <stdio.h>

int main(void)
{
    float fahrenheit, celsius;
    int choice;

    printf("Linus Torvalds style Temperature Converter\n");

    while (1) {
        printf("\nPlease select an option: \n");
        printf("1. Fahrenheit to Celsius\n");
        printf("2. Celsius to Fahrenheit\n");
        printf("3. Quit\n");

        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("\nEnter temperature in Fahrenheit: ");
                scanf("%f", &fahrenheit);
                celsius = (fahrenheit - 32) * 5 / 9;
                printf("Temperature in Celsius: %0.2f", celsius);
                break;
            case 2:
                printf("\nEnter temperature in Celsius: ");
                scanf("%f", &celsius);
                fahrenheit = (celsius * 9 / 5) + 32;
                printf("Temperature in Fahrenheit: %0.2f", fahrenheit);
                break;
            case 3:
                printf("\nThank you for using Linus Torvalds style Temperature Converter!\n");
                return 0;
            default:
                printf("\nInvalid option, please select again.\n");
        }
    }

    return 0;
}