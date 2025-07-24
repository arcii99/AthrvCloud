//FormAI DATASET v1.0 Category: Remote control Vehicle Simulation ; Style: distributed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <pthread.h>
#include <unistd.h>
#include <time.h>

#define NUM_THREADS 4
#define MAX_COMMAND_LEN 50
#define MAX_BATTERY_LEVEL 100

// Global variables for shared data
int battery_level = MAX_BATTERY_LEVEL;
int x_coordinate = 0;
int y_coordinate = 0;
int target_x_coordinate = 5;
int target_y_coordinate = 5;
char last_command[MAX_COMMAND_LEN];

// Define a struct for passing data to threads
struct ThreadData {
    int thread_id; // Unique thread identifier
    int num_threads; // Total number of threads
};

// A thread function for simulating the vehicle movement
void *vehicle_thread(void *thread_arg) {
    struct ThreadData *thread_data;
    thread_data = (struct ThreadData *) thread_arg;
    int thread_id = thread_data->thread_id;
    int num_threads = thread_data->num_threads;

    // Generate a random seed based on time and thread ID
    srand((unsigned) time(NULL) + thread_id);

    // Continuously move the vehicle towards the target coordinates
    while (1) {
        // Check the battery level and stop if it's zero
        if (battery_level == 0) {
            printf("[Thread %d] Vehicle is out of battery!\n", thread_id);
            pthread_exit(NULL);
        }

        // Calculate the distance to the target coordinates
        int x_diff = target_x_coordinate - x_coordinate;
        int y_diff = target_y_coordinate - y_coordinate;
        int distance = (int) sqrt(pow(x_diff, 2) + pow(y_diff, 2));

        // If the distance is less than or equal to one, we've reached the target
        if (distance <= 1) {
            printf("[Thread %d] Vehicle has reached the target coordinates (%d, %d)!\n", thread_id, target_x_coordinate, target_y_coordinate);
            pthread_exit(NULL);
        }

        // Calculate the direction we need to move in
        int x_direction = (x_diff >= 0) ? 1 : -1;
        int y_direction = (y_diff >= 0) ? 1 : -1;

        // Randomly choose to move in the x or y direction
        int move_x = rand() % 2;

        // Depending on the random choice, move either in x or y direction
        if (move_x) {
            // Decrease or increase x coordinate based on the direction
            if (x_direction == 1) {
                x_coordinate++;
            } else {
                x_coordinate--;
            }
        } else {
            // Decrease or increase y coordinate based on the direction
            if (y_direction == 1) {
                y_coordinate++;
            } else {
                y_coordinate--;
            }
        }

        // Decrease the battery level by 1 for every move
        battery_level--;

        // Print the current status of the vehicle
        printf("[Thread %d] Vehicle is now at coordinates (%d, %d) and has %d battery left.\n", thread_id, x_coordinate, y_coordinate, battery_level);

        // Sleep for 1 second to simulate movement
        sleep(1);
    }
}

// A thread function for receiving commands from the remote control
void *remote_thread(void *thread_arg) {
    struct ThreadData *thread_data;
    thread_data = (struct ThreadData *) thread_arg;
    int thread_id = thread_data->thread_id;
    int num_threads = thread_data->num_threads;

    // Continuously prompt the user for a command
    while (1) {
        // Display the current battery level and coordinates
        printf("[Thread %d] Current battery level: %d\n", thread_id, battery_level);
        printf("[Thread %d] Current coordinates: (%d, %d)\n", thread_id, x_coordinate, y_coordinate);

        // Prompt the user for a command
        printf("[Thread %d] Enter a command (up/down/left/right): ", thread_id);
        char command[MAX_COMMAND_LEN];
        scanf("%s", command);

        // Check if the command is valid
        if (strcasecmp(command, "up") == 0 || strcasecmp(command, "down") == 0 || 
            strcasecmp(command, "left") == 0 || strcasecmp(command, "right") == 0) {
            // Save the command for future reference
            strcpy(last_command, command);
        } else {
            printf("[Thread %d] Invalid command: %s\n", thread_id, command);
        }
    }
}

// A thread function for monitoring the battery level
void *battery_thread(void *thread_arg) {
    struct ThreadData *thread_data;
    thread_data = (struct ThreadData *) thread_arg;
    int thread_id = thread_data->thread_id;
    int num_threads = thread_data->num_threads;

    // Continuously check the battery level and print a warning if it's low
    while (1) {
        if (battery_level <= 10) {
            printf("[Thread %d] WARNING: Vehicle has low battery! Current battery level: %d\n", thread_id, battery_level);
        }
        sleep(5);
    }
}

// A thread function for updating the target coordinates
void *target_thread(void *thread_arg) {
    struct ThreadData *thread_data;
    thread_data = (struct ThreadData *) thread_arg;
    int thread_id = thread_data->thread_id;
    int num_threads = thread_data->num_threads;

    // Continuously prompt the user for new target coordinates
    while (1) {
        // Display the current target coordinates
        printf("[Thread %d] Current target coordinates: (%d, %d)\n", thread_id, target_x_coordinate, target_y_coordinate);

        // Prompt the user for new target coordinates
        printf("[Thread %d] Enter new target coordinates (x y): ", thread_id);
        scanf("%d %d", &target_x_coordinate, &target_y_coordinate);
    }
}

int main() {
    pthread_t threads[NUM_THREADS];
    struct ThreadData thread_data[NUM_THREADS];

    // Initialize the thread data
    for (int i = 0; i < NUM_THREADS; i++) {
        thread_data[i].thread_id = i;
        thread_data[i].num_threads = NUM_THREADS;
    }

    // Create the vehicle thread
    pthread_create(&threads[0], NULL, vehicle_thread, (void *) &thread_data[0]);

    // Create the remote thread
    pthread_create(&threads[1], NULL, remote_thread, (void *) &thread_data[1]);

    // Create the battery thread
    pthread_create(&threads[2], NULL, battery_thread, (void *) &thread_data[2]);

    // Create the target thread
    pthread_create(&threads[3], NULL, target_thread, (void *) &thread_data[3]);

    // Wait for all threads to finish
    for (int i = 0; i < NUM_THREADS; i++) {
        pthread_join(threads[i], NULL);
    }
    
    return 0;
}