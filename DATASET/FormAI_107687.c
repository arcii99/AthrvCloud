//FormAI DATASET v1.0 Category: Stock market tracker ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_DAYS 5
#define MAX_COMPANIES 3

int main() {
  int stocks[MAX_DAYS][MAX_COMPANIES]; // Array to store stock prices
  int highest[MAX_COMPANIES]; // Array to store highest stock prices
  int lowest[MAX_COMPANIES]; // Array to store lowest stock prices
  
  // Initialize random seed
  srand(time(NULL));
  
  // Generate random stock prices for each company over five days
  for (int day = 0; day < MAX_DAYS; day++) {
    printf("Day %d: ", day+1);
    for (int company = 0; company < MAX_COMPANIES; company++) {
      stocks[day][company] = rand() % 50 + 50; // Random value between 50 and 99
      printf("%d ", stocks[day][company]);
      
      // Check if this is the highest stock price so far for this company
      if (day == 0 || stocks[day][company] > highest[company]) {
        highest[company] = stocks[day][company];
      }
      
      // Check if this is the lowest stock price so far for this company
      if (day == 0 || stocks[day][company] < lowest[company]) {
        lowest[company] = stocks[day][company];
      }
    }
    printf("\n");
  }
  
  // Print highest and lowest stock prices for each company
  for (int company = 0; company < MAX_COMPANIES; company++) {
    printf("Company %d: Highest price = %d, Lowest price = %d\n", company+1, highest[company], lowest[company]);
  }
  
  return 0;
}