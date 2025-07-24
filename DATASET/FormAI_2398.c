//FormAI DATASET v1.0 Category: Mortgage Calculator ; Style: excited
#include <stdio.h>

int main() {
  float loanAmount, interestRate, monthlyPayment;
  int loanTerm;
  printf("Welcome to the Mortgage Calculator!\n");
  printf("Please enter the loan amount (in dollars): ");
  scanf("%f", &loanAmount);
  printf("Please enter the interest rate (as a percentage): ");
  scanf("%f", &interestRate);
  printf("Please enter the loan term (in years): ");
  scanf("%d", &loanTerm);
  
  // Convert interest rate to monthly rate
  float monthlyRate = interestRate / 1200;
  
  // Calculate monthly payment
  monthlyPayment = (loanAmount * monthlyRate) / (1 - pow(1 + monthlyRate, -1 * loanTerm * 12));
  
  printf("\n");
  printf("Your monthly payment is: $%.2f\n", monthlyPayment);
  printf("Over a %d year loan term, you will pay a total of: $%.2f\n", loanTerm, monthlyPayment * loanTerm * 12);
  return 0;
}