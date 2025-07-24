//FormAI DATASET v1.0 Category: Stock market tracker ; Style: shocked
#include <stdio.h>
#include <stdlib.h>

int main()
{
  float stock_price = 0.0;
  float old_price = 0.0;
  char stock_name[10];
  int i = 0;

  printf("Enter the name of the stock: ");
  scanf("%s", stock_name);

  printf("Enter the initial price of the stock: ");
  scanf("%f", &old_price);

  printf("The initial price of %s is %f.\n\n", stock_name, old_price);

  for(i=0; i<5; i++)
  {
    printf("Enter the new price of the stock: ");
    scanf("%f", &stock_price);

    if(stock_price > old_price)
    {
      printf("The %s stock has gone up by %.2f points.\n", stock_name, stock_price-old_price);
    }
    else if(stock_price < old_price)
    {
      printf("The %s stock has gone down by %.2f points.\n", stock_name, old_price-stock_price);
    }
    else
    {
      printf("The %s stock has stayed at the same price.\n", stock_name);
    }

    old_price = stock_price;

  }

  return 0;
}