//FormAI DATASET v1.0 Category: Mortgage Calculator ; Style: minimalist
#include<stdio.h>

int main() {
    float principal, rate, time, interest, amount;

    // Taking input from user
    printf("Enter Principal Amount:");
    scanf("%f", &principal);

    printf("Enter Rate of Interest:");
    scanf("%f", &rate);

    printf("Enter Time(in years):");
    scanf("%f", &time);

    // Calculation of interest and amount
    interest = (principal * rate * time) / 100;
    amount = principal + interest;

    // Displaying the output
    printf("\nInterest = Rs.%.2f\n", interest);
    printf("Total Amount = Rs.%.2f\n", amount);

    return 0;
}