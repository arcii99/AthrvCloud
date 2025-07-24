//FormAI DATASET v1.0 Category: Mortgage Calculator ; Style: inquisitive
#include <stdio.h>

int main() {
    float loan_amount, interest_rate, monthly_payment, total_interest;
    int num_months;

    printf("Welcome to the Mortgage Calculator!\n");
    
    printf("Enter the loan amount: ");
    scanf("%f", &loan_amount);
    
    printf("Enter the interest rate (in percentage): ");
    scanf("%f", &interest_rate);
    
    printf("Enter the number of months: ");
    scanf("%d", &num_months);

    // Convert interest rate to decimal and monthly interest rate
    interest_rate /= 100;
    float monthly_rate = interest_rate / 12;

    // Calculate the monthly payment using the formula
    monthly_payment = (loan_amount * monthly_rate) /
                      (1 - pow(1 + monthly_rate, -num_months));

    // Calculate total interest paid using the formula
    total_interest = (monthly_payment * num_months) - loan_amount;

    printf("\nYour monthly payment will be: $%.2f", monthly_payment);
    printf("\nOver the %d month period, you will pay $%.2f in interest.", num_months, total_interest);

    return 0;
}