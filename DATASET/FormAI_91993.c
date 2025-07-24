//FormAI DATASET v1.0 Category: Stock market tracker ; Style: mathematical
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int main() {
  int stock_price[10]; // Price of 10 stocks
  int sum = 0; // Sum of prices of all stocks
  float average; // Average of prices of all stocks
  int max_price = 0; // Maximum price among all stocks
  int min_price = 1000000; // Minimum price among all stocks

  // Generate random prices for each stock
  srand(time(0)); // Set random seed using current time
  for(int i=0; i<10; i++) {
    stock_price[i] = rand()%1000 + 100; // Generate random price between 100 and 1099
    printf("Stock %d Price: %d\n", i+1, stock_price[i]);
    sum += stock_price[i]; // Add price to sum
    if(stock_price[i] > max_price) {
      max_price = stock_price[i]; // Update maximum price
    }
    if(stock_price[i] < min_price) {
      min_price = stock_price[i]; // Update minimum price
    }
  }

  // Calculate average price
  average = (float) sum/10;

  // Print summary statistics
  printf("\n");
  printf("SUM: %d\n", sum);
  printf("AVERAGE: %.2f\n", average);
  printf("MAXIMUM PRICE: %d\n", max_price);
  printf("MINIMUM PRICE: %d\n", min_price);

  return 0;
}