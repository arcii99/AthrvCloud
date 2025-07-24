//FormAI DATASET v1.0 Category: Mortgage Calculator ; Style: expert-level
#include <stdio.h>
#include <math.h>

#define MAX_LOAN_AMOUNT 1000000
#define MAX_YEAR_TERM 50
#define MAX_INTEREST_RATE 15

double input_loan_amount() {
  double amount;
  do {
    printf("Enter loan amount (between $1,000 and $%d): ", MAX_LOAN_AMOUNT);
    scanf("%lf", &amount);
    if (amount < 1000 || amount > MAX_LOAN_AMOUNT) {
      printf("Invalid amount.\n");
    }
  } while (amount < 1000 || amount > MAX_LOAN_AMOUNT);
  return amount;
}

int input_loan_term() {
  int term;
  do {
    printf("Enter loan term (in years, between 1 and %d): ", MAX_YEAR_TERM);
    scanf("%d", &term);
    if (term < 1 || term > MAX_YEAR_TERM) {
      printf("Invalid term.\n");
    }
  } while (term < 1 || term > MAX_YEAR_TERM);
  return term;
}

double input_interest_rate() {
  double rate;
  do {
    printf("Enter interest rate (in percentage, between 1 and %d): ", MAX_INTEREST_RATE);
    scanf("%lf", &rate);
    if (rate < 1 || rate > MAX_INTEREST_RATE) {
      printf("Invalid rate.\n");
    }
  } while (rate < 1 || rate > MAX_INTEREST_RATE);
  return rate / 100.0;
}

int main() {
  double loan_amount = input_loan_amount();
  int loan_term = input_loan_term();
  double monthly_interest_rate = input_interest_rate() / 12.0;

  double numerator = loan_amount * monthly_interest_rate;
  double denominator = 1 - pow(1 + monthly_interest_rate, -loan_term * 12);
  double monthly_payment = numerator / denominator;

  printf("\nMonthly payment: $%.2f\n", monthly_payment);

  double total_interest = 0;
  double total_payment = 0;
  double remaining_balance = loan_amount;
  printf("\n%-10s %-20s %-20s %-20s\n", "Year", "Starting Balance", "Payment", "Ending Balance");
  for (int year = 1; year <= loan_term; year++) {
    double yearly_payment = 0;
    double yearly_interest = 0;
    printf("%-10d $%-19.2f ", year, remaining_balance);
    for (int month = 1; month <= 12; month++) {
      double monthly_interest = remaining_balance * monthly_interest_rate;
      double monthly_principal = monthly_payment - monthly_interest;
      remaining_balance -= monthly_principal;
      yearly_payment += monthly_payment;
      yearly_interest += monthly_interest;
    }
    printf("$%-19.2f $%-19.2f\n", yearly_payment, remaining_balance);
    total_interest += yearly_interest;
    total_payment += yearly_payment;
  }
  printf("\nTotal payment: $%.2f\n", total_payment);
  printf("Total interest: $%.2f\n", total_interest);

  return 0;
}