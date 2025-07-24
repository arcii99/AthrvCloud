//FormAI DATASET v1.0 Category: Airport Baggage Handling Simulation ; Style: single-threaded
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<pthread.h>

#define NUM_OF_BELT 5
#define NUM_OF_PASSENGERS 100

// Define structure to represent baggage
typedef struct baggage {
  int baggage_id;
  int num_items;
} Baggage;

// Define queue for the belt
Baggage belt[NUM_OF_BELT];
int front = 0, rear = 0, numOfElementsOnBelt = 0;

// Define variables to keep track of statistics
int numOfBagsLoaded = 0, numOfBagsUnloaded = 0;

// Define a mutex to protect the queue
pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;

// Define condition variables for passenger and conveyor belt
pthread_cond_t passengerWaiting = PTHREAD_COND_INITIALIZER;
pthread_cond_t conveyorLoaded = PTHREAD_COND_INITIALIZER;

// Function to produce new baggage onto the belt
void* produce(void *arg) {
  
  Baggage newBaggage;
  int passengerId = *(int *)arg;
  
  // Generate a random time to produce baggage
  int productionTime = rand() % 5;
  sleep(productionTime);  
  
  // Generate a random number of items for the baggage
  newBaggage.num_items = rand() % 5;

  // Lock the queue
  pthread_mutex_lock(&mutex);

  // If the belt is full, wait for a passenger to take baggage off the belt
  while(numOfElementsOnBelt >= NUM_OF_BELT) {
    pthread_cond_wait(&conveyorLoaded, &mutex);
  }

  // Add the new baggage to the belt
  newBaggage.baggage_id = ++numOfBagsLoaded;
  belt[rear] = newBaggage;
  rear = (rear + 1) % NUM_OF_BELT;
  numOfElementsOnBelt++;

  printf("Passenger %d produced a new baggage with %d items\n", passengerId, newBaggage.num_items);

  // Signal the passenger to take baggage off the belt
  pthread_cond_signal(&passengerWaiting);

  // Unlock the queue
  pthread_mutex_unlock(&mutex);

  return NULL;
}

// Function to consume baggage off the belt
void* consume(void *arg) {

  int passengerId = *(int *)arg;
  
  // Lock the queue
  pthread_mutex_lock(&mutex);

  // If the belt is empty, wait for a new baggage to be produced
  while(numOfElementsOnBelt <= 0) {
    pthread_cond_wait(&passengerWaiting, &mutex);
  }

  // Remove baggage from the belt
  Baggage consumedBaggage = belt[front];
  front = (front + 1) % NUM_OF_BELT;
  numOfElementsOnBelt--;
  numOfBagsUnloaded++;

  printf("Passenger %d consumed a baggage with %d items\n", passengerId, consumedBaggage.num_items);

  // Signal the producer that the belt is empty
  pthread_cond_signal(&conveyorLoaded);

  // Unlock the queue
  pthread_mutex_unlock(&mutex);

  return NULL;
}

int main() {
  
  // Seed the random number generator
  srand(time(NULL));

  // Define threads for producers and consumers
  pthread_t producers[NUM_OF_PASSENGERS];
  pthread_t consumers[NUM_OF_PASSENGERS];

  // Create producers and consumers
  int i;
  for(i = 0; i < NUM_OF_PASSENGERS; i++) {
    pthread_create(&producers[i], NULL, produce, (void *)&i);
    pthread_create(&consumers[i], NULL, consume, (void *)&i);
  }

  // Wait for producers and consumers to finish
  for(i = 0; i < NUM_OF_PASSENGERS; i++) {
    pthread_join(producers[i], NULL);
    pthread_join(consumers[i], NULL);
  }

  // Print statistics
  printf("Number of bags produced: %d\n", numOfBagsLoaded);
  printf("Number of bags consumed: %d\n", numOfBagsUnloaded);

  return 0;
}