//FormAI DATASET v1.0 Category: Mortgage Calculator ; Style: Ken Thompson
#include <stdio.h>

int main() {
  float principal, rate, time, interest, payment, balance;
  int months;

  printf("Enter the principal amount: ");
  scanf("%f",&principal);
  printf("Enter the interest rate: ");
  scanf("%f",&rate);
  printf("Enter the time period in years: ");
  scanf("%f",&time);

  interest = rate/1200; // Monthly interest rate
  months = time*12; // Total number of payments
  balance = principal; // Starting balance

  printf("\n\n Payment Schedule:\n");
  printf("--------------------\n");
  printf(" Payment |   Interest  |  Balance \n");

  for(int i=1; i<=months; i++) {
    payment = (principal*interest) / (1 - pow(1+interest, -months));
    interest = balance*interest;
    balance = balance - payment + interest;
    printf("%3d      |  %8.2f   |  %8.2f \n", i, interest, balance);
  }

  printf("\n\nThe monthly payment is: $%.2f", payment);

  return 0;
}