//FormAI DATASET v1.0 Category: Stock market tracker ; Style: multivariable
#include<stdio.h>
int main() {

  // variable declaration
  float stock_a=500.80, stock_b=320.60, stock_c=145.75; // current values
  float avg_price_a=475.30, avg_price_b=305.50, avg_price_c=140.25; // average buying price
  int quantity_a=100, quantity_b=250, quantity_c=400; // quantity of stocks

  float total_a=stock_a*quantity_a; // total value of stock A
  float total_b=stock_b*quantity_b; // total value of stock B
  float total_c=stock_c*quantity_c; // total value of stock C

  float total_value=total_a+total_b+total_c; // total value of all stocks
  float total_avg_price=(avg_price_a*quantity_a + avg_price_b*quantity_b + avg_price_c*quantity_c)/(quantity_a+quantity_b+quantity_c); // average price of all stocks
  float total_profit=total_value - total_avg_price*(quantity_a+quantity_b+quantity_c); // total profit/loss

  printf("\nCurrent Market Status\n\n");
  printf("Stock A: %.2f\n",stock_a);
  printf("Stock B: %.2f\n",stock_b);
  printf("Stock C: %.2f\n\n",stock_c);

  printf("Your Portfolio\n\n");
  printf("Stock A: Quantity: %d, Average Buying Price: %.2f, Current Value: %.2f, Total Value: %.2f\n", quantity_a, avg_price_a, stock_a, total_a);
  printf("Stock B: Quantity: %d, Average Buying Price: %.2f, Current Value: %.2f, Total Value: %.2f\n", quantity_b, avg_price_b, stock_b, total_b);
  printf("Stock C: Quantity: %d, Average Buying Price: %.2f, Current Value: %.2f, Total Value: %.2f\n\n", quantity_c, avg_price_c, stock_c, total_c);

  printf("Current Portfolio Status\n\n");
  printf("Total Value: %.2f\n",total_value);
  printf("Average Buying Price: %.2f\n",total_avg_price);
  printf("Total Profit/Loss: %.2f\n\n",total_profit);

  return 0;
}