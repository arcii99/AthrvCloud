//FormAI DATASET v1.0 Category: Mortgage Calculator ; Style: surprised
#include <stdio.h>

int main() {
  printf("Welcome to the Mortgage Calculator program!");

  float loan_amount, monthly_payment, interest_rate;
  int loan_period_years;

  printf("\n\nEnter the loan amount (in USD): ");
  scanf("%f", &loan_amount);

  printf("\nEnter the interest rate (in percent): ");
  scanf("%f", &interest_rate);

  printf("\nEnter the loan period (in years): ");
  scanf("%d", &loan_period_years);

  // Monthly interest rate calculation
  float monthly_interest_rate = interest_rate / 1200;

  // Number of payments calculation
  int num_payments = loan_period_years * 12;

  // Monthly payment calculation
  monthly_payment = (loan_amount * monthly_interest_rate) / (1 - (1 / pow((1 + monthly_interest_rate), num_payments)));

  printf("\n\nThe monthly payment for your loan is: $%.2f\n", monthly_payment);

  printf("\nWow, you really will be able to afford that dream home! Thanks for using the Mortgage Calculator program!");
  
  return 0;
}