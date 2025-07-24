//FormAI DATASET v1.0 Category: Stock market tracker ; Style: optimized
#include <stdio.h>

int main() {
   int stockPrices[] = {50, 75, 65, 80, 90, 100, 55, 70};
   int numDays = sizeof(stockPrices) / sizeof(stockPrices[0]);
   int minPrice = stockPrices[0], maxPrice = stockPrices[0];
   int maxProfit = 0, buyDay = 0, sellDay = 0;

   for(int i = 1; i < numDays; i++) {
      if(stockPrices[i] < minPrice) {
         minPrice = stockPrices[i];
         buyDay = i;
         sellDay = i;
      }
      else if(stockPrices[i] > maxPrice) {
         maxPrice = stockPrices[i];
         sellDay = i;
         int profit = maxPrice - minPrice;
         if(profit > maxProfit) {
            maxProfit = profit;
         }
      }
   }

   printf("Maximum profit: $%d\n", maxProfit);
   printf("Buy on day %d at price $%d\n", buyDay+1, stockPrices[buyDay]);
   printf("Sell on day %d at price $%d\n", sellDay+1, stockPrices[sellDay]);

   return 0;
}