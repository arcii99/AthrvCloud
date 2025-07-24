//FormAI DATASET v1.0 Category: Stock market tracker ; Style: real-life
#include<stdio.h>

int main(){
   //insert stock data here or use user input
   int stockPrices[] = {50, 60, 55, 62, 55, 54, 57, 70, 80, 82, 85};
   int numPrices = sizeof(stockPrices)/sizeof(stockPrices[0]);
   int highestPrice = stockPrices[0];
   int lowestPrice = stockPrices[0];
   int total = 0;
   double average = 0.0;

   printf("Daily Stock Prices Tracker\n");
   printf("------------------------------\n");

   for(int i=0;i<numPrices;i++){
      printf("Price on day %d: $%d\n",i+1,stockPrices[i]);

      //check for highest and lowest price
      if(stockPrices[i] > highestPrice){
         highestPrice = stockPrices[i];
      }
      if(stockPrices[i] < lowestPrice){
         lowestPrice = stockPrices[i];
      }

      total += stockPrices[i];
   }

   average = (double)total/numPrices;

   printf("------------------------------\n");
   printf("Highest price: $%d\n",highestPrice);
   printf("Lowest price: $%d\n",lowestPrice);
   printf("Average price: $%.2f\n",average);

   return 0;
}