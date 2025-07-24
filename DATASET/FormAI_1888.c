//FormAI DATASET v1.0 Category: Mortgage Calculator ; Style: intelligent
#include <stdio.h>

int main() {
  double totalAmount, interestRate, monthlyPayment, principle, interest, balance;

  printf("Enter total amount borrowed: ");
  scanf("%lf", &totalAmount);

  printf("Enter interest rate: ");
  scanf("%lf", &interestRate);

  printf("Enter monthly payment: ");
  scanf("%lf", &monthlyPayment);

  principle = totalAmount;
  balance = totalAmount;
  printf("Month | Payment | Principle | Interest | Balance\n");
  int month = 1;
  while (balance > 0) {
    interest = balance * (interestRate / 100 / 12);
    principle = monthlyPayment - interest;
    balance = balance - principle;

    printf("%d\t%.2f\t%.2f\t%.2f\t%.2f\n", month, monthlyPayment, principle, interest, balance>0 ? balance : 0.0);
    month++;
  }

  return 0;
}