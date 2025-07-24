//FormAI DATASET v1.0 Category: Mortgage Calculator ; Style: realistic
#include <stdio.h>

int main() {
    float loan_amount, interest_rate, monthly_payment;
    int num_years, num_months;

    printf("Welcome to the Mortgage Calculator!\n\n");
    
    printf("Please enter the loan amount: ");
    scanf("%f", &loan_amount);
    
    printf("Please enter the interest rate: ");
    scanf("%f", &interest_rate);
    
    printf("Please enter the number of years: ");
    scanf("%d", &num_years);
    
    num_months = num_years * 12;
    interest_rate /= 1200; // convert interest rate from annual to monthly
    
    monthly_payment = (loan_amount * interest_rate) / (1 - (1 / pow(1 + interest_rate, num_months)));
    
    printf("\nYour monthly payment will be: $%.2f\n", monthly_payment);
    
    return 0;
}