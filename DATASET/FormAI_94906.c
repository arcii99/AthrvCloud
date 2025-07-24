//FormAI DATASET v1.0 Category: Mortgage Calculator ; Style: optimized
#include <stdio.h>
#include <math.h>

int main(void) {
  double principle, interest_rate, monthly_payment;
  int term_months;

  printf("Enter the Loan Amount: ");
  scanf("%lf", &principle);

  printf("Enter the Interest Rate: ");
  scanf("%lf", &interest_rate);

  printf("Enter the Term in Months: ");
  scanf("%d", &term_months);

  interest_rate = interest_rate / 100.0 / 12.0;
  monthly_payment = (principle * interest_rate * pow(1 + interest_rate, term_months)) / (pow(1 + interest_rate, term_months) - 1);

  printf("The Monthly Payment is: $%.2lf\n", monthly_payment);
  printf("The Total Payment is: $%.2lf\n", monthly_payment * term_months);
  printf("The Total Interest Paid is: $%.2lf\n", (monthly_payment * term_months) - principle);

  return 0;
}