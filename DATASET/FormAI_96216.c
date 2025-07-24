//FormAI DATASET v1.0 Category: Mortgage Calculator ; Style: shocked
#include <stdio.h>

int main() {
  float principal, rate, mRate, nPayments, monthlyPay, totalInterest, totalCost;

  printf("Welcome to the Fun Mortgage Calculator!\n");
  printf("Enter Principal Amount ($): ");
  scanf("%f", &principal);

  printf("Enter Interest Rate (%% per annum): ");
  scanf("%f", &rate);
  mRate = rate / 1200;

  printf("Enter Number of Payments (months): ");
  scanf("%f", &nPayments);

  monthlyPay = principal * mRate / (1 - 1 / (pow(1 + mRate, nPayments)));
  totalCost = monthlyPay * nPayments;
  totalInterest = totalCost - principal;
  
  printf("\n\n");
  printf("=================== BOOM! ===================\n");
  printf("Your monthly payment for this mortgage is: $%.2f\n", monthlyPay);
  printf("Total cost of the mortgage (principal + interest) is: $%.2f\n", totalCost);
  printf("Total interest paid on the mortgage is: $%.2f\n", totalInterest);
  printf("==============================================\n");

  return 0;
}