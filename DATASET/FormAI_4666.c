//FormAI DATASET v1.0 Category: Product Inventory System ; Style: energetic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PRODUCTS 1000

struct Product {
  char name[50];
  int id;
  float price;
  int quantity;
};

int num_products = 0;
struct Product products[MAX_PRODUCTS];

void add_product() {
  printf("\nAdd a new product\n");
  printf("-----------------\n");

  struct Product product;
  product.id = num_products + 1;

  printf("Enter product name: ");
  fgets(product.name, 50, stdin);

  printf("Enter product price: ");
  scanf("%f", &product.price);

  printf("Enter product quantity: ");
  scanf("%d", &product.quantity);

  products[num_products] = product;
  num_products++;
  printf("\nProduct added successfully!\n");
}

void view_products() {
  printf("\nView all products\n");
  printf("-----------------\n");

  if (num_products == 0) {
    printf("No products available.\n");
    return;
  }

  for (int i = 0; i < num_products; i++) {
    printf("ID: %d | Name: %s | Price: $%.2f | Quantity: %d\n", products[i].id, products[i].name, products[i].price, products[i].quantity);
  }
}

void search_product() {
  printf("\nSearch for a product\n");
  printf("--------------------\n");

  char search_str[50];
  printf("Enter search term: ");
  fgets(search_str, 50, stdin);

  for (int i = 0; i < num_products; i++) {
    if(strstr(products[i].name, search_str) != NULL) {
      printf("ID: %d | Name: %s | Price: $%.2f | Quantity: %d\n", products[i].id, products[i].name, products[i].price, products[i].quantity);
    }
  }
}

void update_product() {
  printf("\nUpdate a product\n");
  printf("-----------------\n");

  int update_id;
  printf("Enter the ID of the product to update: ");
  scanf("%d", &update_id);

  for (int i = 0; i < num_products; i++) {
    if (products[i].id == update_id) {
      printf("Enter new product name: ");
      fgets(products[i].name, 50, stdin);

      printf("Enter new product price: ");
      scanf("%f", &products[i].price);

      printf("Enter new product quantity: ");
      scanf("%d", &products[i].quantity);

      printf("\nProduct updated successfully!\n");
      return;
    }
  }

  printf("No product found with ID %d\n", update_id);
}

void remove_product() {
  printf("\nRemove a product\n");
  printf("-----------------\n");

  int remove_id;
  printf("Enter the ID of the product to remove: ");
  scanf("%d", &remove_id);

  for (int i = 0; i < num_products; i++) {
    if (products[i].id == remove_id) {
      for (int j = i; j < num_products - 1; j++) {
        products[j] = products[j + 1];
      }

      num_products--;
      printf("\nProduct removed successfully\n");
      return;
    }
  }

  printf("No product found with ID %d\n", remove_id);
}

int main() {
  printf("\nC Product Inventory System\n");
  printf("--------------------------\n");
  printf("Commands:\n");
  printf("add - Add a new product\n");
  printf("view - View all products\n");
  printf("search - Search for a product\n");
  printf("update - Update a product\n");
  printf("remove - Remove a product\n");
  printf("exit - Exit the program\n");

  while (1) {
    char command[10];
    printf("\nCommand: ");
    fgets(command, 10, stdin);

    if (strcmp(command, "add\n") == 0) {
      add_product();
    } else if (strcmp(command, "view\n") == 0) {
      view_products();
    } else if (strcmp(command, "search\n") == 0) {
      search_product();
    } else if (strcmp(command, "update\n") == 0) {
      update_product();
    } else if (strcmp(command, "remove\n") == 0) {
      remove_product();
    } else if (strcmp(command, "exit\n") == 0) {
      printf("\nGoodbye!\n");
      return 0;
    }
  }
}