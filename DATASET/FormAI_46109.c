//FormAI DATASET v1.0 Category: Mortgage Calculator ; Style: mind-bending
#include <stdio.h>
#include <math.h>

int main() {
    float principal, rate, payment, balance, interest, monthly_interest, monthly_principal, total_interest = 0;
    int months = 0;

    // Input
    printf("Enter the principal amount: ");
    scanf("%f", &principal);
    printf("Enter the interest rate (%% per year): ");
    scanf("%f", &rate);
    printf("Enter the monthly payment: ");
    scanf("%f", &payment);

    // Calculation
    monthly_interest = rate / 100 / 12;
    while (principal >= 0) {
        interest = principal * monthly_interest;
        monthly_principal = payment - interest;
        balance = principal - monthly_principal;
        if (balance < 0) {
            balance = 0;
            payment = interest + principal;
        }
        principal = balance;
        total_interest += interest;
        months++;
        printf("Month %d: Payment: %.2f, Interest: %.2f, Principal: %.2f, Balance: %.2f\n", months, payment, interest, monthly_principal, balance);
        if (balance == 0) {
            printf("Paid off in %d months\n", months);
            printf("Total interest paid: %.2f\n", total_interest);
            break;
        }
    }

    return 0;
}