//FormAI DATASET v1.0 Category: Mortgage Calculator ; Style: brave
#include <stdio.h>
#include <math.h>

int main() {
    float principal, rate, time, emi, interest, total_amount;
    int years, months;

    printf("Enter the principal amount: ");
    scanf("%f", &principal);
    printf("Enter the rate of interest: ");
    scanf("%f", &rate);
    printf("Enter the time period in years: ");
    scanf("%d", &years);
    
    //conversion of years to months
    months = years * 12;
    rate = rate / (12 * 100); //monthly interest rate
    emi = (principal * rate * pow(1 + rate, months)) / (pow(1 + rate, months) - 1);
    printf("\nEMI for %d years is: %.2f", years, emi);

    total_amount = emi * months;
    interest = total_amount - principal;
    printf("\nTotal interest payable is: %.2f", interest);
    printf("\nTotal payment payable is: %.2f", total_amount);
    return 0;
}