//FormAI DATASET v1.0 Category: Mortgage Calculator ; Style: careful
#include <stdio.h>

int main() {
    float loan, interest_rate, payment;
    int years;

    // user input
    printf("Enter the loan amount: ");
    scanf("%f", &loan);
    printf("Enter the interest rate: ");
    scanf("%f", &interest_rate);
    printf("Enter the number of years: ");
    scanf("%d", &years);

    // calculate monthly interest rate
    float monthly_rate = interest_rate / 1200;

    // calculate monthly payment
    payment = (loan * monthly_rate) / (1 - (pow((1 + monthly_rate), (-12*years))));

    // output
    printf("\n");
    printf("Loan amount: $%.2f\n", loan);
    printf("Interest rate: %.2f%%\n", interest_rate);
    printf("Years: %d\n", years);
    printf("Monthly payment: $%.2f\n", payment);

    return 0;
}