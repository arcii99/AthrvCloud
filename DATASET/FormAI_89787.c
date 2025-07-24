//FormAI DATASET v1.0 Category: Stock market tracker ; Style: funny
/* Disclaimer: This program is for entertainment purposes only. 
   It is not meant to be taken seriously as an actual stock tracker.
   If you invest based on the information from this program, you may lose all your money.
   With that being said, let's get started! */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {

  // initialize random seed
  srand(time(NULL));

  // generate random stock prices
  int apple_stock = rand() % 100 + 1; // Apple stock price between 1 and 100
  int microsoft_stock = rand() % 100 + 1; // Microsoft stock price between 1 and 100
  int amazon_stock = rand() % 100 + 1; // Amazon stock price between 1 and 100
  int tesla_stock = rand() % 100 + 1; // Tesla stock price between 1 and 100
  int google_stock = rand() % 100 + 1; // Google stock price between 1 and 100

  // print out stock prices
  printf("Welcome to the most entertaining stock tracker ever!\n");
  printf("Apple: $%d\n", apple_stock);
  printf("Microsoft: $%d\n", microsoft_stock);
  printf("Amazon: $%d\n", amazon_stock);
  printf("Tesla: $%d\n", tesla_stock);
  printf("Google: $%d\n", google_stock);

  // simulate a day of trading
  int apple_change = rand() % 11 - 5; // change between -5 and 5 dollars
  int microsoft_change = rand() % 11 - 5; // change between -5 and 5 dollars
  int amazon_change = rand() % 11 - 5; // change between -5 and 5 dollars
  int tesla_change = rand() % 11 - 5; // change between -5 and 5 dollars
  int google_change = rand() % 11 - 5; // change between -5 and 5 dollars

  // update stock prices
  apple_stock += apple_change;
  microsoft_stock += microsoft_change;
  amazon_stock += amazon_change;
  tesla_stock += tesla_change;
  google_stock += google_change;

  // print out updated stock prices
  printf("After a day of trading, the new stock prices are:\n");
  printf("Apple: $%d\n", apple_stock);
  printf("Microsoft: $%d\n", microsoft_stock);
  printf("Amazon: $%d\n", amazon_stock);
  printf("Tesla: $%d\n", tesla_stock);
  printf("Google: $%d\n", google_stock);

  // make some funny comments based on the stock prices
  if (apple_stock < 50) {
    printf("Looks like Apple has bitten the dust!\n");
  }
  if (microsoft_stock > 80) {
    printf("Bill Gates is probably feeling pretty good right about now.\n");
  }
  if (amazon_stock > 90) {
    printf("Jeff Bezos will be taking his private spaceship to the moon tonight.\n");
  }
  if (tesla_stock > 70) {
    printf("Elon Musk is probably posting memes on Twitter right now.\n");
  }
  if (google_stock > 60) {
    printf("Thanks to Google, we'll never have to remember anything ever again.\n");
  }

  return 0;
}