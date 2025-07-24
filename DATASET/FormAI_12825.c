//FormAI DATASET v1.0 Category: Mortgage Calculator ; Style: random
#include <stdio.h>

int main() {

  float principal_amount, interest_rate, payment;
  int term, i;

  printf("Enter principal amount: ");
  scanf("%f", &principal_amount);

  printf("Enter interest rate: ");
  scanf("%f", &interest_rate);

  printf("Enter term (in years): ");
  scanf("%d", &term);

  printf("\n");

  float monthly_interest_rate = interest_rate / 1200;
  int total_payments = term * 12;

  float numerator = monthly_interest_rate * principal_amount;
  float denominator = 1 - pow(1 + monthly_interest_rate, -total_payments);

  payment = numerator / denominator;

  printf("Your monthly payment is: $%.2f\n", payment);

  printf("\n");

  printf("Would you like to see a breakdown of your monthly payments?\n");
  printf("Enter 'yes' or 'no': ");

  char response[10];
  scanf("%s", response);

  printf("\n");

  if (strcmp(response, "yes") == 0) {
    printf("Here's a breakdown of your monthly payments:\n");
    printf("\n");

    printf("%-10s %-15s %-15s %-15s\n", "Payment #", "Payment Amount", "Interest Paid", "Principal Paid");

    float balance = principal_amount;
    float month_interest_paid, month_principal_paid;

    for (i = 1; i <= total_payments; i++) {
      month_interest_paid = balance * monthly_interest_rate;
      month_principal_paid = payment - month_interest_paid;

      balance = balance - month_principal_paid;

      printf("%-10d $%-14.2f $%-14.2f $%-14.2f\n", i, payment, month_interest_paid, month_principal_paid);
    }
  }

  else if (strcmp(response, "no") == 0) {
    printf("Thank you for using our mortgage calculator!\n");
  }

  else {
    printf("Invalid response. Please enter 'yes' or 'no'.\n");
  }

  return 0;
}