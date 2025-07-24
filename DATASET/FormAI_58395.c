//FormAI DATASET v1.0 Category: Mortgage Calculator ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main() {

    double principal, interest_rate, payments_per_year, total_years, mortgage_payment;
    double monthly_interest_rate, total_payments, total_interest_paid, principal_paid;
    int option;

    while (1) {
        printf("Shape shifting Mortgage Calculator\n");
        printf("Please select an option:\n");
        printf("1- Calculate mortgage payment\n");
        printf("2- Calculate total payments and total interest paid\n");
        printf("3- Exit\n");
        scanf("%d", &option);

        switch (option) {

            case 1:
                printf("Enter the principal amount (in dollars): ");
                scanf("%lf", &principal);
                printf("Enter the interest rate (in percentage): ");
                scanf("%lf", &interest_rate);
                printf("Enter the number of payments per year: ");
                scanf("%lf", &payments_per_year);
                printf("Enter the total number of years: ");
                scanf("%lf", &total_years);

                monthly_interest_rate = interest_rate / (100 * payments_per_year);
                total_payments = payments_per_year * total_years;
                mortgage_payment = (principal * monthly_interest_rate) / (1 - pow(1 + monthly_interest_rate, -total_payments));

                printf("The monthly mortgage payment is: $%.2lf\n", mortgage_payment);
                break;

            case 2:
                printf("Enter the principal amount (in dollars): ");
                scanf("%lf", &principal);
                printf("Enter the interest rate (in percentage): ");
                scanf("%lf", &interest_rate);
                printf("Enter the number of payments per year: ");
                scanf("%lf", &payments_per_year);
                printf("Enter the total number of years: ");
                scanf("%lf", &total_years);

                monthly_interest_rate = interest_rate / (100 * payments_per_year);
                total_payments = payments_per_year * total_years;
                mortgage_payment = (principal * monthly_interest_rate) / (1 - pow(1 + monthly_interest_rate, -total_payments));
                total_interest_paid = mortgage_payment * total_payments - principal;
                principal_paid = mortgage_payment * total_payments - total_interest_paid;

                printf("The total payments made will be: $%.2lf\n", mortgage_payment * total_payments);
                printf("The total interest paid will be: $%.2lf\n", total_interest_paid);
                printf("The principal paid will be: $%.2lf\n", principal_paid);
                break;

            case 3:
                printf("Exiting Shape shifting Mortgage Calculator!\n");
                exit(1);

            default:
                printf("Invalid choice, try again\n");
        }
    }
    return 0;
}