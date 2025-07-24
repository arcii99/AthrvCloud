//FormAI DATASET v1.0 Category: Mortgage Calculator ; Style: excited
#include <stdio.h>
#include <math.h>

int main() {
  // Define variables
  float principal, interest_rate, monthly_interest_rate;
  int num_payments;
  
  // Get input from user
  printf("Welcome to the mortgage calculator!\n");
  printf("Enter the principal amount (in dollars): ");
  scanf("%f", &principal);
  printf("Enter the interest rate (as a percentage): ");
  scanf("%f", &interest_rate);
  printf("Enter the number of payments: ");
  scanf("%d", &num_payments);
  
  // Convert interest rate to monthly rate
  monthly_interest_rate = interest_rate / 100 / 12;
  
  // Calculate monthly payment
  float monthly_payment = (principal * monthly_interest_rate * pow(1 + monthly_interest_rate, num_payments)) / (pow(1 + monthly_interest_rate, num_payments) - 1);
  
  // Print out results
  printf("\nYour monthly payment is: $%.2f\n", monthly_payment);
  printf("You will make %d payments in total.\n", num_payments);
  printf("\nThank you for using the mortgage calculator!\n");
  
  return 0;
}