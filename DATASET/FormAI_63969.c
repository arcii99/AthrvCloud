//FormAI DATASET v1.0 Category: Mortgage Calculator ; Style: random
#include<stdio.h>
#include<math.h>

//Function to calculate mortgage payment
float calculateMortgagePayment(float principal, float interestRate, int numberOfYears){
    float monthlyInterestRate = interestRate / (12 * 100);
    int numberOfMonths = numberOfYears * 12;
    float monthlyPayment = (principal * monthlyInterestRate) / (1 - (1 / pow(1 + monthlyInterestRate, numberOfMonths)));
    return monthlyPayment;
}

//Function to display the results
void displayResults(float principal, float interestRate, int numberOfYears, float monthlyPayment){
    printf("Loan Amount: %.2f\n", principal);
    printf("Interest Rate: %0.2f%%\n", interestRate);
    printf("Number of Years: %d\n", numberOfYears);
    printf("Monthly Payment: $%.2f\n", monthlyPayment);
}

int main(){
    float principal, interestRate, monthlyPayment;
    int numberOfYears;

    printf("Welcome to the Mortgage Calculator\n\n");

    //Get the loan amount
    printf("Enter the Loan Amount: ");
    scanf("%f", &principal);

    //Get the interest rate
    printf("Enter the Interest Rate: ");
    scanf("%f", &interestRate);

    //Get the number of years
    printf("Enter the Number of Years: ");
    scanf("%d", &numberOfYears);

    //Call the calculateMortgagePayment function to calculate the monthly payment
    monthlyPayment = calculateMortgagePayment(principal, interestRate, numberOfYears);

    //Display the results
    displayResults(principal, interestRate, numberOfYears, monthlyPayment);

    return 0;
}