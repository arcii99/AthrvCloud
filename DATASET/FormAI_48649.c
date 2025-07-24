//FormAI DATASET v1.0 Category: Cafe Billing System ; Style: mind-bending
#include <stdio.h>

// Defining constants for prices and taxes
#define COFFEE_PRICE 2.50
#define TEA_PRICE 1.50
#define TAX_RATE 0.07

// Function to calculate the total cost
float calculateCost(int coffeeCount, int teaCount) {
   float subtotal = (coffeeCount * COFFEE_PRICE) + (teaCount * TEA_PRICE);
   float tax = subtotal * TAX_RATE;
   float total = subtotal + tax;
   return total;
}

int main() {
   // Initializing variables
   int coffeeCount = 0;
   int teaCount = 0;
   
   printf("Welcome to Mind Cafe!\n");
   printf("Enter the number of coffees: ");
   scanf("%d", &coffeeCount);

   printf("Enter the number of teas: ");
   scanf("%d", &teaCount);

   printf("\n");

   // Printing the bill
   printf("===Mind Cafe Bill===\n");
   printf("Coffee\t%d\t$%.2f\n", coffeeCount, coffeeCount * COFFEE_PRICE);
   printf("Tea  \t%d\t$%.2f\n", teaCount, teaCount * TEA_PRICE);

   // Calculating and printing the subtotal, tax, and total
   float subtotal = (coffeeCount * COFFEE_PRICE) + (teaCount * TEA_PRICE);
   float tax = subtotal * TAX_RATE;
   float total = calculateCost(coffeeCount, teaCount);

   printf("====================\n");
   printf("Subtotal\t$%.2f\n", subtotal);
   printf("Tax\t\t$%.2f\n", tax);
   printf("--------------------\n");
   printf("Total\t\t$%.2f\n", total);

   printf("\nThank you for coming to Mind Cafe! Please come again soon!");

   return 0;
}