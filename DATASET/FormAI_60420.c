//FormAI DATASET v1.0 Category: Mortgage Calculator ; Style: relaxed
#include <stdio.h>
#include <math.h>

int main() {
    float loan_amount, interest_rate, monthly_payment;
    int num_months;
    
    printf("Welcome to the Mortgage Calculator!\n");
    
    printf("Please enter the loan amount: ");
    scanf("%f", &loan_amount);
    
    printf("Please enter the interest rate (in percentage): ");
    scanf("%f", &interest_rate);
    
    printf("Please enter the number of months for the loan term: ");
    scanf("%d", &num_months);
    
    // Calculating monthly interest rate
    float monthly_interest_rate = (interest_rate / 100) / 12;
    
    float numerator = monthly_interest_rate * pow(1 + monthly_interest_rate, num_months);
    float denominator = pow(1 + monthly_interest_rate, num_months) - 1;
    
    monthly_payment = loan_amount * (numerator / denominator);
    
    printf("\nFor a loan amount of %.2f, an interest rate of %.2f%%\n", loan_amount, interest_rate);
    printf("and a loan term of %d months, your monthly payment is: $%.2f\n", num_months, monthly_payment);
    
    return 0;
}