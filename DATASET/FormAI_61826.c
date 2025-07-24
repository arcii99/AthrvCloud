//FormAI DATASET v1.0 Category: Hotel Management System ; Style: asynchronous
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <pthread.h>

// hotel occupancy structure
typedef struct {
    int room_number;
    char guest_name[50];
    int occupied; // 1 for occupied, 0 for vacant
} Room;

// declare array of rooms
Room rooms[10];

// define mutex for thread synchronization
pthread_mutex_t mutex;

// asynchronous thread function to display hotel occupancy status
void* display_occupancy(void* arg) {
    // lock mutex before accessing shared data
    pthread_mutex_lock(&mutex);
    printf("------------------------------------------------\n");
    printf("| Room No. | Occupancy        | Guest Name      |\n");
    printf("------------------------------------------------\n");
    for (int i = 0; i < 10; i++) {
        printf("| %8d | %d               | %15s |\n", rooms[i].room_number, rooms[i].occupied, rooms[i].guest_name);
    }
    printf("------------------------------------------------\n");
    // unlock mutex after accessing shared data
    pthread_mutex_unlock(&mutex);
    return NULL;
}

int main() {
    // initialize rooms
    for (int i = 0; i < 10; i++) {
        rooms[i].room_number = i+1;
        rooms[i].occupied = 0;
        strcpy(rooms[i].guest_name, "");
    }

    // initialize mutex
    pthread_mutex_init(&mutex, NULL);

    // create and start asynchronous thread for displaying occupancy status
    pthread_t t1;
    int t1_result = pthread_create(&t1, NULL, display_occupancy, NULL);
    if (t1_result != 0) {
        printf("Error creating thread!\n");
        exit(EXIT_FAILURE);
    }

    // simulate guests checking in
    strcpy(rooms[0].guest_name, "John Doe");
    rooms[0].occupied = 1;
    strcpy(rooms[3].guest_name, "Jane Smith");
    rooms[3].occupied = 1;
    strcpy(rooms[6].guest_name, "Bob Johnson");
    rooms[6].occupied = 1;

    // wait for asynchronous thread to finish
    pthread_join(t1, NULL);

    // cleanup
    pthread_mutex_destroy(&mutex);

    return 0;
}