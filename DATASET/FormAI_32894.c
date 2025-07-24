//FormAI DATASET v1.0 Category: Mortgage Calculator ; Style: paranoid
#include <stdio.h>

int main() {
  float loan_amount, interest_rate, monthly_payment, balance;

  printf("Enter loan amount: $");
  scanf("%f", &loan_amount);

  printf("Enter interest rate: ");
  scanf("%f", &interest_rate);

  printf("Enter monthly payment: $");
  scanf("%f", &monthly_payment);

  balance = loan_amount;
  int months = 0;

  printf("\nNumber of payments: ");
  while (balance > 0) {
    balance += (balance * (interest_rate / 1200)) - monthly_payment;

    months++;

    if (months > 600) {
      printf("\nYou will still be paying off this loan in 50 years. Are you sure you want to continue? (Y/N) ");
      char answer;
      scanf(" %c", &answer);

      if (answer == 'N' || answer == 'n') {
        printf("\nExiting program...");
        return 0;
      }
    }
  }

  printf("%d", months);
  printf("\nLoan paid off in %d months.", months);
  printf("\nTotal interest paid: $%.2f", (months * monthly_payment) - loan_amount);

  return 0;
}