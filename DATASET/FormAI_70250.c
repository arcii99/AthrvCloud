//FormAI DATASET v1.0 Category: Traffic Light Controller ; Style: safe
#include <stdbool.h>
#include <pthread.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

const int NUM_CARS = 20; // Number of cars on the road
bool isStopped = false; // Flag to indicate if traffic lights are red or green
pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER; // Mutex to ensure safe access to isStopped flag

void *car(void *arg){
    int car_id = *(int*) arg;
    while(true){
        if(!isStopped){
            printf("Car %d is passing through the traffic light.\n", car_id);
        } else {
            printf("Car %d is waiting at the traffic light.\n", car_id);
        }
        sleep(1);
    }
    pthread_exit(NULL);
}

void *traffic_light(void *arg){
    int counter = 0;
    while(counter < 50){ // Number of cycles the traffic light should operate for
        pthread_mutex_lock(&mutex);
        isStopped = !isStopped; // Toggle the value of the isStopped flag
        if(isStopped){
            printf("Traffic Light: RED\n");
        } else {
            printf("Traffic Light: GREEN\n");
        }
        pthread_mutex_unlock(&mutex);
        sleep(5); // Each cycle should last for 5 seconds
        counter++;
    }
    pthread_exit(NULL);
}

int main(){
    pthread_t car_threads[NUM_CARS], traffic_light_thread;
    int car_ids[NUM_CARS];
    for(int i = 0; i < NUM_CARS; i++){
        car_ids[i] = i+1;
        pthread_create(&car_threads[i], NULL, &car, &car_ids[i]);
    }
    pthread_create(&traffic_light_thread, NULL, &traffic_light, NULL);
    // Wait for all threads to finish before exiting
    for(int i = 0; i < NUM_CARS; i++){
        pthread_join(car_threads[i], NULL);
    }
    pthread_join(traffic_light_thread, NULL);
    printf("All threads have finished executing.\n");
    return 0;
}