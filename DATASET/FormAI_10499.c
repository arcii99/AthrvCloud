//FormAI DATASET v1.0 Category: Mortgage Calculator ; Style: realistic
#include <stdio.h>

int main() {
  double principal, rate, monthly_payment, balance;
  int num_years, num_payments;

  printf("Enter principal: ");
  scanf("%lf", &principal);

  printf("Enter annual interest rate: ");
  scanf("%lf", &rate);

  printf("Enter number of years: ");
  scanf("%d", &num_years);

  num_payments = num_years * 12; // 12 monthly payments in a year

  rate /= 1200; // convert annual interest rate to monthly rate

  // calculate monthly payment
  monthly_payment = (principal * rate * pow(1 + rate, num_payments)) / (pow(1 + rate, num_payments) - 1);

  // print monthly payment
  printf("Monthly payment: $%.2f\n", monthly_payment);

  // print amortization schedule
  printf("Amortization schedule:\n");

  balance = principal;
  printf("%10s%15s%15s%15s\n", "Payment", "Interest", "Principal", "Balance");
  for (int i = 1; i <= num_payments; i++) {
    double interest = balance * rate;
    double principal_paid = monthly_payment - interest;
    balance -= principal_paid;

    printf("%10d%15.2f%15.2f%15.2f\n", i, interest, principal_paid, balance);
  }

  return 0;
}