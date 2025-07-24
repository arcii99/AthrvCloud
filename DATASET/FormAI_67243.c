//FormAI DATASET v1.0 Category: Mortgage Calculator ; Style: single-threaded
#include <stdio.h>
#include <math.h>

int main() {
  float principal, interest_rate, monthly_payment;
  int loan_term;

  printf("Enter the mortgage principal amount: ");
  scanf("%f", &principal);

  printf("Enter the interest rate (percentage per year): ");
  scanf("%f", &interest_rate);

  printf("Enter the loan term (in years): ");
  scanf("%d", &loan_term);

  float monthly_interest = interest_rate / (12 * 100);
  int number_of_payments = loan_term * 12;

  monthly_payment = (principal * monthly_interest * pow(1 + monthly_interest, number_of_payments)) / (pow(1 + monthly_interest, number_of_payments) - 1);

  printf("The monthly payment is: $%.2f\n", monthly_payment);
}