//FormAI DATASET v1.0 Category: Mortgage Calculator ; Style: expert-level
#include <stdio.h>
#include <math.h>

// Function to calculate monthly mortgage payment
double calculateMortgagePayment(double principal, double interest_rate, int term_in_years)
{
    double monthly_rate = interest_rate / 1200.0; // Monthly interest rate
    int term_in_months = term_in_years * 12; // Term in months
    double mortgage_payment = (principal * monthly_rate) / (1 - pow(1 + monthly_rate, -term_in_months)); // Formula to calculate monthly mortgage payment
    return mortgage_payment;
}

int main()
{
    double principal, interest_rate;
    int term_in_years;

    printf("Enter mortgage principal: ");
    scanf("%lf", &principal);

    printf("Enter mortgage interest rate: ");
    scanf("%lf", &interest_rate);

    printf("Enter mortgage term in years: ");
    scanf("%d", &term_in_years);

    double mortgage_payment = calculateMortgagePayment(principal, interest_rate, term_in_years);

    printf("Mortgage Principal: %.2lf\n", principal);
    printf("Mortgage Interest Rate: %.2lf%%\n", interest_rate);
    printf("Mortgage Term: %d years\n", term_in_years);
    printf("Monthly Mortgage Payment: $%.2lf\n", mortgage_payment);

    return 0;
}