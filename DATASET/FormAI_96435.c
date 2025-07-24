//FormAI DATASET v1.0 Category: Mortgage Calculator ; Style: ephemeral
#include <stdio.h>

int main() {
  double loan_amount, interest_rate, payment_amount, total_interest;
  int duration, total_payments;

  printf("Enter the loan amount: ");
  scanf("%lf", &loan_amount);

  printf("Enter the interest rate: ");
  scanf("%lf", &interest_rate);

  printf("Enter the loan duration (in years): ");
  scanf("%d", &duration);

  // Calculate total number of payments
  total_payments = duration * 12;

  // Calculate monthly interest rate
  double monthly_rate = interest_rate / 1200;

  // Calculate payment amount
  payment_amount = (loan_amount * monthly_rate) / (1 - pow(1 + monthly_rate, -total_payments));

  // Calculate total interest paid
  total_interest = (payment_amount * total_payments) - loan_amount;

  // Print the results
  printf("Monthly Payment: $%.2lf\n", payment_amount);
  printf("Total Interest Paid: $%.2lf\n", total_interest);
  printf("Total Payments: %d\n", total_payments);

  return 0;
}