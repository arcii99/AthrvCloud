//FormAI DATASET v1.0 Category: Warehouse Management System ; Style: statistical
#include<stdio.h>
#include<stdlib.h>

int main()
{
  int n = 10, i, j;
  int warehouse[n][n]; //array for warehouse
  int inventory[n]; // array for inventory

  //initialize inventory
  for(i=0;i<n;i++)
    inventory[i] = rand()%100;

  //initialize warehouse
  for(i=0;i<n;i++)
  {
    for(j=0;j<n;j++)
    {
      warehouse[i][j] = rand()%2;
    }
  }

  //display inventory
  printf("Inventory:\n");
  for(i=0;i<n;i++)
    printf("%d ",inventory[i]);

  printf("\n");

  //display warehouse
  printf("Warehouse:\n");
  for(i=0;i<n;i++)
  {
    for(j=0;j<n;j++)
    {
      printf("%d ",warehouse[i][j]);
    }
    printf("\n");
  }

  //find total stock in warehouse
  int total_stock = 0;
  for(i=0;i<n;i++)
  {
    for(j=0;j<n;j++)
    {
      total_stock += warehouse[i][j];
    }
  }

  printf("Total stock in warehouse: %d\n", total_stock);

  //find items to order
  int items_to_order = 0;
  for(i=0;i<n;i++)
  {
    if(inventory[i] == 0)
      items_to_order++;
  }

  printf("Items to order: %d\n",items_to_order);

  return 0;
}