//FormAI DATASET v1.0 Category: Mortgage Calculator ; Style: mathematical
#include<stdio.h>
#include<math.h>

int main()
{
  float loan_amount, interest_rate, monthly_interest_rate;
  int no_of_years, months;
  float monthly_payment, total_payment, interest_paid;
  printf("Enter the loan amount: ");
  scanf("%f",&loan_amount);
  printf("Enter the interest rate in percentage: ");
  scanf("%f",&interest_rate);
  printf("Enter the number of years: ");
  scanf("%d",&no_of_years);

  monthly_interest_rate = interest_rate / (12 * 100);
  months = no_of_years * 12;

  monthly_payment = (loan_amount *
                     monthly_interest_rate *
                     pow(1 + monthly_interest_rate, months)) /
                    (pow(1 + monthly_interest_rate, months) - 1);

  total_payment = monthly_payment * months;
  interest_paid = total_payment - loan_amount;

  printf("\nMonthly payment: $%.2f", monthly_payment);
  printf("\nTotal payment: $%.2f", total_payment);
  printf("\nInterest paid: $%.2f", interest_paid);
  return 0;
}