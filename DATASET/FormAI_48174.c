//FormAI DATASET v1.0 Category: Temperature Converter ; Style: puzzling
#include <stdio.h>

int main()
{
    float celsius, fahrenheit;
    char choice;

    printf("Welcome to the Puzzling Temperature Converter!\n\n");

    do {
        printf("\nEnter C to convert Celsius to Fahrenheit\nEnter F to convert Fahrenheit to Celsius\nEnter Q to quit\nChoice: ");
        scanf(" %c", &choice);

        if (choice == 'C' || choice == 'c') {

            printf("\nEnter temperature in Celsius: ");
            scanf("%f", &celsius);

            fahrenheit = (celsius * 9/5) + 32;

            printf("%.2f degrees Celsius is equal to ~%.2f degrees Fahrenheit\n", celsius, fahrenheit);

        }
        else if (choice == 'F' || choice == 'f') {

            printf("\nEnter temperature in Fahrenheit: ");
            scanf("%f", &fahrenheit);

            celsius = (fahrenheit - 32) * 5/9;

            printf("%.2f degrees Fahrenheit is equal to ~%.2f degrees Celsius\n", fahrenheit, celsius);

        }
        else if (choice == 'Q' || choice == 'q') {

            printf("\nGoodbye!\n");
            break;

        }
        else {

            printf("\nInvalid choice, try again!\n");

        }

    } while (1);

}