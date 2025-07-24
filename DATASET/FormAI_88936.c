//FormAI DATASET v1.0 Category: Mortgage Calculator ; Style: multiplayer
#include <stdio.h>

int main() {
  float principal, interest_rate, monthly_rate, payment;
  int num_payments;

  printf("Enter principal amount: ");
  scanf("%f", &principal);
  printf("Enter interest rate: ");
  scanf("%f", &interest_rate);
  printf("Enter number of payments: ");
  scanf("%d", &num_payments);

  // Calculate monthly interest rate
  monthly_rate = interest_rate / 1200;

  // Calculate payment
  payment = (principal * monthly_rate) / (1 - pow(1 + monthly_rate, -num_payments));

  printf("\nYour monthly payment is $%.2f.\n\n", payment);

  char choice;
  printf("Would you like to calculate another mortgage? (y/n) ");
  scanf(" %c", &choice);

  while (choice == 'y') {
    printf("\nEnter principal amount: ");
    scanf("%f", &principal);
    printf("Enter interest rate: ");
    scanf("%f", &interest_rate);
    printf("Enter number of payments: ");
    scanf("%d", &num_payments);

    // Recalculate payment
    payment = (principal * monthly_rate) / (1 - pow(1 + monthly_rate, -num_payments));
    printf("\nYour monthly payment is $%.2f.\n\n", payment);

    printf("Would you like to calculate another mortgage? (y/n) ");
    scanf(" %c", &choice);
  }

  printf("Goodbye!\n");

  return 0;
}