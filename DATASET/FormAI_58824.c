//FormAI DATASET v1.0 Category: Mortgage Calculator ; Style: ephemeral
#include <stdio.h>

int main() {
  // greeting message
  printf("Welcome to the Ephemeral Mortgage Calculator!\n");
  
  // get inputs
  float amount;
  float rate;
  int period;
  
  printf("Enter the amount of your loan: $");
  scanf("%f", &amount);
  
  printf("Enter the interest rate (as a decimal): ");
  scanf("%f", &rate);
  
  printf("Enter the loan period (in years): ");
  scanf("%d", &period);
  
  // calculate monthly payment
  float monthly_rate = rate / 12.0;
  int num_payments = period * 12;
  
  float multiplier = pow((1 + monthly_rate), num_payments);
  
  float monthly_payment = amount * ((monthly_rate * multiplier) / (multiplier - 1));
  
  // display results
  printf("\nYour Monthly Payment: $%.2f\n", monthly_payment);
  
  // exit message
  printf("\nThank you for using the Ephemeral Mortgage Calculator! Goodbye.\n");
  
  return 0;
}