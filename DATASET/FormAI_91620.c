//FormAI DATASET v1.0 Category: Mortgage Calculator ; Style: synchronous
#include <stdio.h>

int main() {
  double principal, rate, time;
  
  printf("Enter the mortgage amount: ");
  scanf("%lf", &principal);
  
  printf("Enter the interest rate: ");
  scanf("%lf", &rate);
  
  printf("Enter the number of years: ");
  scanf("%lf", &time);
  
  double monthly_rate = rate / 1200.0;
  double months = time * 12.0;
  
  double monthly_payment = principal * (monthly_rate * pow(1 + monthly_rate, months)) / (pow(1 + monthly_rate, months) - 1);
  
  printf("\nMortgage Amount: $%.2lf\n", principal);
  printf("Interest Rate: %.2lf%%\n", rate);
  printf("Number of Years: %.2lf\n", time);
  printf("Monthly Payment: $%.2lf\n", monthly_payment);
  
  return 0;
}