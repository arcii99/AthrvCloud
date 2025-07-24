//FormAI DATASET v1.0 Category: Mortgage Calculator ; Style: creative
#include <stdio.h>
#include <math.h>

int main() {
    double principal, rate, period, emi;
    printf("Enter the Loan Amount: ");
    scanf("%lf", &principal);
    printf("Enter the Interest Rate: ");
    scanf("%lf", &rate);
    printf("Enter the Loan Period in Months: ");
    scanf("%lf", &period);

    if (rate > 100 || rate < 0) {
        printf("Invalid Interest Rate\n");
        return 0;
    }

    if (period <= 0) {
        printf("Invalid Loan Period\n");
        return 0;
    }

    rate /= 1200.0;
    emi = principal * rate * pow(1 + rate, period) / (pow(1 + rate, period) - 1);

    printf("\n\nLoan Amount: %.2lf\n", principal);
    printf("Interest Rate: %.2lf%%\n", rate * 1200.0);
    printf("Loan Period (in months): %.2lf\n", period);
    printf("EMI: %.2lf\n", emi);

    printf("\n\n==============================\n\n");

    double total_interest = emi * period - principal;
    printf("Total Interest: %.2lf\n", total_interest);
    printf("Total Payment (principal + interest): %.2lf\n", emi * period);
    printf("Total Saving (by paying extra Rs. 1000 per month): \n");

    double new_emi = principal * rate * pow(1 + rate, period) / (pow(1 + rate, period) - 1);
    double new_total_interest = new_emi * period - principal;
    double extra_payment = 1000.0;
    double extra_period = -log10(1 - (new_emi + extra_payment) / (principal * rate)) / log10(1 + rate);
    double total_payment = new_emi * extra_period + extra_payment * (extra_period + 1) / 2 + principal;
    double total_saving = total_payment - emi * period;
    printf("%.2lf months - Rs. %.2lf\n", extra_period, total_saving);

    return 0;
}