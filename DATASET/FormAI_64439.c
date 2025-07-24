//FormAI DATASET v1.0 Category: Mortgage Calculator ; Style: decentralized
/*
* Decentralized mortgage calculator program
* Calculates the monthly mortgage payments based on user input
*/

#include <stdio.h>
#include <math.h>

// Function to calculate the monthly payment
float calculateMonthlyPayment(float principle, float interestRate, int numYears, int numPaymentsPerYear)
{
    float monthlyInterestRate = interestRate / (numPaymentsPerYear * 100);
    int numPayments = numYears * numPaymentsPerYear;
    float numerator = monthlyInterestRate * pow(1 + monthlyInterestRate, numPayments);
    float denominator = pow(1 + monthlyInterestRate, numPayments) - 1;
    float monthlyPayment = principle * (numerator / denominator);

    return monthlyPayment;
}

int main()
{
    // User inputs
    float principle, interestRate;
    int numYears, numPaymentsPerYear;

    // Get user inputs
    printf("Enter the principle amount: ");
    scanf("%f", &principle);
    printf("Enter the interest rate: ");
    scanf("%f", &interestRate);
    printf("Enter the number of years: ");
    scanf("%d", &numYears);
    printf("Enter the number of payments per year: ");
    scanf("%d", &numPaymentsPerYear);

    // Calculate monthly payment
    float monthlyPayment = calculateMonthlyPayment(principle, interestRate, numYears, numPaymentsPerYear);

    // Display results
    printf("\n");
    printf("Principle amount: $%.2f\n", principle);
    printf("Interest rate: %.2f%%\n", interestRate);
    printf("Number of years: %d\n", numYears);
    printf("Number of payments per year: %d\n", numPaymentsPerYear);
    printf("Monthly payment: $%.2f\n", monthlyPayment);

    return 0;
}