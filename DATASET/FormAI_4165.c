//FormAI DATASET v1.0 Category: Mortgage Calculator ; Style: single-threaded
#include <stdio.h>
#include <math.h>

int main()
{
    float principle, interest_rate, monthly_rate, term_years, term_months, total_paid, monthly_payment;
    
    printf("Welcome to the Mortgage Calculator!\n");
    
    //User Input
    printf("Please enter the loan amount: ");
    scanf("%f", &principle);
    
    printf("Please enter the interest rate as a percentage: ");
    scanf("%f", &interest_rate);
    
    printf("Please enter the term in years: ");
    scanf("%f", &term_years);
    
    //Calculations
    term_months = term_years * 12;
    monthly_rate = (interest_rate / 100) / 12;
    monthly_payment = (principle * monthly_rate) / (1 - powf((1 + monthly_rate), -term_months));
    total_paid = monthly_payment * term_months;
    
    //Output
    printf("\nYour monthly payment is: $%.2f\n", monthly_payment);
    printf("Your total paid over %0.0f years is: $%.2f\n", term_years, total_paid);
    
    return 0;
}