//FormAI DATASET v1.0 Category: Stock market tracker ; Style: irregular
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {

  srand(time(0)); // Seed random number generator

  int stock1 = rand()%1000; // Generate random value for stock 1
  int stock2 = rand()%1000; // Generate random value for stock 2
  int stock3 = rand()%1000; // Generate random value for stock 3
  int stock4 = rand()%1000; // Generate random value for stock 4
  int stock5 = rand()%1000; // Generate random value for stock 5

  int total = stock1+stock2+stock3+stock4+stock5; // Calculate total value of all stocks
  float average = (float)total/5; // Calculate average value of all stocks

  printf("Today's stock market report:\n\n");
  printf("Stock 1: %d\n", stock1);
  printf("Stock 2: %d\n", stock2);
  printf("Stock 3: %d\n", stock3);
  printf("Stock 4: %d\n", stock4);
  printf("Stock 5: %d\n\n", stock5);
  printf("Total value of all stocks: %d\n", total);
  printf("Average value of all stocks: %.2f\n", average);

  return 0;
}