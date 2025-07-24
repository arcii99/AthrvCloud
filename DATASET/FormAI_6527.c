//FormAI DATASET v1.0 Category: Mortgage Calculator ; Style: visionary
#include <stdio.h>

int main() {
    float principal, rate, years, monthly_payment, total_paid, total_interest;
    
    printf("Welcome to the Mortgage Calculator\n");
    printf("Please enter the Principal Amount: ");
    scanf("%f", &principal);
    printf("Please enter the Annual Interest Rate (in decimal form): ");
    scanf("%f", &rate);
    printf("Please enter the Number of Years: ");
    scanf("%f", &years);
    
    float r = rate / 12;
    int n = years * 12;
    monthly_payment = (r * principal) / (1 - pow(1 + r, -n));
    total_paid = monthly_payment * n;
    total_interest = total_paid - principal;
    
    printf("Your Monthly Payment is: $%.2f\n", monthly_payment);
    printf("You will pay a total of: $%.2f\n", total_paid);
    printf("Your Total Interest Paid is: $%.2f\n", total_interest);
    
    return 0;
}