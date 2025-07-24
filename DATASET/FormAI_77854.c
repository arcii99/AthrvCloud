//FormAI DATASET v1.0 Category: Mortgage Calculator ; Style: ephemeral
#include <stdio.h>

int main() {
  // Present loan amount
  float present_loan_amount;
  printf("Enter Present Loan Amount: $");
  scanf("%f", &present_loan_amount);

  // Interest Rate
  float interest_rate;
  printf("\nEnter Interest Rate: ");
  scanf("%f", &interest_rate);

  // Number of years left to pay
  int years_left_to_pay;
  printf("\nEnter Remaining Number of Years: ");
  scanf("%d", &years_left_to_pay);

  // Monthly Payment Calculation
  int months_left_to_pay = years_left_to_pay * 12;
  float monthly_interest_rate = interest_rate / 1200;
  float monthly_payment = present_loan_amount * monthly_interest_rate / (1 - (pow(1/(1 + monthly_interest_rate), months_left_to_pay)));

  // Total Payment Calculation
  float total_payment = monthly_payment * months_left_to_pay;
  float total_interest = total_payment - present_loan_amount;

  // Printing Result
  printf("\n\n");
  printf("****************************************************\n");
  printf("Loan Amount: $%.2f\n", present_loan_amount);
  printf("Interest Rate: %.2f %%\n", interest_rate);
  printf("Number of Years Left to Pay: %d years\n", years_left_to_pay);
  printf("Monthly Payment: $%.2f per month\n", monthly_payment);
  printf("Total Payment: $%.2f\n", total_payment);
  printf("Total Interest: $%.2f\n", total_interest);
  printf("****************************************************\n");

  return 0;
}