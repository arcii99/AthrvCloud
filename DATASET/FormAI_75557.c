//FormAI DATASET v1.0 Category: Mortgage Calculator ; Style: mind-bending
#include <stdio.h>
#include <stdlib.h>

int main() {
  float principal, rate, payment, balance;

  printf("Please enter the loan principal: ");
  scanf("%f", &principal);

  printf("Please enter the annual interest rate (as a percentage): ");
  scanf("%f", &rate);

  rate /= 100.0;
  float monthly_rate = rate / 12.0;

  printf("Please enter the monthly payment amount: ");
  scanf("%f", &payment);

  balance = principal;

  printf("\nMonth\tBalance\n");

  int i;
  for (i = 1; i <= 360; i++) {
    float interest = balance * monthly_rate;
    float principal_paid = payment - interest;

    balance -= principal_paid;

    if (balance < 0) {
      balance = 0;
      payment = interest + balance;

      printf("%d\t%.2f\n", i, balance);
      break;
    }

    printf("%d\t%.2f\n", i, balance);
  }

  printf("\nCongratulations, you have paid off your loan in %d months!\n", i);

  return 0;
}