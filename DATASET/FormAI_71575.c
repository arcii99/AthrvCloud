//FormAI DATASET v1.0 Category: Mortgage Calculator ; Style: imaginative
#include <stdio.h>

int main() {
    float principal, interestRate, monthlyPayment, balance, interest, totalInterest;
    int term, totalPayments, currentPayment;

    printf("Welcome to Mortgage Calculator!\n\n");

    //get principal
    printf("Enter Principal (Amount Borrowed): ");
    scanf("%f", &principal);

    //get interest rate
    printf("Enter Interest Rate (per year): ");
    scanf("%f", &interestRate);

    //get term
    printf("Enter Term (in years): ");
    scanf("%d", &term);

    //convert annual interest rate to monthly interest rate
    interestRate /= 12;

    //convert term from years to months
    term *= 12;

    //calculate monthly payment using formula
    monthlyPayment = (principal * interestRate) / (1 - pow(1 + interestRate, -term));

    //display monthly payment
    printf("\nYour Monthly Payment: $%.2f\n", monthlyPayment);

    totalPayments = term;
    balance = principal;
    totalInterest = 0;

    printf("\nYour Amortization Table:\n");
    printf("%-10s %-20s %-20s %-20s %-20s\n", "Payment", "Interest", "Principal", "Balance", "Total Interest");

    for(currentPayment = 1; currentPayment <= totalPayments; currentPayment++) {
        //calculate interest for this month
        interest = balance * interestRate;

        //calculate principal for this month
        principal = monthlyPayment - interest;

        //update balance after payment
        balance = balance - principal;

        //add interest to total interest
        totalInterest += interest;

        //display this month's details
        printf("%-10d $%-19.2f $%-19.2f $%-19.2f $%-19.2f\n", currentPayment, interest, principal, balance, totalInterest);
    }
    
    return 0;
}