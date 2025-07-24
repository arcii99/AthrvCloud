//FormAI DATASET v1.0 Category: Mortgage Calculator ; Style: automated
#include <stdio.h>

int main() {
  double principle, interest_rate, monthly_payment, balance;
  int months = 0;

  printf("Enter the total principle amount: ");
  scanf("%lf", &principle);

  printf("Enter the annual interest rate as a decimal: ");
  scanf("%lf", &interest_rate);

  printf("Enter the monthly payment amount: ");
  scanf("%lf", &monthly_payment);

  // Calculate the monthly interest rate
  double monthly_interest_rate = interest_rate / 12;

  // Calculate the balance after the first month's payment
  balance = principle * (1 + monthly_interest_rate) - monthly_payment;
  
  // Calculate the number of months to pay off the mortgage
  while (balance > 0) {
    balance = balance * (1 + monthly_interest_rate) - monthly_payment;
    months++;
  }

  // Output results
  printf("\nIt will take %d months to pay off the mortgage.\n", months);
  printf("The total amount paid will be $%.2lf.\n", monthly_payment * months);
  printf("The total interest paid will be $%.2lf.\n", (monthly_payment * months) - principle);

  return 0;
}