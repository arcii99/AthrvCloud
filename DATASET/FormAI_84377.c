//FormAI DATASET v1.0 Category: Mortgage Calculator ; Style: realistic
#include<stdio.h>

int main()
{
  float loan_amount, interest_rate, monthly_payment, balance, number_of_years, total_interest = 0;
  int number_of_payments;

  printf("Enter the Loan Amount: ");
  scanf("%f", &loan_amount);

  printf("Enter the Interest Rate (in percentage): ");
  scanf("%f", &interest_rate);

  printf("Enter the Number of years for the Loan: ");
  scanf("%f", &number_of_years);

  // Calculation
  interest_rate /= 1200; // monthy interest rate
  number_of_payments = number_of_years * 12; // total number of payments
  monthly_payment = (loan_amount * interest_rate) / (1 - (pow((1 + interest_rate), -1 * number_of_payments)));
  balance = loan_amount;

  // Print the Amortization Schedule
  printf("\nLoan Amount: $%.2f\n", loan_amount);
  printf("Interest Rate: %.2f%%\n", interest_rate * 1200);
  printf("Number of Payments: %d\n", number_of_payments);
  printf("Monthly Payment: $%.2f\n", monthly_payment);

  printf("\nPayment#\tInterest\tPrincipal\tBalance\n");
  printf("--------\t--------\t---------\t-------\n");

  for (int i = 1; i <= number_of_payments; i++) 
  {
    float interest_part = balance * interest_rate;
    float principal_part = monthly_payment - interest_part;

    total_interest += interest_part;
    balance -= principal_part;

    printf("%d\t\t%.2f\t\t%.2f\t\t%.2f\n", i, interest_part, principal_part, balance);

    if (balance <= 0) 
    {
      break;
    }
  }

  printf("\nTotal Interest Paid: $%.2f\n", total_interest);
  printf("Total Amount Paid: $%.2f\n", (monthly_payment * number_of_payments));
  return 0;
}