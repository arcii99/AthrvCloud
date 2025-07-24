//FormAI DATASET v1.0 Category: Mortgage Calculator ; Style: Alan Touring
//Alan Turing-style Mortgage Calculator program
#include <stdio.h>
#include <math.h>

int main(void) {
    //declaring variables for loan details
    double loan_amount, interest_rate, monthly_payment, total_interest, remaining_balance;
    int loan_term;

    //getting input from user
    printf("Please enter the loan amount: ");
    scanf("%lf", &loan_amount);
    printf("Please enter the interest rate: ");
    scanf("%lf", &interest_rate);
    printf("Please enter the loan term (in years): ");
    scanf("%d", &loan_term);

    //converting annual interest rate to monthly interest rate
    double monthly_rate = (interest_rate / 100) / 12;

    //calculating monthly payment
    monthly_payment = (loan_amount * monthly_rate) / (1 - pow(1 + monthly_rate, -loan_term * 12));
    
    //calculating total interest
    total_interest = (monthly_payment * loan_term * 12) - loan_amount;
    
    //setting remaining balance equal to loan amount
    remaining_balance = loan_amount;

    //printing loan summary for each month
    printf("\nMonth\tRemaining Balance\n");    
    for (int month = 1; month <= (loan_term * 12); month++) {
        double interest_paid = monthly_rate * remaining_balance;
        double principal_paid = monthly_payment - interest_paid;
        remaining_balance = remaining_balance - principal_paid;
        printf("%d\t%0.2lf\n", month, remaining_balance);
    }
    
    //printing total monthly payment and total interest paid
    printf("\nTotal Monthly Payment: $%0.2lf\n", monthly_payment);
    printf("Total Interest Paid: $%0.2lf\n", total_interest);

    return 0;
}