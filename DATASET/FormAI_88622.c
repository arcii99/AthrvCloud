//FormAI DATASET v1.0 Category: Mortgage Calculator ; Style: Ada Lovelace
#include <stdio.h>
#include <math.h>

int main() {
  float p, r, m, n, monthly_payment, total_payment;

  printf("Enter the loan amount: ");
  scanf("%f", &p);

  printf("Enter the annual interest rate as a decimal: ");
  scanf("%f", &r);

  printf("Enter the length of the loan in years: ");
  scanf("%f", &n);

  m = n * 12;

  monthly_payment = (p * r * pow(1 + r, m)) / (pow(1 + r, m) - 1);

  total_payment = monthly_payment * m;

  printf("\nMonthly payment: $%.2f\n", monthly_payment);
  printf("Total payment: $%.2f\n", total_payment);

  return 0;
}