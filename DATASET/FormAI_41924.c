//FormAI DATASET v1.0 Category: Mortgage Calculator ; Style: automated
#include<stdio.h>

int main() {
    float principal, interest_rate, monthly_rate, period, loan_amount, monthly_payment, total_payment, interest_paid, balance;
    
    printf("Enter Principal Amount: ");
    scanf("%f", &principal);

    printf("Enter interest rate: ");
    scanf("%f", &interest_rate);

    printf("Enter loan period in years: ");
    scanf("%f", &period);

    // Converting Years to Months     
    period = period * 12;

    monthly_rate = interest_rate / (12*100);

    // Calculation of Loan Amount
    loan_amount = (monthly_rate * principal) / (1 - pow(1 + monthly_rate, -period));

    // Calculation of Monthly Payment
    monthly_payment = loan_amount * monthly_rate;

    printf("\n");

    printf("Loan Amount: %.2f", loan_amount);

    printf("\n");

    printf("Monthly Payment: %.2f", monthly_payment);

    printf("\n");

    // Calculation of Total Payment
    total_payment = monthly_payment * period;

    printf("Total Payment: %.2f", total_payment);

    printf("\n");

    // Interest Paid
    interest_paid = total_payment - principal;

    printf("Total Interest Paid: %.2f", interest_paid);

    printf("\n");

    // Amortization Schedule
    printf("\n");

    printf("\t\t\tAmortization Schedule");

    printf("\n");

    printf("-----------------------------------------------------");

    printf("\n");

    printf("Payment\tPrincipal\tInterest\tBalance");

    printf("\n");

    printf("-----------------------------------------------------");

    printf("\n");

    balance = principal;

    for(int i = 1; i <= period; i++) {

        // Calculation of Interest
        float interest = balance * monthly_rate;

        // Calculation of Principal Amount
        float principal = monthly_payment - interest;

        // Calculation of Balance
        balance = balance - principal;

        printf("%d\t%.2f\t\t%.2f\t\t%.2f", i, principal, interest, balance);

        printf("\n");

    }

    return 0;

}