//FormAI DATASET v1.0 Category: Mortgage Calculator ; Style: sophisticated
#include <stdio.h>
#include <math.h>

int main() {
    double principle, interest_rate, num_years;
    printf("Enter the principle amount: ");
    scanf("%lf", &principle);
    printf("Enter the interest rate: ");
    scanf("%lf", &interest_rate);
    printf("Enter the number of years: ");
    scanf("%lf", &num_years);

    double num_months = num_years * 12;
    double monthly_interest_rate = interest_rate / (12 * 100);
    double monthly_payment = principle * ((monthly_interest_rate * pow(1 + monthly_interest_rate, num_months)) / (pow(1 + monthly_interest_rate, num_months) - 1));
    double total_payment = monthly_payment * num_months;
    double total_interest = total_payment - principle;

    printf("\nLoan Summary:\n");
    printf("*************\n");
    printf("Principle amount: $%.2lf\n", principle);
    printf("Interest Rate: %.2lf%%\n", interest_rate);
    printf("Number of Years: %.2lf\n", num_years);
    printf("Monthly Payment: $%.2lf\n", monthly_payment);
    printf("Total Payment: $%.2lf\n", total_payment);
    printf("Total Interest: $%.2lf\n", total_interest);

    return 0;
}