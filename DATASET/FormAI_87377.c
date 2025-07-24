//FormAI DATASET v1.0 Category: Mortgage Calculator ; Style: enthusiastic
#include <stdio.h>

int main() {
  float loanAmount, interestRate, payment;
  int numYears;

  printf("Welcome to the Mortgage Calculator! \n\n");

  printf("Please enter the loan amount: $");
  scanf("%f", &loanAmount);

  printf("Please enter the interest rate (ex: 4.5): ");
  scanf("%f", &interestRate);

  printf("Please enter the number of years for the loan: ");
  scanf("%d", &numYears);

  interestRate /= 1200; // Monthly interest rate
  int numPayments = numYears * 12; // Total number of payments

  float numerator = interestRate * pow(1 + interestRate, numPayments);
  float denominator = pow(1 + interestRate, numPayments) - 1;
  float monthlyPayment = loanAmount * (numerator / denominator);

  printf("\n\n");

  printf("Loan amount: $%.2f\n", loanAmount);
  printf("Interest rate: %.2f%\n", interestRate * 100);
  printf("Number of years: %d\n", numYears);
  printf("Number of payments: %d\n", numPayments);
  printf("\n\n");

  printf("Your monthly payment will be: $%.2f\n", monthlyPayment);

  return 0;
}