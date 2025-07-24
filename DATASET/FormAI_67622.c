//FormAI DATASET v1.0 Category: Mortgage Calculator ; Style: grateful
#include <stdio.h>

int main() {

    int principal;
    float rate, monthly_payment;
    int num_years;

    printf("Welcome to the Mortgage Calculator\n\n");

    // Get inputs from user
    printf("Enter the principal amount: \n");
    scanf("%d", &principal);

    printf("Enter the interest rate per year: \n");
    scanf("%f", &rate);

    printf("Enter the number of years for the mortgage: \n");
    scanf("%d", &num_years);

    // Calculate monthly payment
    float monthly_rate = rate / 1200;
    int num_payments = num_years * 12;

    monthly_payment = (principal * monthly_rate) / (1 - (pow(1 + monthly_rate, -num_payments)));

    // Output results to user
    printf("\n\nYour monthly payment will be $%.2f\n", monthly_payment);

    return 0;
}