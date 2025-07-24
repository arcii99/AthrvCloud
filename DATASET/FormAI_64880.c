//FormAI DATASET v1.0 Category: Hotel Management System ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define NUM_ROOMS 100
#define MAX_NAME_LEN 20

int occupancy[NUM_ROOMS]; // 0 if empty, positive if occupied
char guest_names[NUM_ROOMS][MAX_NAME_LEN]; // stores name of guest occupying room

void* check_in(void* arg) {
    int room_num = *((int*) arg); // retrieve room number from argument
    printf("Checking in to room %d\n", room_num);
    occupancy[room_num]++; // mark room as occupied
    printf("Please enter your name: ");
    scanf("%s", guest_names[room_num]);
    printf("Welcome, %s! Enjoy your stay.\n", guest_names[room_num]);
    pthread_exit(NULL); // exit thread
}

void* check_out(void* arg) {
    int room_num = *((int*) arg); // retrieve room number from argument
    printf("Checking out of room %d\n", room_num);
    if (occupancy[room_num] == 0) {
        printf("Error: Room is already empty.\n");
    } else {
        occupancy[room_num]--; // mark room as empty
        printf("Thank you for staying with us, %s! We hope to see you again soon.\n", guest_names[room_num]);
    }
    pthread_exit(NULL); // exit thread
}

int main() {
    pthread_t threads[NUM_ROOMS]; // one thread for each room
    int room_num;
    
    // initialize all rooms to be empty
    for (int i = 0; i < NUM_ROOMS; i++) {
        occupancy[i] = 0;
    }
    
    // check in to room 50-59
    for (int i = 50; i < 60; i++) {
        room_num = i;
        pthread_create(&threads[i], NULL, check_in, &room_num);
    }
    
    // check out of room 55-64
    for (int i = 55; i < 65; i++) {
        room_num = i;
        pthread_create(&threads[i], NULL, check_out, &room_num);
    }
    
    // wait for all threads to finish executing
    for (int i = 0; i < NUM_ROOMS; i++) {
        pthread_join(threads[i], NULL);
    }
    
    return 0;
}