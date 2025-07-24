//FormAI DATASET v1.0 Category: Mortgage Calculator ; Style: futuristic
#include <stdio.h>
#include <stdlib.h>

int main() {
  int years, months;
  float loanAmount, interestRate, monthlyPayment, totalPayment, monthlyInterestRate;

  printf("Welcome to our Futuristic Mortgage Calculator!\n");
  printf("Enter the total loan amount: ");
  scanf("%f", &loanAmount);
  printf("Enter the interest rate (in percentage): ");
  scanf("%f", &interestRate);
  printf("Enter the term of the loan (in years): ");
  scanf("%d", &years);
  printf("Enter the term of the loan (in months): ");
  scanf("%d", &months);

  monthlyInterestRate = (interestRate / 100.0f) / 12.0f;
  monthlyPayment = loanAmount * monthlyInterestRate / (1.0f - powf(1.0f + monthlyInterestRate, -(years * 12 + months)));
  totalPayment = monthlyPayment * years * 12 + monthlyPayment * (float)months;

  printf("\n-----Loan Details-----\n");
  printf("Loan amount: $%.2f\n", loanAmount);
  printf("Interest rate: %.2f%%\n", interestRate);
  printf("Loan term: %d years and %d months\n", years, months);
  printf("\n-----Loan Summary-----\n");
  printf("Monthly payment: $%.2f\n", monthlyPayment);
  printf("Total payment: $%.2f\n", totalPayment);
  printf("--------------------------------------\n");
  printf("Thank you for using our Futuristic Mortgage Calculator!\n");

  return 0;
}