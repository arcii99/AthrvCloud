//FormAI DATASET v1.0 Category: Stock market tracker ; Style: ultraprecise
#include <stdio.h>

int main() {
   int stock_data[5] = {100, 150, 200, 175, 125}; // Array to store stock data
   int stock_count = sizeof(stock_data)/sizeof(stock_data[0]); // Get the number of stocks in the array
   
   // Calculate the average stock value
   int total = 0;
   float average;
   for(int i = 0; i < stock_count; i++) {
      total += stock_data[i];
   }
   average = total / (float) stock_count;
   
   // Calculate the highest and lowest stock values
   int highest = stock_data[0];
   int lowest = stock_data[0];
   for(int i = 1; i < stock_count; i++) {
      if(stock_data[i] > highest) {
         highest = stock_data[i];
      }
      if(stock_data[i] < lowest) {
         lowest = stock_data[i];
      }
   }
   
   // Calculate the percentage change from the previous day for each stock
   float percentage_change[stock_count];
   for(int i = 1; i < stock_count; i++) {
      percentage_change[i] = (stock_data[i] - stock_data[i-1]) / (float) stock_data[i-1] * 100;
   }
   
   printf("Stock Market Tracker\n");
   printf("====================\n\n");
   printf("Average stock value: %.2f\n", average);
   printf("Highest stock value: %d\n", highest);
   printf("Lowest stock value: %d\n\n", lowest);
   
   printf("Stock\t\tCurrent Value\tPercentage Change\n");
   printf("------------------------------------------------\n");
   for(int i = 0; i < stock_count; i++) {
      printf("Stock %d\t\t%d\t\t%.2f%%\n", i+1, stock_data[i], percentage_change[i]);
   }
   
   return 0;
}