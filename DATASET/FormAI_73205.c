//FormAI DATASET v1.0 Category: Mortgage Calculator ; Style: curious
#include <stdio.h>

int main() {

  printf("Welcome to the Mortgage Calculator!\n");

  float loan_amount, interest_rate, monthly_payment;
  int loan_period;

  printf("Please enter the loan amount: $");
  scanf("%f", &loan_amount);

  printf("Please enter the interest rate (annual): ");
  scanf("%f", &interest_rate);

  printf("Please enter the loan period (in years): ");
  scanf("%d", &loan_period);

  // Calculating the monthly interest rate and loan period in months
  float monthly_interest_rate = (interest_rate / 12) / 100;
  int loan_period_months = loan_period * 12;

  // Calculating the monthly payment using the formula
  monthly_payment = (loan_amount * monthly_interest_rate) / (1 - pow((1 + monthly_interest_rate), -loan_period_months));

  printf("The monthly payment for the loan is: $%.2f\n", monthly_payment);

  return 0;
}