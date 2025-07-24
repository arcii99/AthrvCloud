//FormAI DATASET v1.0 Category: Stock market tracker ; Style: Ada Lovelace
// Header files
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// Define struct for stock data
struct stock_data {
   char name[50];
   float price;
   float percent_change;
} ;

// Declare function to print stock data
void print_stock(struct stock_data data) {
   printf("%s\n", data.name);
   printf("Price: $%.2f\n", data.price);
   printf("Percent change: %.2f%%\n", data.percent_change);
}

int main() {
   // Declare and initialize an array of stock data
   struct stock_data stocks[3] = {
      {"Apple Inc.", 141.40, 0.23},
      {"Tesla Inc.", 644.25, -1.54},
      {"Google LLC", 2260.85, 0.15},
   };

   // Display initial stock data
   printf("Stock Market Tracker\n\n");
   for(int i=0; i<3; i++) {
      print_stock(stocks[i]);
   }

   // Simulate changes in stock data
   printf("\nSimulating changes...\n");
   for(int i=0; i<3; i++) {
      stocks[i].price += (float)rand()/(float)(RAND_MAX/10);
      stocks[i].percent_change += (float)rand()/(float)(RAND_MAX/2) - 1;
   }

   // Display updated stock data
   printf("\nUpdated Stock Data\n\n");
   for(int i=0; i<3; i++) {
      print_stock(stocks[i]);
   }

   return 0;
}