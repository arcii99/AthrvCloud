//FormAI DATASET v1.0 Category: Mortgage Calculator ; Style: high level of detail
#include <stdio.h>
#include <math.h>

int main() {
    double principal, interest_rate, monthly_payment, month_payment, total_interest;
    int N, i;

    printf("Enter the principal amount: ");
    scanf("%lf", &principal);

    printf("Enter the interest rate: ");
    scanf("%lf", &interest_rate);

    printf("Enter the number of years: ");
    scanf("%d", &N);

    interest_rate = interest_rate / 1200.0;
    N = N * 12;
    total_interest = 0;

    monthly_payment = principal * interest_rate / (1 - pow(1 + interest_rate, -N));
    printf("Your monthly payment is: %.2lf \n", monthly_payment);

    printf("Month\t Payment\t\t Interest\t\t Principal\t\t Balance\n");

    for (i = 1; i <= N; i++) {
        interest_rate = principal * interest_rate;
        month_payment = monthly_payment - interest_rate;
        principal = principal - month_payment;
        total_interest = total_interest + interest_rate;

        if (i % 12 == 0) {
            printf("%d\t $%.2lf\t $%.2lf\t\t $%.2lf\t\t $%.2lf\n", 
            i/12, monthly_payment, total_interest, principal + month_payment, principal);
            total_interest = 0;
        }
    }

    return 0;
}