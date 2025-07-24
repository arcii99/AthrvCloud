//FormAI DATASET v1.0 Category: Mortgage Calculator ; Style: surprised
#include <stdio.h>

int main() {
  printf("Welcome to the Mortgage Calculator!\n");
  printf("Please enter the loan amount: ");
  float loan_amount;
  scanf("%f", &loan_amount);
  printf("Please enter the interest rate: ");
  float interest_rate;
  scanf("%f", &interest_rate);
  printf("Please enter the loan term in years: ");
  int loan_term;
  scanf("%d", &loan_term);
  float monthly_interest_rate = interest_rate / 1200;
  int total_payments = loan_term * 12;
  float payment_amount = (loan_amount * monthly_interest_rate) / (1 - pow((1 + monthly_interest_rate), -total_payments));
  printf("\n");
  printf("Loan amount: $%.2f\n", loan_amount);
  printf("Interest rate: %.2f%%\n", interest_rate);
  printf("Loan term: %d years\n", loan_term);
  printf("\n");
  printf("Your monthly payment will be: $%.2f\n", payment_amount);
  printf("\n");
  printf("Thank you for using the Mortgage Calculator! Good luck with your loan!\n");
  return 0;
}