//FormAI DATASET v1.0 Category: Product Inventory System ; Style: multivariable
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_PRODUCTS 100

struct product {
  int id;
  char name[50];
  float price;
  int quantity;
};

struct product inventory[MAX_PRODUCTS];

int num_products = 0;

void add_product() {
  struct product new_product;

  printf("Enter product name:");
  scanf("%s", new_product.name);

  printf("Enter product price:");
  scanf("%f", &new_product.price);

  printf("Enter product quantity:");
  scanf("%d", &new_product.quantity);

  new_product.id = num_products + 1;

  inventory[num_products] = new_product;
  num_products++;
}

void display_products() {
  for (int i = 0; i < num_products; i++) {
    printf("%d. %s - %.2f (%d)\n",
      inventory[i].id,
      inventory[i].name,
      inventory[i].price,
      inventory[i].quantity
    );
  }
}

void update_product() {
  int id, choice;
  printf("Enter product ID to update: ");
  scanf("%d", &id);

  for (int i = 0; i < num_products; i++) {
    if (inventory[i].id == id) {
      printf("1. Name\n2. Price\n3. Quantity\n");
      printf("What do you want to update? ");
      scanf("%d", &choice);

      switch(choice) {
        case 1:
          printf("Enter new name: ");
          scanf("%s", inventory[i].name);
          break;
        case 2:
          printf("Enter new price: ");
          scanf("%f", &inventory[i].price);
          break;
        case 3:
          printf("Enter new quantity: ");
          scanf("%d", &inventory[i].quantity);
          break;
        default:
          printf("Invalid choice.\n");
      }

      return;
    }
  }

  printf("Product not found.\n");
}

void remove_product() {
  int id;
  printf("Enter product ID to remove: ");
  scanf("%d", &id);

  for (int i = 0; i < num_products; i++) {
    if (inventory[i].id == id) {
      for (int j = i; j < num_products - 1; j++) {
        inventory[j] = inventory[j + 1];
      }

      num_products--;
      printf("Product removed.\n");
      return;
    }
  }

  printf("Product not found.\n");
}

int main() {
  int choice;

  while (1) {
    printf("1. Add product\n");
    printf("2. Display products\n");
    printf("3. Update product\n");
    printf("4. Remove product\n");
    printf("5. Quit\n");

    printf("What do you want to do? ");
    scanf("%d", &choice);

    switch (choice) {
      case 1:
        add_product();
        break;
      case 2:
        display_products();
        break;
      case 3:
        update_product();
        break;
      case 4:
        remove_product();
        break;
      case 5:
        printf("Goodbye!\n");
        exit(0);
      default:
        printf("Invalid choice.\n");
    }
  }

  return 0;
}