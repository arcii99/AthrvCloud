//FormAI DATASET v1.0 Category: Stock market tracker ; Style: dynamic
#include<stdio.h>

int main() {
  int num_of_stocks;
  printf("Enter the number of stocks to be tracked: ");
  scanf("%d", &num_of_stocks);
  
  char stock_name[num_of_stocks][20];
  float stock_price[num_of_stocks];
  int stock_quantity[num_of_stocks];
  
  for(int i=0; i<num_of_stocks; i++) {
    printf("Enter the name of stock %d: ", i+1);
    scanf("%s", stock_name[i]);

    printf("Enter the price of stock %d: ", i+1);
    scanf("%f", &stock_price[i]);

    printf("Enter the quantity of stock %d: ", i+1);
    scanf("%d", &stock_quantity[i]);
  }

  printf("\nStock Tracker\n");
  printf("-------------------\n");
  printf("Stock Name       | Price         | Quantity       | Value\n");
  printf("-------------------\n");
  
  float total_value = 0;
  for(int i=0; i<num_of_stocks; i++) {
    printf("%-16s| $%-13.2f| %-15d| $%-10.2f\n", stock_name[i], stock_price[i], stock_quantity[i], stock_price[i]*stock_quantity[i]);
    total_value += stock_price[i]*stock_quantity[i];
  }

  printf("-------------------\n");
  printf("Total Value               | $%-10.2f\n", total_value);

  return 0;
}