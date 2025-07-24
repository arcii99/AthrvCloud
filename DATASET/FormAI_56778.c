//FormAI DATASET v1.0 Category: Warehouse Management System ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ITEMS 100
#define MAX_NAME 20

struct Item {
   char name[MAX_NAME];
   int quantity;
};

struct Item inventory[MAX_ITEMS];

int numItems = 0;

void addItem(char name[MAX_NAME], int quantity) {
   if (numItems == MAX_ITEMS) {
      printf("ERROR: Maximum inventory capacity reached.\n");
      return;
   }

   struct Item itemToAdd;
   strcpy(itemToAdd.name, name);
   itemToAdd.quantity = quantity;
   inventory[numItems] = itemToAdd;
   numItems++;

   printf("%d %s added to inventory.\n", quantity, name);
}

void removeItem(char name[MAX_NAME], int quantity) {
   int index = -1;
   for (int i = 0; i < numItems; i++) {
      if (strcmp(inventory[i].name, name) == 0) {
         index = i;
         break;
      }
   }

   if (index == -1) {
      printf("ERROR: Item not found in inventory.\n");
      return;
   }

   if (inventory[index].quantity < quantity) {
      printf("ERROR: Insufficient quantity of %s in inventory.\n", name);
      return;
   }

   inventory[index].quantity -= quantity;

   printf("%d %s removed from inventory.\n", quantity, name);
}

void displayInventory() {
   printf("Inventory:\n");
   for (int i = 0; i < numItems; i++) {
      printf("%s - %d\n", inventory[i].name, inventory[i].quantity);
   }
}

int main() {
   addItem("apple", 10);
   addItem("banana", 15);

   displayInventory();

   removeItem("apple", 5);

   displayInventory();

   removeItem("orange", 2);

   return 0;
}