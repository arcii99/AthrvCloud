//FormAI DATASET v1.0 Category: Stock market tracker ; Style: visionary
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
  int i, numStocks;
  char stockName[20];
  float currPrice, prevPrice, change;

  printf("How many stocks do you want to track? ");
  scanf("%d", &numStocks);

  srand(time(0));

  printf("\n");

  for(i = 0; i < numStocks; i++) {
    printf("Enter the name of stock #%d: ", i+1);
    scanf("%s", stockName);

    printf("Enter the current price of %s: $", stockName);
    scanf("%f", &currPrice);

    prevPrice = currPrice - (((float)rand()/RAND_MAX) * currPrice);

    change = ((currPrice - prevPrice) / prevPrice) * 100;

    printf("%s\t\t$%0.2f\t%+0.2f%%\n", stockName, currPrice, change);
  }

  return 0;
}