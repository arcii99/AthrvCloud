//FormAI DATASET v1.0 Category: Product Inventory System ; Style: recursive
#include <stdio.h>
#include <stdlib.h>

// Declare global variables
int products[100];
int count = 0;

// Function to add a product to the inventory
void addProduct(int productId) {
  if (count == 100) {
    printf("You have reached the maximum number of products that can be added to the inventory.\n");
    return;
  }
  
  products[count] = productId;
  count++;
  printf("Product %d has been successfully added to the inventory.\n", productId);
}

// Function to remove a product from the inventory
void removeProduct(int productId) {
  int i;
  for (i = 0; i < count; i++) {
    if (products[i] == productId) {
      break;
    }
  }

  if (i == count) {
    printf("Product %d is not in the inventory.\n", productId);
    return;
  }

  // Shift all products to the left to remove the product from the inventory
  for (int j = i; j < count-1; j++) {
    products[j] = products[j+1];
  }

  count--;
  printf("Product %d has been successfully removed from the inventory.\n", productId);
}

// Recursive function to display all the products in the inventory
void displayProducts(int index) {
  if (index == count) {
    return;
  }

  printf("Product %d\n", products[index]);

  displayProducts(index+1);
}

int main() {
  // Add some initial products to the inventory
  addProduct(1001);
  addProduct(1002);
  addProduct(1003);

  printf("Inventory:\n");
  displayProducts(0);

  removeProduct(1001);
  
  printf("Inventory:\n");
  displayProducts(0);

  addProduct(1004);

  printf("Inventory:\n");
  displayProducts(0);

  return 0;
}