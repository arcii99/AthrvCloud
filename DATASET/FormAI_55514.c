//FormAI DATASET v1.0 Category: Mortgage Calculator ; Style: creative
#include <stdio.h>

int main() {
  float principal, interestRate, monthlyPayment, balance, interestPaid, month;
  int monthsRemaining;

  // Prompt user for loan details
  printf("Enter the loan amount: ");
  scanf("%f", &principal);

  printf("Enter the annual interest rate (as a decimal): ");
  scanf("%f", &interestRate);

  printf("Enter the monthly payment: ");
  scanf("%f", &monthlyPayment);

  // Initialize balance and month variables
  balance = principal;
  month = 0;

  // Calculate and display payment details for each month
  while (balance > 0) {
    // Calculate interest paid and apply to balance
    interestPaid = interestRate / 12 * balance;
    balance += interestPaid;

    // Apply monthly payment to balance
    if (balance > monthlyPayment) {
      balance -= monthlyPayment;
    } else {
      monthlyPayment = balance;
      balance = 0;
    }

    // Increment month count
    month++;

    // Display payment details for current month
    printf("Month %0.0f: Balance: $%0.2f, Payment: $%0.2f, Interest Paid: $%0.2f\n", month, balance, monthlyPayment, interestPaid);
  }

  // Calculate and display remaining months until payoff
  monthsRemaining = month - 1;
  printf("You paid off your loan in %d months!\n", monthsRemaining);

  return 0;
}