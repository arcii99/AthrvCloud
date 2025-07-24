//FormAI DATASET v1.0 Category: Mortgage Calculator ; Style: random
#include <stdio.h>

int main() {
  float principal, rate, time, monthlyPayment, totalAmt, interestAmt;
  
  printf("Mortgage Calculator\n");
  printf("-------------------\n");
  
  // Get principal amount
  printf("Enter principal amount: $");
  scanf("%f", &principal);
  
  // Get interest rate
  printf("Enter interest rate per year: ");
  scanf("%f", &rate);
  
  // Convert rate to monthly interest rate
  float monthlyRate = (rate / 100) / 12;
  
  // Get the time period
  printf("Enter time period in years: ");
  scanf("%f", &time);
  
  // Calculate number of months
  int numMonths = time * 12;
  
  // Calculate monthly payment
  float numerator = monthlyRate * pow(1+monthlyRate, numMonths);
  float denominator = pow(1+monthlyRate, numMonths) - 1;
  monthlyPayment = principal * (numerator / denominator);
  
  // Calculate total amount to be paid
  totalAmt = monthlyPayment * numMonths;
  
  // Calculate interest amount
  interestAmt = totalAmt - principal;
  
  // Print results
  printf("\n------------------------------------------");
  printf("\nPrincipal amount: $%.2f", principal);
  printf("\nInterest rate: %.2f%%", rate);
  printf("\nTime period: %.0f years", time);
  printf("\n------------------------------------------");
  printf("\nMonthly payment: $%.2f", monthlyPayment);
  printf("\nTotal amount to be paid: $%.2f", totalAmt);
  printf("\nInterest amount: $%.2f", interestAmt);
  
  return 0;
}