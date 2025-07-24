//FormAI DATASET v1.0 Category: Mortgage Calculator ; Style: real-life
#include <stdio.h>
#include <math.h>

int main() {
  double loanAmount, interestRate, monthlyInterestRate, numYears, numMonths, monthlyPayment, totalPayment, totalInterest;
  
  // Get input from user
  printf("Enter the loan amount: ");
  scanf("%lf", &loanAmount);
  
  printf("Enter the interest rate (e.g. 5.25): ");
  scanf("%lf", &interestRate);
  
  printf("Enter the number of years: ");
  scanf("%lf", &numYears);
  
  // Convert numYears to numMonths
  numMonths = numYears * 12;
  
  // Convert interestRate to monthlyInterestRate
  monthlyInterestRate = interestRate / 1200;
  
  // Calculate monthly payment
  monthlyPayment = (loanAmount * monthlyInterestRate) / (1 - pow(1 + monthlyInterestRate, -numMonths));
  
  // Calculate total payment and total interest
  totalPayment = monthlyPayment * numMonths;
  totalInterest = totalPayment - loanAmount;
  
  // Print the results
  printf("\n");
  printf("Mortgage Calculator\n");
  printf("-----------------------------------\n");
  printf("Loan amount: $%.2f\n", loanAmount);
  printf("Interest rate: %.2f%%\n", interestRate);
  printf("Number of years: %.2f\n", numYears);
  printf("Monthly payment: $%.2f\n", monthlyPayment);
  printf("Total payment: $%.2f\n", totalPayment);
  printf("Total interest: $%.2f\n", totalInterest);
  
  return 0;
}