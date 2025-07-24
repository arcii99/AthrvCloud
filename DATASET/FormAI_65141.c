//FormAI DATASET v1.0 Category: Mortgage Calculator ; Style: scalable
#include <stdio.h>
#include <math.h>

int main() {
    float principle, interest_rate, num_years, monthly_payment;
    printf("Enter the Principle amount: ");
    scanf("%f", &principle);
    printf("Enter the Interest Rate per year (in percentage): ");
    scanf("%f", &interest_rate);
    printf("Enter the Number of years: ");
    scanf("%f", &num_years);

    // Calculate the monthly interest rate
    float monthly_interest_rate = (interest_rate / 12) / 100;

    // Calculate the total number of payments
    int total_num_payments = num_years * 12;

    // Calculate the monthly payment
    float numerator = monthly_interest_rate * pow(1 + monthly_interest_rate, total_num_payments);
    float denominator = pow(1 + monthly_interest_rate, total_num_payments) - 1;
    monthly_payment = principle * (numerator / denominator);

    // Output the monthly payment
    printf("The monthly payment is: %.2f\n", monthly_payment);

    return 0;
}