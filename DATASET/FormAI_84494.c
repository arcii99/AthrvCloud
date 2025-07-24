//FormAI DATASET v1.0 Category: Mortgage Calculator ; Style: puzzling
#include <stdio.h>
#include <math.h>

int main() {
   float P, R, T;
   float emi, interest, principal, balance;
   int n, i;
   
   printf("Enter the Loan Amount: ");
   scanf("%f", &P);
   printf("Enter the Annual Interest Rate (in percentage): ");
   scanf("%f", &R);
   printf("Enter the Loan Tenure (in years): ");
   scanf("%f", &T);

   R = R / 1200; // Calculating Monthly Interest Rate
   n = T * 12; // Calculating Total Number of Monthly Installments

   emi = (P * R * pow(1 + R, n)) / (pow(1 + R, n) - 1); // Calculating EMI
   
   printf("\n");
   printf("Loan Amount: %.2f\n", P);
   printf("Annual Interest Rate: %.2f%%\n", R * 1200);
   printf("Loan Tenure: %.2f years\n", T);
   printf("Monthly EMI: %.2f\n", emi);
   printf("\n");

   balance = P; // Initializing Balance with Total Loan Amount
   for(i=1; i<=n; i++) {
      interest = balance * R; // Calculating Interest Component
      principal = emi - interest; // Calculating Principal Component
      balance -= principal; // Calculating Balance
   }
   
   printf("Total Payment Amount: %.2f\n", emi*n); 
   printf("Total Interest Amount: %.2f\n", emi*n-P);
   
   return 0;
}