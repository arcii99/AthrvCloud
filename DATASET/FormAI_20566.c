//FormAI DATASET v1.0 Category: Mortgage Calculator ; Style: excited
#include <stdio.h>
#include <math.h>

int main() {
    float principle_amount, interest_rate, term_in_years, monthly_payment;
    int number_of_payments;

    printf("Welcome to the Mortgage Calculator Program!\n");
    printf("Please enter the Principle Amount: ");
    scanf("%f", &principle_amount);

    printf("Great! Now enter the Interest Rate (in percentage): ");
    scanf("%f", &interest_rate);

    printf("Almost there! Now enter the Term of the loan (in years): ");
    scanf("%f", &term_in_years);

    printf("\nCalculating...\n\n");

    interest_rate /= 100.0;
    number_of_payments = term_in_years * 12;
    monthly_payment = (principle_amount * (interest_rate/12)) / (1 - pow(1+(interest_rate/12), -number_of_payments));
    printf("Your monthly payment will be: $%.2f\n", monthly_payment);
    
    printf("That's it! Thank you for using Mortgage Calculator Program");
    return 0;
}