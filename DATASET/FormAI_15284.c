//FormAI DATASET v1.0 Category: Mortgage Calculator ; Style: careful
#include <stdio.h>
#include <math.h>

int main() {

    double principal, rate, term, monthly, total, interest;
    int years;

    printf("Enter Loan Principal: ");
    scanf("%lf", &principal);

    printf("Enter Annual Interest Rate: ");
    scanf("%lf", &rate);

    printf("Enter Loan Term (in years): ");
    scanf("%d", &years);

    rate /= 1200; // monthly interest rate
    term = years * 12; // number of months

    // calculate monthly payment
    monthly = principal * rate * pow(1 + rate, term) / (pow(1 + rate, term) - 1);
    
    // calculate total payment
    total = monthly * term;

    // calculate total interest
    interest = total - principal;

    printf("\n----------------------------------\n");
    printf("Loan Amount: $%.2lf\n", principal);
    printf("Interest Rate (Annual): %.2lf%%\n", rate * 1200);
    printf("Loan Term: %d years\n", years);
    printf("----------------------------------\n");
    printf("Monthly Payment: $%.2lf\n", monthly);
    printf("Total Payment: $%.2lf\n", total);
    printf("Total Interest: $%.2lf\n", interest);
    printf("----------------------------------\n");

    return 0;
}