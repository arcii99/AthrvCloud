//FormAI DATASET v1.0 Category: Mortgage Calculator ; Style: Dennis Ritchie
#include<stdio.h>
#include<math.h>

int main(){
    float loan_amount, interest_rate, monthly_payment, total_interest, total_payment;
    int duration;
    
    printf("Enter the loan amount: ");
    scanf("%f", &loan_amount);
    
    printf("Enter the interest rate: ");
    scanf("%f", &interest_rate);
    
    printf("Enter the duration of the loan in months: ");
    scanf("%d", &duration);
    
    interest_rate /= 100.0;
    monthly_payment = (loan_amount * interest_rate) / (1 - pow(1 + interest_rate, -duration));
    
    total_payment = monthly_payment * duration;
    total_interest = total_payment - loan_amount;
    
    printf("Monthly Payment : %.2f\n", monthly_payment);
    printf("Total Payment   : %.2f\n", total_payment);
    printf("Total Interest  : %.2f\n", total_interest);
    
    return 0;
}