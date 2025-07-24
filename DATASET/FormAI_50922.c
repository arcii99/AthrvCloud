//FormAI DATASET v1.0 Category: Mortgage Calculator ; Style: happy
#include <stdio.h>

int main() {
  float loan_amount, interest_rate, monthly_payment, monthly_interest, balance;
  int loan_period, i;

  printf("Welcome to the Happy Mortgage Calculator!\n");

  printf("Please enter your loan amount: ");
  scanf("%f", &loan_amount);

  printf("Please enter your annual interest rate: ");
  scanf("%f", &interest_rate);

  printf("Please enter your loan period (in years): ");
  scanf("%d", &loan_period);

  monthly_interest = interest_rate / 1200; // 12 months in a year, converted to percent
  monthly_payment = (loan_amount * monthly_interest) / (1 - pow(1 + monthly_interest, -loan_period * 12));
  balance = loan_amount;

  printf("\nYour monthly payment is: $%.2f\n", monthly_payment);
  printf("Here is your payment schedule:\n");

  printf("%10s | %15s | %15s | %15s\n", "Payment#", "Principal", "Interest", "Balance");
  printf("%s\n", "-----------------------------------------------");

  for (i = 1; i <= (loan_period * 12); i++) {
    float monthly_principal = monthly_payment - balance * monthly_interest;
    float monthly_interest_paid = balance * monthly_interest;
    balance -= monthly_principal;

    printf("%10d | %15.2f | %15.2f | %15.2f\n", i, monthly_principal, monthly_interest_paid, balance);
  }

  printf("\nCongratulations on your Happy Mortgage!\n");

  return 0;
}