//FormAI DATASET v1.0 Category: Unit converter ; Style: inquisitive
#include <stdio.h>

int main() {
    double input, converted_value;
    int choice;

    printf("Welcome to my unit converter program!\n");
    printf("Please select an option:\n");
    printf("1. Convert Celsius to Fahrenheit\n");
    printf("2. Convert Fahrenheit to Celsius\n");
    printf("3. Convert kilometers to miles\n");
    printf("4. Convert miles to kilometers\n");
    scanf("%d", &choice);

    switch (choice) {
        case 1: 
            printf("Enter temperature in Celsius: ");
            scanf("%lf", &input);
            converted_value = (input * 9/5) + 32;
            printf("%.2lf degrees Fahrenheit\n", converted_value);
            break;
        case 2:
            printf("Enter temperature in Fahrenheit: ");
            scanf("%lf", &input);
            converted_value = (input - 32) * 5/9;
            printf("%.2lf degrees Celsius\n", converted_value);
            break;
        case 3:
            printf("Enter distance in kilometers: ");
            scanf("%lf", &input);
            converted_value = input * 0.621371;
            printf("%.2lf miles\n", converted_value);
            break;
        case 4:
            printf("Enter distance in miles: ");
            scanf("%lf", &input);
            converted_value = input * 1.60934;
            printf("%.2lf kilometers\n", converted_value);
            break;
        default:
            printf("Invalid option.\n");
    }

    return 0;
}