//FormAI DATASET v1.0 Category: Warehouse Management System ; Style: shocked
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct Warehouse {
   int warehouseId, numberOfItems;
   char product[100];
};

void addWarehouseItem(struct Warehouse* warehouse,int id,char product[],int number)
{
   warehouse->warehouseId = id;
   strcpy(warehouse->product,product);
   warehouse->numberOfItems = number;
}

void showWarehouse(struct Warehouse* warehouse)
{
   printf("Warehouse ID: %d \n", warehouse->warehouseId);
   printf("Product Name: %s \n", warehouse->product);
   printf("Number of Items: %d \n", warehouse->numberOfItems);
}

int main() {
   struct Warehouse warehouse; 
   printf("You just created a Warehouse Management System! Prepare to be amazed!!\n\n");

   printf("Let's add some items to the warehouse\n");
   addWarehouseItem(&warehouse, 1,"Stapler", 50);
   showWarehouse(&warehouse);

   printf("Wow, that was easy! Let's add some more items\n");
   addWarehouseItem(&warehouse, 2,"Markers", 100);
   showWarehouse(&warehouse);

   printf("We can also update the number of items in a warehouse\n");
   warehouse.numberOfItems = 75;
   showWarehouse(&warehouse);

   printf("The Warehouse Management System is a huge success! \nThank you for using it!\n");

   return 0;
}