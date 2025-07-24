//FormAI DATASET v1.0 Category: Mortgage Calculator ; Style: Donald Knuth
#include <stdio.h>
#include <math.h>

int main() {
  float principle, rate, time, emi, monthly_rate, total_amount;

  printf("Enter principle amount: ");
  scanf("%f", &principle);

  printf("Enter interest rate: ");
  scanf("%f", &rate);

  printf("Enter time in years: ");
  scanf("%f", &time);

  monthly_rate = rate / (12 * 100);
  emi = (principle * monthly_rate * pow(1 + monthly_rate, time * 12)) / (pow(1 + monthly_rate, time * 12) - 1);
  total_amount = emi * time * 12;

  printf("EMI: %.2f\n", emi);
  printf("Total amount: %.2f\n", total_amount);

  return 0;
}