//FormAI DATASET v1.0 Category: Mortgage Calculator ; Style: post-apocalyptic
#include <stdio.h>

int main() {
   int loan_amount, years, total_payments, payment_amount, interest_rate, remaining;
   float monthly_interest;

   // Get loan amount
   printf("Enter loan amount: ");
   scanf("%d", &loan_amount);

   // Get interest rate
   printf("Enter interest rate: ");
   scanf("%d", &interest_rate);

   // Get years
   printf("Enter number of years: ");
   scanf("%d", &years);

   // Calculate monthly interest and total payments
   monthly_interest = (float)interest_rate / 12 / 100;
   total_payments = years * 12;

   // Calculate payment amount
   payment_amount = (float)loan_amount * monthly_interest * pow(1 + monthly_interest, total_payments) / (pow(1 + monthly_interest, total_payments) - 1);

   // Display results
   printf("\nLoan Amount: %d\n", loan_amount);
   printf("Interest Rate: %d%%\n", interest_rate);
   printf("Number of Years: %d\n", years);
   printf("Monthly Payment: $%d", payment_amount);

   // Simulate post-apocalyptic scenario with remaining payments
   remaining = total_payments;
   while (remaining > 0) {
      printf("\n\n%d remaining payments until the system is offline.", remaining);
      remaining--;
      sleep(1);
   }

   return 0;
}