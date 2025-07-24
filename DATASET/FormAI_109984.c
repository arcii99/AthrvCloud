//FormAI DATASET v1.0 Category: Mortgage Calculator ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// function for calculating mortgage payment
double calculate_mortgage(double principal, double interest_rate, double months) {
    double monthly_rate = (interest_rate / 100) / 12;
    double numerator = principal * monthly_rate * pow((1 + monthly_rate), months);
    double denominator = pow((1 + monthly_rate), months) - 1;
    return numerator / denominator;
}

int main() {
    double principal, interest_rate, years, mortgage_payment;
    int num_payments;
    printf("Enter the principal amount: ");
    scanf("%lf", &principal);
    printf("Enter the interest rate: ");
    scanf("%lf", &interest_rate);
    printf("Enter the number of years: ");
    scanf("%lf", &years);
    num_payments = years * 12;
    mortgage_payment = calculate_mortgage(principal, interest_rate, num_payments);
    printf("Your monthly mortgage payment is: $%.2lf\n", mortgage_payment);
    return 0;
}