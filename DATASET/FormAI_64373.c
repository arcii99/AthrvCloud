//FormAI DATASET v1.0 Category: Mortgage Calculator ; Style: scalable
#include <stdio.h>
#include <math.h>

// Function to calculate monthly payment
double calculateMonthlyPayment(double amount, double interestRate, int loanTerm) {
  double monthlyInterestRate = (interestRate / 100) / 12;
  int numberOfPayments = loanTerm * 12;
  
  double monthlyPayment = amount * monthlyInterestRate / (1 - pow(1 + monthlyInterestRate, -numberOfPayments));
  
  return monthlyPayment;
}

int main() {
  double amount, interestRate, monthlyPayment;
  int loanTerm;

  printf("Enter loan amount: ");
  scanf("%lf", &amount);

  printf("Enter interest rate: ");
  scanf("%lf", &interestRate);

  printf("Enter loan term (in years): ");
  scanf("%d", &loanTerm);

  monthlyPayment = calculateMonthlyPayment(amount, interestRate, loanTerm);

  printf("\nLoan amount: $%.2lf\n", amount);
  printf("Interest rate: %.2lf%%\n", interestRate);
  printf("Loan term: %d years\n", loanTerm);
  printf("Monthly payment: $%.2lf\n", monthlyPayment);

  return 0;
}