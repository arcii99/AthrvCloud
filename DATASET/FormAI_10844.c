//FormAI DATASET v1.0 Category: Hotel Management System ; Style: random
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_ROOM 20
#define MAX_NAME_LEN 30

// Structure to store room information
typedef struct Room {
    int roomNo;
    char guestName[MAX_NAME_LEN];
    int occupancy;
} Room;

// Initialize all rooms as empty
void initializeRooms(Room rooms[]) {
    for(int i=0; i<MAX_ROOM; i++) {
        rooms[i].roomNo = i+1;
        rooms[i].occupancy = 0;
        strcpy(rooms[i].guestName, "");
    }
}

// Display all vacant rooms
void displayVacantRooms(Room rooms[]) {
    printf("Vacant Rooms:\n");
    for(int i=0; i<MAX_ROOM; i++) {
        if(rooms[i].occupancy == 0) {
            printf("Room No. %d\n", rooms[i].roomNo);
        }
    }
    printf("\n");
}

// Display all occupied rooms
void displayOccupiedRooms(Room rooms[]) {
    printf("Occupied Rooms:\n");
    for(int i=0; i<MAX_ROOM; i++) {
        if(rooms[i].occupancy == 1) {
            printf("Room No. %d - Guest Name: %s\n", rooms[i].roomNo, rooms[i].guestName);
        }
    }
    printf("\n");
}

// Book a room for a particular guest
void bookRoom(Room rooms[]) {
    int roomNo;
    char guestName[MAX_NAME_LEN];
    printf("Enter Room No.: ");
    scanf("%d", &roomNo);
    printf("Enter Guest Name: ");
    scanf("%s", guestName);
    if(roomNo >= 1 && roomNo <= MAX_ROOM) {
        if(rooms[roomNo-1].occupancy == 0) {
            rooms[roomNo-1].occupancy = 1;
            strcpy(rooms[roomNo-1].guestName, guestName);
            printf("Room No. %d booked for %s.\n", roomNo, guestName);
        } else {
            printf("Room is already occupied.\n");
        }
    } else {
        printf("Invalid Room No.\n");
    }
}

// Unbook a room occupied by a particular guest
void unbookRoom(Room rooms[]) {
    int roomNo;
    char guestName[MAX_NAME_LEN];
    printf("Enter Room No.: ");
    scanf("%d", &roomNo);
    printf("Enter Guest Name: ");
    scanf("%s", guestName);
    if(roomNo >= 1 && roomNo <= MAX_ROOM) {
        if(rooms[roomNo-1].occupancy == 1 && strcmp(rooms[roomNo-1].guestName, guestName) == 0) {
            rooms[roomNo-1].occupancy = 0;
            strcpy(rooms[roomNo-1].guestName, "");
            printf("Room No. %d unbooked from %s.\n", roomNo, guestName);
        } else if(rooms[roomNo-1].occupancy == 0) {
            printf("Room is already vacant.\n");
        } else {
            printf("Guest Name and Room No. do not match.\n");
        }
    } else {
        printf("Invalid Room No.\n");
    }
}

// Main function
int main() {
    Room rooms[MAX_ROOM];
    initializeRooms(rooms);
    int choice;
    do {
        printf("Select an option:\n");
        printf("1. Display Vacant Rooms\n");
        printf("2. Display Occupied Rooms\n");
        printf("3. Book a Room\n");
        printf("4. Unbook a Room\n");
        printf("5. Exit\n");
        printf("Your Choice: ");
        scanf("%d", &choice);
        switch(choice) {
            case 1:
                displayVacantRooms(rooms);
                break;
            case 2:
                displayOccupiedRooms(rooms);
                break;
            case 3:
                bookRoom(rooms);
                break;
            case 4:
                unbookRoom(rooms);
                break;
            case 5:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid Choice. Try Again.\n");
        }
    } while(choice != 5);
    return 0;
}