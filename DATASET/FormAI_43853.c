//FormAI DATASET v1.0 Category: Mortgage Calculator ; Style: imaginative
#include <stdio.h>

int main() {
  float principle, interest_rate, monthly_payment, balance;
  int num_of_months = 0;

  printf("Enter Principle Amount: $");
  scanf("%f", &principle);

  printf("Enter Interest Rate: ");
  scanf("%f", &interest_rate);

  printf("Enter Monthly Payment Amount: $");
  scanf("%f", &monthly_payment);

  balance = principle;

  while (balance > 0) {
    num_of_months++;

    // Calculate interest for this month
    float interest = balance * (interest_rate / 1200);

    // If the interest is more than the monthly payment, the balance will keep increasing
    if (interest >= monthly_payment) {
      printf("\nError: Your monthly payment amount is too low.");
      printf("\nWith current interest rate, your monthly payment should be above $%.2f.\n", interest);
      return 0;
    }

    // Calculate new balance after making monthly payment and adding monthly interest
    balance = balance + interest - monthly_payment;

    // If balance is negative, the loan is paid off
    if (balance < 0) {
      printf("\nCongratulations! You have paid off your mortgage in %d months.\n", num_of_months);
      break;
    }

    // Print updated balance at the end of each month;
    printf("Month %d - Balance: $%.2f\n", num_of_months, balance);
  }

  return 0;
}