//FormAI DATASET v1.0 Category: Warehouse Management System ; Style: authentic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ITEMS 1000
#define MAX_NAME_LENGTH 50

typedef struct {
   char item_name[MAX_NAME_LENGTH];
   int quantity;
} inventory_item;

inventory_item inventory[MAX_ITEMS];

int num_items = 0;

void add_inventory_item(char* item_name, int quantity) {
   if (num_items >= MAX_ITEMS) {
      printf("Error: inventory is full.\n");
      return;
   }
   strcpy(inventory[num_items].item_name, item_name);
   inventory[num_items].quantity = quantity;
   num_items++;
}

void remove_inventory_item(char* item_name) {
    int i = 0;
    int found = 0;
    for (i = 0; i < num_items; i++) {
        if (strcmp(inventory[i].item_name, item_name) == 0) {
            found = 1;
            break;
        }
    }
    if (found) {
        inventory[i].quantity--;
        if (inventory[i].quantity <= 0) {
            for (int j = i; j < num_items - 1; j++) {
                strcpy(inventory[j].item_name, inventory[j + 1].item_name);
                inventory[j].quantity = inventory[j + 1].quantity;
            }
            num_items--;
        }
    }
    else {
        printf("Error: item not found in inventory.\n");
    }
}

void display_inventory() {
   printf("Inventory:\n");
   for(int i=0;i<num_items;i++){
       printf("%d: %s (%d)\n", i+1, inventory[i].item_name, inventory[i].quantity);
   }
}

int main(){
  add_inventory_item("Apples", 10);
  add_inventory_item("Oranges", 5);
  add_inventory_item("Bananas", 12);

  display_inventory();

  remove_inventory_item("Oranges");

  display_inventory();

  return 0;
}