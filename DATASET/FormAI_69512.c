//FormAI DATASET v1.0 Category: Mortgage Calculator ; Style: Sherlock Holmes
#include <stdio.h>
#include <stdlib.h>

int main() {
   float principal, rate, time, interest;
   int option;

   printf("Welcome to the Mortgage Calculator, my dear Watson!\n");
   printf("Please select an option:\n");
   printf("1) Calculate Mortgage Payment.\n");
   printf("2) Calculate Total Interest paid over the life of Mortgage.\n");
   printf("3) Exit.\n");

   scanf("%d", &option);

   while(option != 3) {
      switch(option) {

         case 1:
            printf("\nPlease enter Principal amount: ");
            scanf("%f", &principal);

            printf("Please enter Annual Interest Rate: ");
            scanf("%f", &rate);

            printf("Please enter the Mortgage Term in years: ");
            scanf("%f", &time);

            rate = rate / (12 * 100);    // Monthly Interest Rate
            time = time * 12;    // Total Months

            float emi;
            emi = (principal * rate * pow(1 + rate, time)) / (pow(1 + rate, time) - 1);

            printf("\nYour Monthly Mortgage Payment is: $%.2f\n", emi);
            break;

         case 2:
            printf("\nPlease enter Principal amount: ");
            scanf("%f",&principal);

            printf("Please enter Annual Interest Rate: ");
            scanf("%f",&rate);

            printf("Please enter Mortgage Term in years: ");
            scanf("%f",&time);

            rate = rate/(12*100);    // Monthly Interest Rate
            time = time*12;          // Total Months

            float total_payment, base_payment, total_interest;

            total_payment = (principal*rate*pow(1+rate,time))/(pow(1+rate,time)-1);
            base_payment = principal/ time;

            total_interest = total_payment*time - principal;

            printf("\nTotal interest paid over the life of the Mortgage is: $%.2f\n", total_interest);

            break;

         default:
            printf("\nInvalid Option, Please select a valid Option:\n");
            printf("1) Calculate Mortgage Payment.\n");
            printf("2) Calculate Total Interest paid over the life of Mortgage.\n");
            printf("3) Exit.\n");
            break;
      }
      printf("\nPlease select an option:\n");
      printf("1) Calculate Mortgage Payment.\n");
      printf("2) Calculate Total Interest paid over the life of Mortgage.\n");
      printf("3) Exit.\n");

      scanf("%d", &option);
   }
   printf("\nThank you for using the Mortgage Calculator, my dear Watson!\n");

   return 0;
}