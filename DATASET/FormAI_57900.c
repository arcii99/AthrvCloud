//FormAI DATASET v1.0 Category: Mortgage Calculator ; Style: curious
#include <stdio.h>

int main() {
  float loan_amount, interest_rate, monthly_payment, balance, total_interest;
  int num_of_payments;

  // Get loan amount from user
  printf("Enter loan amount: ");
  scanf("%f", &loan_amount);

  // Get interest rate from user
  printf("Enter interest rate (as a decimal): ");
  scanf("%f", &interest_rate);

  // Get number of payments from user (in months)
  printf("Enter number of payments (in months): ");
  scanf("%d", &num_of_payments);

  // Calculate monthly interest rate
  float monthly_rate = interest_rate / 12;

  // Calculate monthly payment using formula
  monthly_payment = (monthly_rate * loan_amount) / (1 - pow(1 + monthly_rate, -num_of_payments));

  // Print monthly payment to user
  printf("Monthly payment: $%.2f\n", monthly_payment);

  // Calculate total interest paid over loan term
  for (int month = 1; month <= num_of_payments; month++) {
    float interest_paid = balance * monthly_rate;
    total_interest += interest_paid;
    balance -= (monthly_payment - interest_paid);

    // Output balance each month if user wants to see amortization schedule
    printf("Month %d balance: $%.2f\n", month, balance);
  }

  // Print total interest paid over loan term
  printf("Total interest paid: $%.2f\n", total_interest);

  return 0;
}