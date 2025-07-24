//FormAI DATASET v1.0 Category: Mortgage Calculator ; Style: invasive
#include <stdio.h>
#include <math.h>

int main() {
  // prompting user to input values
  double loanAmount, interestRate, monthlyPayment;
  printf("Enter the loan amount: ");
  scanf("%lf", &loanAmount);
  printf("Enter the interest rate (e.g. 5 for 5\%%): ");
  scanf("%lf", &interestRate);
  printf("Enter the monthly payment: ");
  scanf("%lf", &monthlyPayment);
 
  // Calculating monthly interest rate and number of payments
  double monthlyInterestRate = interestRate / (12 * 100);
  double numMonths = log(monthlyPayment / (monthlyPayment - monthlyInterestRate * loanAmount)) / log(1 + monthlyInterestRate);
 
  // Calculating total amount paid and total interest paid
  double totalAmountPaid = numMonths * monthlyPayment;
  double totalInterestPaid = totalAmountPaid - loanAmount;
 
  // Displaying output
  printf("---------------------------------------\n");
  printf("Loan amount: $%.2lf\n", loanAmount);
  printf("Interest rate: %.2lf%%\n", interestRate);
  printf("Monthly payment: $%.2lf\n", monthlyPayment);
  printf("Number of months: %.2lf\n", numMonths);
  printf("Total amount paid: $%.2lf\n", totalAmountPaid);
  printf("Total interest paid: $%.2lf\n", totalInterestPaid);
 
  return 0;
}