//FormAI DATASET v1.0 Category: Mortgage Calculator ; Style: Sherlock Holmes
#include <stdio.h>
#include <math.h>

int main() {
  double principal, interestRate, monthlyInterest, monthlyPayment;
  int numPayments;

  printf("Enter principal amount: ");
  scanf("%lf", &principal);
  printf("Enter annual interest rate: ");
  scanf("%lf", &interestRate);
  printf("Enter number of monthly payments: ");
  scanf("%d", &numPayments);

  // Convert annual interest rate to monthly interest rate
  monthlyInterest = interestRate / 1200.0;

  // Calculate monthly mortgage payment
  monthlyPayment = principal * monthlyInterest * pow(1 + monthlyInterest, numPayments)
                    / (pow(1 + monthlyInterest, numPayments) - 1);

  printf("Monthly mortgage payment: $%.2lf\n", monthlyPayment);
  return 0;
}