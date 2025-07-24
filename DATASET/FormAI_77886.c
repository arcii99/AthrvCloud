//FormAI DATASET v1.0 Category: Mortgage Calculator ; Style: medieval
#include <stdio.h>

int main() {
    int principal = 0, years = 0;
    double interest_rate = 0.0;
    
    printf("Welcome, good sir or lady, to the Mortgage Calculator!\n");
    printf("What is the principal of your loan? (in gold coins): ");
    scanf("%d", &principal);
    
    printf("And how many years will you be repaying your loan? (in moons): ");
    scanf("%d", &years);
    
    printf("Finally, what is the interest rate on your loan? (in percent): ");
    scanf("%lf", &interest_rate);
    
    // Convert interest rate from a percentage to a decimal
    interest_rate /= 100.0;
    
    // Calculate the monthly mortgage payment
    double monthly_interest_rate = interest_rate / 12.0;
    int num_payments = years * 12;
    double term = pow((1 + monthly_interest_rate), num_payments);
    double monthly_payment = (principal * (monthly_interest_rate * term)) / (term - 1);
    
    printf("\n\nYour monthly mortgage payment shall be: %lf gold coins!\n", monthly_payment);
    
    return 0;
}