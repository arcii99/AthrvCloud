//FormAI DATASET v1.0 Category: Mortgage Calculator ; Style: happy
#include <stdio.h>

int main() {
  // Welcome message
  printf("*** Welcome to our Happy Mortgage Calculator! *** \n");

  // Prompt the user to enter the loan amount
  float loanAmount;
  printf("Please enter the loan amount: $");
  scanf("%f", &loanAmount);

  // Prompt the user to enter the interest rate
  float interestRate;
  printf("Please enter the interest rate: ");
  scanf("%f", &interestRate);

  // Prompt the user to enter the loan term in years
  int loanTerm;
  printf("Please enter the loan term in years: ");
  scanf("%d", &loanTerm);

  // Calculate the monthly payment
  float monthlyInterestRate = interestRate / 1200.0;
  int totalPayments = loanTerm * 12;
  float monthlyPayment = loanAmount * monthlyInterestRate / (1 - pow(1 + monthlyInterestRate, -totalPayments));

  // Display the monthly payment
  printf("Your monthly payment is: $%.2f\n", monthlyPayment);

  // Happy message
  printf("Congratulations! You're one step closer to owning your dream home! :)\n");

  return 0;
}