//FormAI DATASET v1.0 Category: Mortgage Calculator ; Style: interoperable
#include<stdio.h>

int main() {
    int amount;
    float interest_rate, monthly_payment, total_interest, total_payment;
    int years, months, total_months;

    printf("Enter the amount of loan: ");
    scanf("%d", &amount);

    printf("Enter the interest rate (in percentage): ");
    scanf("%f", &interest_rate);

    printf("Enter the number of years: ");
    scanf("%d", &years);

    total_months = years * 12;

    monthly_payment = amount / total_months;

    float monthly_interest_rate = interest_rate / 1200;

    total_interest = 0;
    total_payment = 0;

    printf("Month    Payment     Interest    Principal   Remaining balance\n");
    for (int i = 1; i <= total_months; i++) {
        float interest = (amount * monthly_interest_rate);
        float principal = monthly_payment - interest;
        amount -= principal;
        total_payment += monthly_payment;
        total_interest += interest;
        printf("%d\t$%.2f\t   $%.2f\t    $%.2f\t       $%.2f\n", i, monthly_payment, interest, principal, amount);
    }

    printf("Total Interest Paid: $%.2f\n", total_interest);
    printf("Total Payment: $%.2f\n", total_payment);
}