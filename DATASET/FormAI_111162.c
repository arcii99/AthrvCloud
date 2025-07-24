//FormAI DATASET v1.0 Category: Cafe Billing System ; Style: Donald Knuth
#include <stdio.h>
#include <stdlib.h>

int main()
{
   int burger, pizza, sandwich, coffee, tea, coke;
   float burgerPrice = 2.50, pizzaPrice = 3.50, sandwichPrice = 2.00, coffeePrice = 1.50, teaPrice = 1.00, cokePrice = 1.25;
   float totalAmount;

   printf("Welcome to Cafe Billing System\n\n");
   printf("Please enter the quantity of the following items\n");

   printf("Burger: ");
   scanf("%d", &burger);

   printf("Pizza: ");
   scanf("%d", &pizza);

   printf("Sandwich: ");
   scanf("%d", &sandwich);

   printf("Coffee: ");
   scanf("%d", &coffee);

   printf("Tea: ");
   scanf("%d", &tea);

   printf("Coke: ");
   scanf("%d", &coke);

   totalAmount = (burger * burgerPrice) + (pizza * pizzaPrice) + (sandwich * sandwichPrice) + (coffee * coffeePrice) + (tea * teaPrice) + (coke * cokePrice);

   printf("\n\nYour Total Amount is: $%.2f", totalAmount);

   return 0;
}