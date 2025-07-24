//FormAI DATASET v1.0 Category: Mortgage Calculator ; Style: visionary
#include <stdio.h>
#include <math.h>

int main() {
    // Variables for principal, interest rate, period
    double principal, interest_rate, period_years;
    int periods_per_year;
    
    // Get input values from user
    printf("Enter principal amount in dollars: ");
    scanf("%lf", &principal);

    printf("Enter interest rate in percentage: ");
    scanf("%lf", &interest_rate);

    printf("Enter period in years: ");
    scanf("%lf", &period_years);

    printf("Enter periods per year: ");
    scanf("%d", &periods_per_year);

    // Calculate mortgage payment
    double r = interest_rate / 100 / periods_per_year;
    double n = period_years * periods_per_year;
    double mortgage_payment = (principal * r * pow((1 + r), n)) / (pow((1 + r), n) - 1);

    // Output monthly mortgage payment
    printf("\n");
    printf("Monthly mortgage payment: $%.2f\n", mortgage_payment);
    printf("\n");

    // Output amortization table
    double remaining_principal = principal;
    double total_interest_paid = 0;

    printf("Amortization table:\n");
    printf("Month\t\tPayment\t\tInterest\tPrincipal\tBalance\n");
    for (int i = 1; i <= n; i++) {
        // Calculate interest paid
        double interest_paid = remaining_principal * r;
        total_interest_paid += interest_paid;

        // Calculate principal paid
        double principal_paid = mortgage_payment - interest_paid;

        // Calculate remaining balance
        remaining_principal -= principal_paid;

        // Output row of amortization table
        printf("%d\t\t$%.2f\t\t$%.2f\t\t$%.2f\t\t$%.2f\n", i, mortgage_payment, interest_paid, principal_paid, remaining_principal);

        // Check if mortgage has been fully paid off
        if (remaining_principal <= 0) {
            printf("Mortgage fully paid off in %d months\n", i);
            break;
        }
    }

    // Output total mortgage cost
    double total_mortgage_cost = principal + total_interest_paid;
    printf("\n");
    printf("Total mortgage cost: $%.2f\n", total_mortgage_cost);

    return 0;
}