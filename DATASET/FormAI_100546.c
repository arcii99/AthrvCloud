//FormAI DATASET v1.0 Category: Airport Baggage Handling Simulation ; Style: Linus Torvalds
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <semaphore.h>

#define NUM_BAGGAGE_HANDLERS 3
#define NUM_BAGGAGES 20

sem_t empty, full;
pthread_t handlers[NUM_BAGGAGE_HANDLERS];

int buffer[NUM_BAGGAGES];
int in = 0, out = 0;

void* handler(void* arg) {
   int id = (int) arg;
   printf("Baggage handler %d has started working.\n", id);
   while (1) {
      sem_wait(&full);
      int baggage = buffer[out];
      out = (out + 1) % NUM_BAGGAGES;
      sem_post(&empty);
      printf("Baggage handler %d is handling baggage %d.\n", id, baggage);
      sleep(1);
   }
}

int main() {
   sem_init(&empty, 0, NUM_BAGGAGES);
   sem_init(&full, 0, 0);

   for (int i = 0; i < NUM_BAGGAGE_HANDLERS; i++) {
      pthread_create(&handlers[i], NULL, handler, (void*) i);
   }

   for (int i = 0; i < NUM_BAGGAGES; i++) {
      sem_wait(&empty);
      buffer[in] = i;
      in = (in + 1) % NUM_BAGGAGES;
      sem_post(&full);
      printf("A new baggage with ID %d has arrived at the airport.\n", i);
      sleep(1);
   }

   for (int i = 0; i < NUM_BAGGAGE_HANDLERS; i++) {
      pthread_cancel(handlers[i]);
      printf("Baggage handler %d has finished working.\n", i);
   }

   sem_destroy(&empty);
   sem_destroy(&full);

   return 0;
}