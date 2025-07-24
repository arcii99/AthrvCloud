//FormAI DATASET v1.0 Category: Mortgage Calculator ; Style: protected
#include<stdio.h>
#include<math.h>

int main() {
  float loanAmount, interest, monthlyPayment, balance;
  int years;
  
  printf("Enter loan amount: ");
  scanf("%f", &loanAmount);
  
  printf("Enter interest rate: ");
  scanf("%f", &interest);
  
  printf("Enter the number of years: ");
  scanf("%d", &years);
  
  interest = interest/100;
  float totalMonths = years * 12;
  float monthlyInterest = interest / 12;
  
  monthlyPayment = (loanAmount * monthlyInterest) / (1 - pow(1+monthlyInterest, -totalMonths));
  printf("\nMonthly payment: $%.2f", monthlyPayment);
  
  printf("\n\nPayment Schedule\n\n");
  printf("Month\tPayment\tInterst\tPrincipal\tBalance\n");

  balance = loanAmount;
  
  for (int i=1; i<=totalMonths; i++) {
    float interestPaid = balance * monthlyInterest;
    float principalPaid = monthlyPayment - interestPaid;
    balance = balance - principalPaid;
    printf("%d\t%.2f\t%.2f\t%.2f\t%.2f\n", i, monthlyPayment, interestPaid, principalPaid, balance);
  }
  
  return 0;
}