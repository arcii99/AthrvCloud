//FormAI DATASET v1.0 Category: Mortgage Calculator ; Style: real-life
#include <stdio.h>

int main() {
  double principal, rate, term, monthly_payment;
  printf("Enter the principal amount: ");
  scanf("%lf", &principal);
  printf("Enter the interest rate: ");
  scanf("%lf", &rate);
  printf("Enter the term (in years): ");
  scanf("%lf", &term);
  
  // Convert rate from annual to monthly
  rate = rate / 100 / 12;
  
  // Convert term from years to months
  term = term * 12;
  
  // Calculate monthly payment
  monthly_payment = (principal * rate * pow(1 + rate, term)) / (pow(1 + rate, term) - 1);
  
  printf("\nMonthly payment: $%.2lf\n", monthly_payment);

  return 0;
}