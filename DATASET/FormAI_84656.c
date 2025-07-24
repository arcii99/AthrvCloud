//FormAI DATASET v1.0 Category: Mortgage Calculator ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main() {
    double principle, rate, term, monthly_pay, total_pay, total_interest;
    int years;
    
    // Input
    printf("Enter the loan amount: ");
    scanf("%lf", &principle);
    printf("Enter the interest rate: ");
    scanf("%lf", &rate);
    printf("Enter the term in years: ");
    scanf("%d", &years);
    
    // Calculation
    rate = rate/1200; // Monthly interest rate
    term = years*12; // Total number of months
    monthly_pay = (principle*rate*pow(1+rate, term))/(pow(1+rate, term)-1);
    total_pay = monthly_pay * term;
    total_interest = total_pay - principle;
    
    // Output
    printf("\nMortgage Amortization Schedule:\n");
    printf("*********************************\n");
    printf("Loan amount: $%.2lf\n", principle);
    printf("Interest rate: %.2lf%%\n", rate*1200);
    printf("Term: %d years\n", years);
    printf("Monthly payment: $%.2lf\n", monthly_pay);
    printf("Total payment: $%.2lf\n", total_pay);
    printf("Total interest: $%.2lf\n", total_interest);
    printf("*********************************\n\n");
    
    // Monthly Payment Table
    printf("Monthly Payment Table:\n");
    printf("|-------------------------------------------------|\n");
    printf("|  Month  |   Monthly Payment  |  Principal  |  Interest  |\n");
    printf("|-------------------------------------------------|\n");
    double balance = principle;
    double principal_paid, interest_paid;
    for(int i=1; i<=term; i++) {
        interest_paid = balance*rate;
        principal_paid = monthly_pay - interest_paid;
        balance = balance - principal_paid;
        printf("|   %3d   |      $%-9.2lf  |    $%-7.2lf |  $%-7.2lf |\n", i, monthly_pay, principal_paid, interest_paid);
        
        if(i%12 == 0) {
            printf("|-------------------------------------------------|\n");
        }
    }
    
    return 0;
}