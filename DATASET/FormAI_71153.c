//FormAI DATASET v1.0 Category: Mortgage Calculator ; Style: inquisitive
#include <stdio.h>

int main() {
  float loanAmount, interestRate, monthlyPayment, remainingBalance;
  int yearsToPay;
  printf("Welcome to Mortgage Calculator!\n");
  printf("Please enter the loan amount: ");
  scanf("%f", &loanAmount);
  printf("Please enter the interest rate per year: ");
  scanf("%f", &interestRate);
  printf("Please enter the number of years to pay: ");
  scanf("%d", &yearsToPay);
  printf("\n");

  float monthlyInterest = interestRate / 1200;
  int numberOfPayments = yearsToPay * 12;
  float numerator = (monthlyInterest * (pow(1 + monthlyInterest, numberOfPayments)));
  float denominator = (pow(1 + monthlyInterest, numberOfPayments) - 1);
  monthlyPayment = loanAmount * (numerator / denominator);
  remainingBalance = loanAmount;

  printf("Your monthly payment will be: $%.2f\n", monthlyPayment);
  printf("\nPayment Schedule\n");
  printf("Month\t\tPayment\t\tRemaining Balance\n");

  for(int i = 1; i <= numberOfPayments; i++) {
    float interestPayment = remainingBalance * monthlyInterest;
    float principalPayment = monthlyPayment - interestPayment;
    remainingBalance -= principalPayment;

    printf("%d\t\t$%.2f\t\t$%.2f\n", i, monthlyPayment, remainingBalance);

    if(i == numberOfPayments) {
      printf("\nCongratulations! You have successfully paid off your loan.\n");
    }
  }

  return 0;
}