//FormAI DATASET v1.0 Category: Mortgage Calculator ; Style: retro
#include <stdio.h>

int main() {
  float loan_amount, interest_rate, payment;
  int term;
  
  printf("MORTGAGE CALCULATOR\n");
  printf("===================\n");
  printf("Enter loan amount: ");
  scanf("%f", &loan_amount);
  printf("Enter interest rate: ");
  scanf("%f", &interest_rate);
  printf("Enter term (in years): ");
  scanf("%d", &term);
  
  printf("\n");
  
  // Monthly interest rate
  float monthly_rate = interest_rate / 1200.0;
  
  // Number of payments
  int num_payments = term * 12;
  
  // Calculation
  payment = (loan_amount * monthly_rate) / (1 - pow((1 + monthly_rate), -num_payments));
  
  // Output
  printf("Loan amount: $%.2f\n", loan_amount);
  printf("Interest rate: %.2f%%\n", interest_rate);
  printf("Term: %d years\n", term);
  printf("Monthly payment: $%.2f\n", payment);
  
  return 0;
}