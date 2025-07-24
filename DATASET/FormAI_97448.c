//FormAI DATASET v1.0 Category: Mortgage Calculator ; Style: enthusiastic
#include<stdio.h>

int main() {
    printf("Welcome to the Mortgage Calculator Program!\n");
    printf("Please enter the following details to calculate your monthly mortgage payment:\n");
    
    float principle, interest_rate, years, monthly_payment;
    
    printf("Enter the principle amount: ");
    scanf("%f", &principle);
    
    printf("Enter the interest rate (in percentage): ");
    scanf("%f", &interest_rate);
    
    printf("Enter the loan period (in years): ");
    scanf("%f", &years);
    
    // Converting years to months
    float months = years * 12;
    
    // Converting percentate to decimal
    interest_rate = interest_rate / 100.0;
    
    float monthly_interest_rate = interest_rate / 12.0;
    monthly_payment = (principle * monthly_interest_rate) / (1 - pow(1 + monthly_interest_rate, -months));
    
    printf("Your monthly mortgage payment is: $%.2f\n", monthly_payment);
    
    return 0;
}