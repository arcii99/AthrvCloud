//FormAI DATASET v1.0 Category: Personal Finance Planner ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>

/* Function to calculate the monthly mortgage payment */
double monthly_mortgage_payment(double principle, double interest_rate, int tenure_years) {
    double interest_rate_monthly = interest_rate / (12 * 100);
    int tenure_months = tenure_years * 12;
    double numerator = principle * interest_rate_monthly;
    double denominator = 1 - pow((1 + interest_rate_monthly), - tenure_months);
    return numerator / denominator;
}

/* Function to calculate the monthly car loan payment */
double monthly_car_loan_payment(double principle, double interest_rate, int tenure_years) {
    double interest_rate_monthly = interest_rate / (12 * 100);
    int tenure_months = tenure_years * 12;
    double numerator = principle * interest_rate_monthly;
    double denominator = 1 - pow((1 + interest_rate_monthly), - tenure_months);
    return numerator / denominator;
}

/* Function to calculate the monthly utility bill expense */
double monthly_utility_bill(double electricity_charges, double gas_charges, double water_charges) {
    return electricity_charges + gas_charges + water_charges;
}

int main() {
    int choice;
    double principle, interest_rate;
    int tenure_years;
    double car_price, down_payment, car_interest_rate;
    double electricity_charges, gas_charges, water_charges;
    char more = 'y';

    printf("\nWelcome to Personal Finance Planner\n\n");

    /* Menu-driven program */
    while(more == 'y') {
        printf("Choose an option:\n");
        printf("1. Calculate monthly mortgage payment\n");
        printf("2. Calculate monthly car loan payment\n");
        printf("3. Calculate monthly utility bill expense\n");
        printf("Your choice: ");
        scanf("%d", &choice);

        /* Switch case for different options */
        switch(choice) {

            case 1:
                printf("\nEnter the principle amount: ");
                scanf("%lf", &principle);
                printf("Enter the interest rate (in percentage): ");
                scanf("%lf", &interest_rate);
                printf("Enter the tenure (in years): ");
                scanf("%d", &tenure_years);
                printf("\nThe monthly mortgage payment is: $%.2lf\n", monthly_mortgage_payment(principle, interest_rate, tenure_years));
                break;

            case 2:
                printf("\nEnter the car price: ");
                scanf("%lf", &car_price);
                printf("Enter the down payment: ");
                scanf("%lf", &down_payment);
                printf("Enter the interest rate (in percentage): ");
                scanf("%lf", &car_interest_rate);
                printf("Enter the tenure (in years): ");
                scanf("%d", &tenure_years);
                printf("\nThe monthly car loan payment is: $%.2lf\n", monthly_car_loan_payment(car_price - down_payment, car_interest_rate, tenure_years));
                break;

            case 3:
                printf("\nEnter the electricity bill charges: ");
                scanf("%lf", &electricity_charges);
                printf("Enter the gas bill charges: ");
                scanf("%lf", &gas_charges);
                printf("Enter the water bill charges: ");
                scanf("%lf", &water_charges);
                printf("\nThe monthly utility bill is: $%.2lf\n", monthly_utility_bill(electricity_charges, gas_charges, water_charges));
                break;

            default:
                printf("\nInvalid option!\n");
                break;
        }

        printf("\nDo you want to continue (y/n)? ");
        scanf(" %c", &more);
    }

    printf("\nGoodbye!\n");

    return 0;
}