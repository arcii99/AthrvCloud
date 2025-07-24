//FormAI DATASET v1.0 Category: Warehouse Management System ; Style: scientific
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the maximum items in the warehouse
#define MAX_ITEMS 1000

// Define the maximum length of the item name and description
#define MAX_NAME_LENGTH 50
#define MAX_DESC_LENGTH 500

// Define the item struct
typedef struct item {
  int id;
  char name[MAX_NAME_LENGTH];
  char description[MAX_DESC_LENGTH];
  int quantity;
} Item;

// Define the warehouse struct
typedef struct warehouse {
  Item items[MAX_ITEMS];
  int itemCount;
} Warehouse;

// Define a function to add an item to the warehouse
void addItem(Warehouse *warehouse) {
  Item newItem;

  printf("Enter the name of the item: ");
  fgets(newItem.name, MAX_NAME_LENGTH, stdin);
  newItem.name[strcspn(newItem.name, "\n")] = 0; // Remove trailing newline character

  printf("Enter a description for the item: ");
  fgets(newItem.description, MAX_DESC_LENGTH, stdin);
  newItem.description[strcspn(newItem.description, "\n")] = 0; // Remove trailing newline character

  printf("Enter the quantity of the item: ");
  scanf("%d", &newItem.quantity);
  getchar(); // Remove trailing newline character from previous input

  // Assign the item a unique ID
  newItem.id = warehouse->itemCount;

  // Add the item to the warehouse
  warehouse->items[warehouse->itemCount] = newItem;
  warehouse->itemCount++;

  printf("\nItem successfully added to the warehouse!\n");
}

// Define a function to search for an item by name
void searchItem(Warehouse *warehouse) {
  char searchName[MAX_NAME_LENGTH];
  int itemFound = 0;

  printf("Enter the name of the item to search for: ");
  fgets(searchName, MAX_NAME_LENGTH, stdin);
  searchName[strcspn(searchName, "\n")] = 0; // Remove trailing newline character

  for (int i = 0; i < warehouse->itemCount; i++) {
    if (strcmp(warehouse->items[i].name, searchName) == 0) {
      printf("\nItem found!\n\n");
      printf("Name: %s\n", warehouse->items[i].name);
      printf("Description: %s\n", warehouse->items[i].description);
      printf("Quantity: %d\n", warehouse->items[i].quantity);
      itemFound = 1;
      break;
    }
  }

  if (itemFound == 0) {
    printf("\nThe item with name '%s' was not found in the warehouse.\n", searchName);
  }
}

int main() {
  Warehouse warehouse;
  warehouse.itemCount = 0;

  int choice;

  do {
    printf("\nWarehouse Management System\n");
    printf("===========================\n");
    printf("1. Add an item to the warehouse\n");
    printf("2. Search for an item in the warehouse\n");
    printf("3. Exit\n");
    printf("\nEnter your choice (1-3): ");
    scanf("%d", &choice);
    getchar(); // Remove trailing newline character from previous input

    switch (choice) {
      case 1:
        addItem(&warehouse);
        break;
      case 2:
        searchItem(&warehouse);
        break;
      case 3:
        printf("\nGoodbye!\n");
        break;
      default:
        printf("\nInvalid choice. Please enter a number between 1 and 3.\n");
        break;
    }
  } while (choice != 3);

  return 0;
}