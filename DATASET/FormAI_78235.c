//FormAI DATASET v1.0 Category: Mortgage Calculator ; Style: happy
#include <stdio.h>

int main() {
  printf("Welcome to the Happy Mortgage Calculator!\n");
  printf("Please enter the loan amount:");
  double loan_amount;
  scanf("%lf", &loan_amount);

  printf("Great! Now enter the interest rate:");
  double interest_rate;
  scanf("%lf", &interest_rate);

  printf("Awesome! How many years is the loan for?:");
  int num_years;
  scanf("%d", &num_years);

  double monthly_interest_rate = (interest_rate / 100) / 12;
  int num_payments = num_years * 12;
  double monthly_payment = (loan_amount * monthly_interest_rate) / (1 - pow(1 + monthly_interest_rate, -num_payments));

  printf("Calculating...\n");

  printf("\nYour monthly mortgage payment will be: $%.2lf\n", monthly_payment);
  printf("Over the course of %d years, you will pay: $%.2lf\n", num_years, monthly_payment * num_payments);
  printf("Total interest paid over the life of the loan: $%.2lf\n", (monthly_payment * num_payments) - loan_amount);

  printf("\nThank you for using the Happy Mortgage Calculator! Have a great day!\n");

  return 0;
}