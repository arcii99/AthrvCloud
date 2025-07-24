//FormAI DATASET v1.0 Category: Medical Store Management System ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <semaphore.h>

#define MAX_STOCK 100
#define MAX_CUSTOMERS 5

typedef struct {
  int stock;
  sem_t sem_stock;
} item;

item stock;

void *customer(void *arg) {
  int id = *((int *)arg);
  int quantity = rand() % 10 + 1;
  printf("Customer %d wants to buy %d items.\n", id, quantity);
  
  sem_wait(&stock.sem_stock); // Wait for stock availability
  
  if (stock.stock >= quantity) {
    stock.stock -= quantity;
    printf("Customer %d has bought %d items. Stock remaining: %d\n", id, quantity, stock.stock);
  } else {
    printf("Customer %d could only buy %d items. Stock remaining: %d\n", id, stock.stock, stock.stock);
    stock.stock = 0;
  }
  
  sem_post(&stock.sem_stock); // Release stock
  
  pthread_exit(NULL);
}

void *supplier(void *arg) {
  int quantity = rand() % 10 + 1;
  printf("Supplier has delivered %d items.\n", quantity);
  
  sem_wait(&stock.sem_stock); // Wait for stock availability
  
  stock.stock += quantity;
  if (stock.stock > MAX_STOCK) {
    stock.stock = MAX_STOCK;
  }
  printf("%d items added to stock. Stock remaining: %d\n", quantity, stock.stock);
  
  sem_post(&stock.sem_stock); // Release stock
  
  pthread_exit(NULL);
}

int main() {
  pthread_t customers[MAX_CUSTOMERS];
  pthread_t sup;
  int cust_ids[MAX_CUSTOMERS];
 
  stock.stock = MAX_STOCK;
  sem_init(&stock.sem_stock, 0, 1);
  
  for (int i = 0; i < MAX_CUSTOMERS; i++) {
    cust_ids[i] = i + 1;
  }
  
  for (int i = 0; i < MAX_CUSTOMERS; i++) {
    pthread_create(&customers[i], NULL, customer, &cust_ids[i]);
  }
  
  pthread_create(&sup, NULL, supplier, NULL);
  
  for (int i = 0; i < MAX_CUSTOMERS; i++) {
    pthread_join(customers[i], NULL);
  }
  
  pthread_join(sup, NULL);
  
  sem_destroy(&stock.sem_stock);
  
  return 0;
}