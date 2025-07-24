//FormAI DATASET v1.0 Category: Mortgage Calculator ; Style: careful
#include<stdio.h>
#include<math.h>

int main(){
    float principal, interest_rate, monthly_payment, loan_tenure;
    float monthly_interest, total_interest;
    int no_of_payments;

    printf("Enter principal amount: ");
    scanf("%f", &principal);

    printf("Enter interest rate: ");
    scanf("%f", &interest_rate);

    printf("Enter loan tenure (in years): ");
    scanf("%f", &loan_tenure);

    // Calculating monthly payment
    interest_rate = interest_rate / 100.0;
    monthly_interest = interest_rate / 12.0;
    no_of_payments = loan_tenure * 12.0;

    monthly_payment = (principal * monthly_interest) / (1 - pow(1 + monthly_interest, -no_of_payments));

    printf("\nMonthly Payment: $%.2f\n", monthly_payment);
    
    //Calculating interest
    total_interest = monthly_payment * no_of_payments - principal;
    printf("Total Interest: $%.2f\n", total_interest);

    return 0;
}