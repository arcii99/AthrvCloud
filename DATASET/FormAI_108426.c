//FormAI DATASET v1.0 Category: Mortgage Calculator ; Style: portable
#include <stdio.h>
#include <math.h>

int main() {
    double principal, rate, time;
    int choice;

    printf("Welcome to Mortgage Calculator\n");

    while(1) {
        printf("\nChoose an option:\n");
        printf("1. Calculate Monthly Payment\n");
        printf("2. Calculate Total Payment\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");

        scanf("%d", &choice);

        if(choice == 3) {
            printf("\nThanks for using Mortgage Calculator!\n");
            break;
        }

        if(choice != 1 && choice != 2) {
            printf("\nInvalid choice! Please enter a valid option.\n");
            continue;
        }

        printf("\nEnter the principal amount: ");
        scanf("%lf", &principal);

        printf("Enter the interest rate (percentage per annum): ");
        scanf("%lf", &rate);

        printf("Enter the term of the loan (in years): ");
        scanf("%lf", &time);

        double monthly_rate = (rate / 100) / 12;
        double total_payments = time * 12;

        if(choice == 1) {
            double power = pow(1 + monthly_rate, total_payments);
            double monthly_payment = (principal * power * monthly_rate) / (power - 1);

            printf("\nMonthly Payment: $%.2lf\n", monthly_payment);
        } else {
            double total_amount = principal * pow(1 + monthly_rate, total_payments);
            printf("\nTotal Payment: $%.2lf\n", total_amount);
        }
    }

    return 0;
}