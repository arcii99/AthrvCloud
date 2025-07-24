//FormAI DATASET v1.0 Category: Haunted House Simulator ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

const int ROOMS = 5; // The number of rooms in the haunted house
const int MAX_GUESTS = 10; // The max number of guests a room can hold
const int MIN_GUESTS = 1; // The min number of guests a room can hold

// Define a struct for each Room in the house
typedef struct {
    int number; // The Room number
    int guests; // The number of guests currently in the room
    int has_ghost; // Whether or not the room has a ghost in it
} Room;

// Define an array of Rooms
Room rooms[5];

// Define a function to randomly assign ghosts to each Room
void randomly_assign_ghosts() {
    srand(time(NULL)); // Seed the random number generator with the current time
    for (int i = 0; i < ROOMS; i++) {
        rooms[i].has_ghost = rand() % 2; // Randomly assign a 0 or 1 for each room
    }
}

// Define a function to print out the status of each room
void print_room_status() {
    printf("Room\tGuests\tGhost\n");
    for (int i = 0; i < ROOMS; i++) {
        printf("%d\t%d\t%d\n", rooms[i].number, rooms[i].guests, rooms[i].has_ghost);
    }
}

// Define a function to simulate the haunted house
void run_haunted_house() {
    // Randomly assign ghosts to each Room
    randomly_assign_ghosts();

    // Initialize each Room with a random number of guests
    for (int i = 0; i < ROOMS; i++) {
        rooms[i].number = i+1; // Assign a unique Room number
        rooms[i].guests = rand() % (MAX_GUESTS - MIN_GUESTS + 1) + MIN_GUESTS; // Randomly assign a number of guests between MIN_GUESTS and MAX_GUESTS
    }

    // Print out the initial status of each Room
    printf("Initial Room Status:\n");
    print_room_status();
    
    // Iterate through each Room and check if there is a ghost
    for (int i = 0; i < ROOMS; i++) {
        if (rooms[i].has_ghost) {
            printf("Oh no! There is a ghost in Room %d!\n", rooms[i].number);
            printf("All guests in Room %d have fled the house!\n", rooms[i].number);
            rooms[i].guests = 0; // Remove all guests from the Room
        }
        else {
            int guests_fleeing = rand() % rooms[i].guests + 1; // Randomly assign the number of guests fleeing the Room
            printf("%d guests are fleeing from Room %d!\n", guests_fleeing, rooms[i].number);
            rooms[i].guests -= guests_fleeing; // Remove the fleeing guests from the Room
        }
    }

    // Print out the final status of each Room
    printf("Final Room Status:\n");
    print_room_status();
}

int main() {
    run_haunted_house();
    return 0;
}