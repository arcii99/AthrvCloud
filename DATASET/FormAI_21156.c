//FormAI DATASET v1.0 Category: Mortgage Calculator ; Style: mathematical
#include <stdio.h>
#include <math.h>

int main() {
  float loan_amount, rate, monthly_rate, num_years, num_months, monthly_payment, total_interest;
  
  // Input loan details
  printf("Enter loan amount: ");
  scanf("%f", &loan_amount);
  
  printf("Enter annual interest rate: ");
  scanf("%f", &rate);
  
  printf("Enter number of years: ");
  scanf("%f", &num_years);
  
  // Calculate monthly interest rate and number of months
  monthly_rate = rate / 12.0;
  num_months = num_years * 12.0;
  
  // Calculate monthly payment
  monthly_payment = (loan_amount * monthly_rate) / (1 - pow(1 + monthly_rate, -num_months));
  
  // Calculate total interest paid
  total_interest = (monthly_payment * num_months) - loan_amount;
  
  // Output results
  printf("\nLoan details:\n");
  printf("Loan amount: $%.2f\n", loan_amount);
  printf("Annual interest rate: %.2f%%\n", rate);
  printf("Number of years: %.0f\n", num_years);
  printf("Monthly payment: $%.2f\n", monthly_payment);
  printf("Total interest paid: $%.2f\n", total_interest);

  return 0;
}