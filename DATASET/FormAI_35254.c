//FormAI DATASET v1.0 Category: Mortgage Calculator ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(){

    // input variables
    float loan_amount, interest_rate, loan_term, monthly_payment;

    // menu
    printf("\n***************************************************");
    printf("\n\tMortgage Calculator");
    printf("\n***************************************************\n");
    printf("Enter loan amount (in dollars): ");
    scanf("%f", &loan_amount);
    printf("Enter interest rate (in percentage): ");
    scanf("%f", &interest_rate);
    printf("Enter loan term (in years): ");
    scanf("%f", &loan_term);

    // converts annual interest rate to monthly and calculates monthly payment
    float monthly_interest_rate = (interest_rate/100)/12;
    float loan_term_months = loan_term*12;
    monthly_payment = loan_amount * (monthly_interest_rate * pow(1 + monthly_interest_rate, loan_term_months)) / (pow(1 + monthly_interest_rate, loan_term_months) - 1);

    // displays monthly payment
    printf("\n***************************************************");
    printf("\n\tYour monthly payment is: $%.2f", monthly_payment);
    printf("\n***************************************************\n");

    return 0;
}