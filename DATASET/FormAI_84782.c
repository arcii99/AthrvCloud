//FormAI DATASET v1.0 Category: Mortgage Calculator ; Style: portable
#include <stdio.h>
#include <stdlib.h>

int main() {

  // Variables for user input
  float loanAmount = 0, interestRate = 0;
  int loanTerm = 0;

  // Variables for calculations
  float monthlyRate = 0, monthlyPayment = 0;

  // Prompt user for loan amount
  printf("Enter the loan amount: ");
  scanf("%f", &loanAmount);

  // Prompt user for interest rate
  printf("Enter the interest rate: ");
  scanf("%f", &interestRate);

  // Prompt user for loan term
  printf("Enter the loan term (in months): ");
  scanf("%d", &loanTerm);

  // Calculate monthly interest rate
  monthlyRate = interestRate / 1200;

  // Calculate monthly payment
  monthlyPayment = (loanAmount * monthlyRate) / (1 - pow(1 + monthlyRate, -loanTerm));

  // Display monthly payment
  printf("Your monthly payment is: $%.2f", monthlyPayment);

  return 0;

}