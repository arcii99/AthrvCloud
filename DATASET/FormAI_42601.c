//FormAI DATASET v1.0 Category: Stock market tracker ; Style: surprised
#include <stdio.h>

int main() {

  printf("Welcome to the C Stock Market Tracker!\n");
  printf("Please enter the number of stocks you would like to track: ");

  int numStocks;
  scanf("%d", &numStocks);

  char stocks[numStocks][5];
  float prices[numStocks];
  float previous[numStocks];

  for(int i=0; i<numStocks; i++) {
    printf("\nEnter stock symbol %d: ", i+1);
    scanf("%s", &stocks[i]);
    printf("Enter current price of %s: ", stocks[i]);
    scanf("%f", &prices[i]);
    printf("Enter previous day's closing price of %s: ", stocks[i]);
    scanf("%f", &previous[i]);
  }

  printf("\n\nHere are your tracked stocks with their current prices and changes:\n\n");
  printf("Symbol    | Current Price    | Change\n");
  printf("--------------------------------------\n");

  for(int i=0; i<numStocks; i++) {
    float change = (prices[i] - previous[i]) / previous[i] * 100;
    printf("%-10s| $%.2f            | %.2f%%\n", stocks[i], prices[i], change);
  }

  printf("\nPress enter to exit.");
  getchar();

  return 0;
}