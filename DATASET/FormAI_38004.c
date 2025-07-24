//FormAI DATASET v1.0 Category: Stock market tracker ; Style: calm
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NAME_LENGTH 30
#define MAX_SYMBOL_LENGTH 10

typedef struct {
  char name[MAX_NAME_LENGTH];
  char symbol[MAX_SYMBOL_LENGTH];
  float price;
  float change;
} Stock;

void updatePrice(Stock *s, float price);

int main() {
  Stock stock1, stock2;

  // initialize stock1
  strcpy(stock1.name, "Apple Inc.");
  strcpy(stock1.symbol, "AAPL");
  stock1.price = 150.5;
  stock1.change = -0.2;

  // initialize stock2
  strcpy(stock2.name, "Microsoft Corporation");
  strcpy(stock2.symbol, "MSFT");
  stock2.price = 255.7;
  stock2.change = 1.1;

  printf("Stock Market Tracker\n");
  printf("====================\n\n");

  printf("%-18s%-10s%-10s%-10s\n", "Name", "Symbol", "Price", "Change");
  printf("-----------------------------------------------------------\n");
  printf("%-18s%-10s%-10.2f%-+9.2f%%\n", stock1.name, stock1.symbol, stock1.price, stock1.change);
  printf("%-18s%-10s%-10.2f%-+9.2f%%\n", stock2.name, stock2.symbol, stock2.price, stock2.change);

  // simulate price change and update
  updatePrice(&stock1, 149.7);
  updatePrice(&stock2, 253.3);

  printf("\nAfter Price Update\n");
  printf("==================\n\n");

  printf("%-18s%-10s%-10s%-10s\n", "Name", "Symbol", "Price", "Change");
  printf("-----------------------------------------------------------\n");
  printf("%-18s%-10s%-10.2f%-+9.2f%%\n", stock1.name, stock1.symbol, stock1.price, stock1.change);
  printf("%-18s%-10s%-10.2f%-+9.2f%%\n", stock2.name, stock2.symbol, stock2.price, stock2.change);

  return 0;
}

void updatePrice(Stock *s, float price) {
  float change = (price - s->price) / s->price * 100;
  s->price = price;
  s->change = change;
}