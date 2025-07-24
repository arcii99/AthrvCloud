//FormAI DATASET v1.0 Category: Mortgage Calculator ; Style: high level of detail
#include <stdio.h>
#include <math.h>

int main(){
    
    float loan_amount, interest_rate, monthly_payment, total_interest_paid, monthly_interest_rate, balance;
    int loan_term_months, i;
    
    printf("Welcome to the Mortgage Calculator!\n");
    
    //accept input from user
    printf("Enter the loan amount: ");
    scanf("%f", &loan_amount);
    printf("Enter the interest rate per annum: ");
    scanf("%f", &interest_rate);
    printf("Enter the loan term in months: ");
    scanf("%d", &loan_term_months);
    
    //convert interest rate to monthly rate
    monthly_interest_rate = interest_rate/1200;
    
    //calculate monthly payment
    monthly_payment = (loan_amount*monthly_interest_rate*pow(1+monthly_interest_rate,loan_term_months))/((pow(1+monthly_interest_rate,loan_term_months))-1);
    
    //display monthly payment
    printf("Your monthly payment is: $%.2f\n", monthly_payment);
    
    //calculate total interest paid
    total_interest_paid = (monthly_payment*loan_term_months)-loan_amount;
    
    //display total interest paid
    printf("Total interest paid over the life of the loan is: $%.2f\n", total_interest_paid);
    
    //initialize balance
    balance = loan_amount;
    
    //display table showing monthly payment, interest paid, principal paid, and remaining balance
    printf("\nPayment#\tPayment\t\tInterest Paid\tPrincipal Paid\tRemaining Balance\n");
    
    for(i=1;i<=loan_term_months;i++){
        float interest, principal;
        interest = balance*monthly_interest_rate;
        principal = monthly_payment - interest;
        balance -= principal;
        
        printf("%d\t\t$%.2f\t\t$%.2f\t\t$%.2f\t\t$%.2f\n", i, monthly_payment, interest, principal, balance);
    }
    
    return 0;
}