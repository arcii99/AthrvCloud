//FormAI DATASET v1.0 Category: Traffic Flow Simulation ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>
#include <pthread.h>

#define MAX_CARS 100 // Maximum number of cars that can be on the road
#define ROAD_LENGTH 100 // Length of the road in meters
#define MIN_CAR_SPEED 20 // Minimum speed of a car in meters per second
#define MAX_CAR_SPEED 50 // Maximum speed of a car in meters per second
#define MIN_DISTANCE 5 // Minimum distance between two cars in meters

int num_cars; // Number of cars currently on the road
int car_positions[MAX_CARS]; // Position of each car on the road
int car_speeds[MAX_CARS]; // Speed of each car
pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER; // Mutex lock for synchronizing access to shared data

void* car_thread(void* arg) {
    int car_id = *(int*) arg; // Get the ID of the car from the argument
    int position = 0; // Starting position of the car
    
    while (position < ROAD_LENGTH) { // Keep driving until the car reaches the end of the road
        // Slow down if there is a car ahead
        pthread_mutex_lock(&mutex);
        int distance_to_next_car = ROAD_LENGTH; // Distance to the next car on the road
        for (int i = 0; i < num_cars; i++) {
            if (car_positions[i] > position && car_positions[i] - position < distance_to_next_car) {
                distance_to_next_car = car_positions[i] - position;
            }
        }
        pthread_mutex_unlock(&mutex);
        
        if (distance_to_next_car < MIN_DISTANCE) { // There is a car ahead, slow down
            int new_speed = car_speeds[car_id] - 1;
            if (new_speed < MIN_CAR_SPEED) {
                new_speed = MIN_CAR_SPEED; // Can't go slower than the minimum speed
            }
            car_speeds[car_id] = new_speed;
        } else { // No car ahead, speed up if possible
            int new_speed = car_speeds[car_id] + 1;
            if (new_speed > MAX_CAR_SPEED) {
                new_speed = MAX_CAR_SPEED; // Can't go faster than the maximum speed
            }
            car_speeds[car_id] = new_speed;
        }
        
        // Move the car according to its speed
        usleep(1000000 / car_speeds[car_id]); // Sleep for the appropriate amount of time (in microseconds)
        position += car_speeds[car_id];
        
        // Update the position of the car in the array
        pthread_mutex_lock(&mutex);
        car_positions[car_id] = position;
        pthread_mutex_unlock(&mutex);
    }
    
    printf("Car %d reached the end of the road.\n", car_id);
    return NULL;
}

int main() {
    // Seed the random number generator
    srand(time(NULL));
    
    // Initialize the arrays with random values
    num_cars = rand() % MAX_CARS + 1; // Choose a random number of cars between 1 and MAX_CARS
    for (int i = 0; i < num_cars; i++) {
        car_positions[i] = rand() % ROAD_LENGTH; // Choose a random starting position between 0 and ROAD_LENGTH
        car_speeds[i] = rand() % (MAX_CAR_SPEED - MIN_CAR_SPEED + 1) + MIN_CAR_SPEED; // Choose a random speed between MIN_CAR_SPEED and MAX_CAR_SPEED
    }
    
    // Print the initial state of the road
    printf("Initial state of the road:\n");
    for (int i = 0; i < ROAD_LENGTH; i++) {
        printf("-");
    }
    printf("\n");
    
    // Start the car threads
    pthread_t threads[num_cars];
    int thread_args[num_cars];
    for (int i = 0; i < num_cars; i++) {
        thread_args[i] = i; // Pass the car ID as an argument to the thread
        pthread_create(&threads[i], NULL, car_thread, &thread_args[i]);
    }
    
    // Wait for all threads to finish
    for (int i = 0; i < num_cars; i++) {
        pthread_join(threads[i], NULL);
    }
    
    printf("All cars have reached the end of the road.\n");
    
    return 0;
}