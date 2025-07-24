//FormAI DATASET v1.0 Category: Mortgage Calculator ; Style: random
#include <stdio.h>

int main() {
  float loan_amount, interest_rate, monthly_payment, balance;
  int num_of_months;

  printf("Enter the loan amount: ");
  scanf("%f", &loan_amount);

  printf("\nEnter the interest rate: ");
  scanf("%f", &interest_rate);

  printf("\nEnter the number of months: ");
  scanf("%d", &num_of_months);

  // convert interest rate to decimal
  interest_rate = interest_rate / 100.0;

  // calculate monthly payment
  float x = pow(1 + interest_rate, num_of_months);
  monthly_payment = (loan_amount * x * interest_rate) / (x - 1);

  // print the monthly payment
  printf("\nMonthly Payment: $%.2f", monthly_payment);

  // print out the monthly balance and interest for each month
  balance = loan_amount;
  for (int i = 1; i <= num_of_months; i++) {
    float interest = balance * interest_rate;
    float principle = monthly_payment - interest;

    printf("\nMonth %d: Balance=$%.2f, Interest=$%.2f, Principle=$%.2f", i, balance, interest, principle);

    balance = balance - principle;
  }

  return 0;
}