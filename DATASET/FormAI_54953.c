//FormAI DATASET v1.0 Category: Mortgage Calculator ; Style: decentralized
#include<stdio.h>

int main(){

    float principal, rate, time, emi, interest, balance;

    printf("Enter the principal amount: ");
    scanf("%f", &principal);
    
    printf("\nEnter the rate of interest (per annum): ");
    scanf("%f", &rate);
    
    printf("\nEnter the time period (in years): ");
    scanf("%f", &time);
    
    interest = (principal * rate * time) / 100;

    balance = principal;

    printf("\nLoan Summary:\nPrincipal: $%.2f\nInterest Rate: %.2f%% per annum\nTime Period: %.2f years\n", principal, rate, time);

    // Monthly Interest Calculation
    rate /= 1200;

    // Monthly EMI Calculation
    emi = (principal*rate*pow(1+rate, time*12))/(pow(1+rate, time*12)-1);

    printf("\nEMI for %.2f years = $%.2f\n", time, emi);

    printf("\nRepayment Schedule:\n");
    printf("Month\tLoan Amount\tEMI\t\tInterest\tPrincipal\tBalance\n");

    for(int i=1; i<=time*12; i++){

        float interest_p = balance * rate;
        float principal_p = emi - interest_p;
        balance -= principal_p;
        printf("%d\t$%.2f\t\t$%.2f\t$%.2f\t\t$%.2f\t\t$%.2f\n", i, balance+principal_p, emi, interest_p, principal_p, balance);

    }

    return 0;
}