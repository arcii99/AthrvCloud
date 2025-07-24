//FormAI DATASET v1.0 Category: Stock market tracker ; Style: Cyberpunk
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
   srand(time(NULL)); // initialize the random number generator with the current time

   // generate a random stock price between $10 and $100
   float stock_price = (rand() % 9000) / 100.0 + 10.0;

   // keep track of the maximum and minimum prices seen so far
   float max_price = stock_price;
   float min_price = stock_price;

   // initialize the previous price to the current price
   float prev_price = stock_price;

   // print the header for the table
   printf("=============================================\n");
   printf("=          CYBERPUNK STOCK TRACKER           =\n");
   printf("=============================================\n");
   printf("=  TIME  |  PRICE  |  CHANGE  |  %s  |\n", (prev_price < stock_price) ? "TREND" : "TREND ");
   printf("=============================================\n");

   // print the initial row for the table
   printf("| %5s | %7.2f | %8s | %6s |\n", "0m", stock_price, "-", "-");

   // generate prices for the next 49 minutes
   for (int t = 1; t < 50; t++) {
      // generate a new price based on the previous price
      float change = (rand() % 2001 - 1000) / 100.0; // change between -10.00 and 10.00
      float new_price = prev_price + change;

      // check if the new price is the new maximum or minimum
      if (new_price > max_price) {
         max_price = new_price;
      } else if (new_price < min_price) {
         min_price = new_price;
      }

      // print the row for the new price
      printf("| %5dm | %7.2f | %+.2f%s | %6s |\n", t, new_price, change, (change >= 0) ? " " : "", (new_price > prev_price) ? "UP" : ((new_price < prev_price) ? "DOWN" : "-"));

      // update the previous price to the new price
      prev_price = new_price;
   }

   // print the footer for the table
   printf("=============================================\n");
   printf("=      MAXIMUM: %7.2f | MINIMUM: %7.2f      =\n", max_price, min_price);
   printf("=============================================\n");

   return 0;
}