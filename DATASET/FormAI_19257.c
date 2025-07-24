//FormAI DATASET v1.0 Category: Mortgage Calculator ; Style: creative
#include <stdio.h>

int main() {
  float loan_amount, interest_rate, monthly_payment;
  int number_of_years;

  printf("Enter the loan amount: ");
  scanf("%f", &loan_amount);

  printf("Enter the interest rate: ");
  scanf("%f", &interest_rate);

  printf("Enter the number of years: ");
  scanf("%d", &number_of_years);

  // Calculate the monthly interest rate
  float monthly_interest_rate = interest_rate / 1200;

  // Calculate the number of payments
  int number_of_payments = number_of_years * 12;

  // Calculate the monthly payment using the formula
  monthly_payment = (loan_amount * monthly_interest_rate) / (1 - pow(1 + monthly_interest_rate, -number_of_payments));

  // Display the results
  printf("\nLoan Amount: $%.2f\n", loan_amount);
  printf("Interest Rate: %.2f %%\n", interest_rate);
  printf("Number of Years: %d years\n", number_of_years);
  printf("Monthly Payment: $%.2f\n", monthly_payment);

  return 0;
}