//FormAI DATASET v1.0 Category: Mortgage Calculator ; Style: modular
#include <stdio.h>

float get_principal() {
  float principal;
  printf("Enter the principal amount: ");
  scanf("%f", &principal);
  return principal;
}

float get_interest_rate() {
  float interest_rate;
  printf("Enter the interest rate: ");
  scanf("%f", &interest_rate);
  return interest_rate;
}

int get_years() {
  int years;
  printf("Enter the number of years: ");
  scanf("%d", &years);
  return years;
}

float calculate_monthly_payment(float principal, float interest_rate, int years) {
  float monthly_interest_rate = interest_rate / 1200;
  int months = years * 12;
  float numerator = monthly_interest_rate * principal;
  float denominator = 1 - pow(1 + monthly_interest_rate, -months);
  return numerator / denominator;
}

int main() {
  float principal = get_principal();
  float interest_rate = get_interest_rate();
  int years = get_years();

  float monthly_payment = calculate_monthly_payment(principal, interest_rate, years);

  printf("Monthly Payment: $%.2f\n", monthly_payment);

  return 0;
}