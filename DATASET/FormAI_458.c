//FormAI DATASET v1.0 Category: Mortgage Calculator ; Style: visionary
#include <stdio.h>
#include <math.h>

int main()
{
    float principalAmount;
    float interestRate;
    int years;
    float monthlyPayment;
    float monthlyInterestRate;
    float numerator;
    float denominator;
    float finalNum;
    int i;

    // Take input from user
    printf("\nEnter the Principal Amount: ");
    scanf("%f", &principalAmount);
    printf("Enter the Interest Rate: ");
    scanf("%f", &interestRate);
    printf("Enter the Number of Years for Mortgage: ");
    scanf("%d", &years);

    // Calculate monthly interest rate
    monthlyInterestRate = (interestRate/100) / 12;

    // Calculate the numerator and denominator values
    numerator = monthlyInterestRate * pow(1 + monthlyInterestRate, years*12);
    denominator = pow(1 + monthlyInterestRate, years*12) - 1;

    // Calculate the final monthly payment
    finalNum = numerator / denominator;
    monthlyPayment = principalAmount * finalNum;

    // Print out the monthly payment
    printf("\nYour Monthly Payment is: $%.2f\n\nThe Amortization Table is as follows:\n", monthlyPayment);

    // Amortization Table
    float principalPaid, interestPaid, totalPaid;
    float balance = principalAmount;
    for (i=1; i<=years*12; i++) {
        // Calculate monthly payments
        interestPaid = balance * monthlyInterestRate;
        principalPaid = monthlyPayment - interestPaid;
        totalPaid = interestPaid + principalPaid;

        // Calculate balance
        balance -= principalPaid;

        // Print out the table
        printf("%2d     $%8.2f  $%8.2f  $%8.2f  $%8.2f\n", i, balance+principalPaid, interestPaid, principalPaid, totalPaid);
    }

    return 0;
}