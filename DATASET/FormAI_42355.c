//FormAI DATASET v1.0 Category: Threading Library Implementation ; Style: secure
#include<stdio.h>
#include<stdlib.h>
#include<pthread.h>
 
int thread_count;
pthread_mutex_t mutex;
 
void* hello(void* rank) {
   long my_rank = (long) rank;
   pthread_mutex_lock(&mutex);
   printf("Hello from thread %ld of %d\n", my_rank, thread_count);
   pthread_mutex_unlock(&mutex);
   return NULL;
}  
 
int main(int argc, char** argv) {
   long thread;
   pthread_t* thread_handles;
 
   thread_count = strtol(argv[1], NULL, 10);
   thread_handles = malloc (thread_count*sizeof(pthread_t));
   pthread_mutex_init(&mutex, NULL);

   for (thread = 0; thread < thread_count; thread++)
      pthread_create(&thread_handles[thread], NULL, hello, (void*) thread);
 
   for (thread = 0; thread < thread_count; thread++) 
      pthread_join(thread_handles[thread], NULL);
 
   pthread_mutex_destroy(&mutex);
   free(thread_handles);
 
   return 0;
}