//FormAI DATASET v1.0 Category: Unit converter ; Style: thoughtful
#include<stdio.h>

int main() {
    float userInput, result;
    int choice;

    printf("Please select an option:\n");
    printf("1. Convert Celsius to Fahrenheit\n");
    printf("2. Convert Fahrenheit to Celsius\n");
    scanf("%d",&choice);

    switch(choice) {
        case 1:
            printf("Enter the temperature in Celsius: ");
            scanf("%f",&userInput);
            result = (userInput * 1.8) + 32;
            printf("%.2f°C = %.2f°F",userInput,result);
            break;
        case 2:
            printf("Enter the temperature in Fahrenheit: ");
            scanf("%f",&userInput);
            result = (userInput - 32) / 1.8;
            printf("%.2f°F = %.2f°C",userInput,result);
            break;
        default:
            printf("Invalid input! Try again.");
    }

    return 0;
}