//FormAI DATASET v1.0 Category: Mortgage Calculator ; Style: scalable
#include <stdio.h>
#include <math.h>

int main() {

  float loan_amount, interest_rate, monthly_payment, remaining_balance;
  int num_of_payments, i;

  // Getting input from user
  printf("Enter loan amount: ");
  scanf("%f", &loan_amount);

  printf("Enter interest rate: ");
  scanf("%f", &interest_rate);

  printf("Enter number of payments: ");
  scanf("%d", &num_of_payments);

  // Converting annual interest rate to monthly interest rate
  float monthly_interest_rate = interest_rate / 1200;

  // Calculating monthly payment
  monthly_payment = (loan_amount * monthly_interest_rate) / (1 - pow(1 + monthly_interest_rate, -num_of_payments));

  // Displaying monthly payment with 2 decimal places
  printf("\nMonthly Payment: $%.2f", monthly_payment);

  // Calculating and displaying remaining balance for every year
  remaining_balance = loan_amount;
  printf("\n\nYear         Remaining Balance");

  for (i = 1; i <= num_of_payments; i++) {
    float interest_paid = remaining_balance * monthly_interest_rate;
    float principal_paid = monthly_payment - interest_paid;

    remaining_balance -= principal_paid;

    if (i % 12 == 0) {
      printf("\n%d         $%.2f", i/12, remaining_balance);
    }
  }

  return 0;
}