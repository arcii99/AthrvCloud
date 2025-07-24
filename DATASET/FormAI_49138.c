//FormAI DATASET v1.0 Category: Traffic Flow Simulation ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

// Constants
#define MAX_CARS 20
#define MAX_ROADS 3
#define CAR_DELAY 50000
#define ROAD_LENGTH 10

// Structures
typedef struct road {
    int length;
    int* cars;
    pthread_mutex_t mutex;
} road_t;

// Global Variables
road_t roads[MAX_ROADS];
pthread_t car_threads[MAX_CARS];
int car_count = 0;

// Function Prototypes
void* car_function(void* arg);

int main() {
    // Initialize roads
    for(int i = 0; i < MAX_ROADS; i++) {
        roads[i].length = ROAD_LENGTH;
        roads[i].cars = (int*) malloc(ROAD_LENGTH * sizeof(int));
        pthread_mutex_init(&roads[i].mutex, NULL);
    }
    
    // Create car threads
    for(int i = 0; i < MAX_CARS; i++) {
        pthread_create(&car_threads[i], NULL, car_function, (void*) i);
        car_count++;
        usleep(CAR_DELAY);
    }
    
    // Wait for car threads to finish
    for(int i = 0; i < MAX_CARS; i++) {
        pthread_join(car_threads[i], NULL);
    }
    
    // Destroy roads
    for(int i = 0; i < MAX_ROADS; i++) {
        pthread_mutex_destroy(&roads[i].mutex);
        free(roads[i].cars);
    }
    
    return 0;
}

void* car_function(void* arg) {
    int id = (int) arg;
    int current_road = rand() % MAX_ROADS;
    int position = 0;
    
    while(position < roads[current_road].length) {
        // Enter critical section
        pthread_mutex_lock(&roads[current_road].mutex);
        
        // Check if space is available
        if(roads[current_road].cars[position] == 0) {
            roads[current_road].cars[position] = id;
            printf("Car %d is on road %d at position %d\n", id, current_road, position);
            // Exit critical section
            pthread_mutex_unlock(&roads[current_road].mutex);
            position++;
            usleep(CAR_DELAY);
        } else {
            // Exit critical section
            pthread_mutex_unlock(&roads[current_road].mutex);
            // Switch to a different road
            do {
                current_road = rand() % MAX_ROADS;
            } while(roads[current_road].cars[0] != 0);
        }
    }
    
    printf("Car %d has exited road %d\n", id, current_road);
    car_count--;
    
    return NULL;
}