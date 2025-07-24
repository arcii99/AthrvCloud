//FormAI DATASET v1.0 Category: Mortgage Calculator ; Style: authentic
#include <stdio.h>
#include <math.h>

int main() {
  double principal, rate, monthlyPayment, totalPayments, totalInterest;
  int years;

  printf("Enter the principal amount: ");
  scanf("%lf", &principal);

  printf("\nEnter the annual interest rate (as percentage): ");
  scanf("%lf", &rate);
  rate /= 100;

  printf("\nEnter the loan term in years: ");
  scanf("%d", &years);

  double monthlyRate = rate / 12;
  int months = years * 12;

  // Calculation of monthly payment
  monthlyPayment = (principal * monthlyRate) / (1 - pow(1 + monthlyRate, -months));

  // Calculation of total payments
  totalPayments = monthlyPayment * months;

  // Calculation of total interest
  totalInterest = totalPayments - principal;

  printf("\nMonthly payment: $%.2lf", monthlyPayment);
  printf("\nTotal payments: $%.2lf", totalPayments);
  printf("\nTotal interest: $%.2lf\n", totalInterest);

  return 0;
}