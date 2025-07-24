//FormAI DATASET v1.0 Category: Mortgage Calculator ; Style: Ken Thompson
#include <stdio.h>
#include <math.h>

int main() {
  double loan_amount, interest_rate, term_years;
  printf("Enter the loan amount (in dollars): ");
  scanf("%lf", &loan_amount);
  printf("Enter the interest rate (as a decimal): ");
  scanf("%lf", &interest_rate);
  printf("Enter the loan term (in years): ");
  scanf("%lf", &term_years);

  double n = term_years * 12;
  double r = interest_rate / 12;
  double d = (1.0 - pow(1.0 + r, -n)) / r;

  printf("Monthly payment: $%.2lf\n", loan_amount / d);
  return 0;
}