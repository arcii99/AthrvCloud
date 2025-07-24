//FormAI DATASET v1.0 Category: Mortgage Calculator ; Style: visionary
// Mortgage Calculator Program

#include <stdio.h>

int main() {
  float loanAmount, interestRate, monthlyPayment, balance, interestPaid, principalPaid;
  int numMonths, i;

  // Getting loan details from user
  printf("Enter the loan amount: ");
  scanf("%f", &loanAmount);

  printf("Enter the interest rate in percentage: ");
  scanf("%f", &interestRate);

  printf("Enter the number of months to pay off the loan: ");
  scanf("%d", &numMonths);

  // Calculating monthly interest rate
  interestRate = interestRate / 1200;

  // Calculating monthly payment
  monthlyPayment = (loanAmount * interestRate) / (1 - pow(1 + interestRate, -numMonths));

  // Displaying the monthly payment
  printf("Your monthly payment will be: $%.2f\n", monthlyPayment);

  // Displaying the payments schedule
  balance = loanAmount;

  printf("\nMonth   Payment   Interest Paid   Principal Paid   New Balance");
  printf("\n-----   -------   -------------   ---------------   -----------");

  for (i = 1; i <= numMonths; i++) {
    // Calculating interest paid and principal paid
    interestPaid = balance * interestRate;
    principalPaid = monthlyPayment - interestPaid;
    balance = balance - principalPaid;

    // Displaying payment details for each month
    printf("\n%5d  $%7.2f    $%7.2f     $%7.2f        $%7.2f", i, monthlyPayment, interestPaid, principalPaid, balance);
  }

  return 0;
}