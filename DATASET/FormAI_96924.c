//FormAI DATASET v1.0 Category: Mortgage Calculator ; Style: ultraprecise
#include <stdio.h>
#include <math.h>

int main() {
    double principal, rate, time, emi, total_interest, total_payment, month_rate;
    int num_months;

    printf("Enter the principal amount: ");
    scanf("%lf", &principal);
    printf("Enter the rate of interest per annum: ");
    scanf("%lf", &rate);
    printf("Enter the time period in years: ");
    scanf("%lf", &time);

    month_rate = rate / 1200; // Monthly rate calculation
    num_months = time * 12; // Number of months calculation

    emi = (principal * month_rate * pow(1 + month_rate, num_months)) / (pow(1 + month_rate, num_months) - 1);
    total_payment = emi * num_months;
    total_interest = total_payment - principal;

    printf("\nMonthly EMI: $%.2f\n", emi);
    printf("Total Payment: $%.2f\n", total_payment);
    printf("Total Interest: $%.2f\n", total_interest);

    return 0;
}