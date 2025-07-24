//FormAI DATASET v1.0 Category: Mortgage Calculator ; Style: innovative
#include <stdio.h>

int main() {
  float principal, rate, time;
  printf("Enter the principal amount: ");
  scanf("%f", &principal);
  printf("Enter the interest rate: ");
  scanf("%f", &rate);
  printf("Enter the time (in years): ");
  scanf("%f", &time);

  /* calculate monthly interest rate */
  float monthlyRate = rate / 1200;

  /* calculate monthly payment */
  float monthlyPayment = (principal * monthlyRate)/(1 - (1/pow(1+monthlyRate, time*12)));

  /* calculate total payment */
  float totalPayment = monthlyPayment * time * 12;

  /* print results */
  printf("\n");
  printf("Monthly Payment: $%.2f\n", monthlyPayment);
  printf("Total Payment: $%.2f\n", totalPayment);

  return 0;
}