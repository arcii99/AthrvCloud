//FormAI DATASET v1.0 Category: Mortgage Calculator ; Style: thoughtful
// C Program to Calculate Mortgage
#include <stdio.h>
#include <math.h>

int main() {
  // Variables for Calculation
  float principal, interest_rate, monthly_payment, loan_duration, mortgage;
  float rate_month, t_payment, t_interest;

  // User Input
  printf("Enter the Loan Amount (Principal): ");
  scanf("%f", &principal);

  printf("Enter the Interest Rate (Annual Percentage): ");
  scanf("%f", &interest_rate);

  printf("Enter the Loan Duration (in years): ");
  scanf("%f", &loan_duration);

  // Calculation of Monthly Interest Rate
  rate_month = interest_rate / 1200;

  // Calculation of Monthly Payment
  monthly_payment = principal * rate_month / (1 - pow(1 + rate_month, -loan_duration * 12));

  // Calculation of Total Payment and Total Interest
  t_payment = monthly_payment * loan_duration * 12;
  t_interest = t_payment - principal;

  // Calculation of Mortgage
  mortgage = monthly_payment * 12 * loan_duration;

  // Output the Result
  printf("\nMonthly Payment: %.2f\n", monthly_payment);
  printf("Total Payment: %.2f\n", t_payment);
  printf("Total Interest: %.2f\n", t_interest);
  printf("Mortgage: %.2f", mortgage);

  return 0;
}