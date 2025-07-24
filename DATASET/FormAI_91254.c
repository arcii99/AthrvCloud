//FormAI DATASET v1.0 Category: Mortgage Calculator ; Style: Ken Thompson
#include <stdio.h>
#include <math.h>

int main()
{
    float principle, interest_rate, monthly_payment, total_interest, total_amount, monthly_interest_rate;
    int no_of_months;

    printf("Welcome to the Mortgage Calculator!\n");

    // User Input
    printf("Enter the Principle Amount: ");
    scanf("%f", &principle);

    printf("Enter the Interest Rate per year: ");
    scanf("%f", &interest_rate);

    printf("Enter the Loan Period in years: ");
    scanf("%d", &no_of_months);

    // Calculations
    monthly_interest_rate = interest_rate / 1200;
    monthly_payment = (principle * monthly_interest_rate) / (1 - pow(1 + monthly_interest_rate, - no_of_months * 12));
    total_amount = monthly_payment * no_of_months * 12;
    total_interest = total_amount - principle;

    // Output
    printf("\nYour Monthly Payment is: $%.2f\n", monthly_payment);
    printf("Total Interest Paid: $%.2f\n", total_interest);
    printf("Total Amount Paid: $%.2f\n", total_amount);

    return 0;
}