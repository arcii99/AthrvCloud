//FormAI DATASET v1.0 Category: Temperature Converter ; Style: happy
#include<stdio.h>
#include<stdlib.h>

int main() {
    int choice;
    float celsius, fahrenheit, result;

    printf("\nHi there! Let's convert temperature from Celsius to Fahrenheit or vice versa.\n");
    printf("1. Convert Celsius to Fahrenheit\n");
    printf("2. Convert Fahrenheit to Celsius\n");
    printf("Enter your choice (1 or 2): ");
    scanf("%d", &choice);
    printf("\n");

    switch (choice) {
        case 1:
            printf("You chose to convert Celsius to Fahrenheit!\n");
            printf("Enter temperature in Celsius: ");
            scanf("%f", &celsius);
            result = ((celsius * 9) / 5) + 32;
            printf("\nResult: %.2f Fahrenheit\n", result);
            break;
        case 2:
            printf("You chose to convert Fahrenheit to Celsius!\n");
            printf("Enter temperature in Fahrenheit: ");
            scanf("%f", &fahrenheit);
            result = (fahrenheit - 32) * 5 / 9;
            printf("\nResult: %.2f Celsius\n", result);
            break;
        default:
            printf("Invalid choice! Please enter choice 1 or 2.\n");
            break;
    }
    printf("\nThank you for using this temperature converter program. Stay happy and stay healthy!\n\n");
    return 0;
}