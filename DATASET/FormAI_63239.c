//FormAI DATASET v1.0 Category: Mortgage Calculator ; Style: rigorous
#include <stdio.h>

int main() {
  double loanAmount, rate, monthlyPayment, principle, interest, balance;
  int numMonths, i;
  
  printf("Enter the loan amount: ");
  scanf("%lf", &loanAmount);
  printf("Enter the annual interest rate: ");
  scanf("%lf", &rate);
  printf("Enter the number of months: ");
  scanf("%d", &numMonths);
  
  rate /= 1200;
  balance = loanAmount;
  
  printf("\nMonth \t Payment \t Interest \t Principle \t Balance\n");
  
  for(i = 1; i <= numMonths; i++) {
    interest = rate * balance;
    monthlyPayment = (loanAmount * rate) / (1 - pow(1 + rate, -numMonths));
    principle = monthlyPayment - interest;
    balance -= principle;
    
    printf("%d \t $%.2lf \t\t $%.2lf \t\t $%.2lf \t\t $%.2lf\n", i, monthlyPayment, interest, principle, balance);
  }
  
  return 0;
}