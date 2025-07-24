//FormAI DATASET v1.0 Category: Temperature Converter ; Style: ephemeral
#include <stdio.h>

int main(){

    float fahrenheit, celsius;
    int option;

    printf("Welcome to the Temperature Converter Program\n");
    printf("\n1. Celsius to Fahrenheit\n2. Fahrenheit to Celsius\n3. Exit\n");
    printf("Enter your choice: ");
    scanf("%d", &option);

    switch(option){
        case 1:
            printf("\nEnter temperature in Celsius: ");
            scanf("%f", &celsius);
            fahrenheit = (celsius * 9/5) + 32;
            printf("%.2f Celsius is equal to %.2f Fahrenheit", celsius, fahrenheit);
            break;
        case 2:
            printf("\nEnter temperature in Fahrenheit: ");
            scanf("%f", &fahrenheit);
            celsius = (fahrenheit - 32) * 5/9;
            printf("%.2f Fahrenheit is equal to %.2f Celsius", fahrenheit, celsius);
            break;
        case 3:
            printf("\nThank you for using the Temperature Converter Program");
            break;
        default:
            printf("\nInvalid choice, please enter a valid choice!");
            break;
    }

    return 0;
}