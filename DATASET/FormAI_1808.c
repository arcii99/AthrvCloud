//FormAI DATASET v1.0 Category: Mortgage Calculator ; Style: beginner-friendly
#include <stdio.h>
#include <math.h>

int main() {
  float principle, rate, time, emi, payable_amount;
  int months;

  // User input
  printf("Enter the principle amount: ");
  scanf("%f", &principle);
  printf("Enter the rate of interest: ");
  scanf("%f", &rate);
  printf("Enter the time duration in years: ");
  scanf("%f", &time);

  // Calculation
  months = time * 12;
  rate = rate / (12 * 100);
  emi = (principle * rate * pow(1 + rate, months)) / (pow(1 + rate, months) - 1);
  payable_amount = emi * months;
  
  // Output
  printf("\nEMI per month: %.2f", emi);
  printf("\nPayable Amount: %.2f", payable_amount);
  
  return 0;
}