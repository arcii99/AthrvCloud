//FormAI DATASET v1.0 Category: Mortgage Calculator ; Style: random
#include <stdio.h>

int main() {
  float principal, interest_rate, monthly_payment, remaining_balance;
  int num_payments;
  float monthly_interest, interest_paid, principal_paid;

  printf("Enter the loan amount: ");
  scanf("%f", &principal);

  printf("Enter the interest rate: ");
  scanf("%f", &interest_rate);

  printf("Enter the number of payments: ");
  scanf("%d", &num_payments);

  monthly_interest = interest_rate / 1200;
  remaining_balance = principal;

  printf("\nPayment#\tPayment\t\tInterest\tPrincipal\tBalance\n");
  for (int i = 1; i <= num_payments; i++) {
    interest_paid = remaining_balance * monthly_interest;
    principal_paid = monthly_payment - interest_paid;
    remaining_balance -= principal_paid;

    printf("%d\t\t$%.2f\t\t$%.2f\t\t$%.2f\t\t$%.2f\n", i, monthly_payment, interest_paid, principal_paid, remaining_balance);

    if (remaining_balance < 0) {
      printf("\nYou have paid off the loan in %d months!\n", i);
      break;
    }
  }

  return 0;
}