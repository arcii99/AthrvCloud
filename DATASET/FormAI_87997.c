//FormAI DATASET v1.0 Category: Medical Store Management System ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define NUM_MEDICINES 10
#define NUM_CUSTOMERS 5
#define MAX_STOCK 50
#define MIN_STOCK 10

int stock_count[NUM_MEDICINES];
pthread_mutex_t lock;

void* customer_order(void* arg) {
  int medicine_num = *((int*)arg);
  int quantity = rand() % 5 + 1;

  pthread_mutex_lock(&lock);

  if(stock_count[medicine_num] >= quantity) {
    stock_count[medicine_num] -= quantity;
    printf("Customer ordered %d quantity of medicine %d. Stock remaining: %d\n", quantity, medicine_num, stock_count[medicine_num]);
  }
  else {
    printf("Customer tried to order %d quantity of medicine %d but it is out of stock.\n", quantity, medicine_num);
  }

  pthread_mutex_unlock(&lock);
  pthread_exit(NULL);
}

void* stock_update(void* arg) {
  int medicine_num = *((int*)arg);

  pthread_mutex_lock(&lock);

  if(stock_count[medicine_num] < MAX_STOCK) {
    stock_count[medicine_num] += rand() % 10 + 1;
    printf("Updated stock for medicine %d. New stock count: %d\n", medicine_num, stock_count[medicine_num]);
  }

  pthread_mutex_unlock(&lock);
  pthread_exit(NULL);
}

int main() {
  pthread_t customers[NUM_CUSTOMERS];
  pthread_t stock_updaters[NUM_MEDICINES];
  int medicine_nums[NUM_MEDICINES];

  pthread_mutex_init(&lock, NULL);

  // Initialize stock count for each medicine
  for(int i = 0; i < NUM_MEDICINES; i++) {
    stock_count[i] = rand() % (MAX_STOCK-MIN_STOCK+1) + MIN_STOCK;
    medicine_nums[i] = i;
  }

  // Print initial stock count
  printf("Initial stock count for each medicine:\n");
  for(int i = 0; i < NUM_MEDICINES; i++) {
    printf("Medicine %d: %d\n", i, stock_count[i]);
  }

  // Create customer threads
  for(int i = 0; i < NUM_CUSTOMERS; i++) {
    int medicine_num = rand() % NUM_MEDICINES;
    pthread_create(&customers[i], NULL, customer_order, &medicine_num);
  }

  // Create stock updater threads
  for(int i = 0; i < NUM_MEDICINES; i++) {
    pthread_create(&stock_updaters[i], NULL, stock_update, &medicine_nums[i]);
  }

  // Join customer threads
  for(int i = 0; i < NUM_CUSTOMERS; i++) {
    pthread_join(customers[i], NULL);
  }

  // Join stock updater threads
  for(int i = 0; i < NUM_MEDICINES; i++) {
    pthread_join(stock_updaters[i], NULL);
  }

  // Print final stock count
  printf("Final stock count for each medicine:\n");
  for(int i = 0; i < NUM_MEDICINES; i++) {
    printf("Medicine %d: %d\n", i, stock_count[i]);
  }

  pthread_mutex_destroy(&lock);
  return 0;
}