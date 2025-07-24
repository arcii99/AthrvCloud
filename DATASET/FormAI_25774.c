//FormAI DATASET v1.0 Category: Mortgage Calculator ; Style: protected
#include <stdio.h>

int main() {
    float principal, rate, time, emi, total_amount;

    // Taking input from the user
    printf("Enter the Principal Amount: ");
    scanf("%f", &principal);

    printf("Enter the Rate of Interest: ");
    scanf("%f", &rate);

    printf("Enter the Time period in Years: ");
    scanf("%f", &time);

    // Calculating EMI
    rate = rate / (12 * 100); // Converting yearly rate to monthly rate
    time = time * 12; // Converting years to months
    emi = (principal * rate * pow(1 + rate, time)) / (pow(1 + rate, time) - 1);

    // Calculating Total Amount Payable
    total_amount = emi * time;

    // Displaying the final output
    printf("\n");
    printf("****************************************************************\n");
    printf("                      LOAN DETAILS                               \n");
    printf("****************************************************************\n");
    printf("Principal Amount\t: $%.2f\n", principal);
    printf("Interest Rate\t\t: %.2f%%\n", rate * 12 * 100);
    printf("Time Period\t\t: %.2f Years\n\n", time / 12);
    printf("***************************************************************\n");
    printf("                       EMI DETAILS                               \n");
    printf("***************************************************************\n");
    printf("EMI\t\t\t: $%.2f\n", emi);
    printf("Total Amount Payable\t: $%.2f\n\n", total_amount);

    return 0;
}