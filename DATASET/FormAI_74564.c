//FormAI DATASET v1.0 Category: Data mining ; Style: authentic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CUSTOMERS 1000
#define MAX_PURCHASES 1000
#define MAX_PRODUCTS 100
#define MAX_PROMOTIONS 10

/* Struct for storing a product */
typedef struct {
  int id;
  char name[50];
} Product;

/* Struct for storing a customer's purchase */
typedef struct {
  int customer_id;
  int product_id;
  float price;
} Purchase;

/* Struct for storing a promotion */
typedef struct {
  char name[50];
  int product_id;
  float discount;
} Promotion;

/* Struct for storing a customer */
typedef struct {
  int id;
  char name[50];
  int num_purchases;
  Purchase purchases[MAX_PURCHASES];
} Customer;

/* Function to read a CSV file containing products */
int read_products(const char* filename, Product products[]) {
  FILE* file = fopen(filename, "r");
  if (!file) {
    fprintf(stderr, "Error: Failed to open file %s\n", filename);
    return 0;
  }

  char line[256];
  int num_products = 0;

  /* Read each line of the file */
  while(fgets(line, sizeof(line), file)) {
    /* Split the line into fields */
    char* id_str = strtok(line, ",");
    char* name = strtok(NULL, ",");
    if (!id_str || !name) {
      fprintf(stderr, "Error: Invalid product line in file %s\n", filename);
      continue;
    }

    /* Convert the ID to an integer */
    int id = atoi(id_str);
    if (id <= 0) {
      fprintf(stderr, "Error: Invalid product ID in file %s\n", filename);
      continue;
    }

    /* Create the product */
    products[num_products].id = id;
    strncpy(products[num_products].name, name, sizeof(products[num_products].name) - 1);
    num_products++;
  }

  fclose(file);
  return num_products;
}

/* Function to read a CSV file containing purchases */
int read_purchases(const char* filename, Purchase purchases[]) {
  FILE* file = fopen(filename, "r");
  if (!file) {
    fprintf(stderr, "Error: Failed to open file %s\n", filename);
    return 0;
  }

  char line[256];
  int num_purchases = 0;

  /* Read each line of the file */
  while(fgets(line, sizeof(line), file)) {
    /* Split the line into fields */
    char* customer_id_str = strtok(line, ",");
    char* product_id_str = strtok(NULL, ",");
    char* price_str = strtok(NULL, ",");
    if (!customer_id_str || !product_id_str || !price_str) {
      fprintf(stderr, "Error: Invalid purchase line in file %s\n", filename);
      continue;
    }

    /* Convert the IDs and price to integers/floats */
    int customer_id = atoi(customer_id_str);
    int product_id = atoi(product_id_str);
    float price = atof(price_str);

    /* Create the purchase */
    purchases[num_purchases].customer_id = customer_id;
    purchases[num_purchases].product_id = product_id;
    purchases[num_purchases].price = price;
    num_purchases++;
  }

  fclose(file);
  return num_purchases;
}

/* Function to read a CSV file containing promotions */
int read_promotions(const char* filename, Promotion promotions[]) {
  FILE* file = fopen(filename, "r");
  if (!file) {
    fprintf(stderr, "Error: Failed to open file %s\n", filename);
    return 0;
  }

  char line[256];
  int num_promotions = 0;

  /* Read each line of the file */
  while(fgets(line, sizeof(line), file)) {
    /* Split the line into fields */
    char* name = strtok(line, ",");
    char* product_id_str = strtok(NULL, ",");
    char* discount_str = strtok(NULL, ",");
    if (!name || !product_id_str || !discount_str) {
      fprintf(stderr, "Error: Invalid promotion line in file %s\n", filename);
      continue;
    }

    /* Convert the product ID and discount to integers/floats */
    int product_id = atoi(product_id_str);
    float discount = atof(discount_str);

    /* Create the promotion */
    strncpy(promotions[num_promotions].name, name, sizeof(promotions[num_promotions].name) - 1);
    promotions[num_promotions].product_id = product_id;
    promotions[num_promotions].discount = discount;
    num_promotions++;
  }

  fclose(file);
  return num_promotions;
}

/* Function to find a product by ID */
Product* find_product(Product products[], int num_products, int product_id) {
  for (int i = 0; i < num_products; i++) {
    if (products[i].id == product_id) {
      return &products[i];
    }
  }
  return NULL;
}

int main() {
  /* Read in the data */
  Product products[MAX_PRODUCTS];
  int num_products = read_products("products.csv", products);

  Purchase purchases[MAX_PURCHASES];
  int num_purchases = read_purchases("purchases.csv", purchases);

  Promotion promotions[MAX_PROMOTIONS];
  int num_promotions = read_promotions("promotions.csv", promotions);

  /* Create the customers */
  Customer customers[MAX_CUSTOMERS];
  int num_customers = 0;

  for (int i = 0; i < num_purchases; i++) {
    /* Find the customer in the existing list, or create a new one */
    int customer_id = purchases[i].customer_id;
    Customer* customer = NULL;

    for (int j = 0; j < num_customers; j++) {
      if (customers[j].id == customer_id) {
        customer = &customers[j];
        break;
      }
    }

    if (!customer) {
      if (num_customers >= MAX_CUSTOMERS) {
        fprintf(stderr, "Error: Too many customers\n");
        return 1;
      }
      customer = &customers[num_customers];
      customer->id = customer_id;
      num_customers++;
    }

    /* Add the purchase to the customer's list */
    int product_id = purchases[i].product_id;
    Product* product = find_product(products, num_products, product_id);

    if (!product) {
      fprintf(stderr, "Error: Invalid product ID %d\n", product_id);
      continue;
    }

    customer->purchases[customer->num_purchases].product_id = product_id;
    customer->purchases[customer->num_purchases].price = purchases[i].price;
    customer->num_purchases++;
  }

  /* Analyze the data */
  for (int i = 0; i < num_customers; i++) {
    Customer* customer = &customers[i];
    printf("Customer %d (%s)\n", customer->id, customer->name);
    printf("Purchases:\n");
    float total_spent = 0;

    for (int j = 0; j < customer->num_purchases; j++) {
      int product_id = customer->purchases[j].product_id;
      Product* product = find_product(products, num_products, product_id);
      total_spent += customer->purchases[j].price;
      printf("- %s ($%.2f)\n", product ? product->name : "Unknown", customer->purchases[j].price);
    }

    printf("Total spent: $%.2f\n", total_spent);

    /* Find the customer's preferred promotion */
    float best_discount = 0;
    Promotion* best_promotion = NULL;

    for (int j = 0; j < num_promotions; j++) {
      if (promotions[j].product_id == customer->purchases[0].product_id
          && promotions[j].discount > best_discount) {
        best_discount = promotions[j].discount;
        best_promotion = &promotions[j];
      }
    }

    if (best_promotion) {
      printf("Recommended promotion: %s (%.0f%% off)\n", best_promotion->name, best_promotion->discount * 100);
    }

    printf("\n");
  }

  return 0;
}