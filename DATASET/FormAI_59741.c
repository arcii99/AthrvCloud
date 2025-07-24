//FormAI DATASET v1.0 Category: Mortgage Calculator ; Style: interoperable
#include <stdio.h>
#include <math.h>

int main() {
    float amount, rate, years, monthly_payment, total_interest;
    int n;

    printf("Enter the loan amount: ");
    scanf("%f", &amount);

    printf("Enter the interest rate (in percent): ");
    scanf("%f", &rate);

    printf("Enter the loan period (in years): ");
    scanf("%f", &years);

    printf("Enter the number of payments per year: ");
    scanf("%d", &n);

    rate = rate / 100;
    float r = rate / n;

    float np = n * years;
    float m_rate = r / (1 - pow(1 + r, -np));

    monthly_payment = m_rate * amount;
    total_interest = np * monthly_payment - amount;

    printf("\nLoan amount: $%.2f\n", amount);
    printf("Interest rate: %.2f%%\n", rate * 100);
    printf("Loan period: %.2f years\n", years);
    printf("Number of payments per year: %d\n", n);
    printf("Monthly payment: $%.2f\n", monthly_payment);
    printf("Total interest: $%.2f\n", total_interest);

    return 0;
}