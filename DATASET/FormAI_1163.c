//FormAI DATASET v1.0 Category: Temperature Converter ; Style: complex
#include<stdio.h>
#include<stdlib.h>

int main(){
    int choice;
    float temp, converted;

    printf("Welcome to the Temperature Converter Application\n");

    while(1){
        printf("What would you like to do?\n");
        printf("1. Convert Celsius to Fahrenheit\n");
        printf("2. Convert Fahrenheit to Celsius\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice){
            case 1:
                printf("Enter temperature in Celsius: ");
                scanf("%f", &temp);
                converted = (temp * 9/5) + 32;
                printf("%.2f Celsius = %.2f Fahrenheit\n", temp, converted);
                break;
            case 2:
                printf("Enter temperature in Fahrenheit: ");
                scanf("%f", &temp);
                converted = (temp - 32) * 5/9;
                printf("%.2f Fahrenheit = %.2f Celsius\n", temp, converted);
                break;
            case 3:
                printf("Thank you for using the application\n");
                exit(0);
            default:
                printf("Invalid choice! Please try again.\n\n");
        }
    }

    return 0;
}