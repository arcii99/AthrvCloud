//FormAI DATASET v1.0 Category: Mortgage Calculator ; Style: protected
#include <stdio.h>

int main()
{
    float loanAmount, interestRate, monthlyPayment, remainingAmount;
    int numPayments, monthCount;

    printf("Welcome to Mortgage Calculator!\n\n");
    
    printf("Enter loan amount: $");
    scanf("%f", &loanAmount);

    printf("Enter number of payments: ");
    scanf("%d", &numPayments);

    printf("Enter annual interest rate: ");
    scanf("%f", &interestRate);

    // Calculate monthly interest rate
    float monthlyInterestRate = interestRate / 1200;

    // Calculate monthly payment
    monthlyPayment = (loanAmount * monthlyInterestRate) / 
                     (1 - pow(1 + monthlyInterestRate, -numPayments));

    // Display monthly payment
    printf("\nYour monthly payment will be: $%.2f\n", monthlyPayment);

    // Start payment schedule
    printf("Payment Schedule:\n");

    // Initialize remaining amount to loan amount
    remainingAmount = loanAmount;

    // Loop through each month to display payment schedule
    for(monthCount = 1; monthCount <= numPayments; monthCount++)
    {
        // Calculate interest payment for each month
        float interestPayment = remainingAmount * monthlyInterestRate;

        // Calculate principal payment for each month
        float principalPayment = monthlyPayment - interestPayment;

        // Calculate remaining balance
        remainingAmount -= principalPayment;

        // Display payment schedule for this month
        printf("Month %d: $%.2f | $%.2f | $%.2f\n", monthCount, 
               interestPayment, principalPayment, remainingAmount);

        // Check if loan is fully paid off
        if(remainingAmount == 0)
        {
            printf("\nCongratulations! You have paid off your loan!\n");
            break;
        }
    }

    printf("\nThank you for using Mortgage Calculator.");

    return 0;
}