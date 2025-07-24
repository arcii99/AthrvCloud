//FormAI DATASET v1.0 Category: Personal Finance Planner ; Style: scientific
#include <stdio.h>

// Function to calculate monthly payments
double calculate_payments(double principal, double rate, int years) {
    int n = years * 12; // Total number of payments over n years
    double r = rate / (12 * 100); // Monthly interest rate
    double monthly_payment = (principal * r * pow(1 + r, n)) / (pow(1 + r, n) - 1); // Calculate monthly payment
    return monthly_payment;
}

// Function to calculate total interest paid
double calculate_total_interest(double principal, double rate, int years) {
    int n = years * 12; // Total number of payments over n years
    double r = rate / (12 * 100); // Monthly interest rate
    double monthly_payment = calculate_payments(principal, rate, years); // Monthly payment
    double total_interest = (monthly_payment * n) - principal; // Calculate total interest paid
    return total_interest;
}

int main() {
    double principal, rate, monthly_payment, total_interest;
    int years;

    // Prompt user to enter principal, rate, and years
    printf("Enter principal amount: ");
    scanf("%lf", &principal);
    printf("Enter annual interest rate: ");
    scanf("%lf", &rate);
    printf("Enter number of years: ");
    scanf("%d", &years);

    // Calculate and print monthly payments and total interest
    monthly_payment = calculate_payments(principal, rate, years);
    total_interest = calculate_total_interest(principal, rate, years);
    printf("\nMonths \t\t Payment \t Principal \t Interest \t Balance\n");
    int n = years * 12;
    double r = rate / (12 * 100);
    double balance = principal;
    for (int month = 1; month <= n; month++) {
        double interest = balance * r;
        double principal_paid = monthly_payment - interest;
        balance -= principal_paid;
        // print table
        printf("%d \t\t %6.2f \t\t %6.2f \t %6.2f \t\t %6.2f\n", month, monthly_payment, principal_paid, interest, balance);
    }
    printf("\n");
    printf("Monthly payment: $%.2f\n", monthly_payment);
    printf("Total interest paid: $%.2f\n", total_interest);
    printf("Total amount paid: $%.2f\n", principal + total_interest);

    return 0;
}