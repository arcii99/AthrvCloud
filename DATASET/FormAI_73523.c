//FormAI DATASET v1.0 Category: Stock market tracker ; Style: active
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STOCKS 50
#define MAX_NAME_LENGTH 20

typedef struct {
   char symbol[6];
   char name[MAX_NAME_LENGTH];
   double price;
} Stock;

Stock stocks[MAX_STOCKS];
int numStocks = 0;

int main() {
   int choice;
   do {
      printf("Welcome to the Stock Market Tracker\n");
      printf("----------------------------------\n");
      printf("1. Add a new stock\n");
      printf("2. Remove a stock\n");
      printf("3. Update the price of a stock\n");
      printf("4. Display all stocks\n");
      printf("5. Exit\n");
      printf("Enter your choice: ");
      scanf("%d", &choice);
      switch (choice) {
         case 1:
            addStock();
            break;
         case 2:
            removeStock();
            break;
         case 3:
            updateStockPrice();
            break;
         case 4:
            displayAllStocks();
            break;
         case 5:
            printf("Thank you for using the Stock Market Tracker.\n");
            break;
         default:
            printf("Invalid choice. Please try again.\n");
      }
   } while (choice != 5);
   return 0;
}

void addStock() {
   if (numStocks == MAX_STOCKS) {
      printf("Sorry, the maximum number of stocks has been reached.\n");
   } else {
      Stock stock;
      printf("Enter the stock symbol (max 5 characters): ");
      scanf("%s", stock.symbol);
      printf("Enter the stock name (max 19 characters): ");
      scanf("%s", stock.name);
      printf("Enter the stock price: ");
      scanf("%lf", &stock.price);
      stocks[numStocks++] = stock;
      printf("%s (%s) has been added to the stock market tracker.\n", stock.symbol, stock.name);
   }
}

void removeStock() {
   char symbol[6];
   printf("Enter the symbol of the stock to remove: ");
   scanf("%s", symbol);
   int i, index = -1;
   for (i = 0; i < numStocks; i++) {
      if (strcmp(stocks[i].symbol, symbol) == 0) {
         index = i;
         break;
      }
   }
   if (index == -1) {
      printf("Sorry, that stock is not in the stock market tracker.\n");
   } else {
      printf("%s (%s) has been removed from the stock market tracker.\n", stocks[index].symbol, stocks[index].name);
      for (i = index; i < numStocks - 1; i++) {
         stocks[i] = stocks[i + 1];
      }
      numStocks--;
   }
}

void updateStockPrice() {
   char symbol[6];
   printf("Enter the symbol of the stock to update: ");
   scanf("%s", symbol);
   int i, index = -1;
   for (i = 0; i < numStocks; i++) {
      if (strcmp(stocks[i].symbol, symbol) == 0) {
         index = i;
         break;
      }
   }
   if (index == -1) {
      printf("Sorry, that stock is not in the stock market tracker.\n");
   } else {
      double price;
      printf("Enter the new price of %s (%s): ", stocks[index].symbol, stocks[index].name);
      scanf("%lf", &price);
      stocks[index].price = price;
      printf("The price of %s (%s) has been updated to %.2lf.\n", stocks[index].symbol, stocks[index].name, stocks[index].price);
   }
}

void displayAllStocks() {
   if (numStocks == 0) {
      printf("There are no stocks in the stock market tracker.\n");
   } else {
      printf("Symbol\tName\t\tPrice\n");
      printf("----------------------------------\n");
      int i;
      for (i = 0; i < numStocks; i++) {
         printf("%s\t%-20s%.2lf\n", stocks[i].symbol, stocks[i].name, stocks[i].price);
      }
   }
}