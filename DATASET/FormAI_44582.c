//FormAI DATASET v1.0 Category: Personal Finance Planner ; Style: configurable
#include<stdio.h>

// Function to calculate monthly mortgage payments
float monthlyMortgage(float principal, float interest, int num_years)
{
    float monthly_interest = interest / 1200.0; // monthly interest rate
    int num_payments = num_years * 12; // number of monthly payments
    float monthly_payment = (principal * monthly_interest) / (1 - pow(1 + monthly_interest, -num_payments));
    
    return monthly_payment;
}

// Function to calculate monthly car loan payments
float monthlyCarPayment(float principal, float interest, int num_months)
{
    float monthly_interest = interest / 1200.0; // monthly interest rate
    float monthly_payment = (principal * monthly_interest) / (1 - pow(1 + monthly_interest, -num_months));
    
    return monthly_payment;
}

// Function to calculate monthly credit card payments
float monthlyCreditCardPayment(float balance)
{
    float monthly_payment = balance * 0.02; // 2% of balance
    if(monthly_payment < 15)
        monthly_payment = 15; // Minimum payment of $15
    
    return monthly_payment;
}

int main()
{
    printf("Welcome to the Personal Finance Planner!\n");
    printf("Please enter the following information:\n");
    
    // Getting input from user
    float mortgage_principal, mortgage_interest, car_loan_principal, car_loan_interest, credit_card_balance;
    int mortgage_years, car_loan_months;
    printf("Mortgage Principal: ");
    scanf("%f", &mortgage_principal);
    printf("Mortgage Interest Rate: ");
    scanf("%f", &mortgage_interest);
    printf("Mortgage Term (Years): ");
    scanf("%d", &mortgage_years);
    printf("Car Loan Principal: ");
    scanf("%f", &car_loan_principal);
    printf("Car Loan Interest Rate: ");
    scanf("%f", &car_loan_interest);
    printf("Car Loan Term (Months): ");
    scanf("%d", &car_loan_months);
    printf("Credit Card Balance: ");
    scanf("%f", &credit_card_balance);
    
    // Calculating monthly payments
    float mortgage_monthly = monthlyMortgage(mortgage_principal, mortgage_interest, mortgage_years);
    float car_loan_monthly = monthlyCarPayment(car_loan_principal, car_loan_interest, car_loan_months);
    float credit_card_monthly = monthlyCreditCardPayment(credit_card_balance);
    
    // Displaying results to user
    printf("\nYour monthly mortgage payment is: $%.2f\n", mortgage_monthly);
    printf("Your monthly car loan payment is: $%.2f\n", car_loan_monthly);
    printf("Your monthly credit card payment is: $%.2f\n", credit_card_monthly);
    
    return 0;
}