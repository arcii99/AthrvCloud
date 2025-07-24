//FormAI DATASET v1.0 Category: Mortgage Calculator ; Style: scientific
#include <stdio.h>
#include <math.h>

int main(void) {
  double loanAmount = 0, annualInterest = 0, monthlyInterest = 0, monthlyPayment = 0;
  int numPayments = 0;

  // Asking user to input loan amount, annual interest rate and number of payments
  printf("Enter loan amount: ");
  scanf("%lf", &loanAmount);

  printf("Enter annual interest rate (as a decimal): ");
  scanf("%lf", &annualInterest);

  printf("Enter number of payments: ");
  scanf("%d", &numPayments);

  // Converting annual interest rate into monthly interest rate
  monthlyInterest = (annualInterest / 12);

  // Calculating monthly payment
  monthlyPayment = (loanAmount*monthlyInterest) / (1 - pow( (1 + monthlyInterest), -numPayments));

  // Printing out the monthly payment
  printf("\nYour monthly payment is $%.2f\n", monthlyPayment);

  return 0;
}