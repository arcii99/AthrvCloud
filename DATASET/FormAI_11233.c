//FormAI DATASET v1.0 Category: Mortgage Calculator ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main() {
    float principal, rate, term, monthly_payment, total_payment;
    int choice;

    printf("------Mortgage Calculator------\n\n");
    printf("Enter the principal amount: ");
    scanf("%f", &principal);
    printf("Enter the annual interest rate: ");
    scanf("%f", &rate);
    printf("Enter the term in years: ");
    scanf("%f", &term);
    
    // Converting annual rate to monthly rate and term to number of months
    float monthly_rate = rate / 1200;
    int num_months = term * 12;

    printf("\nWhat would you like to calculate?\n");
    printf("1. Monthly Payment\n");
    printf("2. Total Payment\n");
    printf("Enter your choice (1 or 2): ");
    scanf("%d", &choice);

    switch(choice) {
        case 1:
            // Calculation for monthly payment
            monthly_payment = (principal * monthly_rate * pow(1 + monthly_rate, num_months)) / (pow(1 + monthly_rate, num_months) - 1);
            printf("\nYour monthly payment is: $%.2f\n", monthly_payment);
            break;
        case 2:
            // Calculation for total payment
            total_payment = (monthly_payment * num_months);
            printf("\nYour total payment over %d months is: $%.2f\n", num_months, total_payment);
            break;
        default:
            printf("\nInvalid choice. Please enter 1 or 2.\n");
            break;
    }

    return 0;
}