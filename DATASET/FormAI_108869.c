//FormAI DATASET v1.0 Category: Mortgage Calculator ; Style: statistical
#include <stdio.h>
#include <math.h>

int main(void) 
{
    double principal, interest, duration, payment, total_interest, total_cost, interest_month, actual_principal;
  	int i;

    printf("Enter the principal amount of the loan: ");
    scanf("%lf", &principal);

    printf("Enter the annual interest rate: ");
    scanf("%lf", &interest);

    printf("Enter the duration of the loan in years: ");
    scanf("%lf", &duration);

    interest_month = interest / 1200; // Calculates monthly interest rate
    payment = (principal * interest_month) / (1 - pow(1 + interest_month, -12 * duration)); // Calculates monthly payment

    printf("\nMonthly Payment: $%.2f\n", payment);

    total_cost = payment * duration * 12; // Calculates total cost of loan
    total_interest = total_cost - principal; // Calculates total interest paid

    printf("Total Cost: $%.2f\n", total_cost);
    printf("Total Interest Paid: $%.2f\n", total_interest);

    printf("\nAmortization Table:\n");
    printf("Payment\tPrincipal\tInterest\tBalance\n");

    for(i = 1; i <= duration * 12; i++) {
        interest = principal * interest_month; // Calculates amount of interest
        actual_principal = payment - interest; // Calculates amount of principal paid
        principal -= actual_principal; // Calculates new principal balance

        printf("%d\t$%.2f\t\t$%.2f\t\t$%.2f\n", i, actual_principal, interest, principal);

        // Check if loan has been fully repaid
        if(principal <= 0) {
          printf("\nLoan has been fully repaid in %d months", i);
          break;
        }
    }

    return 0;
}