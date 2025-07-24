//FormAI DATASET v1.0 Category: Mortgage Calculator ; Style: automated
#include<stdio.h>

int main() {
    float principal, rate, time, emi, interest, amount;
    printf("\nWelcome to Mortgage Calculator\n");
    printf("----------------------------\n");
    printf("Enter the Principal amount (in dollars): ");
    scanf("%f", &principal);
    printf("Enter the Rate of Interest (in percentage): ");
    scanf("%f", &rate);
    printf("Enter the Time period (in years): ");
    scanf("%f", &time);

    //Conversion of rate and time 
    rate = rate / 100.0;
    time = time * 12;

    // calculation of EMI Value
    emi = (principal * rate * pow(1 + rate, time)) / (pow(1 + rate, time) - 1);

    // Interest Calculation 
    interest = emi * time - principal;

    // Total Amount calculation 
    amount = emi * time;

    //Result Display
    printf("\n----------------------------\n");
    printf("Loan Amount : $%.2f\n", principal);
    printf("Interest Rate : %.2f %%\n", rate * 100);
    printf("Time period (in years) : %.2f\n", time/12);
    printf("Monthly Payment : $%.2f\n", emi);
    printf("Total Interest Payable : $ %.2f\n", interest);
    printf("Total Payment (Principal + Interest) : $ %.2f\n", amount);
    printf("----------------------------\n");
    return 0;
}