//FormAI DATASET v1.0 Category: Mortgage Calculator ; Style: cheerful
#include <stdio.h>

int main() {
  printf("Welcome to the Happy Mortgage Calculator!\n");
  
  double loanAmount, interestRate, monthlyPayment;
  int loanTerm;
  
  printf("\nEnter the loan amount: ");
  scanf("%lf", &loanAmount);
  
  printf("\nEnter the interest rate: ");
  scanf("%lf", &interestRate);
  
  printf("\nEnter the loan term (in years): ");
  scanf("%d", &loanTerm);
  
  interestRate /= 1200; // convert annual rate to monthly rate
  int numPayments = loanTerm * 12;
  
  // calculate monthly payment
  monthlyPayment = (interestRate * loanAmount) / (1 - pow(1 + interestRate, -numPayments));
  
  printf("\nCongratulations, your monthly payment is $%.2lf\n", monthlyPayment);
  
  printf("\nThank you for using the Happy Mortgage Calculator! Have a great day!");
  
  return 0;
}