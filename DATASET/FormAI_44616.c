//FormAI DATASET v1.0 Category: Mortgage Calculator ; Style: relaxed
#include <stdio.h>

int main() {
  float principal, rate, time, monthlyPayment, totalPayment;
  printf("Welcome to the Mortgage Calculator Program!\n");
  printf("Please enter the principal amount: ");
  scanf("%f", &principal);
  printf("Please enter the interest rate: ");
  scanf("%f", &rate);
  printf("Please enter the time in years: ");
  scanf("%f", &time);
  rate /= 1200;
  time *= 12;
  monthlyPayment = (principal * rate) / (1 - (pow(1 + rate, -time)));
  totalPayment = monthlyPayment * time;
  printf("\nYour monthly payment will be: $%.2f\n", monthlyPayment);
  printf("Your total payment will be: $%.2f\n", totalPayment);
  printf("Thank you for using the Mortgage Calculator Program!\n");

  return 0;
}