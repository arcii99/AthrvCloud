//FormAI DATASET v1.0 Category: Threading Library Implementation ; Style: detailed
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define MAX_THREADS 5
#define MAX_COUNT 10

pthread_mutex_t count_mutex;
pthread_cond_t count_cv;

int count = 0;

void *counter_thread(void *arg){
   int i;
   for(i = 0; i < MAX_COUNT; i++){
      pthread_mutex_lock(&count_mutex);
      count++;
      printf("Counter Thread: count = %d\n", count);
      if(count == MAX_COUNT){
         pthread_cond_signal(&count_cv);
      }
      pthread_mutex_unlock(&count_mutex);
   }
   pthread_exit(NULL);
}

int main(){
   pthread_t threads[MAX_THREADS];
   int rc, i;
   pthread_mutex_init(&count_mutex, NULL);
   pthread_cond_init(&count_cv, NULL);

   for(i = 0; i < MAX_THREADS; i++){
      rc = pthread_create(&threads[i], NULL, counter_thread, NULL);
      if(rc != 0){
         printf("ERROR: Return code from pthread_create() is %d\n", rc);
         exit(-1);
      }
   }
   pthread_mutex_lock(&count_mutex);
   while(count < MAX_COUNT){
      pthread_cond_wait(&count_cv, &count_mutex);
   }
   pthread_mutex_unlock(&count_mutex);
   printf("Main Thread: count = %d\n", count);
   pthread_mutex_destroy(&count_mutex);
   pthread_cond_destroy(&count_cv);
   pthread_exit(NULL);
}