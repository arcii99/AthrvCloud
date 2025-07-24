//FormAI DATASET v1.0 Category: Mortgage Calculator ; Style: active
#include <stdio.h>
#include <math.h>

int main() {
  float loan_amount, interest_rate, monthly_payment, balance, principal_portion, interest_portion;
  int num_payments, i;

  // get input from the user
  printf("Enter the loan amount: ");
  scanf("%f", &loan_amount);

  printf("Enter the interest rate (as a percentage): ");
  scanf("%f", &interest_rate);

  printf("Enter the number of payments: ");
  scanf("%d", &num_payments);

  // convert the interest rate to a decimal and calculate the monthly interest rate
  interest_rate = interest_rate / 100.0;
  float monthly_interest_rate = interest_rate / 12.0;

  // calculate the monthly payment using the formula
  monthly_payment = (loan_amount * monthly_interest_rate * pow(1 + monthly_interest_rate, num_payments)) / (pow(1 + monthly_interest_rate, num_payments) - 1);
  
  // display the monthly payment
  printf("Monthly Payment: $%.2f\n", monthly_payment);

  // initialize the balance to the loan amount
  balance = loan_amount;

  // print the header for the payment schedule
  printf("\nPayment Schedule\n");
  printf("Payment#   Payment Amount   Interest Portion   Principal Portion   Balance\n");

  // loop over the number of payments and calculate the payment amount, interest portion, principal portion, and balance for each payment
  for(i = 1; i <= num_payments; i++) {
    // calculate the interest portion and principal portion for the payment
    interest_portion = balance * monthly_interest_rate;
    principal_portion = monthly_payment - interest_portion;

    // update the balance after the payment
    balance = balance - principal_portion;
    
    // print the payment details
    printf("%7d   $%10.2f   $%10.2f   $%10.2f   $%10.2f\n", i, monthly_payment, interest_portion, principal_portion, balance);
  }

  return 0;
}