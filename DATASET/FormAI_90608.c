//FormAI DATASET v1.0 Category: Mortgage Calculator ; Style: invasive
#include <stdio.h>
#include <math.h>

int main() {

    // Declare variables
    double loan_amount, interest_rate, monthly_rate, payment;
    int num_years, num_months;

    // Get input from user
    printf("Enter the loan amount: ");
    scanf("%lf", &loan_amount);

    printf("Enter the interest rate: ");
    scanf("%lf", &interest_rate);

    printf("Enter the number of years: ");
    scanf("%d", &num_years);

    // Convert number of years to months
    num_months = num_years * 12;

    // Convert annual interest rate to monthly interest rate
    monthly_rate = interest_rate / 1200;

    // Calculate monthly payment
    payment = loan_amount * monthly_rate / (1 - pow(1 + monthly_rate, -num_months));

    // Print monthly payment
    printf("The monthly payment is: $%.2lf\n", payment);

    return 0;
}