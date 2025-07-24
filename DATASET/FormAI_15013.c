//FormAI DATASET v1.0 Category: Mortgage Calculator ; Style: invasive
#include <stdio.h>
#include <math.h>

int main() {
    float loan_amount, interest_rate, monthly_payment, total_payment;
    int years;
    
    printf("Enter the loan amount: $");
    scanf("%f", &loan_amount);
    printf("Enter the interest rate: ");
    scanf("%f", &interest_rate);
    printf("Enter the number of years of the loan: ");
    scanf("%d", &years);
    
    interest_rate /= 1200; // convert from annual to monthly rate
    monthly_payment = loan_amount * interest_rate / (1 - pow(1 + interest_rate, -years*12));
    total_payment = monthly_payment * years * 12;
    
    printf("Monthly payment: $%.2f\n", monthly_payment);
    printf("Total payment: $%.2f\n", total_payment);
    
    return 0;
}