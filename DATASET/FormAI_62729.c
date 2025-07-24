//FormAI DATASET v1.0 Category: Mortgage Calculator ; Style: Ada Lovelace
#include <stdio.h>
#include <math.h>

int main(void) {
    double loan_amount, annual_interest_rate, monthly_interest_rate, monthly_payment, balance;
    int loan_period, total_payments;
    printf("Please enter the loan amount: ");
    scanf("%lf", &loan_amount);
    printf("Please enter the annual interest rate: ");
    scanf("%lf", &annual_interest_rate);
    monthly_interest_rate = annual_interest_rate / 1200.0;
    printf("Please enter the loan period (in years): ");
    scanf("%d", &loan_period);
    total_payments = loan_period * 12;
    monthly_payment = (loan_amount * monthly_interest_rate) / (1 - pow(1 + monthly_interest_rate, -total_payments));
    balance = loan_amount;
    printf("\nMortgage payment details:\n\n");
    printf("%-10s%-12s%-18s%-18s\n", "Payment", "Amount", "Interest Paid", "Balance");
    printf("%-10s%-12s%-18s%-18s\n", "-------", "------", "-------------", "-------");
    for(int i = 1; i <= total_payments; i++) {
        double interest_paid = monthly_interest_rate * balance;
        double principal_paid = monthly_payment - interest_paid;
        balance = balance - principal_paid;
        printf("%-10d$%-11.2lf$%-17.2lf$%-17.2lf\n", i, monthly_payment, interest_paid, balance);
    }
    return 0;
}