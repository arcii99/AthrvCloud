//FormAI DATASET v1.0 Category: Mortgage Calculator ; Style: shocked
#include <stdio.h>

int main() {
  float p, r, m, n, payment, interest, principal, balance;

  printf("Welcome to the Mortgage Calculator!\n\n");
  
  printf("Please enter the loan amount (in dollars): ");
  scanf("%f", &p);
  
  printf("Please enter the interest rate (as a decimal): ");
  scanf("%f", &r);
  
  printf("Please enter the loan term (in years): ");
  scanf("%f", &n);
  
  printf("\nCalculating your monthly payment for a $%.2f loan at %.2f%% for %.0f years...\n", p, r*100, n);
  
  m = n * 12;
  float i = r / 12;

  payment = p * (i * pow((1 + i), m)) / (pow((1 + i), m) - 1);
  printf("Your monthly payment will be: $%.2f\n", payment);

  balance = p;
  printf("\nHere is the payment schedule for your loan:\n");
  printf("%10s %15s %15s %15s %15s\n", "Month", "Payment", "Interest", "Principal", "Balance");
  for (int j = 1; j <= m; j++) {
    interest = balance * i;
    principal = payment - interest;
    balance -= principal;
    printf("%10d $%15.2f $%15.2f $%15.2f $%15.2f\n", j, payment, interest, principal, balance);
  }
  
  printf("\nThank you for using the Mortgage Calculator!\n");
  
  return 0;
}