//FormAI DATASET v1.0 Category: Mortgage Calculator ; Style: inquisitive
#include <stdio.h>

int main() {
  printf("Welcome to your personal mortgage calculator!\n");
  float loan_amt;
  printf("Enter the amount of your loan: ");
  scanf("%f", &loan_amt);
  printf("Great! Now enter the interest rate in percentage: ");
  float interest_rate;
  scanf("%f", &interest_rate);
  while(interest_rate < 0) {
      printf("You entered a negative interest rate. Please enter a positive interest rate: ");
      scanf("%f", &interest_rate);
  }
  interest_rate /= 100;
  printf("Finally, enter the duration of the loan in years: ");
  float loan_duration;
  scanf("%f", &loan_duration);
  while(loan_duration < 0) {
      printf("You entered a negative loan duration. Please enter a positive loan duration: ");
      scanf("%f", &loan_duration);
  }
  float monthly_rate = interest_rate / 12;
  float num_payments = loan_duration * 12;
  float monthly_payment = (loan_amt * monthly_rate) / (1 - pow(1 + monthly_rate, -num_payments));

  printf("\nYour monthly payment is $%.2f\n", monthly_payment);
  printf("Over the course of %.0f years, you will pay a total of $%.2f towards this loan.\n", loan_duration, monthly_payment * num_payments);
  return 0;
}