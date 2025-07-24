//FormAI DATASET v1.0 Category: Mortgage Calculator ; Style: minimalist
#include <stdio.h>

int main() {
  float principal, rate, time, interest, total;

  // input the necessary parameters
  printf("Enter Principal Amount: ");
  scanf("%f", &principal);

  printf("Enter Rate of Interest: ");
  scanf("%f", &rate);

  printf("Enter Time Period (Years): ");
  scanf("%f", &time);

  // calculate and print the results
  interest = (principal * rate * time) / 100;
  total = principal + interest;

  printf("\nInterest Amount: $%.2f", interest);
  printf("\nTotal Amount: $%.2f\n", total);

  return 0;
}