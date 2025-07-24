//FormAI DATASET v1.0 Category: Mortgage Calculator ; Style: inquisitive
#include <stdio.h>

int main() {
  double loanAmount, interestRate, monthlyPayment, totalInterest;
  int loanDuration, numPayments;

  // Prompt for loan amount
  printf("What's the loan amount? ");
  scanf("%lf", &loanAmount);

  // Prompt for interest rate
  printf("What's the interest rate per annum (in percentage)? ");
  scanf("%lf", &interestRate);

  // Prompt for loan duration in years
  printf("What's the loan duration (in years)? ");
  scanf("%d", &loanDuration);

  // Convert interest rate from percentage to decimal
  interestRate = interestRate / 100;

  // Compute the number of payments and monthly interest rate
  numPayments = loanDuration *12;
  double monthlyRate = interestRate / 12;

  // Compute the monthly payment using the mortgage formula
  monthlyPayment = (loanAmount * monthlyRate * pow(1 + monthlyRate, numPayments)) / (pow(1 + monthlyRate, numPayments) - 1);

  // Compute the total interest paid over the life of the loan
  totalInterest = (monthlyPayment * numPayments) - loanAmount;

  // Print out the results to the user
  printf("\n\nFor a loan amount of %.2f with an interest rate of %.2f percent per annum for a duration of %d years,\n", loanAmount, interestRate*100, loanDuration);
  printf("your monthly payment will be $%.2f and the total amount of interest paid over the life of the loan will be $%.2f.\n\n", monthlyPayment, totalInterest);

  return 0;
}