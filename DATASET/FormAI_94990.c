//FormAI DATASET v1.0 Category: Airport Baggage Handling Simulation ; Style: realistic
#include<stdio.h>
#include<stdlib.h>
#include<pthread.h>
#include<unistd.h>

#define BELT_SIZE 10            // maximum size of conveyor belt
#define MAX_LUGGAGE_WEIGHT 30   // maximum weight of a luggage
#define MAX_DELAY_TIME 5        // maximum time a worker can take to add a luggage
#define MAX_WORKERS 2           // maximum number of baggage handlers

pthread_mutex_t mutex;          // mutex for synchronization
pthread_cond_t conveyor_empty;  // conditional variable for empty conveyor belt
pthread_cond_t conveyor_full;   // conditional variable for full conveyor belt

int luggage_on_belt = 0;        // number of luggages present on the belt
int total_luggage_count = 0;    // total number of luggages handled by the system

void *worker(void *arg) {
    int worker_id = *(int*)arg;
    
    while(1) {
        // randomly generate luggage weight and delay time
        int luggage_weight = rand() % MAX_LUGGAGE_WEIGHT + 1;
        int delay_time = rand() % MAX_DELAY_TIME + 1;
        
        // sleep for delay time
        sleep(delay_time);
        
        // add luggage to the conveyor belt
        pthread_mutex_lock(&mutex);
        while(luggage_on_belt == BELT_SIZE) {
            printf("Worker %d waiting for space on conveyor belt\n", worker_id);
            pthread_cond_wait(&conveyor_full, &mutex);
        }
        printf("Worker %d adding luggage (weight = %d) to conveyor belt\n", worker_id, luggage_weight);
        luggage_on_belt++;
        total_luggage_count++;
        pthread_cond_signal(&conveyor_empty);
        pthread_mutex_unlock(&mutex);
    }
}

int main() {
    srand(time(NULL));
    
    // initialize mutex and conditional variable
    pthread_mutex_init(&mutex, NULL);
    pthread_cond_init(&conveyor_empty, NULL);
    pthread_cond_init(&conveyor_full, NULL);
    
    // create worker threads
    pthread_t workers[MAX_WORKERS];
    int worker_ids[MAX_WORKERS];
    for(int i = 0; i < MAX_WORKERS; i++) {
        worker_ids[i] = i;
        pthread_create(&workers[i], NULL, worker, &worker_ids[i]);
    }

    // continuously monitor the conveyor belt
    while(1) {
        pthread_mutex_lock(&mutex);
        
        // wait for a luggage to arrive on the conveyor belt
        while(luggage_on_belt == 0) {
            printf("No luggage on conveyor belt\n");
            pthread_cond_wait(&conveyor_empty, &mutex);
        }
        
        // randomly select a worker to handle the luggage
        int worker_id = rand() % MAX_WORKERS;
        printf("Worker %d handling luggage from conveyor belt\n", worker_id);
        luggage_on_belt--;
        
        // signal worker thread to add another luggage
        pthread_cond_signal(&conveyor_full);
        pthread_mutex_unlock(&mutex);
    }
    
    // cleanup
    pthread_mutex_destroy(&mutex);
    pthread_cond_destroy(&conveyor_empty);
    pthread_cond_destroy(&conveyor_full);
    for(int i = 0; i < MAX_WORKERS; i++) {
        pthread_cancel(workers[i]);
        pthread_join(workers[i], NULL);
    }
    
    return 0;
}