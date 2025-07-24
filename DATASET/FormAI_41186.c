//FormAI DATASET v1.0 Category: Mortgage Calculator ; Style: creative
#include <stdio.h>

int main() {
  float amount, interest_rate, monthly_payment;
  int num_months;
  
  printf("Welcome to the Mortgage Calculator Program!\n");
  
  // Get user input for loan amount
  printf("Please enter the total loan amount: ");
  scanf("%f", &amount);
  
  // Get user input for interest rate
  printf("Please enter the interest rate as a decimal: ");
  scanf("%f", &interest_rate);
  
  // Get user input for payment period in months
  printf("Please enter the duration of the mortgage in months: ");
  scanf("%d", &num_months);
  
  // Calculate monthly payment
  monthly_payment = (amount * interest_rate * (1 + interest_rate) * num_months) / ((1 + interest_rate) * num_months - 1);
  
  // Display monthly payment amount
  printf("Your monthly payment is %.2f\n", monthly_payment);
  
  return 0;
}