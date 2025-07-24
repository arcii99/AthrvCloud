//FormAI DATASET v1.0 Category: Mortgage Calculator ; Style: grateful
#include <stdio.h>
#include <math.h>

int main() {
    // Displaying gratitude message to the user
    printf("Welcome to our Mortgage Calculator program!\n");
    printf("We are grateful that you chose to use our service.\n");

    // Declaring variables for user input
    float loan_amount, interest_rate, monthly_payment;
    int loan_term;

    // Requesting user input
    printf("Please enter the loan amount: ");
    scanf("%f", &loan_amount);

    printf("Please enter the annual interest rate: ");
    scanf("%f", &interest_rate);

    printf("Please enter the loan term (in months): ");
    scanf("%d", &loan_term);

    // Calculating monthly interest rate
    float monthly_interest_rate = interest_rate / (12 * 100);

    // Calculating monthly payment
    monthly_payment = (loan_amount * monthly_interest_rate * pow(1 + monthly_interest_rate, loan_term)) / (pow(1 + monthly_interest_rate, loan_term) - 1);

    // Displaying the result to the user
    printf("\nThank you for using our Mortgage Calculator program!\n");
    printf("Your monthly payment is: $%.2f\n", monthly_payment);

    return 0;
}