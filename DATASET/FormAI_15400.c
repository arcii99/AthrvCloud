//FormAI DATASET v1.0 Category: Airport Baggage Handling Simulation ; Style: futuristic
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <semaphore.h>
#include <unistd.h>

#define NUM_BAGS 30
#define MAX_CARTS 5

int bags_processed = 0;
sem_t cart_semaphore, bag_semaphore;
pthread_mutex_t mutex;

/* Function to simulate processing of a bag */
void process_bag(int bag_id) {
  printf("Processing bag %d\n", bag_id);
  sleep(1); // Do some processing
}

/* Function to simulate handling of a bag by a baggage cart */
void handle_bag(int bag_id, int cart_id) {
  printf("Handling bag %d with cart %d\n", bag_id, cart_id);
  sleep(rand()%4+1); // Simulate handling time
}

/* Function for baggage cart thread */
void *baggage_cart(void *arg) {
  int cart_id = *((int *) arg);
  int bags_handled = 0;
  while (1) {
    // Wait for a bag to be available
    sem_wait(&bag_semaphore);
    pthread_mutex_lock(&mutex);
    bags_processed++;
    pthread_mutex_unlock(&mutex);
    bags_handled++;

    // Check if maximum bags per cart limit has been reached
    if (bags_handled == MAX_CARTS) {
      printf("Cart %d is full. Going to unload bags\n", cart_id);
      // Signal main thread that cart is ready to unload
      sem_post(&cart_semaphore);

      // Wait for main thread to signal that bags have been unloaded
      sem_wait(&bag_semaphore);
      bags_handled = 0;
    }

    // Simulate handling of the bag
    handle_bag(bags_processed, cart_id);
    process_bag(bags_processed); // Process the bag
  }
  pthread_exit(NULL);
}

int main() {
  pthread_t carts[MAX_CARTS];
  sem_init(&cart_semaphore, 0, 0);
  sem_init(&bag_semaphore, 0, NUM_BAGS);

  int cart_ids[MAX_CARTS];
  for (int i = 0; i < MAX_CARTS; i++) {
    cart_ids[i] = i+1;
    pthread_create(&carts[i], NULL, baggage_cart, &cart_ids[i]);
  }

  while (1) {
    // Wait for a baggage cart to be ready for unloading
    sem_wait(&cart_semaphore);

    // Signal all baggage carts to start loading again
    sem_post(&bag_semaphore);

    // Wait for all baggage carts to finish unloading
    for (int i = 0; i < MAX_CARTS; i++)
      sem_wait(&cart_semaphore);
  }

  sem_destroy(&cart_semaphore);
  sem_destroy(&bag_semaphore);
  pthread_mutex_destroy(&mutex);
  return 0;
}