//FormAI DATASET v1.0 Category: Hotel Management System ; Style: systematic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define constants for maximum values
#define MAX_ROOMS 10
#define MAX_NAME_LENGTH 20

// Define struct for rooms
typedef struct {
    int room_number;
    char guest_name[MAX_NAME_LENGTH];
} Room;

// Define array to hold rooms
Room rooms[MAX_ROOMS];

// Function to check if a room is occupied
int isRoomOccupied(int room_number) {
    int i;
    for (i = 0; i < MAX_ROOMS; i++) {
        if (rooms[i].room_number == room_number && strlen(rooms[i].guest_name) > 0) {
            return 1;
        }
    }
    return 0;
}

// Function to print all occupied rooms and their guest names
void printOccupiedRooms() {
    int i;
    for (i = 0; i < MAX_ROOMS; i++) {
        if (strlen(rooms[i].guest_name) > 0) {
            printf("Room %d is occupied by %s\n", rooms[i].room_number, rooms[i].guest_name);
        }
    }
}

// Function to add a new guest to a room
void addGuestToRoom(int room_number, char* guest_name) {
    int i;
    for (i = 0; i < MAX_ROOMS; i++) {
        if (rooms[i].room_number == room_number) {
            if (strlen(rooms[i].guest_name) > 0) {
                printf("Error: Room %d is already occupied by %s\n", room_number, rooms[i].guest_name);
            } else {
                strcpy(rooms[i].guest_name, guest_name);
                printf("Guest %s added to room %d\n", guest_name, room_number);
            }
            return;
        }
    }
    printf("Error: Room %d not found\n", room_number);
}

// Function to remove an existing guest from a room
void removeGuestFromRoom(int room_number) {
    int i;
    for (i = 0; i < MAX_ROOMS; i++) {
        if (rooms[i].room_number == room_number) {
            if (strlen(rooms[i].guest_name) > 0) {
                printf("Guest %s removed from room %d\n", rooms[i].guest_name, room_number);
                strcpy(rooms[i].guest_name, "");
            } else {
                printf("Error: Room %d is not occupied\n", room_number);
            }
            return;
        }
    }
    printf("Error: Room %d not found\n", room_number);
}

int main() {
    // Initialize rooms
    int i;
    for (i = 0; i < MAX_ROOMS; i++) {
        rooms[i].room_number = i + 1;
        strcpy(rooms[i].guest_name, "");
    }

    // Main program loop
    int choice, room_number;
    char guest_name[MAX_NAME_LENGTH];
    do {
        printf("\nHotel Management System\n");
        printf("------------------------\n");
        printf("1. Print occupied rooms\n");
        printf("2. Add guest to room\n");
        printf("3. Remove guest from room\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printOccupiedRooms();
                break;
            case 2:
                printf("Enter room number: ");
                scanf("%d", &room_number);
                if (isRoomOccupied(room_number)) {
                    printf("Error: Room %d is already occupied\n", room_number);
                } else {
                    printf("Enter guest name: ");
                    scanf("%s", guest_name);
                    addGuestToRoom(room_number, guest_name);
                }
                break;
            case 3:
                printf("Enter room number: ");
                scanf("%d", &room_number);
                removeGuestFromRoom(room_number);
                break;
            case 4:
                printf("Exiting program...\n");
                break;
            default:
                printf("Invalid choice, please try again\n");
        }
    } while (choice != 4);

    return 0;
}