//FormAI DATASET v1.0 Category: Mortgage Calculator ; Style: Romeo and Juliet
// Romeo and Juliet Mortgage Calculator

#include <stdio.h>
#include <math.h>

int main() {
    double principal, interest_rate, monthly_payment, total_interest, total_cost;
    int months;
    
    // Romeo enters the principal amount
    printf("Oh Juliet, what is the principal amount? ");
    scanf("%lf", &principal);
    
    // Juliet wants to know the interest rate
    printf("Romeo, what is the interest rate (in percentage)? ");
    scanf("%lf", &interest_rate);
    interest_rate /= 100.0; // Convert to decimal
    
    // Romeo has to calculate the monthly payment
    printf("Juliet, how long (in years) is the mortgage? ");
    int years;
    scanf("%d", &years);
    months = years * 12;
    double monthly_interest_rate = interest_rate / 12.0;
    monthly_payment = (principal * monthly_interest_rate) / (1 - pow(1 + monthly_interest_rate, -months));
    
    // Juliet wants to know the total cost and interest
    total_cost = monthly_payment * months;
    total_interest = total_cost - principal;
    
    // Romeo and Juliet display the results
    printf("\nAh, Juliet, the monthly payment is: %.2lf\n", monthly_payment);
    printf("And the total cost of the mortgage is: %.2lf\n", total_cost);
    printf("The total interest paid will be: %.2lf\n", total_interest);
    
    // Romeo and Juliet may live happily ever after
    return 0;
}