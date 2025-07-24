//FormAI DATASET v1.0 Category: Mortgage Calculator ; Style: energetic
#include <stdio.h>

int main() {
    float loan_amount, interest_rate, monthly_payment;
    int loan_period;
    printf("Welcome to the Mortgage Calculator!\n");
    printf("Please enter your loan amount: $");
    scanf("%f", &loan_amount);
    printf("Please enter your interest rate: ");
    scanf("%f", &interest_rate);
    printf("Please enter your loan period in years: ");
    scanf("%d", &loan_period);
    interest_rate /= 1200;  // convert annual interest rate to monthly interest rate
    monthly_payment = loan_amount * interest_rate / (1 - 1 / pow(1 + interest_rate, loan_period * 12));
    printf("\nYour monthly payment for a $%.2f loan at %.2f%% interest rate for %d years is: $%.2f\n", 
           loan_amount, interest_rate * 1200, loan_period, monthly_payment);
    printf("\nThank you for using the Mortgage Calculator!\n");
    return 0;
}