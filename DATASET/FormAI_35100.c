//FormAI DATASET v1.0 Category: Mortgage Calculator ; Style: complete
#include <stdio.h>
#include <math.h>

int main() {

    double loan_amount, interest_rate, monthly_payment, balance;
    int term, months_passed, payments_per_year;

    printf("Welcome to the Mortgage Calculator!\n\n");

    printf("Please enter the loan amount: ");
    scanf("%lf", &loan_amount);

    printf("Please enter the interest rate percentage: ");
    scanf("%lf", &interest_rate);

    printf("Please enter the term (in years): ");
    scanf("%d", &term);

    printf("Please enter the number of payments per year: ");
    scanf("%d", &payments_per_year);

    printf("\n");

    // Calculate the monthly interest rate
    double monthly_rate = interest_rate / (12 * 100);

    // Calculate the total number of payments
    int num_payments = term * payments_per_year;

    // Calculate the monthly payment amount
    double num = pow((1 + monthly_rate), num_payments);
    double monthly_payment_top = loan_amount * monthly_rate * num;
    double monthly_payment_bottom = num - 1;
    monthly_payment = monthly_payment_top / monthly_payment_bottom;

    // Display the monthly payment amount
    printf("Your monthly payment will be: $%.2lf\n\n", monthly_payment);

    printf("Would you like to see a payment schedule for the loan? (Y/N): ");
    char answer;
    scanf(" %c", &answer);

    printf("\n");

    // Display a payment schedule if requested
    if (answer == 'Y' || answer == 'y') {

        balance = loan_amount;
        months_passed = 0;

        printf("Month\t\tBalance\n");

        while (balance > 0) {

            months_passed += 1;

            // Calculate the interest and principal portion of the payment
            double interest_payment = balance * monthly_rate;
            double principal_payment = monthly_payment - interest_payment;

            // Ensure balance is not negative
            if (balance < principal_payment) {
                principal_payment = balance;
                monthly_payment = interest_payment + principal_payment;
            }

            balance -= principal_payment;

            // Display the monthly payment and the updated balance
            printf("%d\t\t$%.2lf\n", months_passed, balance);

        }

        printf("\nCongratulations, you have paid off the loan in %d months!\n", months_passed);

    }

    return 0;

}