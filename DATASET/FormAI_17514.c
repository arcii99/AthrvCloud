//FormAI DATASET v1.0 Category: Mortgage Calculator ; Style: detailed
#include <stdio.h>
#include <math.h>

int main() {
    
    double principal, rate, years, monthly_rate, monthly_payment, total_payment, balance;
    int i, num_payments;
    
    // Get user input for mortgage details
    printf("Enter the principal amount: $");
    scanf("%lf", &principal);
    
    printf("Enter the interest rate (as a percentage): ");
    scanf("%lf", &rate);
    rate = rate / 100; // Convert to decimal
    
    printf("Enter the number of years: ");
    scanf("%lf", &years);
    
    // Calculate monthly payment and total payment
    monthly_rate = rate / 12;
    num_payments = years * 12;
    
    monthly_payment = (principal * monthly_rate) / (1 - pow(1 + monthly_rate, -num_payments));
    total_payment = monthly_payment * num_payments;
    
    printf("\n");
    printf("Mortgage Details:\n");
    printf("-----------------\n");
    printf("Principal amount: $%.2f\n", principal);
    printf("Interest rate: %.2f%%\n", rate * 100);
    printf("Number of years: %.0f\n", years);
    printf("Monthly payment: $%.2f\n", monthly_payment);
    printf("Total payment: $%.2f\n", total_payment);
    
    // Print mortgage amortization table
    balance = principal;
    printf("\n");
    printf("Mortgage Amortization Table:\n");
    printf("----------------------------\n");
    printf("Payment\t\tInterest\tPrincipal\tBalance\n");
    
    for (i = 1; i <= num_payments; i++) {
        double interest = balance * monthly_rate;
        double principal_paid = monthly_payment - interest;
        balance -= principal_paid;
        
        printf("%d\t\t%.2f\t\t%.2f\t\t%.2f\n", i, interest, principal_paid, balance);
    }
    
    return 0;
}