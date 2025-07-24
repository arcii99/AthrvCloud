//FormAI DATASET v1.0 Category: Mortgage Calculator ; Style: portable
#include <stdio.h>

int main() {
  float loanAmount, interestRate, payment;
  int numYears, numPayments;
 
  printf("Enter the loan amount: ");
  scanf("%f", &loanAmount);

  printf("Enter the interest rate: ");
  scanf("%f", &interestRate);

  printf("Enter the number of years: ");
  scanf("%d", &numYears);

  numPayments = numYears * 12;
  interestRate = interestRate / 100 / 12;

  payment = (loanAmount * interestRate) / (1 - pow(1 + interestRate, -numPayments));

  printf("Loan amount: $%.2f\n", loanAmount);
  printf("Interest rate: %.2f%%\n", interestRate * 100 * 12);
  printf("Number of payments: %d\n", numPayments);
  printf("Monthly payment: $%.2f\n", payment);

  return 0;
}