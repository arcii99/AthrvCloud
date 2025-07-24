//FormAI DATASET v1.0 Category: Mortgage Calculator ; Style: relaxed
#include <stdio.h>

int main() {
  double loan_amount, interest_rate, monthly_payment, principal, balance;
  int term_years, term_months, months;

  printf("Welcome to the Mortgage Calculator!\n");

  // get loan information from user input
  printf("\nEnter loan amount: $");
  scanf("%lf", &loan_amount);

  printf("Enter interest rate: ");
  scanf("%lf", &interest_rate);

  printf("Enter loan term in years: ");
  scanf("%d", &term_years);

  // convert loan term to months
  term_months = term_years * 12;

  // calculate monthly interest rate
  double monthly_rate = interest_rate / 12 / 100;

  // calculate monthly payment
  monthly_payment = (loan_amount * monthly_rate * pow(1 + monthly_rate, term_months)) / (pow(1 + monthly_rate, term_months) - 1);

  printf("\nYour monthly payment is: $%.2lf\n", monthly_payment);

  // calculate remaining balance and interest paid after each month
  balance = loan_amount;
  printf("\nMonth\t\tBalance\t\tInterest Paid\n");
  for (months = 1; months <= term_months; months++) {
    // calculate monthly interest paid
    double monthly_interest = balance * monthly_rate;
    // calculate monthly principal paid
    principal = monthly_payment - monthly_interest;
    // calculate remaining balance
    balance -= principal;
    // print results for current month
    printf("%d\t\t$%.2lf\t\t$%.2lf\n", months, balance, monthly_interest);
  }

  return 0;
}