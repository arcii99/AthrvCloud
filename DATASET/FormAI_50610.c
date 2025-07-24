//FormAI DATASET v1.0 Category: GPS Navigation Simulation ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

// Function to simulate GPS navigation
void* gps_navigation(void* arg) {
    int distance = *(int*) arg;
    printf("Starting navigation...\n");
    while(distance > 0) {
        printf("Distance remaining: %d meters\n", distance);
        sleep(1); // Simulate time passing
        distance -= rand() % 10 + 1; // Simulate movement
    }
    printf("Destination reached!\n");
    pthread_exit(NULL);
}

int main() {
    int destination_distance = 1000; // Distance to destination in meters
    pthread_t navigation_thread;
    srand(time(NULL)); // Seed random number generator
    printf("Enter destination distance (in meters): ");
    scanf("%d", &destination_distance);
    printf("Starting GPS navigation simulation...\n");
    pthread_create(&navigation_thread, NULL, gps_navigation, &destination_distance);
    pthread_join(navigation_thread, NULL); // Wait for navigation thread to complete
    printf("Navigation simulation completed\n");
    return 0;
}