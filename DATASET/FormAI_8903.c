//FormAI DATASET v1.0 Category: Mortgage Calculator ; Style: immersive
#include <stdio.h>
#include <stdlib.h>

int main() {
  
  //User input for loan amount and interest rate
  double loanAmount;
  printf("Enter total loan amount: ");
  scanf("%lf", &loanAmount);
  
  double interestRate;
  printf("Enter interest rate: ");
  scanf("%lf", &interestRate);
  
  //User input for loan duration in years
  int years;
  printf("Enter duration of loan (in years): ");
  scanf("%d", &years);
  
  //Conversion of interest rate to monthly rate
  double monthlyRate = (interestRate/100)/12;
  
  //Calculation of number of payments
  int n = years * 12;
  
  //Calculation of monthly payment using payment formula
  double monthlyPayment = (loanAmount*monthlyRate)/(1-pow(1+monthlyRate, -n));
  
  //Output of monthly payment
  printf("\nYour monthly mortgage payment would be: $%.2lf\n", monthlyPayment);
  
  return 0;
}