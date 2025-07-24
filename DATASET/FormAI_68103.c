//FormAI DATASET v1.0 Category: Mortgage Calculator ; Style: scalable
#include<stdio.h>
#include<math.h>

int main(){
    float principal, rate, time, emi, interest, amount;
    int term;

    printf("Enter the Principal Amount: ");
    scanf("%f",&principal);
    printf("Enter the Interest Rate (p.a): ");
    scanf("%f",&rate);
    printf("Enter the Loan Term (in years): ");
    scanf("%d",&term);

    rate = rate/(12*100); // monthly interest rate
    time = term*12; // terms in months

    // calculate emi
    emi = (principal * rate * pow(1 + rate, time))/(pow(1 + rate, time) - 1);

    // calculate total interest payable
    interest = emi*time - principal;

    // calculate total amount payable
    amount = emi*time;

    // display results
    printf("\n\n");
    printf("EMI: %0.2f\n", emi);
    printf("Total Interest Payable: %0.2f\n", interest);
    printf("Total Amount Payable: %0.2f\n", amount);

    return 0;
}