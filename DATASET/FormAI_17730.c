//FormAI DATASET v1.0 Category: Mortgage Calculator ; Style: futuristic
#include <stdio.h>
#include <math.h>

int main()
{
    float P, r, t, m, total_payment, monthly_payment, interest_paid, principal_paid, balance;
    printf("Enter the principal amount: ");
    scanf("%f", &P);
    printf("Enter the annual interest rate (in percentage): ");
    scanf("%f", &r);
    printf("Enter the term of the mortgage (in years): ");
    scanf("%f", &t);
    printf("Enter the number of payments per year: ");
    scanf("%f", &m);
    
    // Calculating the monthly interest rate in decimal form
    r = r/1200;
    
    // Calculating the total number of payments
    float total_number_of_payments = t*m;
    
    // Calculating the monthly payment
    monthly_payment = P * (r * pow((1+r), total_number_of_payments)) / (pow((1+r), total_number_of_payments) - 1);
    
    // Calculating the total payment and interest paid
    total_payment = monthly_payment * total_number_of_payments;
    interest_paid = total_payment - P;
    
    printf("\n");
    printf("Monthly Payment: %.2f\n", monthly_payment);
    printf("Total Payment: %.2f\n", total_payment);
    printf("Total Interest Paid: %.2f\n", interest_paid);
    printf("\n");

    // Printing the amortization table
    printf("Amortization Table: \n");
    printf("\n");
    printf("Payment #\t Interest \t Principal \t Balance\n");
    
    balance = P;

    for(int i = 1; i <= total_number_of_payments; i++){
        float interest = balance * r;
        float principal = monthly_payment - interest;
        balance = balance - principal;
        
        interest_paid += interest;
        principal_paid += principal;
        
        printf("%d \t\t %.2f \t\t %.2f \t\t %.2f\n", i, interest, principal, balance);
    }
    return 0;
}