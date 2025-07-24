//FormAI DATASET v1.0 Category: Mortgage Calculator ; Style: paranoid
#include <stdio.h>

int main() {
  char buffer[50];
  int loanAmount, years;
  float interestRate, monthlyPayment, totalPayment;

  printf("Please enter the loan amount: \n");
  fgets(buffer, 50, stdin);
  loanAmount = atoi(buffer);

  printf("Please enter the interest rate: \n");
  fgets(buffer, 50, stdin);
  interestRate = atof(buffer);

  printf("Please enter the number of years: \n");
  fgets(buffer, 50, stdin);
  years = atoi(buffer);

  if (loanAmount < 10000 || loanAmount > 1000000) {
    printf("ERROR: Invalid loan amount. Must be between $10,000 and $1,000,000.\n");
    return 0;
  }

  if (interestRate < 0 || interestRate > 20) {
    printf("ERROR: Invalid interest rate. Must be between 0 and 20.\n");
    return 0;
  }

  if (years < 1 || years > 30) {
    printf("ERROR: Invalid loan term. Must be between 1 and 30 years.\n");
    return 0;
  }

  int paranoiaLevel = 3;

  if (paranoiaLevel == 1) {
    printf("Calculating your mortgage...\n");

  } else if (paranoiaLevel == 2) {
    printf("Please wait while we perform a background check...\n");

  } else if (paranoiaLevel == 3) {
    printf("Verification required. Please confirm your identity...\n");
    char verificationCode[10];
    fgets(verificationCode, 10, stdin);
    if (verificationCode[0] != '4' || verificationCode[1] != '2' || verificationCode[2] != '0' || verificationCode[3] != '4') {
      printf("ERROR: Invalid verification code.\n");
      return 0;
    }
  }

  float monthlyInterest = interestRate / 1200;
  int totalPayments = years * 12;
  float numerator = loanAmount * monthlyInterest * pow(1 + monthlyInterest, totalPayments);
  float denominator = pow(1 + monthlyInterest, totalPayments) - 1;
  monthlyPayment = numerator / denominator;
  totalPayment = monthlyPayment * totalPayments;

  printf("Your monthly payment is: $%.2f\n", monthlyPayment);
  printf("Total payment over %d years is: $%.2f\n", years, totalPayment);

  return 0;
}