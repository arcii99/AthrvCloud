//FormAI DATASET v1.0 Category: Stock market tracker ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct Stock {
  char symbol[5];
  double price;
} Stock;

void updateStockPrice(Stock *s) {
  double delta = ((double)rand() / RAND_MAX) - 0.5;
  s->price += delta;
}

void printStock(Stock *s) {
  printf("%s: $%.2f\n", s->symbol, s->price);
}

void printTopGainers(Stock *stocks, int numStocks, int numGainers) {
  Stock *gainers[numGainers];
  int i, j;

  // Initialize gainers array to first numGainers stocks.
  for (i = 0; i < numGainers; i++) {
    gainers[i] = &stocks[i];
  }

  // Find top gainers.
  for (i = numGainers; i < numStocks; i++) {
    for (j = 0; j < numGainers; j++) {
      if (stocks[i].price - gainers[j]->price > 0) {
        gainers[j] = &stocks[i];
        break;
      }
    }
  }

  // Print top gainers.
  printf("Top %d Gainers:\n", numGainers);
  for (i = 0; i < numGainers; i++) {
    printStock(gainers[i]);
  }
}

int main() {
  srand(time(NULL));
  int numStocks = 10;
  Stock stocks[numStocks];
  int i;

  // Initialize stocks.
  for (i = 0; i < numStocks; i++) {
    sprintf(stocks[i].symbol, "ST%d", i+1);
    stocks[i].price = ((double)rand() / RAND_MAX) * 100;
  }

  // Print initial stock prices.
  printf("Initial Stock Prices:\n");
  for (i = 0; i < numStocks; i++) {
    printStock(&stocks[i]);
  }

  // Update stock prices.
  for (i = 0; i < numStocks; i++) {
    updateStockPrice(&stocks[i]);
  }

  // Print updated stock prices.
  printf("\nUpdated Stock Prices:\n");
  for (i = 0; i < numStocks; i++) {
    printStock(&stocks[i]);
  }

  // Print top gainers.
  int numGainers = 3;
  printTopGainers(stocks, numStocks, numGainers);

  return 0;
}