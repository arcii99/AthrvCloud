//FormAI DATASET v1.0 Category: Mortgage Calculator ; Style: lively
#include <stdio.h>
#include <math.h>

int main() {
  double loanAmount, interestRate, monthlyPayment;
  int loanTerm;

  // get user input
  printf("Welcome to the Mortgage Calculator!\n\n");

  printf("Enter the amount of your loan: ");
  scanf("%lf", &loanAmount);

  printf("Enter your interest rate (in percentage): ");
  scanf("%lf", &interestRate);

  printf("Enter the term of your loan (in years): ");
  scanf("%d", &loanTerm);

  // calculate monthly payment
  double monthlyInterestRate = (interestRate/100) / 12;
  double totalPayments = loanTerm * 12;
  double numerator = pow((1 + monthlyInterestRate), totalPayments);
  double denominator = numerator - 1;
  monthlyPayment = (loanAmount * monthlyInterestRate * numerator) / denominator;

  // print summary
  printf("\nMORTGAGE SUMMARY\n");
  printf("-----------------\n");
  printf("Loan Amount: $%.2f\n", loanAmount);
  printf("Interest Rate: %.2f%%\n", interestRate);
  printf("Loan Term: %d years\n", loanTerm);
  printf("Monthly Payment: $%.2f\n", monthlyPayment);

  printf("\n");

  return 0;
}