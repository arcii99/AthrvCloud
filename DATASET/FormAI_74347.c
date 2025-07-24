//FormAI DATASET v1.0 Category: Mortgage Calculator ; Style: romantic
#include <stdio.h>
int main() {
    float principal, rate, time, emi, interest;
    printf("Hello dear, let's calculate the mortgage payment for our new house.\n");
    printf("Enter the loan amount: ");
    scanf("%f", &principal);
    printf("Enter the interest rate: ");
    scanf("%f", &rate);
    printf("Enter the loan duration in years: ");
    scanf("%f", &time);
    interest = rate / 100;
    emi = (principal * interest * (pow(1+interest, time*12))) / (pow(1+interest, time*12) - 1);
    printf("\nOh my love, our monthly mortgage payment will be $%.2f.\n\n", emi);
    return 0;
}