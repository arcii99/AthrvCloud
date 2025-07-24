//FormAI DATASET v1.0 Category: Mortgage Calculator ; Style: portable
#include <stdio.h>
#include <math.h>

int main() {
  double principle, rate, term;
  printf("Enter the principle amount: ");
  scanf("%lf", &principle);
  printf("Enter the annual interest rate: ");
  scanf("%lf", &rate);
  printf("Enter the loan term (in years): ");
  scanf("%lf", &term);

  // Calculating monthly interest rate and number of payments
  double monthly_rate = rate / 1200;
  double number_payments = term * 12;

  // Calculating monthly payment amount
  double monthly_payment = principle * monthly_rate / (1 - pow(1 + monthly_rate, -number_payments));
  
  // Calculating total amount paid and total interest paid
  double total_paid = monthly_payment * number_payments;
  double total_interest = total_paid - principle;

  // Displaying results
  printf("\nRESULTS\n");
  printf("Monthly Payment: %.2lf\n", monthly_payment);
  printf("Total Amount Paid: %.2lf\n", total_paid);
  printf("Total Interest Paid: %.2lf\n", total_interest);

  return 0;
}