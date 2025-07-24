//FormAI DATASET v1.0 Category: Drone Remote Control ; Style: multi-threaded
#include <stdio.h>
#include <pthread.h>

// Function to be executed by the thread
void* flight_controller(void *arg) {
    int drone_num = *((int*)arg);
    printf("Drone %d is ready for flight!\n", drone_num);
    
    // Infinite loop for drone flight control
    while(1) {
        // Code for drone flight control goes here
        printf("Drone %d is flying...\n", drone_num);
        // Simulate drone flight by pausing for 1 second
        sleep(1);
    }
}

int main() {
    int num_drones = 3;
    pthread_t drone_threads[num_drones];
    int drone_ids[num_drones];
    
    // Create threads for each drone
    for(int i=0; i<num_drones; i++) {
        drone_ids[i] = i+1;
        int rc = pthread_create(&drone_threads[i], NULL, flight_controller, &drone_ids[i]);
        
        // Check if thread creation was successful
        if (rc) {
            printf("Error creating thread for Drone %d! Return code: %d\n", i+1, rc);
            return 1;
        }
    }
    
    // Wait for all threads to finish
    for(int i=0; i<num_drones; i++) {
        pthread_join(drone_threads[i], NULL);
        printf("Drone %d has landed.\n", i+1);
    }
    
    return 0;
}