//FormAI DATASET v1.0 Category: Mortgage Calculator ; Style: brave
#include <stdio.h>

// function to calculate monthly payment
float calculateMonthlyPayment(float P, float r, int n)
{
    float monthlyInterestRate = r / 1200;  // converting annual interest rate to monthly interest rate
    float monthlyPayment = (P * monthlyInterestRate) / (1 - pow(1 + monthlyInterestRate, -n));
    return monthlyPayment;
}

int main()
{
    float principal, annualInterestRate;
    int numOfYears;

    // taking input from user
    printf("Enter principal amount: $");
    scanf("%f", &principal);
    printf("Enter annual interest rate: ");
    scanf("%f", &annualInterestRate);
    printf("Enter number of years: ");
    scanf("%d", &numOfYears);

    // calculating monthly payment and total payment
    float monthlyPayment = calculateMonthlyPayment(principal, annualInterestRate, numOfYears * 12);
    float totalPayment = monthlyPayment * numOfYears * 12;

    // printing the results
    printf("\nYour monthly payment: $%.2f\n", monthlyPayment);
    printf("Total payment: $%.2f\n", totalPayment);

    return 0;
}