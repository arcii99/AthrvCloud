//FormAI DATASET v1.0 Category: Mortgage Calculator ; Style: curious
#include <stdio.h>

int main() {
  // Greetings from your friendly neighborhood mortgage calculator!

  float loan_amount; // Here we declare a variable for the loan amount.
  int num_years; // We'll need another for the number of years the loan lasts.
  float rate; // And one for the interest rate.
  float monthly_payment; // Finally, we'll need somewhere to store the monthly payment.

  printf("Hello! I'm here to help you calculate your mortgage payments.\n");
  printf("How much money did you borrow?");
  scanf("%f", &loan_amount); // Here we grab the loan amount from the user.

  printf("Great! And how many years did you take the loan for?");
  scanf("%d", &num_years); // Here we grab the number of years.

  printf("Finally, what's the yearly interest rate (as a decimal)?");
  scanf("%f", &rate); // Here we grab the interest rate.

  float monthly_rate = rate / 12; // We need this to calculate the monthly payment.

  int num_months = num_years * 12; // We also need to know how many months the loan lasts.

  // Now for the fun part!
  monthly_payment = (loan_amount * monthly_rate) / (1 - pow(1 + monthly_rate, -num_months));

  // Let's display the monthly payments.
  printf("Your monthly payment is %0.2f dollars.\n", monthly_payment);

  return 0;
}