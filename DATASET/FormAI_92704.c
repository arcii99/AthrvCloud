//FormAI DATASET v1.0 Category: Mortgage Calculator ; Style: irregular
#include<stdio.h>

int main() {

  float principleAmount, interestRate, monthlyPayment, totalPayment, totalInterest;
  int paymentTerm, loanYears;

  printf("Welcome to Mortgage Calculator\n");

  printf("Please enter the principle amount (in USD):\n");
  scanf("%f", &principleAmount);

  printf("\nPlease enter the interest rate:\n");
  scanf("%f", &interestRate);

  printf("\nPlease enter the loan term (in years):\n");
  scanf("%d", &loanYears);

  paymentTerm = loanYears * 12;
  monthlyPayment = principleAmount * (interestRate / 12) * pow((1 + interestRate / 12), paymentTerm) / (pow((1 + interestRate / 12), paymentTerm) - 1);
  totalPayment = monthlyPayment * paymentTerm;
  totalInterest = totalPayment - principleAmount;

  printf("\n**************************************\n");
  printf("Mortgage Summary\n");
  printf("**************************************\n");
  printf("Principle Amount: $%.2f\n", principleAmount);
  printf("Interest Rate: %.2f%%\n", interestRate);
  printf("Loan Term: %d years\n", loanYears);
  printf("Monthly Payment: $%.2f\n", monthlyPayment);
  printf("Total Payment: $%.2f\n", totalPayment);
  printf("Total Interest: $%.2f\n", totalInterest);
  printf("**************************************\n");

  return 0;
}