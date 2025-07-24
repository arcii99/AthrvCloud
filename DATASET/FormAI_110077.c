//FormAI DATASET v1.0 Category: Personal Finance Planner ; Style: recursive
#include<stdio.h>
#include<stdlib.h>

/*Recursive function to calculate compound interest*/
double compoundInterest(double principal, double rate, int years, int compPerYear){
    if (years == 0){
        return principal;
    }
    double amount = (1 + rate/compPerYear);
    amount = pow(amount, compPerYear * years);
    amount = amount * principal;
    return amount;
}

int main(){
    double principal, rate, interest, amount;
    int choice, years, compPerYear;

    while(1){
        printf("Enter 1 for Compound Interest, 2 for Exit: ");
        scanf("%d", &choice);
        switch(choice){
            case 1:
                /*Taking Input*/
                printf("\nEnter Principal Amount: ");
                scanf("%lf", &principal);
                printf("Enter Rate of Interest: ");
                scanf("%lf", &rate);
                printf("Enter Number of Years: ");
                scanf("%d", &years);
                printf("Enter Number of Compoundings per Year: ");
                scanf("%d", &compPerYear);

                /*Calculating and Displaying Result*/
                amount = compoundInterest(principal, rate, years, compPerYear);
                interest = amount - principal;
                printf("\nAmount after Compound Interest: $%.2lf", amount);
                printf("\nInterest after Compound Interest: $%.2lf\n\n", interest);
                break;

            case 2:
                /*Exit*/
                printf("\nExiting Program.");
                exit(0);

            default:
                /*Invalid Input*/
                printf("\nInvalid Input!\n\n");
                break;
        }
    }

    return 0;
}