//FormAI DATASET v1.0 Category: Mortgage Calculator ; Style: mind-bending
#include <stdio.h>
#include <math.h>

int main() {
    printf("Welcome to the Mind-Bending Mortgage Calculator!\n");
    printf("Please enter the principal amount: ");

    double principal;
    scanf("%lf", &principal);

    printf("Please enter the interest rate (in percentage): ");

    double rate;
    scanf("%lf", &rate);

    rate /= 100;
    printf("Please enter the loan term (in years): ");

    int years;
    scanf("%d", &years);

    int months = years * 12;
    double monthly_rate = rate / 12;
    double monthly_payment = principal * (monthly_rate * pow((1 + monthly_rate), months) / (pow((1 + monthly_rate), months) - 1));

    printf("Calculating monthly payments...\n");
    printf("Your monthly payment is: $%.2lf\n", monthly_payment);

    printf("\nEnter the number of months you've already made payments for: ");
    int paid_months;
    scanf("%d", &paid_months);

    double interest_paid = 0;
    double principal_paid = 0;

    printf("\nPayment Schedule:\n\n");

    printf("| Month |  Payment | Interest | Principal |  Balance |\n");

    for(int i = 1; i <= months; i++) {
        double interest = principal * (rate / 12);
        double principal_contribution = monthly_payment - interest;
        principal_paid += principal_contribution;

        if(i <= paid_months) {
            interest_paid += interest;
            principal -= principal_contribution;
            continue;
        }

        interest_paid += interest;
        principal -= principal_contribution;

        printf("| %d    |  $%.2lf  |  $%.2lf  |  $%.2lf    |  $%.2lf  |\n", i, monthly_payment, interest, principal_contribution, principal);
    }

    printf("\nInterest paid so far: $%.2lf\n", interest_paid);
    printf("Principal paid so far: $%.2lf\n", principal_paid);
    printf("Total paid so far: $%.2lf\n", interest_paid + principal_paid);

    return 0;
}