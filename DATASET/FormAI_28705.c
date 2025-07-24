//FormAI DATASET v1.0 Category: Stock market tracker ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define NUM_STOCKS 5

struct stock {
  char* name;
  float price;
};

struct stock stocks[NUM_STOCKS] = {
  {"AAPL", 125.65},
  {"GOOG", 2104.11},
  {"MSFT", 242.35},
  {"TSLA", 743.61},
  {"AMZN", 3549.59}
};

void *update_prices(void *arg) {
  int index = *(int *) arg;

  while (1) {
    float new_price = (((float) rand()) / RAND_MAX) * 100;
    printf("%s: %.2f -> %.2f\n", stocks[index].name, stocks[index].price, new_price);
    stocks[index].price = new_price;
    sleep(1);
  }
  return NULL;
}

int main() {
  pthread_t threads[NUM_STOCKS];
  int indexes[NUM_STOCKS];

  for (int i = 0; i < NUM_STOCKS; i++) {
    indexes[i] = i;
    pthread_create(&threads[i], NULL, update_prices, &indexes[i]);
  }

  for (int i = 0; i < NUM_STOCKS; i++) {
    pthread_join(threads[i], NULL);
  }

  return 0;
}