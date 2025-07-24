//FormAI DATASET v1.0 Category: Mortgage Calculator ; Style: real-life
#include <stdio.h>
#include <stdlib.h>

int main(){

    float loan_amount, interest_rate, monthly_payment, total_interest, total_payment;
    int years;

    // taking loan amount as input
    printf("Enter the loan amount: ");
    scanf("%f", &loan_amount);

    // taking interest rate as input
    printf("Enter the interest rate (per annum): ");
    scanf("%f", &interest_rate);

    // taking loan term in years as input
    printf("Enter the loan term (in years): ");
    scanf("%d", &years);

    // calculating monthly interest rate
    float monthly_rate = interest_rate/(12 * 100);

    // calculating number of months
    int months = years * 12;

    // calculating monthly payment
    monthly_payment = (loan_amount * monthly_rate * pow(1 + monthly_rate, months)) / (pow(1 + monthly_rate, months) - 1);

    // calculating total interest paid
    total_interest = monthly_payment * months - loan_amount;

    // calculating total payment
    total_payment = monthly_payment * months;

    // print the output
    printf("Loan Amount: %.2f\n",loan_amount);
    printf("Interest Rate: %.2f per annum\n",interest_rate);
    printf("Loan Term: %d years\n",years);
    printf("Monthly Payment: %.2f\n",monthly_payment);
    printf("Total Interest Paid: %.2f\n",total_interest);
    printf("Total Payment: %.2f\n",total_payment);

    return 0;
}