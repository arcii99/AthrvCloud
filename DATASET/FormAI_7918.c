//FormAI DATASET v1.0 Category: Mortgage Calculator ; Style: enthusiastic
#include <stdio.h>

int main() {

    printf("Welcome to the Mortgage Calculator!\n\n");

    float principle, interestRate, monthlyInterest, monthlyPayment;
    int years, months;

    printf("Please enter the principle amount of the mortgage: ");
    scanf("%f", &principle);

    printf("Please enter the annual interest rate (in percentage): ");
    scanf("%f", &interestRate);

    printf("Please enter the number of years: ");
    scanf("%d", &years);

    monthlyInterest = interestRate / 12.0 / 100.0;   //Calculates the monthly interest
    months = years * 12;    //Calculates the total number of months
    monthlyPayment = principle * monthlyInterest / (1 - 1 / (pow(1 + monthlyInterest, months)));   //Calculates the monthly payment

    printf("\n");
    printf("Your monthly payment will be: $%.2f", monthlyPayment);   //Displays the monthly payment

    return 0;
}