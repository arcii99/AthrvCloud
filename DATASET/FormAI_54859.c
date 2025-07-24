//FormAI DATASET v1.0 Category: Stock market tracker ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <string.h>
#include <unistd.h>

#define NUM_THREADS 5	// number of threads

struct thread_data {
  int thread_id;		// thread id
  int delay_time;		// delay time
  char symbol[10];		// stock symbol
  float prev_price;	// previous price of stock
  float cur_price;		// current price of stock
};

struct thread_data thread_data_array[NUM_THREADS];	// array of thread data

pthread_mutex_t mutex;	// mutex for thread synchronization

void *monitor_stock(void *threadarg) {
  struct thread_data *my_data;
  my_data = (struct thread_data *) threadarg;

  while(1) {
    // generate random stock price change
    float price_change = (float)(rand() % 500 - 250) / 100.0;

    // update current stock price
    pthread_mutex_lock(&mutex);
    my_data->cur_price = my_data->prev_price + price_change;
    my_data->prev_price = my_data->cur_price;
    pthread_mutex_unlock(&mutex);

    // print stock price update
    printf("Thread %d: Stock symbol %s price changed from %.2f to %.2f\n", 
        my_data->thread_id, my_data->symbol, my_data->prev_price, my_data->cur_price);

    // add delay for next update
    sleep(my_data->delay_time);
  }
}

int main() {
  int i;
  pthread_t threads[NUM_THREADS];

  // initialize thread data array
  strncpy(thread_data_array[0].symbol, "AAPL", 4);
  thread_data_array[0].prev_price = 140.29;
  thread_data_array[0].cur_price = 140.29;
  thread_data_array[0].delay_time = 3;
  thread_data_array[0].thread_id = 1;

  strncpy(thread_data_array[1].symbol, "GOOG", 4);
  thread_data_array[1].prev_price = 2254.96;
  thread_data_array[1].cur_price = 2254.96;
  thread_data_array[1].delay_time = 5;
  thread_data_array[1].thread_id = 2;

  strncpy(thread_data_array[2].symbol, "MSFT", 4);
  thread_data_array[2].prev_price = 240.97;
  thread_data_array[2].cur_price = 240.97;
  thread_data_array[2].delay_time = 7;
  thread_data_array[2].thread_id = 3;

  strncpy(thread_data_array[3].symbol, "TSLA", 4);
  thread_data_array[3].prev_price = 729.40;
  thread_data_array[3].cur_price = 729.40;
  thread_data_array[3].delay_time = 4;
  thread_data_array[3].thread_id = 4;

  strncpy(thread_data_array[4].symbol, "AMZN", 4);
  thread_data_array[4].prev_price = 3351.30;
  thread_data_array[4].cur_price = 3351.30;
  thread_data_array[4].delay_time = 6;
  thread_data_array[4].thread_id = 5;

  // initialize mutex
  pthread_mutex_init(&mutex, NULL);

  // create threads
  for (i = 0; i < NUM_THREADS; i++) {
    int rc = pthread_create(&threads[i], NULL, monitor_stock, (void *)&thread_data_array[i]);
    if (rc) {
      printf("ERROR; return code from pthread_create() is %d\n", rc);
      exit(-1);
    }
  }

  // wait for threads to finish
  for (i = 0; i < NUM_THREADS; i++) {
    pthread_join(threads[i], NULL);
  }

  pthread_mutex_destroy(&mutex);	// destroy mutex

  return 0;
}