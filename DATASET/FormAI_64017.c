//FormAI DATASET v1.0 Category: Mortgage Calculator ; Style: cheerful
#include <stdio.h>

int main() {
    printf("Welcome to our Mortgage Calculator! Let's make homeownership a reality!\n\n");

    // Taking input from the user
    float loan_amount, interest_rate, monthly_payment;
    int loan_period;
    printf("Enter the loan amount: ");
    scanf("%f", &loan_amount);
    printf("Enter the interest rate (in percentage): ");
    scanf("%f", &interest_rate);
    printf("Enter the loan period (in years): ");
    scanf("%d", &loan_period);
    printf("Enter the monthly payment: ");
    scanf("%f", &monthly_payment);

    // Calculation of monthly interest rate and number of months
    float monthly_interest = interest_rate / 1200;
    int num_months = loan_period * 12;

    // Calculation of monthly payment and total payment
    float total_payment = monthly_payment * num_months;
    float amount_paid = loan_amount;
    for (int i = 1; i <= num_months; i++) {
        amount_paid += (amount_paid * monthly_interest) - monthly_payment;
    }

    // Displaying results
    printf("\nTotal amount paid: %.2f\n", amount_paid);
    printf("Total interest paid: %.2f\n", amount_paid - loan_amount);
    printf("Total payment: %.2f\n", total_payment);
    printf("\nThank you for using our Mortgage Calculator! Happy house hunting!\n");

    return 0;
}