//FormAI DATASET v1.0 Category: Mortgage Calculator ; Style: medieval
#include <stdio.h>

int main() {
    float total_loan_amount, annual_interest_rate, monthly_interest_rate, monthly_payment;
    int total_months;

    printf("Welcome to the Medieval Mortgage Calculator!\n");
    printf("Please enter the total loan amount: ");
    scanf("%f", &total_loan_amount);
    printf("Please enter the annual interest rate: ");
    scanf("%f", &annual_interest_rate);
    printf("Please enter the total number of months: ");
    scanf("%d", &total_months);

    // calculate monthly interest rate
    monthly_interest_rate = annual_interest_rate / 1200;

    // calculate monthly payment
    monthly_payment = (total_loan_amount * monthly_interest_rate) / (1 - (pow(1 + monthly_interest_rate, -total_months)));

    printf("Your monthly payment is: %.2f gold coins\n", monthly_payment);
    printf("May your mortgage be paid in full and may you live long and prosper!\n");

    return 0;
}