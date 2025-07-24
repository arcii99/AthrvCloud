//FormAI DATASET v1.0 Category: Warehouse Management System ; Style: excited
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct {
  int id;
  char name[50];
  int quantity;
  float price;
}Product;

void printProduct(Product *product){
  printf("\nProduct ID: %d\n", product->id);
  printf("Product Name: %s\n", product->name);
  printf("Product Quantity: %d\n", product->quantity);
  printf("Product Price: %.2f\n", product->price);
}

int main(){
  Product products[5];

  for(int i = 0; i < 5; i++){
    printf("Enter product ID: ");
    scanf("%d", &products[i].id);

    printf("Enter product name: ");
    scanf("%s", products[i].name);

    printf("Enter product quantity: ");
    scanf("%d", &products[i].quantity);

    printf("Enter product price: ");
    scanf("%f", &products[i].price);
  }

  printf("Warehouse Inventory\n");
  printf("====================\n");

  for(int i = 0; i < 5; i++){
    printProduct(&products[i]);
  }

  return 0;
}