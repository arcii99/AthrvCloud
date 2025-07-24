//FormAI DATASET v1.0 Category: Data mining ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>

#define NUM_CUSTOMERS 100
#define NUM_ITEMS 10

int main() {
  int customer_data[NUM_CUSTOMERS][NUM_ITEMS];
  int i, j, total_num_items = 0, total_num_customers = 0;

  // fill customer data randomly (0-10 for each item purchased)
  for (i = 0; i < NUM_CUSTOMERS; i++) {
    for (j = 0; j < NUM_ITEMS; j++) {
      customer_data[i][j] = rand() % 11;
    }
  }

  // calculate total number of items purchased
  for (i = 0; i < NUM_CUSTOMERS; i++) {
    for (j = 0; j < NUM_ITEMS; j++) {
      total_num_items += customer_data[i][j];
    }
  }

  // calculate total number of customers
  for (i = 0; i < NUM_CUSTOMERS; i++) {
    int count = 0;
    for (j = 0; j < NUM_ITEMS; j++) {
      if (customer_data[i][j] > 0) {
        count++;
      }
    }
    if (count > 0) {
      total_num_customers++;
    }
  }

  // print results
  printf("Total number of items purchased: %d\n", total_num_items);
  printf("Total number of customers: %d\n", total_num_customers);

  return 0;
}