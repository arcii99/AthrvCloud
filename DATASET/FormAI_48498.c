//FormAI DATASET v1.0 Category: Mortgage Calculator ; Style: post-apocalyptic
#include <stdio.h>

int main() {
    printf("Greetings survivor, welcome to the Mortgage Calculator.\n");
    printf("Please enter the amount of your loan: ");

    float loanAmount;
    scanf("%f", &loanAmount);
    while (loanAmount <= 0) {
        printf("Invalid input. Loan amount must be greater than 0. Please enter a valid amount: ");
        scanf("%f", &loanAmount);
    }

    printf("Please enter the interest rate: ");
    float interestRate;
    scanf("%f", &interestRate);
    while (interestRate < 0 || interestRate > 100) {
        printf("Invalid input. Interest rate must be between 0 and 100. Please enter a valid rate: ");
        scanf("%f", &interestRate);
    }

    printf("Please enter the number of years for the loan: ");
    int numYears;
    scanf("%d", &numYears);
    while (numYears <= 0) {
        printf("Invalid input. Number of years must be greater than 0. Please enter a valid number: ");
        scanf("%d", &numYears);
    }

    float monthlyRate = interestRate / 1200; // convert annual rate to monthly
    int numPayments = numYears * 12; // convert years to months
    float powerFactor = powf(1 + monthlyRate, numPayments);
    float monthlyPayment = loanAmount * monthlyRate * powerFactor / (powerFactor - 1);

    printf("Your monthly payment is: $%.2f\n", monthlyPayment);

    printf("Oh no, looks like we ran out of paper to print your payment schedule.\n");
    printf("Don't worry, we'll just have to do this the old fashioned way.\n");

    printf("You will make %d payments of $%.2f over the next %d years.\n", numPayments, monthlyPayment, numYears);

    float totalInterest = monthlyPayment * numPayments - loanAmount;
    printf("You will pay a total of $%.2f in interest over the life of the loan.\n", totalInterest);

    printf("Take care and good luck out there.\n");

    return 0;
}