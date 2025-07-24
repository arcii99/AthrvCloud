//FormAI DATASET v1.0 Category: Mortgage Calculator ; Style: realistic
#include<stdio.h>
#include<math.h>

int main()
{
    float loan_amount, interest_rate, monthly_payment;
    int duration_years;

    printf("Enter loan amount: $");
    scanf("%f", &loan_amount);
    printf("Enter interest rate: ");
    scanf("%f", &interest_rate);
    printf("Enter duration in years: ");
    scanf("%d", &duration_years);

    float monthly_interest_rate = interest_rate / 1200.0; // yearly to monthly conversion
    int duration_months = duration_years * 12; // years to months conversion

    monthly_payment = loan_amount * monthly_interest_rate / (1 - pow(1+monthly_interest_rate, -duration_months));

    printf("Monthly payment: $%.2f\n", monthly_payment);

    float total_payment = monthly_payment * duration_months;
    float total_interest = total_payment - loan_amount;
    float annual_payment_percentage = (monthly_payment * 12) / loan_amount * 100;

    printf("Total payment: $%.2f\n", total_payment);
    printf("Total interest: $%.2f\n", total_interest);
    printf("Annual payment percentage: %.2f", annual_payment_percentage);
    
    return 0;
}