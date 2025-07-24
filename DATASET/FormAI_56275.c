//FormAI DATASET v1.0 Category: Mortgage Calculator ; Style: calm
#include<stdio.h>
#include<math.h>

int main() {
  float principal_amount, rate_of_interest, time_period, monthly_payment, total_payment, interest_amount;
  int choice;

  printf("Welcome to the Mortgage Calculator!\n\n");
  printf("Please enter the principal amount: ");
  scanf("%f", &principal_amount);

  printf("\nPlease enter the interest rate: ");
  scanf("%f", &rate_of_interest);

  printf("\nPlease enter the time period in months: ");
  scanf("%f", &time_period);

  printf("\n\nPlease choose an option from the menu below:\n");
  printf("1. Calculate monthly payment\n");
  printf("2. Calculate total payment\n");
  printf("3. Calculate interest amount paid\n");
  printf("4. Exit\n");

  printf("\nEnter your choice: ");
  scanf("%d", &choice);

  switch (choice) {
    case 1:
      monthly_payment = (principal_amount * (rate_of_interest/1200)) / (1 - pow((1 + (rate_of_interest/1200)),-time_period));
      printf("\nYour monthly payment will be: $%.2f\n", monthly_payment);
      break;
    case 2:
      total_payment = (principal_amount * pow((1 + (rate_of_interest/1200)),time_period));
      printf("\nYour total payment will be: $%.2f\n", total_payment);
      break;
    case 3:
      interest_amount = (total_payment - principal_amount);
      printf("\nYour interest amount paid will be: $%.2f\n", interest_amount);
      break;
    case 4:
      printf("\nThanks for using the Mortgage Calculator. Goodbye!\n");
      break;
    default:
      printf("\nInvalid choice. Please choose again.\n");
      break;
  }

  return 0;
}