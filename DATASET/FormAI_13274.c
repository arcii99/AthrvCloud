//FormAI DATASET v1.0 Category: Mortgage Calculator ; Style: configurable
#include <stdio.h>
#include <stdlib.h>

int main() {
  float loan_amount, interest_rate, monthly_payment, principal, interest, balance;
  int num_of_years, num_of_payments, i;

  // get the input values from the user
  printf("Enter the loan amount: ");
  scanf("%f", &loan_amount);

  printf("Enter the interest rate: ");
  scanf("%f", &interest_rate);

  printf("Enter the number of years: ");
  scanf("%d", &num_of_years);

  // calculate the monthly interest rate and number of payments
  float monthly_interest_rate = interest_rate / 1200;
  num_of_payments = num_of_years * 12;

  // calculate the monthly payment
  monthly_payment = loan_amount * (monthly_interest_rate / (1 - powf(1 + monthly_interest_rate, -num_of_payments)));

  // print the monthly payment
  printf("Monthly payment: %0.2f\n", monthly_payment);

  // print the amortization table
  printf("Payment No.\t\tPayment Amount\t\tPrincipal Amount\t\tInterest Amount\t\tBalance\n");
  balance = loan_amount;
  for (i=1; i<=num_of_payments; i++) {
    interest = balance * monthly_interest_rate;
    principal = monthly_payment - interest;
    balance -= principal;
    printf("%d\t\t%0.2f\t\t%0.2f\t\t%0.2f\t\t%0.2f\n", i, monthly_payment, principal, interest, balance);
  }

  return 0;
}