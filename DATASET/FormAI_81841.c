//FormAI DATASET v1.0 Category: Mortgage Calculator ; Style: visionary
#include <stdio.h>
#include <math.h>

int main() {
  double loan_amount, interest_rate, monthly_payment, total_payment, total_interest;
  int loan_duration_months, i;
  
  // Taking input from user
  printf("Enter the loan amount: ");
  scanf("%lf", &loan_amount);
  printf("Enter the interest rate (in percentage): ");
  scanf("%lf", &interest_rate);
  printf("Enter the loan duration (in months): ");
  scanf("%d", &loan_duration_months);
  
  // Converting interest rate to decimal form
  interest_rate = interest_rate / 100;
  
  // Calculating monthly interest rate
  double monthly_interest_rate = interest_rate / 12;
  
  // Calculating monthly payment
  monthly_payment = (loan_amount * monthly_interest_rate) / (1 - pow(1 + monthly_interest_rate, -loan_duration_months));
  
  // Printing monthly payment
  printf("\nMonthly Payment: %.2lf\n", monthly_payment);
  
  total_payment = monthly_payment * loan_duration_months;
  total_interest = total_payment - loan_amount;
  
  printf("\nTotal Payment: %.2lf", total_payment);
  printf("\nTotal Interest: %.2lf", total_interest);
  
  printf("\n\nPayment Schedule:\n\n");
  printf("Payment \t Interest \t Principal \t Balance\n");
  
  double balance = loan_amount;
  double interest, principal;
  
  for(i = 1; i <= loan_duration_months; i++) {
    interest = balance * monthly_interest_rate;
    principal = monthly_payment - interest;
    balance -= principal;

    printf("%d \t %.2lf \t\t %.2lf \t\t %.2lf\n", i, interest, principal, balance);
  }

  return 0;
}