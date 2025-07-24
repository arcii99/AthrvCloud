//FormAI DATASET v1.0 Category: Stock market tracker ; Style: satisfied
#include <stdio.h>
#define N 10

int main() {
   int stock_prices[N] = {100, 120, 95, 80, 110, 115, 90, 105, 125, 130};
   
   int highest_price = stock_prices[0];
   int highest_index = 0;
   int lowest_price = stock_prices[0];
   int lowest_index = 0;
   float average_price = 0;
   
   printf("Today's stock prices:\n\n");
   
   for(int i = 0; i < N; i++) {
      printf("Price %d: %d\n", i+1, stock_prices[i]);
      
      if(stock_prices[i] > highest_price) {
         highest_price = stock_prices[i];
         highest_index = i;
      }
      
      if(stock_prices[i] < lowest_price) {
         lowest_price = stock_prices[i];
         lowest_index = i;
      }
      
      average_price += stock_prices[i];
   }
   
   average_price /= N;
   
   printf("\nHighest price of the day: $%d (Price %d)\n", highest_price, highest_index+1);
   printf("Lowest price of the day: $%d (Price %d)\n", lowest_price, lowest_index+1);
   printf("Average price of the day: $%.2f\n", average_price);
   
   return 0;
}