//FormAI DATASET v1.0 Category: Mortgage Calculator ; Style: shocked
#include <stdio.h>
#include <math.h>

int main() {
  float loanAmt, apr, monthlyRate, payment;
  int years, months, totalMonths;

  printf("Enter Loan Amount: ");
  scanf("%f", &loanAmt);

  printf("Enter APR: ");
  scanf("%f", &apr);

  printf("Enter Years: ");
  scanf("%d", &years);

  totalMonths = years * 12;
  monthlyRate = (apr / 100) / 12;
  payment = (loanAmt * monthlyRate * pow(1 + monthlyRate, totalMonths)) / (pow(1 + monthlyRate, totalMonths) - 1);

  printf("\nMortgage Payment: $%.2f\n", payment);

  return 0;
}