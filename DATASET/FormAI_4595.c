//FormAI DATASET v1.0 Category: Mortgage Calculator ; Style: decentralized
#include<stdio.h>
#include<stdlib.h>

float calculateMonthlyPayment(float principal, float interestRate, float term)
{
    float monthlyInterest, monthlyPayment;

    //Calculate monthly interest rate
    monthlyInterest = (interestRate / 100) / 12;

    //Calculate monthly payment using the mortgage formula
    monthlyPayment = (principal * monthlyInterest) / (1 - pow(1 + monthlyInterest, -term));

    return monthlyPayment;
}

int main()
{
    float principal, interestRate, term, monthlyPayment;

    //Get input from user
    printf("Enter the loan amount: ");
    scanf("%f", &principal);

    printf("Enter the interest rate: ");
    scanf("%f", &interestRate);

    printf("Enter the loan term in years: ");
    scanf("%f", &term);

    //Calculate monthly payment using the function
    monthlyPayment = calculateMonthlyPayment(principal, interestRate, term);

    //Display the result
    printf("Monthly payment = $%.2f\n", monthlyPayment);

    return 0;
}