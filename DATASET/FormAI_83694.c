//FormAI DATASET v1.0 Category: Unit converter ; Style: enthusiastic
#include <stdio.h>

int main() {

    printf("Welcome to the Ultimate Unit Converter! \n");
    printf("This program converts various units for you with ease. \n");

    float userInput;
    int choice;

    printf("\nEnter the value you want to convert: ");
    scanf("%f", &userInput);

    printf("\nChoose the option to convert your unit: \n");
    printf("1. Celsius to Fahrenheit \n");
    printf("2. Fahrenheit to Celsius \n");
    printf("3. Kilometers to Miles \n");
    printf("4. Miles to Kilometers \n");
    printf("5. Pounds to Kilograms \n");
    printf("6. Kilograms to Pounds \n");
    scanf("%d", &choice);

    switch (choice) {
        case 1:
            printf("%.2f Celsius is %.2f Fahrenheit \n", userInput, (userInput * 1.8) + 32);
            break;
        case 2:
            printf("%.2f Fahrenheit is %.2f Celsius \n", userInput, (userInput - 32) * 0.56);
            break;
        case 3:
            printf("%.2f Kilometers is %.2f Miles \n", userInput, userInput * 0.621371);
            break;
        case 4:
            printf("%.2f Miles is %.2f Kilometers \n", userInput, userInput * 1.60934);
            break;
        case 5:
            printf("%.2f Pounds is %.2f Kilograms \n", userInput, userInput * 0.453592);
            break;
        case 6:
            printf("%.2f Kilograms is %.2f Pounds \n", userInput, userInput * 2.20462);
            break;
        default:
            printf("Invalid option! Please enter number from 1 to 6. \n");
    }

    return 0;
}