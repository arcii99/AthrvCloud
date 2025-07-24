//FormAI DATASET v1.0 Category: Mortgage Calculator ; Style: decentralized
#include <stdio.h>

int main() {
  float principal, yearlyRate, monthlyRate, period, monthlyPayments, totalPayments, totalInterest;
  printf("Enter the principal amount: $");
  scanf("%f", &principal);
  printf("Enter the yearly interest rate: ");
  scanf("%f", &yearlyRate);
  yearlyRate /= 100.0;
  monthlyRate = yearlyRate / 12.0;
  printf("Enter the mortgage period in years: ");
  scanf("%f", &period);
  period *= 12.0;
  monthlyPayments = (principal * pow(1 + monthlyRate, period) * monthlyRate) / (pow(1 + monthlyRate, period) - 1);
  totalPayments = monthlyPayments * period;
  totalInterest = totalPayments - principal;
  printf("---------------------------------------\n");
  printf("Mortgage Calculator\n\n");
  printf("Principal amount        : $%.2f\n", principal);
  printf("Yearly interest rate   : %.2f%%\n", yearlyRate * 100.0);
  printf("Mortgage period in years: %.2f years\n", period / 12.0);
  printf("---------------------------------------\n");
  printf("Monthly payment         : $%.2f\n", monthlyPayments);
  printf("Total payments          : $%.2f\n", totalPayments);
  printf("Total interest          : $%.2f\n", totalInterest);
  printf("---------------------------------------\n");
  return 0;
}