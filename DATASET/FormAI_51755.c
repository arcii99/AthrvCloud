//FormAI DATASET v1.0 Category: Temperature Converter ; Style: calm
#include<stdio.h>

int main(){

    float celsius, fahrenheit;
    int choice;

    printf("Temperature Converter\n");
    printf("1. Celsius to Fahrenheit\n");
    printf("2. Fahrenheit to Celsius\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);

    switch(choice){

        case 1:
            printf("Enter temperature in Celsius: ");
            scanf("%f", &celsius);
            fahrenheit = (celsius * 9/5) + 32;
            printf("%.2f\u00b0 Celsius is equal to %.2f\u00b0 Fahrenheit\n", celsius, fahrenheit);
            break;

        case 2:
            printf("Enter temperature in Fahrenheit: ");
            scanf("%f", &fahrenheit);
            celsius = (fahrenheit - 32) * 5/9;
            printf("%.2f\u00b0 Fahrenheit is equal to %.2f\u00b0 Celsius\n", fahrenheit, celsius);
            break;

        default:
            printf("Invalid choice\n");

    }

    return 0;

}