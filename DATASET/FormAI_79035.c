//FormAI DATASET v1.0 Category: Mortgage Calculator ; Style: curious
#include <stdio.h>
#include <math.h>

int main()
{
  float loanAmount, interestRate, monthlyPayment, totalInterest, principal, interest, balance;
  int numMonths;

  printf("Welcome to the Mortgage Calculator!\n\n");

  printf("Please enter the loan amount: ");
  scanf("%f", &loanAmount);

  printf("Please enter the interest rate in percentage: ");
  scanf("%f", &interestRate);

  printf("Please enter the number of months for repayment: ");
  scanf("%d", &numMonths);

  // Calculate monthly payment using formula
  float rate = (interestRate/100)/12;
  monthlyPayment = loanAmount * ((rate * pow(1 + rate, numMonths)) / (pow(1 + rate, numMonths) - 1));

  printf("\nYour monthly payment is: $%.2f\n", monthlyPayment);

  // Calculate total interest and principal paid
  totalInterest = 0;
  principal = loanAmount;
  printf("\n          Interest       Principal         Balance\n");
  for(int month=1; month<=numMonths; month++)
  {
    interest = principal * rate;
    balance = principal + interest - monthlyPayment;
    totalInterest += interest;
    printf("Month %d: $%.2f     $%.2f        $%.2f\n", month, interest, (monthlyPayment - interest), balance);
    principal = balance;
  }

  printf("\nTotal interest paid over the life of the loan is: $%.2f\n", totalInterest);

  return 0;
}