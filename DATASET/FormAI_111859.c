//FormAI DATASET v1.0 Category: Mortgage Calculator ; Style: optimized
#include<stdio.h>

int main()
{
    float mortgage, rate, principal, m_interest, term, payment;
    int months;
    
    printf("Enter the loan amount: ");
    scanf("%f", &mortgage);
    
    printf("Enter the annual interest rate: ");
    scanf("%f", &rate);
    
    printf("Enter the duration of loan in years: ");
    scanf("%f", &term);
    
    principal = mortgage;
    m_interest = rate / (12 * 100);
    months = term * 12;

    // Calculating monthly payments using formula
    payment = (mortgage * m_interest * pow((1+m_interest),months)) / (pow((1+m_interest),months)-1);

    // Displaying total monthly payment
    printf("The monthly payment is $%.2f\n", payment);
    
    return 0;
}