//FormAI DATASET v1.0 Category: Mortgage Calculator ; Style: ephemeral
/* 
Ephemeral Mortgage Calculator
By Chatbot
*/

#include <stdio.h>

int main() {
    float amount, rate, payment;
    int years, months, totalMonths;
    
    // Get user input
    printf("Enter the loan amount: ");
    scanf("%f", &amount);
    printf("Enter the interest rate (as a decimal): ");
    scanf("%f", &rate);
    printf("Enter the loan term in years: ");
    scanf("%d", &years);
    printf("Enter the loan term in additional months: ");
    scanf("%d", &months);
    
    // Calculate total months and monthly rate
    totalMonths = years * 12 + months;
    rate = rate / 12;
    
    // Calculate monthly payment
    payment = (amount * rate) / (1 - pow(1 + rate, -totalMonths));
    
    // Output results
    printf("\n\n");
    printf("Loan Amount: %.2f\n", amount);
    printf("Interest Rate: %.2f%%\n", rate * 100);
    printf("Loan Term: %d years, %d months\n", years, months);
    printf("Monthly Payment: $%.2f\n", payment);
    printf("Total Payment: $%.2f\n", payment * totalMonths);
    printf("Total Interest Paid: $%.2f\n", payment * totalMonths - amount);
    
    return 0;
}