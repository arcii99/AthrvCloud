//FormAI DATASET v1.0 Category: Mortgage Calculator ; Style: beginner-friendly
#include <stdio.h>

int main() {
  float loan_amount, yearly_interest_rate, monthly_interest_rate, monthly_payment, total_payment, balance;
  int num_payments, i;

  // Get loan amount
  printf("Enter the loan amount: ");
  scanf("%f", &loan_amount);

  // Get yearly interest rate
  printf("Enter the yearly interest rate: ");
  scanf("%f", &yearly_interest_rate);

  // Get number of payments
  printf("Enter the number of payments: ");
  scanf("%d", &num_payments);

  // Convert yearly interest rate to monthly interest rate
  monthly_interest_rate = yearly_interest_rate / 1200;

  // Calculate monthly payment
  monthly_payment = (loan_amount * monthly_interest_rate) / (1 - pow(1 + monthly_interest_rate, -num_payments));

  // Print monthly payment
  printf("\nMonthly payment: $%.2f\n\n", monthly_payment);

  // Print payment schedule
  printf("Payment\t| Payment Amount\t| Interest\t| Principal\t| Balance\n");
  printf("--------------------------------------------------------------------------\n");

  total_payment = 0;
  balance = loan_amount;
  for (i = 1; i <= num_payments; i++) {
    // Calculate interest for this month
    float interest = balance * monthly_interest_rate;

    // Calculate principal for this month
    float principal = monthly_payment - interest;

    // Calculate new balance after this payment
    balance -= principal;

    // Print payment information
    printf("%d\t| $%.2f\t\t| $%.2f\t| $%.2f\t| $%.2f\n", i, monthly_payment, interest, principal, balance);

    // Track total payment
    total_payment += monthly_payment;
  }

  // Print total payment information
  printf("--------------------------------------------------------------------------\n");
  printf("\nTotal payment: $%.2f\n", total_payment);
  printf("Interest paid: $%.2f\n", total_payment - loan_amount);

  return 0;
}