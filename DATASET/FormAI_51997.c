//FormAI DATASET v1.0 Category: Mortgage Calculator ; Style: immersive
#include <stdio.h>

int main() {
  double principal, interest_rate, term_years, monthly_payment, balance;
  printf("Welcome to Mortgage Calculator\n");
  
  printf("Please enter the principal amount: $");
  scanf("%lf", &principal);
  
  printf("\nPlease enter the annual interest rate: ");
  scanf("%lf", &interest_rate);
  
  printf("\nPlease enter the loan term (in years): ");
  scanf("%lf", &term_years);
  
  printf("\nCalculating monthly payment amount...\n");
  
  // Calculation
  double monthly_interest_rate = interest_rate / 1200.0;
  double term_months = term_years * 12.0;
  double power_factor = pow(1 + monthly_interest_rate, term_months);
  monthly_payment = (principal * monthly_interest_rate * power_factor) / (power_factor - 1);
  
  printf("\nYour monthly payment amount is: $%.2lf", monthly_payment);
  printf("\n\nAmortization schedule:\n\n");
  
  balance = principal;
  
  // Table header
  printf("%10s %15s %15s %15s\n", "Payment#", "Interest", "Principal", "Balance");
  
  // Table content
  for(int i = 1; i <= term_months; i++) {
    double interest = balance * monthly_interest_rate;
    double principal = monthly_payment - interest;
    
    printf("%10d %15.2lf %15.2lf %15.2lf\n", i, interest, principal, balance);
    
    balance -= principal;
  }
  
  return 0;
}