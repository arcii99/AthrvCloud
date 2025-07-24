//FormAI DATASET v1.0 Category: Mortgage Calculator ; Style: shape shifting
#include <stdio.h>

int main() {
  int mortgage_amount, years;
  float interest_rate, monthly_payment, total_payment, balance;

  printf("Welcome to the Shape Shifting Mortgage Calculator!\n");

  printf("Enter the mortgage amount: ");
  scanf("%d", &mortgage_amount);

  printf("Enter the interest rate (in percentage): ");
  scanf("%f", &interest_rate);

  printf("Enter the years for mortgage: ");
  scanf("%d", &years);

  // Convert interest rate to monthly rate
  interest_rate /= 100;
  interest_rate /= 12;

  // Calculate monthly payment
  monthly_payment = (mortgage_amount * interest_rate) / (1 - pow(1 + interest_rate, -years * 12));

  // Calculate total payment and balance
  total_payment = monthly_payment * years * 12;
  balance = total_payment - mortgage_amount;

  // Display results
  printf("\n");
  printf("Monthly Payment: $%.2f\n", monthly_payment);
  printf("Total Payment: $%.2f\n", total_payment);
  printf("Balance: $%.2f\n", balance);

  return 0;
}