//FormAI DATASET v1.0 Category: Personal Finance Planner ; Style: ultraprecise
#include<stdio.h>

//Function to calculate monthly payment for a loan
double monthlyPayment(double principal, double interest, int years){
    double r = interest/(12*100);
    int n = years*12;
    double payment = (r * principal) / (1 - pow(1+r,-n));
    return payment;
}

//Function to calculate compound interest for savings
double compoundInterest(double principal, double interest, int years){
    double r = interest/(12*100);
    int n = years*12;
    double amount = principal*pow(1 + r,n);
    double interestEarned = amount - principal;
    return interestEarned;
}

int main(){
    int choice;
    double principal, interest, payment, interestEarned;
    int years;

    //Displaying menu for the user to choose from
    printf("Enter your choice:\n1. Calculate Monthly Payment for a Loan\n2. Calculate Compound Interest for Savings\n");
    scanf("%d", &choice);
    
    switch(choice){
        case 1:
            printf("Enter Principal Amount: ");
            scanf("%lf", &principal);
            printf("Enter Interest Rate: ");
            scanf("%lf", &interest);
            printf("Enter Loan Tenure (in years): ");
            scanf("%d", &years);
            payment = monthlyPayment(principal,interest,years);
            printf("Your Monthly Payment is: %.2lf", payment);
            break;

        case 2:
            printf("Enter Principal Amount: ");
            scanf("%lf", &principal);
            printf("Enter Interest Rate: ");
            scanf("%lf", &interest);
            printf("Enter Tenure of Investment (in years): ");
            scanf("%d", &years);
            interestEarned = compoundInterest(principal,interest,years);
            printf("Your Interest Earned is: %.2lf", interestEarned);
            break;

        default:
            printf("Invalid Choice!!");
    }
    
    return 0;
}