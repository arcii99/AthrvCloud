//FormAI DATASET v1.0 Category: Mortgage Calculator ; Style: immersive
#include <stdio.h>

int main() {
    float principalAmount, annualInterestRate, monthlyInterestRate, monthlyPayment, totalPayment, remainingBalance;
    int numberOfYears, numberOfMonths, userInput;

    printf("Welcome to the Mortgage Calculator!\n");

    do {
        printf("\nEnter the Principal Amount: ");
        scanf("%f", &principalAmount); 
      
        printf("Enter the Annual Interest Rate (in percentage): ");
        scanf("%f", &annualInterestRate);
        monthlyInterestRate = (annualInterestRate / 100) / 12;
      
        printf("\nEnter the Number of Years: ");
        scanf("%d", &numberOfYears);
        numberOfMonths = numberOfYears * 12;

        monthlyPayment = (principalAmount * monthlyInterestRate * pow(1 + monthlyInterestRate, numberOfMonths)) / (pow(1 + monthlyInterestRate, numberOfMonths) - 1);
      
        totalPayment = monthlyPayment * numberOfMonths;
      
        printf("\nMonthly Payment: $%.2f\n", monthlyPayment);
        printf("Total Payment: $%.2f\n", totalPayment);

        printf("\nWould you like to calculate for another Mortgage? (1-Yes/0-No): ");
        scanf("%d", &userInput);
    } while (userInput == 1);

    printf("\nThank you for using the Mortgage Calculator!\n");
    return 0;
}