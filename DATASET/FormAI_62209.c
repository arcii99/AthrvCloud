//FormAI DATASET v1.0 Category: Mortgage Calculator ; Style: enthusiastic
#include<stdio.h>

int main() {
    float loan_amount, interest_rate, monthly_payment;
    int term;
    
    printf("Welcome to the Mortgage Calculator!\n");
    printf("Enter the loan amount: ");
    scanf("%f", &loan_amount);
    printf("Enter the interest rate: ");
    scanf("%f", &interest_rate);
    printf("Enter the term in years: ");
    scanf("%d", &term);
    
    //Convert interest rate to monthly rate
    interest_rate = interest_rate / 12 / 100;
    
    //Calculate the monthly payment
    monthly_payment = (loan_amount * interest_rate * pow(1 + interest_rate, term * 12)) / (pow(1 + interest_rate, term * 12) - 1);
    
    //Print the monthly payment
    printf("\nWith a loan of $%.2f, an interest rate of %.2f%%,\n", loan_amount, interest_rate * 12 * 100);
    printf("and a term of %d years, your monthly payment will be: $%.2f\n\n", term, monthly_payment);
    
    return 0;
}