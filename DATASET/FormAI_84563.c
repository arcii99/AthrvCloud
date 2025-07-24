//FormAI DATASET v1.0 Category: Mortgage Calculator ; Style: synchronous
#include <stdio.h>

int main() {
  double loan_amount, rate, monthly_payment, remaining_balance, principle_paid, interest_paid;
  int num_payments, i;

  printf("Enter the loan amount: ");
  scanf("%lf", &loan_amount);
  printf("Enter the interest rate: ");
  scanf("%lf", &rate);
  printf("Enter the number of payments: ");
  scanf("%d", &num_payments);

  rate /= 1200.0; // convert annual rate to monthly rate
  monthly_payment = loan_amount * rate / (1 - pow(1 + rate, -num_payments));
  remaining_balance = loan_amount;

  printf("\nMonthly payment: $%.2lf\n\n", monthly_payment);

  printf(" Payment #\t Payment  \t Interest Paid \t Principle Paid \t Remaining Balance\n");
  printf("-----------------------------------------------------------------------------------\n");

  for (i = 1; i <= num_payments; i++) {
    interest_paid = remaining_balance * rate;
    principle_paid = monthly_payment - interest_paid;
    remaining_balance -= principle_paid;

    printf(" %-12d\t$%.2lf\t$%.2lf\t$%.2lf\t$%.2lf\n", i, monthly_payment, interest_paid, principle_paid, remaining_balance);
  }

  return 0;
}