//FormAI DATASET v1.0 Category: Stock market tracker ; Style: unmistakable
#include <stdio.h>

int main() {
   float stock_price = 100.00;
   float stock_change = 0.00;

   // Display initial stock price
   printf("Initial Stock Price: %.2f\n", stock_price);

   // Enter stock price change for the day
   printf("Enter Stock Price Change: $");
   scanf("%f", &stock_change);

   // Calculate and display new stock price
   stock_price += stock_change;
   printf("New Stock Price: %.2f\n", stock_price);

   // Determine whether stock went up or down
   if (stock_change > 0) {
      printf("Stock went up by $%.2f\n", stock_change);
   } else if (stock_change < 0) {
      printf("Stock went down by $%.2f\n", -stock_change);
   } else {
      printf("Stock remained the same\n");
   }

   return 0;
}