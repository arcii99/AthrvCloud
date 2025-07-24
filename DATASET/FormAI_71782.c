//FormAI DATASET v1.0 Category: Product Inventory System ; Style: Ken Thompson
#include <stdio.h>

/* Struct to hold product information */
typedef struct product {
  char name[50];
  int id;
  float price;
  int quantity;
} Product;

/* Function to print a product */
void print_product(Product p) {
  printf("%s (ID: %d)\n", p.name, p.id);
  printf("Price: $%.2f\n", p.price);
  printf("Quantity: %d\n", p.quantity);
}

int main() {
  /* Declare and initialize products */
  Product p1 = {"iPhone 12", 1, 999.99, 10};
  Product p2 = {"Samsung Galaxy S21", 2, 899.99, 12};
  Product p3 = {"Google Pixel 5", 3, 699.99, 8};

  /* Print initial inventory */
  printf("Initial inventory:\n");
  print_product(p1);
  print_product(p2);
  print_product(p3);

  /* Update product quantities */
  p1.quantity -= 2;
  p2.quantity += 4;
  p3.quantity -= 1;

  /* Print updated inventory */
  printf("Updated inventory:\n");
  print_product(p1);
  print_product(p2);
  print_product(p3);

  return 0;
}