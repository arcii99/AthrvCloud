//FormAI DATASET v1.0 Category: Mortgage Calculator ; Style: complex
#include <stdio.h>
#include <math.h>

int main() {
  float principal, rate, term, monthly_payment, total_payment, total_interest;
  int n;

  printf("-------------------------------------\n");
  printf("|          Mortgage Calculator      |\n");
  printf("-------------------------------------\n");

  printf("\nEnter the principal amount ($): ");
  scanf("%f", &principal);

  printf("\nEnter the annual interest rate (%%): ");
  scanf("%f", &rate);

  printf("\nEnter the term (years): ");
  scanf("%f", &term);

  printf("\nEnter the number of payments per year (12 or 24): ");
  scanf("%d", &n);

  rate = rate / 100 / n;
  term = term * n;

  monthly_payment = principal * (rate * pow((1 + rate), term)) / (pow((1 + rate), term) - 1);
  total_payment = monthly_payment * term;
  total_interest = total_payment - principal;

  printf("\n-------------------------------------\n");
  printf("               Results\n");
  printf("-------------------------------------\n");

  printf("Principal amount: $%.2f\n", principal);
  printf("Annual interest rate: %.2f%%\n", rate * 100 * n);
  printf("Term: %.2f years\n", term / n);
  printf("Number of payments per year: %d\n", n);
  printf("Monthly payment: $%.2f\n", monthly_payment);
  printf("Total payment: $%.2f\n", total_payment);
  printf("Total interest: $%.2f\n", total_interest);

  printf("\n-------------------------------------\n");

  return 0;
}