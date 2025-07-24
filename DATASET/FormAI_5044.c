//FormAI DATASET v1.0 Category: Cafe Billing System ; Style: visionary
#include <stdio.h>
#include <stdlib.h>

int main(void) {
   const float TAX_RATE = 0.05;
   float mealPrice, tipRate;
   float tipAmount, taxAmount, totalCost;

   printf("***Welcome to the visionary C Cafe Billing System***\n\n");

   // Get the meal price from user
   printf("What is the price of your meal? ");
   scanf("%f", &mealPrice);

   // Get the tip rate from user
   printf("What percentage would you like to tip? ");
   scanf("%f", &tipRate);

   // Calculate tip amount
   tipAmount = (mealPrice * (tipRate / 100));

   // Calculate tax amount
   taxAmount = (mealPrice * TAX_RATE);

   // Calculate total cost
   totalCost = (mealPrice + tipAmount + taxAmount);

   // Display the results
   printf("\nYour meal price:\t\t$%.2f", mealPrice);
   printf("\nYour tip rate:\t\t\t%.2f%%", tipRate);
   printf("\nTip amount:\t\t\t$%.2f", tipAmount);
   printf("\nTax amount:\t\t\t$%.2f", taxAmount);
   printf("\nTotal cost:\t\t\t$%.2f", totalCost);

   printf("\n\nThank you for using C Cafe Billing System!");

   return 0;
}