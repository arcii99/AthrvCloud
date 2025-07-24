//FormAI DATASET v1.0 Category: Temperature Converter ; Style: funny
#include<stdio.h>
#include<stdlib.h>

void main() {
    float celsius, fahrenheit;    
    int choice;    

    while(1) {
        printf("\nWelcome to the Temperature Converter! \n\n");
        printf("1. Celsius to Fahrenheit\n");
        printf("2. Fahrenheit to Celsius\n");
        printf("3. Exit\n\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                printf("\nEnter temperature in Celsius: ");
                scanf("%f", &celsius);

                fahrenheit = ((celsius * 9) / 5) + 32;

                printf("\n%f degree Celsius = %f degree Fahrenheit\n", celsius, fahrenheit);
                break;

            case 2:
                printf("\nEnter temperature in Fahrenheit: ");
                scanf("%f", &fahrenheit);

                celsius = (fahrenheit - 32) * 5 / 9;

                printf("\n%f degree Fahrenheit = %f degree Celsius\n", fahrenheit, celsius);
                break;

            case 3:
                printf("\nThank you for using the Temperature Converter! Goodbye!\n");
                exit(0);

            default:
                printf("\nInvalid choice. Please try again.\n");
        }
    }
}