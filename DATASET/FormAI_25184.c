//FormAI DATASET v1.0 Category: Hotel Management System ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <pthread.h>

#define MAX_ROOMS 100
#define MAX_NAME_LENGTH 100
#define MAX_STAY_LENGTH 7

typedef struct {
    int room_number;
    char guest_name[MAX_NAME_LENGTH];
    int stay_length;
} Reservation;

Reservation reservations[MAX_ROOMS];
int num_reservations = 0;
pthread_rwlock_t rwlock;

void* add_reservation(void* arg) {
    Reservation* reservation = (Reservation*) arg;
    
    pthread_rwlock_wrlock(&rwlock); // write lock to prevent concurrent writes
    if (num_reservations >= MAX_ROOMS) {
        printf("Error: Maximum number of reservations reached\n");
    } else {
        reservations[num_reservations++] = *reservation;
        printf("Reservation added successfully\n");
    }
    pthread_rwlock_unlock(&rwlock); // unlock after write complete
    
    return NULL;
}

void* cancel_reservation(void* arg) {
    int room_number = *((int*) arg);
    
    pthread_rwlock_wrlock(&rwlock); // write lock to prevent concurrent writes
    bool reservation_found = false;
    for (int i = 0; i < num_reservations; i++) {
        if (reservations[i].room_number == room_number) {
            memset(&reservations[i], 0, sizeof(Reservation)); // clear entry in array
            reservation_found = true;
            break;
        }
    }
    if (!reservation_found) {
        printf("Error: Room number %d not found in reservations\n", room_number);
    } else {
        num_reservations--;
        printf("Reservation for room %d canceled successfully\n", room_number);
    }
    pthread_rwlock_unlock(&rwlock); // unlock after write complete
    
    return NULL;
}

void* display_reservations(void* arg) {
    printf("Room Number\tGuest Name\tStay Length\n");
    pthread_rwlock_rdlock(&rwlock); // read lock to prevent concurrent writes
    for (int i = 0; i < num_reservations; i++) {
        printf("%d\t\t%s\t\t%d days\n", reservations[i].room_number, reservations[i].guest_name, reservations[i].stay_length);
    }
    pthread_rwlock_unlock(&rwlock); // unlock after read complete
    
    return NULL;
}

int main() {
    pthread_t add_thread, cancel_thread, display_thread;
    
    pthread_rwlock_init(&rwlock, NULL); // initialize read-write lock
    
    Reservation reservation1 = {101, "John Smith", 3};
    Reservation reservation2 = {102, "Jane Doe", 5};
    Reservation reservation3 = {103, "Bob Johnson", 2};
    
    pthread_create(&add_thread, NULL, add_reservation, &reservation1);
    pthread_create(&add_thread, NULL, add_reservation, &reservation2);
    pthread_create(&add_thread, NULL, add_reservation, &reservation3);
    
    pthread_join(add_thread, NULL);
    pthread_join(add_thread, NULL);
    pthread_join(add_thread, NULL);
    
    // display reservations
    pthread_create(&display_thread, NULL, display_reservations, NULL);
    pthread_join(display_thread, NULL);
    
    // cancel reservation
    int room_number = 102;
    pthread_create(&cancel_thread, NULL, cancel_reservation, &room_number);
    pthread_join(cancel_thread, NULL);
    
    // display updated reservations
    pthread_create(&display_thread, NULL, display_reservations, NULL);
    pthread_join(display_thread, NULL);
    
    pthread_rwlock_destroy(&rwlock); // destroy read-write lock
    
    return 0;
}