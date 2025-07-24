//FormAI DATASET v1.0 Category: Movie Rating System ; Style: multi-threaded
#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>
#include <unistd.h>

int rating = 0; // variable to hold movie rating
pthread_mutex_t mutex; // mutex to synchronize access to rating variable
pthread_cond_t cond; // condition variable to signal consumers when rating is updated

void *producer(void *arg);
void *consumer(void *arg);

int main(int argc, char *argv[]) {
    pthread_t t1,t2,t3,t4; // threads for one producer and three consumers
    
    // initialize mutex and condition variables
    pthread_mutex_init(&mutex, NULL);
    pthread_cond_init(&cond, NULL);
    
    // create threads
    pthread_create(&t1, NULL, producer, NULL);
    pthread_create(&t2, NULL, consumer, (void *) 1);
    pthread_create(&t3, NULL, consumer, (void *) 2);
    pthread_create(&t4, NULL, consumer, (void *) 3);
    
    // join threads
    pthread_join(t1, NULL);
    pthread_join(t2, NULL);
    pthread_join(t3, NULL);
    pthread_join(t4, NULL);
    
    // destroy mutex and condition variables
    pthread_mutex_destroy(&mutex);
    pthread_cond_destroy(&cond);
    return 0;
}

void *producer(void *arg) {
    int i;
    for(i=0; i<10; i++) {
        sleep(1); // simulate some work
        int new_rating = rand() % 10; // generate random rating between 0-9
        pthread_mutex_lock(&mutex); // acquire lock on rating variable
        rating = new_rating; // update rating
        printf("Producer: The movie rating is now %d\n", rating);
        pthread_cond_broadcast(&cond); // signal all waiting consumers that rating has been updated
        pthread_mutex_unlock(&mutex); // release lock on rating variable
    }
    return NULL;
}

void *consumer(void *arg) {
    int id = (int) arg;
    while(1) {
        pthread_mutex_lock(&mutex); // acquire lock on rating variable
        while(rating == 0) { // while rating is not set, wait for producer to update
            pthread_cond_wait(&cond, &mutex); // release lock and wait for signal from producer
        }
        printf("Consumer %d: The movie rating is %d\n", id, rating); // consume rating
        pthread_mutex_unlock(&mutex); // release lock on rating variable
        sleep(2); // simulate some work
    }
    return NULL;
}