//FormAI DATASET v1.0 Category: Stock market tracker ; Style: ultraprecise
#include <stdio.h>
#include <stdlib.h>

int main() {
   int num_stocks, i, j;
   float *stock_prices, average_price = 0;
   
   printf("Enter the number of stocks to track: ");
   scanf("%d", &num_stocks);
   
   stock_prices = (float*) malloc(num_stocks * sizeof(float));
   
   if(stock_prices == NULL) {
      printf("Memory allocation failed.");
      return 0;
   }
   
   for(i = 0; i < num_stocks; i++) {
      printf("Enter the price of stock %d: ", i + 1);
      scanf("%f", &stock_prices[i]);
      
      average_price += stock_prices[i];
   }
   
   average_price /= num_stocks;
   
   printf("\nStock prices entered:\n");
   
   for(i = 0; i < num_stocks; i++) {
      printf("Stock %d: %.2f\n", i + 1, stock_prices[i]);
      
      if(stock_prices[i] < average_price) {
         printf("Stock %d is below average price.\n", i + 1);
      } else if(stock_prices[i] > average_price) {
         printf("Stock %d is above average price.\n", i + 1);
      } else {
         printf("Stock %d is at average price.\n", i + 1);
      }
   }
   
   free(stock_prices);
   
   return 0;
}