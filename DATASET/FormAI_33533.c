//FormAI DATASET v1.0 Category: Mortgage Calculator ; Style: unmistakable
#include <stdio.h>

int main() {
    float amount, interest, years;
    printf("Enter the loan amount: ");
    scanf("%f", &amount);
    
    printf("Enter the interest rate: ");
    scanf("%f", &interest);
    
    printf("Enter the number of years: ");
    scanf("%f", &years);
    
    float monthly_payment = (amount*interest/100/12) / (1-1/(pow(1+interest/100/12, years*12)));
    float total_payment = monthly_payment * years * 12;
    float total_interest = total_payment - amount;
    
    printf("\nLoan amount: $%.2f\n", amount);
    printf("Interest rate: %.2f%%\n", interest);
    printf("Number of years: %.0f\n", years);
    printf("Monthly payment: $%.2f\n", monthly_payment);
    printf("Total payment: $%.2f\n", total_payment);
    printf("Total interest: $%.2f\n", total_interest);
    
    return 0;
}