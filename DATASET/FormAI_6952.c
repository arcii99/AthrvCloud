//FormAI DATASET v1.0 Category: Airport Baggage Handling Simulation ; Style: authentic
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <stdbool.h>
#include <time.h>

// Constants
#define MAX_BAGS 100         // maximum number of bags
#define MAX_WEIGHT 50        // maximum weight of a bag
#define CONVEYOR_SIZE 10     // maximum number of bags on the conveyor at once
#define NUM_CHECKINS 3       // number of check-in counters
#define NUM_SCANNERS 2       // number of baggage scanners
#define NUM_CONVEYORS 2      // number of conveyor belts for loading onto plane
#define TIME_MIN 1           // minimum time to process a bag (in seconds)
#define TIME_MAX 3           // maximum time to process a bag (in seconds)
#define SIM_TIME 60          // simulation time (in seconds)

// Global variables
pthread_mutex_t mutex_checkin[NUM_CHECKINS];             // mutex array for check-in counters
pthread_mutex_t mutex_scanner[NUM_SCANNERS];             // mutex array for baggage scanners
pthread_mutex_t mutex_conveyor[NUM_CONVEYORS];           // mutex array for loading conveyor belts
pthread_mutex_t mutex_outbound;                          // mutex for outbound conveyor belt
int bags_checked_in = 0;                                 // number of bags checked in
int bags_scanned = 0;                                    // number of bags scanned
int bags_loaded = 0;                                     // number of bags loaded onto plane
int bags_unloaded = 0;                                   // number of bags unloaded from plane
int checkin_queue[NUM_CHECKINS * CONVEYOR_SIZE] = {0};    // array for check-in queues
int checkin_front[NUM_CHECKINS] = {0};                    // array for check-in queue fronts
int scanner_queue[NUM_SCANNERS * CONVEYOR_SIZE] = {0};    // array for scanner queues
int scanner_front[NUM_SCANNERS] = {0};                    // array for scanner queue fronts
int conveyor_queue[NUM_CONVEYORS][CONVEYOR_SIZE];          // 2D array for conveyor belt queues
int conveyor_size[NUM_CONVEYORS] = {0};                   // array for conveyor belt sizes
int conveyor_capacity[NUM_CONVEYORS] = {CONVEYOR_SIZE};   // array for conveyor belt capacities
int conveyor_front[NUM_CONVEYORS] = {0};                  // array for conveyor belt queue fronts
int outbound_queue[CONVEYOR_SIZE] = {0};                  // array for outbound conveyor belt queue
int outbound_front = 0;                                  // front of outbound conveyor belt queue

// Function prototypes
void *checkin_counter(void *arg);
void *scanner(void *arg);
void *outbound_conveyor(void *arg);
void *flight(void *arg);
void enqueue(int *queue, int *front, int item);
int dequeue(int *queue, int *front);
bool queue_full(int *queue, int *front, int capacity);
bool queue_empty(int *queue, int *front);

// Main function
int main() {
    // Seed random number generator
    srand(time(NULL));
    
    // Initialize mutexes
    for (int i = 0; i < NUM_CHECKINS; i++) {
        pthread_mutex_init(&mutex_checkin[i], NULL);
    }
    for (int i = 0; i < NUM_SCANNERS; i++) {
        pthread_mutex_init(&mutex_scanner[i], NULL);
    }
    for (int i = 0; i < NUM_CONVEYORS; i++) {
        pthread_mutex_init(&mutex_conveyor[i], NULL);
    }
    pthread_mutex_init(&mutex_outbound, NULL);
    
    // Initialize threads
    pthread_t checkin_threads[NUM_CHECKINS];
    pthread_t scanner_threads[NUM_SCANNERS];
    pthread_t outbound_thread;
    pthread_t flight_thread;
    
    // Create check-in threads
    for (int i = 0; i < NUM_CHECKINS; i++) {
        pthread_create(&checkin_threads[i], NULL, checkin_counter, &i);
    }
    
    // Create scanner threads
    for (int i = 0; i < NUM_SCANNERS; i++) {
        pthread_create(&scanner_threads[i], NULL, scanner, &i);
    }
    
    // Create outbound conveyor thread
    pthread_create(&outbound_thread, NULL, outbound_conveyor, NULL);
    
    // Create flight thread
    pthread_create(&flight_thread, NULL, flight, NULL);
    
    // Sleep for simulation time
    sleep(SIM_TIME);
    
    // Join threads
    for (int i = 0; i < NUM_CHECKINS; i++) {
        pthread_join(checkin_threads[i], NULL);
    }
    for (int i = 0; i < NUM_SCANNERS; i++) {
        pthread_join(scanner_threads[i], NULL);
    }
    pthread_join(outbound_thread, NULL);
    pthread_join(flight_thread, NULL);
    
    // Print simulation results
    printf("Total bags checked in: %d\n", bags_checked_in);
    printf("Total bags scanned: %d\n", bags_scanned);
    printf("Total bags loaded onto plane: %d\n", bags_loaded);
    printf("Total bags unloaded from plane: %d\n", bags_unloaded);
    
    // Destroy mutexes
    for (int i = 0; i < NUM_CHECKINS; i++) {
        pthread_mutex_destroy(&mutex_checkin[i]);
    }
    for (int i = 0; i < NUM_SCANNERS; i++) {
        pthread_mutex_destroy(&mutex_scanner[i]);
    }
    for (int i = 0; i < NUM_CONVEYORS; i++) {
        pthread_mutex_destroy(&mutex_conveyor[i]);
    }
    pthread_mutex_destroy(&mutex_outbound);
    
    return 0;
}

