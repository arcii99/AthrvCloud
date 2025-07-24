//FormAI DATASET v1.0 Category: Hotel Management System ; Style: distributed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define a struct for a hotel room
struct Room {
    int roomNumber;
    int numOfBeds;
    int isOccupied;
};

// Define a struct for a guest
struct Guest {
    char name[50];
    char phoneNumber[15];
};

// Function to check if a room is occupied
int isOccupied(struct Room *rooms, int roomNum) {
    if (rooms[roomNum-1].isOccupied == 1) {
        return 1;
    } else {
        return 0;
    }
}

// Function to check in a guest
void checkInGuest(struct Room *rooms, int roomNum, struct Guest guest) {
    // Check if the room is already occupied
    if (isOccupied(rooms, roomNum)) {
        printf("Error: Room is already occupied\n");
    } else {
        // Set the room as occupied and add the guest details
        rooms[roomNum-1].isOccupied = 1;
        printf("Successfully checked in %s into room %d\n", guest.name, roomNum);
    }
}

// Function to check out a guest
void checkOutGuest(struct Room *rooms, int roomNum) {
    // Check if the room is already vacant
    if (!isOccupied(rooms, roomNum)) {
        printf("Error: Room is already vacant\n");
    } else {
        // Set the room as vacant and remove the guest details
        rooms[roomNum-1].isOccupied = 0;
        printf("Successfully checked out of room %d\n", roomNum);
    }
}

int main() {
    // Create an array of 10 hotel rooms
    struct Room rooms[10];
    for (int i = 0; i < 10; i++) {
        rooms[i].roomNumber = i+1;
        rooms[i].numOfBeds = 2;
        rooms[i].isOccupied = 0;
    }

    // Check in a guest to room 5
    struct Guest guest1;
    strcpy(guest1.name, "John Smith");
    strcpy(guest1.phoneNumber, "555-1234");
    checkInGuest(rooms, 5, guest1);

    // Check out the guest from room 5
    checkOutGuest(rooms, 5);

    return 0;
}