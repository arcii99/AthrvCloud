//FormAI DATASET v1.0 Category: Mortgage Calculator ; Style: detailed
#include <stdio.h>
#include <math.h>

int main() {
  float loan_amount, interest_rate, monthly_payment;
  int loan_term, num_payments;
  
  printf("Enter the loan amount: ");
  scanf("%f", &loan_amount);
  
  printf("Enter the interest rate: ");
  scanf("%f", &interest_rate);
  
  printf("Enter the loan term (in years): ");
  scanf("%d", &loan_term);
  
  num_payments = loan_term * 12;
  
  interest_rate = interest_rate / 100;
  float monthly_rate = interest_rate / 12;
  
  // Mortgage formula: M = P [ i(1 + i)^n ] / [ (1 + i)^n - 1]
  monthly_payment = (loan_amount*monthly_rate*pow(1+monthly_rate,num_payments))/(pow(1+monthly_rate,num_payments)-1);
  
  printf("\nLoan Amount: $%.2f", loan_amount);
  printf("\nInterest Rate: %.2f%%", interest_rate*100);
  printf("\nLoan Term: %d year(s)", loan_term);
  
  printf("\n\nMonthly Payment: $%.2f\n", monthly_payment);
  
  return 0;
}