// Function for check-in counter thread
void *checkin_counter(void *arg) {
    int counter = *(int *)arg;
    
    while (true) {
        // Wait for a bag to arrive
        pthread_mutex_lock(&mutex_checkin[counter]);
        while (queue_empty(&checkin_queue[counter * CONVEYOR_SIZE], &checkin_front[counter])) {
            pthread_mutex_unlock(&mutex_checkin[counter]);
            usleep(1000);
            pthread_mutex_lock(&mutex_checkin[counter]);
        }
        int bag = dequeue(&checkin_queue[counter * CONVEYOR_SIZE], &checkin_front[counter]);
        pthread_mutex_unlock(&mutex_checkin[counter]);
        
        // Process the bag
        int sleep_time = rand() % (TIME_MAX - TIME_MIN + 1) + TIME_MIN;
        sleep(sleep_time);
        
        // Put the bag on the conveyor belt
        int conveyor = rand() % NUM_CONVEYORS;
        pthread_mutex_lock(&mutex_conveyor[conveyor]);
        while (queue_full(conveyor_queue[conveyor], &conveyor_front[conveyor], conveyor_capacity[conveyor])) {
            pthread_mutex_unlock(&mutex_conveyor[conveyor]);
            usleep(1000);
            pthread_mutex_lock(&mutex_conveyor[conveyor]);
        }
        enqueue(conveyor_queue[conveyor], &conveyor_front[conveyor], bag);
        pthread_mutex_unlock(&mutex_conveyor[conveyor]);
        
        // Update bags checked in counter
        pthread_mutex_lock(&mutex_checkin[counter]);
        bags_checked_in++;
        pthread_mutex_unlock(&mutex_checkin[counter]);
    }
}

// Function for scanner thread
void *scanner(void *arg) {
    int scanner = *(int *)arg;
    
    while (true) {
        // Wait for a bag to arrive
        pthread_mutex_lock(&mutex_scanner[scanner]);
        while (queue_empty(&scanner_queue[scanner * CONVEYOR_SIZE], &scanner_front[scanner])) {
            pthread_mutex_unlock(&mutex_scanner[scanner]);
            usleep(1000);
            pthread_mutex_lock(&mutex_scanner[scanner]);
        }
        int bag = dequeue(&scanner_queue[scanner * CONVEYOR_SIZE], &scanner_front[scanner]);
        pthread_mutex_unlock(&mutex_scanner[scanner]);
        
        // Process the bag
        int sleep_time = rand() % (TIME_MAX - TIME_MIN + 1) + TIME_MIN;
        sleep(sleep_time);
        
        // Put the bag on the outbound conveyor belt
        pthread_mutex_lock(&mutex_outbound);
        while (queue_full(outbound_queue, &outbound_front, CONVEYOR_SIZE)) {
            pthread_mutex_unlock(&mutex_outbound);
            usleep(1000);
            pthread_mutex_lock(&mutex_outbound);
        }
        enqueue(outbound_queue, &outbound_front, bag);
        pthread_mutex_unlock(&mutex_outbound);
        
        // Update bags scanned counter
        pthread_mutex_lock(&mutex_scanner[scanner]);
        bags_scanned++;
        pthread_mutex_unlock(&mutex_scanner[scanner]);
    }
}

// Function for outbound conveyor belt thread
void *outbound_conveyor(void *arg) {
    while (true) {
        // Wait for a bag to arrive
        pthread_mutex_lock(&mutex_outbound);
        while (queue_empty(outbound_queue, &outbound_front)) {
            pthread_mutex_unlock(&mutex_outbound);
            usleep(1000);
            pthread_mutex_lock(&mutex_outbound);
        }
        int bag = dequeue(outbound_queue, &outbound_front);
        pthread_mutex_unlock(&mutex_outbound);
        
        // Load the bag onto the plane
        int sleep_time = rand() % (TIME_MAX - TIME_MIN + 1) + TIME_MIN;
        sleep(sleep_time);
        
        // Update bags loaded counter
        bags_loaded++;
    }
}

// Function for flight thread
void *flight(void *arg) {
    while (true) {
        // Unload bags from the plane
        int sleep_time = rand() % (TIME_MAX - TIME_MIN + 1) + TIME_MIN;
        sleep(sleep_time);
        
        // Update bags unloaded counter
        bags_unloaded++;
    }
}

// Function to enqueue item to queue
void enqueue(int *queue, int *front, int item) {
    queue[(*front)++] = item;
}

// Function to dequeue item from queue
int dequeue(int *queue, int *front) {
    return queue[(*front)--];
}

// Function to check if queue is full
bool queue_full(int *queue, int *front, int capacity) {
    return (*front) == capacity;
}

// Function to check if queue is empty
bool queue_empty(int *queue, int *front) {
    return (*front) == 0;
}