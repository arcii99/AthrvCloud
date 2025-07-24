//FormAI DATASET v1.0 Category: Airport Baggage Handling Simulation ; Style: multi-threaded
#include<stdio.h>
#include<stdlib.h>
#include<pthread.h>
#include<time.h>

#define NUM_THREADS 4
#define MAX_BAGS 50
#define MAX_WEIGHT 50

pthread_mutex_t conveyor_lock = PTHREAD_MUTEX_INITIALIZER;
pthread_cond_t conveyor_cond = PTHREAD_COND_INITIALIZER;
pthread_mutex_t load_lock = PTHREAD_MUTEX_INITIALIZER;
pthread_cond_t load_cond = PTHREAD_COND_INITIALIZER;

int conveyor_bags[MAX_BAGS];
int conveyor_count = 0;
int unload_count = 0;

void* conveyor(void* arg){
  int id = *((int*)arg);

  while(1){
    pthread_mutex_lock(&conveyor_lock);

    // Check if the conveyor is full
    while(conveyor_count==MAX_BAGS){
      pthread_cond_wait(&conveyor_cond,&conveyor_lock);
    }

    // Add a random bag to the conveyor belt
    int new_bag = rand()%MAX_WEIGHT;
    conveyor_bags[conveyor_count++] = new_bag;

    // Print status
    printf("Thread %d added a new bag of weight %d to the conveyor belt.\n",id,new_bag);

    // Signal the loader that a new bag has been added
    pthread_cond_signal(&load_cond);
    pthread_mutex_unlock(&conveyor_lock);

    // Wait for some time before adding another bag
    sleep(rand()%3+1);
  }

  return NULL;
}

void* loader(void* arg){
  while(1){
    pthread_mutex_lock(&load_lock);

    // Check if there are bags to unload
    while(conveyor_count==0){
      pthread_cond_wait(&load_cond,&load_lock);
    }

    // Unload a random bag from the conveyor belt
    int unloaded_bag = conveyor_bags[--conveyor_count];

    // Print status
    printf("Loader unloaded a bag of weight %d from the conveyor belt.\n",unloaded_bag);

    // Signal the conveyor thread that a bag has been unloaded
    unload_count++;
    pthread_cond_signal(&conveyor_cond);
    pthread_mutex_unlock(&load_lock);

    // Wait for some time before unloading another bag
    sleep(rand()%4+2);
  }

  return NULL;
}

int main(){
  srand(time(NULL));
  int i;
  pthread_t threads[NUM_THREADS];
  int thread_ids[NUM_THREADS];
  
  // Create conveyor thread
  thread_ids[0] = 0;
  pthread_create(&threads[0],NULL,conveyor,&thread_ids[0]);

  // Create loader threads
  for(i=1;i<NUM_THREADS;i++){
    thread_ids[i] = i;
    pthread_create(&threads[i],NULL,loader,&thread_ids[i]);
  }

  // Join all threads
  for(i=0;i<NUM_THREADS;i++){
    pthread_join(threads[i],NULL);
  }

  return 0;
}