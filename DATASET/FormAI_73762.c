//FormAI DATASET v1.0 Category: Stock market tracker ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define NUM_STOCKS 5

struct Stock {
  char name[20];
  float price;
  float change;
};

void initializeStocks(struct Stock stocks[]) {
  // Initialize the name and price of each stock
  strcpy(stocks[0].name, "GOOG");
  stocks[0].price = 1523.67;
  strcpy(stocks[1].name, "AAPL");
  stocks[1].price = 326.09;
  strcpy(stocks[2].name, "MSFT");
  stocks[2].price = 187.27;
  strcpy(stocks[3].name, "AMZN");
  stocks[3].price = 3159.53;
  strcpy(stocks[4].name, "FB");
  stocks[4].price = 252.86;
  
  // Set the initial change to 0
  for(int i=0; i<NUM_STOCKS; i++) {
    stocks[i].change = 0;
  }
}

float getRandomChange() {
  // Generate a random number between -1% and 1%
  float change = ((float) rand()/(float) RAND_MAX) * 0.02 - 0.01;
  return change;
}

void updateStock(struct Stock* stock) {
  // Get a random change in price
  float change = getRandomChange();
  stock->change = change;
  
  // Calculate the new price
  float newPrice = stock->price * (1 + change);
  stock->price = newPrice;
}

void printStocks(struct Stock stocks[]) {
  printf("|--------------------------------------------------------|\n");
  printf("| Stock  | Price    | Change   | \n");
  printf("|--------------------------------------------------------|\n");
  for(int i=0; i<NUM_STOCKS; i++) {
    printf("| %-5s  | %-7.2f | %-7.2f%% |\n", stocks[i].name, stocks[i].price, stocks[i].change*100);
  }
  printf("|--------------------------------------------------------|\n");
}

int main() {
  struct Stock stocks[NUM_STOCKS];
  initializeStocks(stocks);
  srand((unsigned) time(NULL));
  
  printf("Welcome to the Stock Market Tracker!\n");
  
  int choice;
  do {
    printf("\nWhat would you like to do?\n");
    printf("1 - View Stock Prices\n");
    printf("2 - Update Stock Prices\n");
    printf("3 - Exit\n");
    printf("Choice: ");
    scanf("%d", &choice);
    
    switch(choice) {
      case 1:
        printStocks(stocks);
        break;
      case 2:
        for(int i=0; i<NUM_STOCKS; i++) {
          updateStock(&stocks[i]);
        }
        printf("Stock prices updated!\n");
        break;
      case 3:
        printf("Thanks for using the Stock Market Tracker!\n");
        break;
      default:
        printf("Invalid choice. Please select a valid option.\n");
        break;
    }
  } while(choice != 3);
  
  return 0;
}