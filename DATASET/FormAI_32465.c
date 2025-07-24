//FormAI DATASET v1.0 Category: Warehouse Management System ; Style: multi-threaded
#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define NUM_THREADS 5

int warehouse_stock = 0;
pthread_mutex_t warehouse_lock;

void *producer(void *threadid) {
   long tid;
   tid = (long)threadid;
   
   while(1){
      // Acquire lock to access warehouse_stock
      pthread_mutex_lock(&warehouse_lock);
      if(warehouse_stock < 100){
         // Produce item and increase warehouse_stock
         int produced = rand() % 11;
         warehouse_stock += produced;
         printf("Producer %ld produced %d items. Currently stocked: %d\n", tid, produced, warehouse_stock);
      }
      // Release lock
      pthread_mutex_unlock(&warehouse_lock);
      usleep(rand() % 500000 + 500000); // Sleep for random amount between 0.5 and 1 seconds
   }
   pthread_exit(NULL);
}

void *consumer(void *threadid) {
   long tid;
   tid = (long)threadid;
   
   while(1){
      // Acquire lock to access warehouse_stock
      pthread_mutex_lock(&warehouse_lock);
      if(warehouse_stock > 0){
         // Consume item and decrease warehouse_stock
         int consumed = rand() % 6;
         if(warehouse_stock - consumed < 0){ // Make sure we don't have negative stock
            consumed = warehouse_stock;
            warehouse_stock = 0;
         } else {
            warehouse_stock -= consumed;
         }
         printf("Consumer %ld consumed %d items. Currently stocked: %d\n", tid, consumed, warehouse_stock);
      }
      // Release lock
      pthread_mutex_unlock(&warehouse_lock);
      usleep(rand() % 500000 + 500000); // Sleep for random amount between 0.5 and 1 seconds
   }
   pthread_exit(NULL);
}

int main(int argc, char *argv[]) {
   pthread_t threads[NUM_THREADS];
   int rc;
   long t;
   
   // Initialize mutex lock
   pthread_mutex_init(&warehouse_lock, NULL);
   
   // Create producer threads
   for(t=0; t<NUM_THREADS/2; t++){
      rc = pthread_create(&threads[t], NULL, producer, (void *)t);
      if (rc){
         printf("ERROR; return code from pthread_create() is %d\n", rc);
         exit(-1);
      }
   }
   
   // Create consumer threads
   for(t=NUM_THREADS/2; t<NUM_THREADS; t++){
      rc = pthread_create(&threads[t], NULL, consumer, (void *)t);
      if (rc){
         printf("ERROR; return code from pthread_create() is %d\n", rc);
         exit(-1);
      }
   }
   
   // Join all threads
   for(t=0; t<NUM_THREADS; t++){
      rc = pthread_join(threads[t], NULL);
      if (rc){
         printf("ERROR; return code from pthread_join() is %d\n", rc);
         exit(-1);
      }
   }
  
  // Destroy mutex lock
  pthread_mutex_destroy(&warehouse_lock);

  return 0;
}