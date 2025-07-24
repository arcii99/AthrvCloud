//FormAI DATASET v1.0 Category: Stock market tracker ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
  printf("Welcome to the Stock Market Tracker!\n");
  printf("This program allows you to randomly track the value of stocks.\n");
  printf("Let's get started!\n");

  srand(time(NULL));
  int stockValue = rand() % 100 + 1; // Starting stock value between 1 and 100
  int i;

  printf("Starting stock value: %d\n", stockValue);

  for (i = 1; i <= 50; i++) { // Randomly track stock value for 50 days
    int change = rand() % 41 - 20; // Random change in stock value between -20 and 20
    stockValue += change;
    printf("Day %d: %d\n", i, stockValue);
  }

  printf("Thanks for tracking your stock with us!\n");

  return 0;
}