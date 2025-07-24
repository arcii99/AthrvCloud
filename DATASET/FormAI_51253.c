//FormAI DATASET v1.0 Category: Mortgage Calculator ; Style: satisfied
#include <stdio.h>
#include <math.h>

float calculateMortgagePayment(float p, float r, int n);

int main(void) {
    float principal;
    float interestRate;
    int numberOfPayments;
    float monthlyPayment;
    
    printf("Welcome to the Mortgage Calculator!\n\n");
    
    printf("Enter the principal amount (in dollars): ");
    scanf("%f", &principal);
    
    printf("Enter the interest rate (annual percentage): ");
    scanf("%f", &interestRate);
    
    interestRate /= 100;
    interestRate /= 12;
    
    printf("Enter the number of payments: ");
    scanf("%d", &numberOfPayments);
    
    monthlyPayment = calculateMortgagePayment(principal, interestRate, numberOfPayments);
    
    printf("\nYour monthly payment is: $%.2f\n\n", monthlyPayment);
    
    return 0;
}

float calculateMortgagePayment(float p, float r, int n) {
    r /= 100;
    float monthlyInterestRate = r / 12;
    float numerator = monthlyInterestRate * pow((1 + monthlyInterestRate), n);
    float denominator = pow((1 + monthlyInterestRate), n) - 1;
    float result = p * (numerator / denominator);
    return result;
}