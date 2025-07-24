//FormAI DATASET v1.0 Category: Geometric algorithms ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <math.h>

// Function to calculate the Euclidean distance between two points
double calculate_distance(int x1, int y1, int x2, int y2) {
    int x_diff = x2 - x1;
    int y_diff = y2 - y1;
    return sqrt(x_diff * x_diff + y_diff * y_diff);
}

// Function to find the maximum distance between any two points
// in a given set of points
void* find_maximum_distance(void* arg) {
    int num_points = *((int*)arg);
    int max_distance = 0;
    
    for(int i=0; i<num_points; i++) {
        for(int j=i+1; j<num_points; j++) {
            int x1 = rand() % 100;
            int y1 = rand() % 100;
            int x2 = rand() % 100;
            int y2 = rand() % 100;
            
            double distance = calculate_distance(x1, y1, x2, y2);
            if(distance > max_distance) {
                max_distance = distance;
            }
        }
    }
    
    return (void*)max_distance;
}

int main() {
    srand(time(0));
    int num_points = 10;
    pthread_t thread_id;
    
    // Create a new thread to find the maximum distance
    // between any two points in the given set of points
    pthread_create(&thread_id, NULL, find_maximum_distance, &num_points);
    
    // Wait for the thread to finish and get the result
    int max_distance;
    pthread_join(thread_id, (void**)&max_distance);
    
    // Print the maximum distance
    printf("The maximum distance between any two points in the set is: %d\n", max_distance);
    
    return 0;
}