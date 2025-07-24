//FormAI DATASET v1.0 Category: Mortgage Calculator ; Style: configurable
#include <stdio.h>
#include <stdlib.h>

// Function to calculate mortgage payment
float calculate_mortgage(float principal, float interest_rate, int number_of_payments) {
    float monthly_interest_rate = interest_rate / 1200; // Convert annual interest rate to monthly interest rate
    float x = pow (1 + monthly_interest_rate, number_of_payments);
    float monthly_payment = (principal * x * monthly_interest_rate) / (x - 1);
    return monthly_payment;
}

int main() {
    float principal;
    float interest_rate;
    int number_of_years;
    int number_of_payments;
    char choice;

    do {
        system("clear");
        printf("-----------------MORTGAGE CALCULATOR-----------------\n");
        printf("Enter principal amount (in dollars): ");
        scanf("%f", &principal);
        printf("Enter interest rate (in percentage): ");
        scanf("%f", &interest_rate);
        printf("Enter number of years: ");
        scanf("%d", &number_of_years);
        number_of_payments = number_of_years * 12; // Convert years to months
        float monthly_payment = calculate_mortgage(principal, interest_rate, number_of_payments);
        printf("-------------------------------------------------------\n");
        printf("Monthly payment: %0.2f dollars\n", monthly_payment);
        printf("-------------------------------------------------------\n");
        printf("Would you like to calculate another mortgage? (y/n) ");
        scanf(" %c", &choice); // Space before %c is important to consume any leftover newline character
    } while (choice == 'y' || choice == 'Y');

    printf("Thank you for using Mortgage Calculator!\n");

    return 0;
}