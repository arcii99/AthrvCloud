//FormAI DATASET v1.0 Category: Product Inventory System ; Style: excited
#include <stdio.h>
#include <string.h>

struct Product {
  char name[50];
  float price;
  int quantity;
};

void addProduct(struct Product products[], int *quantity) {
  printf("Enter the product name: ");
  scanf("%s", products[*quantity].name);
  printf("Enter the product price: ");
  scanf("%f", &products[*quantity].price);
  printf("Enter the product quantity: ");
  scanf("%d", &products[*quantity].quantity);
  (*quantity)++;
}

void displayProducts(struct Product products[], int quantity) {
  printf("Name\t\tPrice\tQuantity\n");
  for (int i = 0; i < quantity; i++) {
    printf("%s\t$%.2f\t%d\n", products[i].name, products[i].price, products[i].quantity);
  }
}

int main() {
  struct Product products[100];
  int quantity = 0;
  char choice[10];
  do {
    printf("\n1. Add product");
    printf("\n2. Display products");
    printf("\n3. Exit");
    printf("\nEnter your choice: ");
    scanf("%s", choice);
    if (strcmp(choice, "1") == 0) {
      addProduct(products, &quantity);
    } else if (strcmp(choice, "2") == 0) {
      displayProducts(products, quantity);
    } else if (strcmp(choice, "3") != 0) {
      printf("Invalid choice!\n");
    }
  } while (strcmp(choice, "3") != 0);
  printf("Thank you for using our product inventory system!\n");
  return 0;
}