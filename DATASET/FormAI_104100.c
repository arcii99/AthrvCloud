//FormAI DATASET v1.0 Category: Mortgage Calculator ; Style: retro
#include <stdio.h>

int main() {
  float loanAmount, rate, years, monthlyPayment, totalPayment, interest;
  
  printf("Welcome to the Retro Mortgage Calculator!\n\n");

  printf("Enter the loan amount: ");
  scanf("%f", &loanAmount);

  printf("Enter the interest rate in percentage: ");
  scanf("%f", &rate);

  printf("Enter the loan period in years: ");
  scanf("%f", &years);

  // converting interest rate from percentage to decimal
  rate = rate / 100;

  // calculating monthly interest rate
  float monthlyRate = rate / 12;

  // calculating number of payments
  float n = years * 12;

  // calculating monthly payment
  monthlyPayment = (loanAmount * monthlyRate * pow(1 + monthlyRate, n)) / (pow(1 + monthlyRate, n) - 1);

  // calculating total amount paid
  totalPayment = monthlyPayment * n;

  // calculating total interest paid
  interest = totalPayment - loanAmount;

  printf("\n------------------------\n");
  printf("MORTGAGE CALCULATOR RESULT\n");
  printf("------------------------\n");
  printf("Loan Amount:    $%.2f\n", loanAmount);
  printf("Interest Rate:  %.2f%%\n", rate*100);
  printf("Loan Period:    %.0f years\n", years);
  printf("Monthly payment:$%.2f\n", monthlyPayment);
  printf("Total payment:  $%.2f\n", totalPayment);
  printf("Total interest: $%.2f\n", interest);
  
  printf("\nThank you for using Retro Mortgage Calculator!\n");

  return 0;
}