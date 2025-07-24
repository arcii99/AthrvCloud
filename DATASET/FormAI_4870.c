//FormAI DATASET v1.0 Category: Stock market tracker ; Style: introspective
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STOCK_NAME_LENGTH 20
#define MAX_PRICE_CHANGE 10

typedef struct Stock {
  char name[MAX_STOCK_NAME_LENGTH];
  double current_price;
  double previous_day_price;
  double price_change;
} Stock;

int main() {
  int num_stocks;
  printf("Enter the number of stocks to track: ");
  scanf("%d", &num_stocks);

  Stock* stocks = (Stock*) malloc(num_stocks * sizeof(Stock));

  for(int i = 0; i < num_stocks; i++) {
    printf("Enter the name of the stock: ");
    scanf("%s", stocks[i].name);
    printf("Enter the current price of the stock: ");
    scanf("%lf", &stocks[i].current_price);
    printf("Enter the previous day's price of the stock: ");
    scanf("%lf", &stocks[i].previous_day_price);
    stocks[i].price_change = (stocks[i].current_price - stocks[i].previous_day_price) / stocks[i].previous_day_price;
  }

  printf("\n\n\n");

  printf("Stock Name\tCurrent Price\tPrevious Price\tPrice Change\n");
  for(int i = 0; i < num_stocks; i++) {
    printf("%s\t\t%.2lf\t\t%.2lf\t\t%.2lf%%\n", stocks[i].name, stocks[i].current_price, stocks[i].previous_day_price, stocks[i].price_change * 100);
    if(stocks[i].price_change > MAX_PRICE_CHANGE) {
      printf("%s has had a significant increase in price.\n", stocks[i].name);
    } else if(stocks[i].price_change < -MAX_PRICE_CHANGE) {
      printf("%s has had a significant decrease in price.\n", stocks[i].name);
    }
  }

  free(stocks);

  return 0;
}