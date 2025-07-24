//FormAI DATASET v1.0 Category: Product Inventory System ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define NUM_PRODUCTS 10
#define THREADS_NUM 5

int inventory[NUM_PRODUCTS]; // array representing the inventory
pthread_mutex_t lock; // mutex lock for thread-safe access to inventory

// function for the product handler threads
void* handle_product(void* arg) {
  int product_num = *((int*) arg);

  while (1) {
    // lock the mutex before accessing the inventory
    pthread_mutex_lock(&lock);

    if (inventory[product_num] > 0) {
      // if there is inventory for the product, sell one unit
      inventory[product_num]--;
      printf("Sold one unit of product %d. ", product_num);
      printf("New inventory for product %d: %d\n", product_num, inventory[product_num]);
    } else {
      // if there is no inventory for the product, exit the loop and unlock the mutex
      printf("No inventory for product %d. ", product_num);
      break;
    }

    // unlock the mutex after accessing the inventory
    pthread_mutex_unlock(&lock);
  }

  return NULL;
}

int main() {
  // initialize the inventory array to random values
  for (int i = 0; i < NUM_PRODUCTS; i++) {
    inventory[i] = rand() % 10;
  }

  // initialize the mutex lock
  pthread_mutex_init(&lock, NULL);

  // create and start the product handler threads
  pthread_t threads[THREADS_NUM];
  int products[THREADS_NUM] = {0, 1, 2, 3, 4}; // each thread handles one product
  for (int i = 0; i < THREADS_NUM; i++) {
    pthread_create(&threads[i], NULL, handle_product, &products[i]);
  }

  // join the product handler threads
  for (int i = 0; i < THREADS_NUM; i++) {
    pthread_join(threads[i], NULL);
  }

  // destroy the mutex lock
  pthread_mutex_destroy(&lock);

  return 0;
}