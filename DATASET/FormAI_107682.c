//FormAI DATASET v1.0 Category: Mortgage Calculator ; Style: brave
#include <stdio.h>

int main() {
    double principal, rate, time, interest, total_amount;
    
    printf("Welcome to the Brave Mortgage Calculator!\n\n");
    
    printf("Enter the principal amount: $");
    scanf("%lf", &principal);
    printf("Enter the interest rate: ");
    scanf("%lf", &rate);
    printf("Enter the time period (in years): ");
    scanf("%lf", &time);
    
    rate = rate / 100;
    interest = principal * rate * time;
    total_amount = principal + interest;
    
    printf("\n");
    printf("Loan Information\n");
    printf("--------------------------------------------------\n");
    printf("Principal amount: $%.2lf\n", principal);
    printf("Interest rate: %.2lf%%\n", rate*100);
    printf("Time period: %.2lf years\n", time);
    
    printf("\n");
    printf("Payment Information\n");
    printf("--------------------------------------------------\n");
    printf("Interest amount: $%.2lf\n", interest);
    printf("Total amount payable: $%.2lf\n", total_amount);
    printf("Monthly payment: $%.2lf\n", total_amount / (time * 12));
    
    printf("\n");
    printf("Thank you for using the Brave Mortgage Calculator! Goodbye!\n");
    
    return 0;
}