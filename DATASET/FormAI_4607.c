//FormAI DATASET v1.0 Category: Warehouse Management System ; Style: enthusiastic
#include <stdio.h>

struct item {
  int id;
  char name[50];
  float price;
  int quantity;
} warehouse[100];

int numOfItems = 0;

void addItem() {
  printf("Enter item name: ");
  scanf("%s", &warehouse[numOfItems].name);

  printf("Enter item price: ");
  scanf("%f", &warehouse[numOfItems].price);

  printf("Enter item quantity: ");
  scanf("%d", &warehouse[numOfItems].quantity);

  warehouse[numOfItems].id = numOfItems + 1;
  numOfItems++;
}

void removeItem() {
  int itemId;

  printf("Enter item ID to remove: ");
  scanf("%d", &itemId);

  for (int i = 0; i < numOfItems; i++) {
    if (warehouse[i].id == itemId) {
      for (int j = i; j < (numOfItems - 1); j++) {
        warehouse[j] = warehouse[j + 1];
      }
      numOfItems--;
      printf("Item removed successfully!\n");
      return;
    }
  }
  printf("Item not found!\n");
}

void listItems() {
  printf("ID   Name                                  Price     Quantity\n");
  for (int i = 0; i < numOfItems; i++) {
    printf("%-4d %-35s%.2f     %d\n", warehouse[i].id, warehouse[i].name, warehouse[i].price, warehouse[i].quantity);
  }
}

int main() {
  int option;

  do {
    printf("Welcome to the Warehouse Management System!\n");
    printf("1. Add item\n");
    printf("2. Remove item\n");
    printf("3. List items\n");
    printf("4. Exit\n");

    printf("Enter your option: ");
    scanf("%d", &option);

    switch (option) {
      case 1:
        addItem();
        break;
      case 2:
        removeItem();
        break;
      case 3:
        listItems();
        break;
      case 4:
        printf("Goodbye!");
        break;
      default:
        printf("Invalid option!\n");
        break;
    }

  } while (option != 4);

  return 0;
}