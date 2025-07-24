//FormAI DATASET v1.0 Category: Mortgage Calculator ; Style: systematic
#include <stdio.h>
#include <math.h>

int main() {
   double loan_amount, interest_rate, monthly_payment;
   int duration_in_years;

   // Get inputs from user
   printf("Enter loan amount: ");
   scanf("%lf", &loan_amount);

   printf("Enter interest rate: ");
   scanf("%lf", &interest_rate);

   printf("Enter duration in years: ");
   scanf("%d", &duration_in_years);

   // Convert interest rate to decimal and calculate monthly interest rate
   interest_rate = interest_rate / 100;
   double monthly_interest_rate = interest_rate / 12;

   // Calculate total number of payments
   int total_payments = duration_in_years * 12;

   // Calculate monthly payment
   monthly_payment = (loan_amount * monthly_interest_rate) / (1 - pow(1 + monthly_interest_rate, -total_payments));

   // Display results
   printf("\n");
   printf("Loan Amount: $%.2lf\n", loan_amount);
   printf("Interest Rate: %.2lf%%\n", interest_rate);
   printf("Duration: %d years\n", duration_in_years);
   printf("Monthly Payment: $%.2lf\n", monthly_payment);
   printf("Total Payment: $%.2lf\n", monthly_payment * total_payments);
   printf("Total Interest Paid: $%.2lf\n", (monthly_payment * total_payments) - loan_amount);

   return 0;
}