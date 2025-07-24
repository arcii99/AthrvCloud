//FormAI DATASET v1.0 Category: Stock market tracker ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LEN 100

struct Stock {
   char ticker[MAX_LEN];
   float price;
   float change;
};

struct Stock tracker[10]; //assume we want to track 10 stocks

void printHeaders() {
   printf("%-10s %-10s %-10s\n", "Ticker", "Price", "Change");
}

void printStock(struct Stock s) {
   printf("%-10s $%.2f ", s.ticker, s.price);
   if (s.change > 0) {
      printf("+%.2f\n", s.change);
   } else {
      printf("%.2f\n", s.change);
   }
}

void updateStock(struct Stock* s, float newPrice) {
   float prevPrice = s->price;
   s->price = newPrice;
   s->change = newPrice - prevPrice;

   //do some fancy algo to check and alert if price is significantly up or down
   if (s->change / prevPrice > 0.05) {
      printf("*** ALERT: %s jumped over 5%% from $%.2f to $%.2f\n", s->ticker, prevPrice, s->price);
   } else if (s->change / prevPrice < -0.05) {
      printf("*** ALERT: %s dropped over 5%% from $%.2f to $%.2f\n", s->ticker, prevPrice, s->price);
   }
}

int main() {
   strcpy(tracker[0].ticker, "AAPL");
   tracker[0].price = 134.87;
   tracker[0].change = 0;

   strcpy(tracker[1].ticker, "GOOG");
   tracker[1].price = 1532.02;
   tracker[1].change = 0;

   strcpy(tracker[2].ticker, "TSLA");
   tracker[2].price = 658.82;
   tracker[2].change = 0;

   printHeaders();
   for (int i = 0; i < 3; i++) {
      printStock(tracker[i]);
   }

   printf("\n\n-------------\n\n");

   //after some time, update the prices
   updateStock(&tracker[0], 136.12);
   updateStock(&tracker[1], 1552.23);
   updateStock(&tracker[2], 675.36);

   printHeaders();
   for (int i = 0; i < 3; i++) {
      printStock(tracker[i]);
   }

   return 0;
}