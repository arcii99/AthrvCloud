//FormAI DATASET v1.0 Category: Warehouse Management System ; Style: Dennis Ritchie
#include <stdio.h>

// Defining structure for a warehouse item
struct item {
  int item_id;
  char item_name[50];
  int quantity;
  float price;
};

// Global array to store items in warehouse
struct item warehouse[100];

// Function to add a new item to the warehouse
void add_item() {
  int id, quantity;
  char name[50];
  float price;
  printf("Enter the details of the new item:\n");
  printf("Item ID: ");
  scanf("%d", &id);
  printf("Item Name: ");
  scanf("%s", name);
  printf("Item Quantity: ");
  scanf("%d", &quantity);
  printf("Item Price: ");
  scanf("%f", &price);
  warehouse[id].item_id = id;
  strcpy(warehouse[id].item_name, name);
  warehouse[id].quantity = quantity;
  warehouse[id].price = price;
  printf("Item added successfully!\n");
}

// Function to update the details of an existing item
void update_item() {
  int id, choice;
  printf("Enter the ID of the item you want to update: ");
  scanf("%d", &id);
  printf("Choose the detail you want to update:\n");
  printf("1. Item Name\n");
  printf("2. Item Quantity\n");
  printf("3. Item Price\n");
  scanf("%d", &choice);
  switch (choice) {
    case 1:
      printf("Enter the new name for the item: ");
      scanf("%s", warehouse[id].item_name);
      break;
    case 2:
      printf("Enter the new quantity for the item: ");
      scanf("%d", &warehouse[id].quantity);
      break;
    case 3:
      printf("Enter the new price for the item: ");
      scanf("%f", &warehouse[id].price);
      break;
    default:
      printf("Invalid choice!\n");
      break;
  }
  printf("Item details updated successfully!\n");
}

// Function to delete an item from the warehouse
void delete_item() {
  int id;
  printf("Enter the ID of the item you want to delete: ");
  scanf("%d", &id);
  warehouse[id].item_id = -1;
  printf("Item deleted successfully!\n");
}

// Function to display the details of a specific item
void display_item() {
  int id;
  printf("Enter the ID of the item you want to display: ");
  scanf("%d", &id);
  if (warehouse[id].item_id == -1) {
    printf("Item not found!\n");
    return;
  }
  printf("Item ID: %d\n", warehouse[id].item_id);
  printf("Item Name: %s\n", warehouse[id].item_name);
  printf("Item Quantity: %d\n", warehouse[id].quantity);
  printf("Item Price: %.2f\n", warehouse[id].price);
}

// Function to display the details of all items in the warehouse
void display_all_items() {
  for (int i = 0; i < 100; i++) {
    if (warehouse[i].item_id != -1) {
      printf("Item ID: %d\n", warehouse[i].item_id);
      printf("Item Name: %s\n", warehouse[i].item_name);
      printf("Item Quantity: %d\n", warehouse[i].quantity);
      printf("Item Price: %.2f\n\n", warehouse[i].price);
    }
  }
}

int main() {
  int choice;
  // Initializing all IDs to -1 to represent an empty slot in the array
  for (int i = 0; i < 100; i++) {
    warehouse[i].item_id = -1;
  }
  while (1) {
    printf("Choose an option:\n");
    printf("1. Add Item\n");
    printf("2. Update Item\n");
    printf("3. Delete Item\n");
    printf("4. Display Item\n");
    printf("5. Display All Items\n");
    printf("6. Exit\n");
    scanf("%d", &choice);
    switch (choice) {
      case 1:
        add_item();
        break;
      case 2:
        update_item();
        break;
      case 3:
        delete_item();
        break;
      case 4:
        display_item();
        break;
      case 5:
        display_all_items();
        break;
      case 6:
        printf("Goodbye!\n");
        return 0;
      default:
        printf("Invalid choice!\n");
        break;
    }
  }
  return 0;
}