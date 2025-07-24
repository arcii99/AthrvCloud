//FormAI DATASET v1.0 Category: Alien Invasion Probability Calculator ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define NUM_THREADS 3

typedef struct alienStats {
  int numAliens;
  int numCities;
  float invasionProb;
} AlienStats;

void *calculateInvasionProb(void *threadData) {
  AlienStats *data;
  data = (AlienStats *) threadData;
  
  data->invasionProb = ((float) data->numAliens / data->numCities) * 100;

  pthread_exit(NULL);
}

int main() {
  pthread_t threads[NUM_THREADS];
  AlienStats aliens[NUM_THREADS];
  int rc, t;
  
  for (t = 0; t < NUM_THREADS; t++) {
    aliens[t].numAliens = (rand() % 1000) + 1;
    aliens[t].numCities = (rand() % 100) + 1;
    
    rc = pthread_create(&threads[t], NULL, calculateInvasionProb, (void *) &aliens[t]);
    
    if (rc) {
      printf("Error: Unable to create thread %d\n", t);
      exit(-1);
    }
  }
  
  for (t = 0; t < NUM_THREADS; t++) {
    rc = pthread_join(threads[t], NULL);
    
    if (rc) {
      printf("Error: Unable to join thread %d\n", t);
      exit(-1);
    }
    
    printf("Thread %d - Alien Invasion Probability: %.2f%%\n", t+1, aliens[t].invasionProb);
  }
  
  pthread_exit(NULL);
}