//FormAI DATASET v1.0 Category: Temperature Converter ; Style: sophisticated
#include<stdio.h>

int main(){
    float fahrenheit, celsius;
    int choice;

    printf("\nWelcome to the Temperature Converter Program\n");

    do{
        printf("\nWhat would you like to do?\n");
        printf("1. Convert Celsius to Fahrenheit\n");
        printf("2. Convert Fahrenheit to Celsius\n");
        printf("3. Exit the program\n");
        printf("Enter your choice (1-3): ");
        scanf("%d", &choice);

        switch(choice){
            case 1:
                printf("\nEnter temperature in Celsius: ");
                scanf("%f", &celsius);
                fahrenheit = (celsius * 9/5) + 32;
                printf("%.2f degrees Celsius is equal to %.2f degrees Fahrenheit\n", celsius, fahrenheit);
                break;

            case 2:
                printf("\nEnter temperature in Fahrenheit: ");
                scanf("%f", &fahrenheit);
                celsius = (fahrenheit - 32) * 5/9;
                printf("%.2f degrees Fahrenheit is equal to %.2f degrees Celsius\n", fahrenheit, celsius);
                break;

            case 3:
                printf("\nThank you for using the program. Goodbye!\n");
                break;

            default:
                printf("\nInvalid choice. Please enter a valid choice.\n");
                break;
        }

    }while(choice != 3);


    return 0;
}