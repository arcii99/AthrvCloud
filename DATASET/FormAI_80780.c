//FormAI DATASET v1.0 Category: Mortgage Calculator ; Style: all-encompassing
#include <stdio.h>
#include <math.h>

int main() {
   double principal, rate, time, emi, interest, total_interest, total_payment;
   
   printf("Enter Principal: ");
   scanf("%lf", &principal);

   printf("Enter Annual Interest Rate: ");
   scanf("%lf", &rate);

   printf("Enter Time in Years: ");
   scanf("%lf", &time);
   
   rate /= (12*100); // convert annual rate to monthly rate
   time *= 12; // convert time in years to months
   
   emi = (principal*rate*pow(1+rate,time))/(pow(1+rate,time)-1); // calculate EMI
  
   total_payment = emi*time; // calculate total payment over the loan period
   
   total_interest = total_payment - principal; // calculate total interest paid
   
   printf("\nLoan Details:\n");
   printf("Principal: %.2lf\n", principal);
   printf("Annual Interest Rate: %.2lf%%\n", (rate*12*100));
   printf("Time in Months: %.0lf\n", time);
   printf("Monthly Payment (EMI): %.2lf\n", emi);
   printf("Total Payment: %.2lf\n", total_payment);
   printf("Total Interest Paid: %.2lf\n", total_interest);

   return 0;
}