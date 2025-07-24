//FormAI DATASET v1.0 Category: Mortgage Calculator ; Style: safe
#include <stdio.h>
#include <math.h>

int main() {
    double loan_amount, interest_rate, monthly_payment, principal, monthly_interest;
    int num_payments;

    printf("Enter the loan amount: ");
    scanf("%lf", &loan_amount);

    printf("Enter the interest rate: ");
    scanf("%lf", &interest_rate);

    printf("Enter the number of payments in months: ");
    scanf("%d", &num_payments);

    monthly_interest = interest_rate / 1200.0; //calculate monthly interest rate

    // Calculate monthly payment using the formula for mortgage payments
    monthly_payment = (loan_amount * monthly_interest) / (1.0 - pow(1.0 + monthly_interest, -num_payments));

    printf("\n");

    // Display the monthly mortgage payment
    printf("Your monthly mortgage payment is: $%.2lf\n", monthly_payment);

    printf("\n");

    printf("Would you like to calculate your remaining balance after a certain number of payments?\n");
    printf("Enter 'Y' for Yes or 'N' for No: ");

    char answer;
    scanf(" %c", &answer);

    if (answer == 'Y' || answer == 'y') {
        int num_payments_made;
        printf("Enter the number of payments you have already made: ");
        scanf("%d", &num_payments_made);

        // Calculate the remaining balance using the formula for the present value of an annuity
        principal = loan_amount * (pow(1 + monthly_interest, num_payments_made) - pow(1 + monthly_interest, num_payments))
                    / (pow(1 + monthly_interest, num_payments) - 1);

        printf("\n");

        // Display the remaining mortgage balance
        printf("Your remaining mortgage balance after %d payments is: $%.2lf\n", num_payments_made, principal);

        printf("\n");

    } else if (answer == 'N' || answer == 'n') {
        printf("Thank you for using the mortgage calculator.\n");

    } else {
        printf("Invalid input. Exiting program.\n");
    }

    return 0;
}