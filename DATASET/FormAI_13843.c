//FormAI DATASET v1.0 Category: Airport Baggage Handling Simulation ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>
#include <pthread.h>
#include <unistd.h>

#define MAX_NUM_FLIGHTS 10
#define MAX_NUM_BAGS 50

typedef struct {
    int flight_num;
    int num_bags;
    bool loaded;
} Flight;

Flight flights[MAX_NUM_FLIGHTS];
pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;

void* baggage_handler(void* arg) {
    int flight_index = *(int*) arg;
    printf("[BH] Starting baggage handling for Flight %d\n", flights[flight_index].flight_num);
    printf("[BH] Number of bags to handle: %d\n", flights[flight_index].num_bags);
    
    usleep(1000000); // Simulate baggage handling delay
    
    pthread_mutex_lock(&mutex);
    flights[flight_index].loaded = true;
    printf("[BH] Flight %d loaded and ready to depart. \n", flights[flight_index].flight_num);
    pthread_mutex_unlock(&mutex);
    pthread_exit(NULL);
}

int main() {
    srand(time(0));
    int num_flights = rand() % MAX_NUM_FLIGHTS + 1;
    printf("[AP] Number of flights scheduled: %d\n", num_flights);
    
    for(int i=0; i<num_flights; i++) {
        flights[i].flight_num = i+1;
        flights[i].num_bags = rand() % MAX_NUM_BAGS + 1;
        flights[i].loaded = false;
        printf("[AP] Flight %d scheduled with %d bags. \n", flights[i].flight_num, flights[i].num_bags);
    }
    
    pthread_t threads[num_flights];
    int indexes[num_flights];
    
    for(int i=0; i<num_flights; i++) {
        indexes[i] = i;
        pthread_create(&threads[i], NULL, baggage_handler, &indexes[i]);
    }
    
    for(int i=0; i<num_flights; i++) {
        pthread_join(threads[i], NULL);
    }
    
    printf("[AP] All flights have been loaded and are ready to depart. \n");
    
    return 0;
}