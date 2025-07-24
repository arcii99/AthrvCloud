//FormAI DATASET v1.0 Category: Mortgage Calculator ; Style: single-threaded
#include <stdio.h>
#include <math.h>

#define MONTHS_IN_YEAR 12
#define DECIMAL_POINT_PRECISION 2

float get_monthly_payment(float principal, float interest_rate, int payment_term_in_years) {
    float monthly_interest_rate = interest_rate / 100 / MONTHS_IN_YEAR;
    int total_payments = payment_term_in_years * MONTHS_IN_YEAR;
    float numerator = principal * monthly_interest_rate * powf((1 + monthly_interest_rate), total_payments);
    float denominator = powf((1 + monthly_interest_rate), total_payments) - 1;
    float monthly_payment = numerator / denominator;
    return monthly_payment;
}

int main() {
    float principal, interest_rate;
    int payment_term_in_years;

    printf("MORTGAGE CALCULATOR\n");
    printf("-------------------\n");
    printf("Enter principal amount: ");
    scanf("%f", &principal);
    printf("Enter annual interest rate (in %%): ");
    scanf("%f", &interest_rate);
    printf("Enter payment term (in years): ");
    scanf("%d", &payment_term_in_years);

    float monthly_payment = get_monthly_payment(principal, interest_rate, payment_term_in_years);
    printf("\n\nRESULT:\n");
    printf("Monthly Payment: $%.2f\n", monthly_payment);

    return 0;
}