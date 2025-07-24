//FormAI DATASET v1.0 Category: Temperature Converter ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>

int main() {

    float celsius, fahrenheit;
    int choice;

    printf("Welcome to the Temperature Converter!\n\n");

    printf("Please choose an option:\n");
    printf("1. Celsius to Fahrenheit\n");
    printf("2. Fahrenheit to Celsius\n");

    scanf("%d", &choice);

    switch(choice) {

        case 1:
            printf("Enter the temperature in Celsius: ");
            scanf("%f", &celsius);

            fahrenheit = (celsius * 9/5) + 32; //convert celsius to fahrenheit formula

            printf("%.2f degree Celsius is equal to %.2f degree Fahrenheit.", celsius, fahrenheit);
            break;

        case 2:
            printf("Enter the temperature in Fahrenheit: ");
            scanf("%f", &fahrenheit);

            celsius = (fahrenheit - 32) * 5/9; //convert fahrenheit to celsius formula

            printf("%.2f degree Fahrenheit is equal to %.2f degree Celsius.", fahrenheit, celsius);
            break;

        default:
            printf("Invalid choice entered."); //if choice is not 1 or 2
            break;
    }

    return 0;
}