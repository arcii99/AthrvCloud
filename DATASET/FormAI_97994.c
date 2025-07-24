//FormAI DATASET v1.0 Category: Temperature Converter ; Style: cheerful
#include <stdio.h>

int main() {
    float fahrenheit, celsius;

    printf("Welcome to the Temperature Converter!\n");
    printf("------------------------------------\n");
    
    while(1) {  // loop until user chooses to exit

        printf("\nWhat would you like to convert?\n");
        printf("1. Celsius to Fahrenheit\n");
        printf("2. Fahrenheit to Celsius\n");
        printf("3. Exit\n");
        
        int choice;
        scanf("%d", &choice);

        switch(choice) {
            
            case 1:
                printf("\nEnter the temperature in Celsius: ");
                scanf("%f", &celsius);
                fahrenheit = (celsius * 9 / 5) + 32;
                printf("%.2f degrees Celsius is equal to %.2f degrees Fahrenheit!\n", celsius, fahrenheit);
                break;

            case 2:
                printf("\nEnter the temperature in Fahrenheit: ");
                scanf("%f", &fahrenheit);
                celsius = (fahrenheit - 32) * 5 / 9;
                printf("%.2f degrees Fahrenheit is equal to %.2f degrees Celsius!\n", fahrenheit, celsius);
                break;

            case 3:
                printf("\nThank you for using the Temperature Converter!\n");
                printf("Have a nice day!\n");
                return 0;

            default:
                printf("\nInvalid choice. Please try again.\n");
                break;
        }
    }

    return 0;
}