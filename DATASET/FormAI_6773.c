//FormAI DATASET v1.0 Category: Mortgage Calculator ; Style: light-weight
#include <stdio.h>

int main() {
  float loanAmount, rate, monthlyPayment, totalPayment;
  int termInYears, termInMonths;

  printf("Enter loan amount: ");
  scanf("%f", &loanAmount);

  printf("Enter interest rate: ");
  scanf("%f", &rate);

  printf("Enter term (in years): ");
  scanf("%d", &termInYears);

  termInMonths = termInYears * 12;

  monthlyPayment = (loanAmount * rate / 1200) / (1 - (pow(1 + rate / 1200, -termInMonths)));
  totalPayment = monthlyPayment * termInMonths;

  printf("\nMonthly payment: $%.2f\n", monthlyPayment);
  printf("Total payment: $%.2f\n", totalPayment);

  return 0;
}