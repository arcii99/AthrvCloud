//FormAI DATASET v1.0 Category: Mortgage Calculator ; Style: brave
#include <stdio.h>

int main() {
    float amount, rate, months, principal, interest, payment;
    
    printf("Welcome to Brave Mortgage Calculator!\n");
    printf("Enter loan amount: ");
    scanf("%f", &amount);
    
    printf("Enter interest rate: ");
    scanf("%f", &rate);
    
    printf("Enter loan term in months: ");
    scanf("%f", &months);
    
    rate = rate / 100;
    principal = amount;
    
    for (int i = 1; i <= months; i++) {
        interest = principal * rate;
        principal = principal + interest;
    }
    
    payment = principal / months;
    
    printf("\n====================== RESULTS ======================\n");
    printf("Loan amount: $%.2f\n", amount);
    printf("Interest rate: %.2f%%\n", rate * 100);
    printf("Loan term: %.0f months\n", months);
    printf("Monthly payment: $%.2f\n", payment);
    printf("Total payment: $%.2f\n", principal);
    printf("Interest paid: $%.2f\n", principal - amount);
    
    return 0;
}