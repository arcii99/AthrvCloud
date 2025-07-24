//FormAI DATASET v1.0 Category: Hotel Management System ; Style: standalone
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ROOMS 100 // Maximum number of rooms available in the hotel

struct Room {
    int roomNumber;
    int occupied;       // 0 - unoccupied, 1 - occupied
    char guestName[50];
    int rate;
};

int numRooms = 0;           // Number of rooms currently available
struct Room rooms[MAX_ROOMS]; // Array of rooms

void addRoom(int roomNumber, int occupied, char guestName[], int rate) {
    // Create a new room and add it to the array
    rooms[numRooms].roomNumber = roomNumber;
    rooms[numRooms].occupied = occupied;
    strcpy(rooms[numRooms].guestName, guestName);
    rooms[numRooms].rate = rate;
    
    numRooms++;
}

void listRooms() {
    // List all the rooms with their details
    printf("Room Number\tOccupied\tGuest Name\t\tRate\n");
    for (int i = 0; i < numRooms; i++) {
        printf("%d\t\t%s\t\t%s\t%d\n", rooms[i].roomNumber, rooms[i].occupied ? "Yes" : "No", rooms[i].guestName, rooms[i].rate);
    }
}

void checkIn(int roomNumber, char guestName[], int rate) {
    // Check if the room is available and check in the guest
    for (int i = 0; i < numRooms; i++) {
        if (rooms[i].roomNumber == roomNumber && rooms[i].occupied == 0) {
            rooms[i].occupied = 1;
            strcpy(rooms[i].guestName, guestName);
            rooms[i].rate = rate;
            printf("%s has been checked into Room %d\n", guestName, roomNumber);
            return;
        }
    }
    
    printf("The requested room is not available for check-in\n");
}

void checkOut(int roomNumber) {
    // Check out the guest and mark the room as unoccupied
    for (int i = 0; i < numRooms; i++) {
        if (rooms[i].roomNumber == roomNumber && rooms[i].occupied == 1) {
            rooms[i].occupied = 0;
            printf("%s has been checked out of Room %d\n", rooms[i].guestName, roomNumber);
            return;
        }
    }
    
    printf("The requested room is not currently occupied\n");
}

int main() {
    // Add some initial rooms to the hotel
    addRoom(101, 0, "", 100);
    addRoom(102, 0, "", 80);
    addRoom(103, 1, "John Doe", 120);
    
    // Display the list of rooms
    listRooms();
    
    // Check in a new guest
    checkIn(102, "Jane Doe", 80);
    
    // Display the list of rooms after checking in a new guest
    listRooms();
    
    // Check out the guest in room 101
    checkOut(101);
    
    // Display the list of rooms after checking out a guest
    listRooms();
    
    return 0;
}