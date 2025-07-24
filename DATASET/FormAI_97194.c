//FormAI DATASET v1.0 Category: Unit converter ; Style: innovative
#include <stdio.h>

int main() {
    float input;
    int option;
    printf("Welcome to the Unit Converter!\n");
    printf("Enter 1 to convert Celsius to Fahrenheit\n");
    printf("Enter 2 to convert Kilometers to Miles\n");
    printf("Enter 3 to convert Feet to Meters\n");
    printf("Enter 4 to convert Pounds to Kilograms\n");
    scanf("%d", &option);
    switch(option) {
        case 1:
            printf("Enter temperature in Celsius: ");
            scanf("%f", &input);
            printf("%.2f Celsius = %.2f Fahrenheit\n", input, (input * 9/5) + 32);
            break;
        case 2:
            printf("Enter distance in Kilometers: ");
            scanf("%f", &input);
            printf("%.2f Kilometers = %.2f Miles\n", input, input * 0.621371);
            break;
        case 3:
            printf("Enter length in Feet: ");
            scanf("%f", &input);
            printf("%.2f Feet = %.2f Meters\n", input, input * 0.3048);
            break;
        case 4:
            printf("Enter weight in Pounds: ");
            scanf("%f", &input);
            printf("%.2f Pounds = %.2f Kilograms\n", input, input * 0.453592);
            break;
        default:
            printf("Invalid option\n");
    }
    return 0;
}