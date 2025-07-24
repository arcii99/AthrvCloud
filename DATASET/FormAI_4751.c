//FormAI DATASET v1.0 Category: Mortgage Calculator ; Style: visionary
#include <stdio.h>

int main() {

  float rate, principal;
  int years;

  printf("Enter the principal amount: ");
  scanf("%f", &principal);

  printf("Enter the annual interest rate: ");
  scanf("%f",&rate);

  printf("Enter the number of years of the loan: ");
  scanf("%d",&years);

  float r = rate / 1200; // monthly interest rate
  int n = years * 12; // number of months in the loan

  float payment = (principal * r) / (1 - pow(1+r, -n)); // calculate monthly payment

  printf("\nYour monthly mortgage payment is: $%.2f\n\n", payment);

  return 0;
}