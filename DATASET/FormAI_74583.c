//FormAI DATASET v1.0 Category: Mortgage Calculator ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>

int main() {
    char choice = '\0';
    float amount = 0.0;
    float rate = 0.0;
    float years = 0.0;
    float monthlyPayment = 0.0;
    float totalPayment = 0.0;
    float balance = 0.0;
    do {
        printf("Welcome to the Shape Shifting Mortgage Calculator!\n\n");
        printf("Please select an option:\n");
        printf("1 - Calculate monthly payment\n");
        printf("2 - Calculate total payment\n");
        printf("3 - Calculate balance after certain number of years\n");
        printf("4 - Exit\n");
        scanf(" %c", &choice);
        switch (choice) {
            case '1':
                printf("\nEnter loan amount: ");
                scanf("%f", &amount);
                printf("Enter monthly interest rate: ");
                scanf("%f", &rate);
                printf("Enter number of years: ");
                scanf("%f", &years);
                monthlyPayment = amount * (rate * pow(1 + rate, years)) / (pow(1 + rate, years) - 1);
                printf("\nMonthly payment: $%.2f\n\n", monthlyPayment);
                break;
            case '2':
                printf("\nEnter loan amount: ");
                scanf("%f", &amount);
                printf("Enter monthly interest rate: ");
                scanf("%f", &rate);
                printf("Enter number of years: ");
                scanf("%f", &years);
                balance = amount * pow(1 + rate, years);
                totalPayment = balance / years / 12;
                printf("\nTotal payment: $%.2f\n\n", totalPayment);
                break;
            case '3':
                printf("\nEnter loan amount: ");
                scanf("%f", &amount);
                printf("Enter monthly interest rate: ");
                scanf("%f", &rate);
                printf("Enter number of years: ");
                scanf("%f", &years);
                printf("Enter number of years to calculate balance after: ");
                float calcYears = 0.0;
                scanf("%f", &calcYears);
                balance = amount * pow(1 + rate, years) - (totalPayment * 12 * calcYears);
                printf("\nBalance after %d years: $%.2f\n\n", (int)calcYears, balance);
                break;
            case '4':
                printf("\nExiting program...\n");
                return 0;
            default:
                printf("\nInvalid choice, please try again.\n\n");
                break;
        }
    } while (choice != '4');
    return 0;
}