//FormAI DATASET v1.0 Category: Mortgage Calculator ; Style: mind-bending
#include <stdio.h>

int main() {
  printf("Welcome to the Mind-bending Mortgage Calculator 5000!\n");
  printf("Please enter the loan amount: ");

  double loanAmount;
  scanf("%lf", &loanAmount);

  printf("Please enter the interest rate: ");

  double interestRate;
  scanf("%lf", &interestRate);

  printf("Please enter the term (in years): ");

  int years;
  scanf("%d", &years);

  double monthlyInterestRate = interestRate / 1200;
  int months = years * 12;
  double monthlyPayment = (loanAmount * monthlyInterestRate) / (1 - pow(1 + monthlyInterestRate, -months));

  printf("\nCongratulations, you are now the proud owner of a mind-bending mortgage payment of $%.2lf per month!\n", monthlyPayment);

  printf("\nDon't be fooled by the simplicity of this program - it is but a mere glimpse into the mind-bending world of financial calculations.\n");
  printf("The true power of this calculator lies in its ability to bend your mind to the will of compound interest, debt-to-income ratios, and amortization schedules.\n");
  printf("With this calculator, you will be able to visualize the very fabric of economic reality and mold it to your will.\n");
  printf("So go forth, financially empowered, and conquer the world!\n");

  return 0;
}