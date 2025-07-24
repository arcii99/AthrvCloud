//FormAI DATASET v1.0 Category: Mortgage Calculator ; Style: ultraprecise
#include <stdio.h>
#include <math.h>

int main() {
  double loan, rate, payment, principal_paid, interest_paid, total_principal = 0, total_interest = 0, balance;
  int years, months;
  
  // Taking input from the user
  printf("Enter the loan amount: ");
  scanf("%lf", &loan);
  printf("Enter the interest rate in percentage: ");
  scanf("%lf", &rate);
  printf("Enter the number of years: ");
  scanf("%d", &years);

  // Calculating monthly interest rate
  rate = rate / 1200;
  
  // Calculating number of months
  months = years * 12;
  
  // Calculating monthly payment
  payment = (loan * rate) / (1 - pow(1 + rate, -months));

  // Displaying the result
  printf("\n");
  printf("Loan Amount: $%.2lf\n", loan);
  printf("Interest Rate: %.2lf%%\n", rate * 1200);
  printf("Number of Years: %d\n", years);
  printf("Monthly Payment: $%.2lf\n\n", payment);

  // Displaying loan schedule
  printf("Month\tPrincipal\tInterest\tBalance\n");
  printf("--------------------------------------------------\n");

  balance = loan;
  
  for(int i = 1; i <= months; i++) {
    interest_paid = balance * rate;
    principal_paid = payment - interest_paid;

    total_principal += principal_paid;
    total_interest += interest_paid;

    balance -= principal_paid;

    printf("%d\t%.2lf\t\t%.2lf\t\t%.2lf\n", i, principal_paid, interest_paid, balance);
  }

  // Displaying total interest and principal
  printf("\nTotal Principal Paid: $%.2lf\n", total_principal);
  printf("Total Interest Paid: $%.2lf\n", total_interest);

  return 0;
}