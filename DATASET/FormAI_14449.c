//FormAI DATASET v1.0 Category: Hotel Management System ; Style: random
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define MAX_ROOMS 30
#define MAX_NAME_LENGTH 30

typedef struct {
    int roomNumber;
    bool available;
    char guestName[MAX_NAME_LENGTH];
} Room;

Room rooms[MAX_ROOMS];

void initializeRooms() {
    for (int i = 0; i < MAX_ROOMS; i++) {
        rooms[i].roomNumber = i + 1;
        rooms[i].available = true;
        strcpy(rooms[i].guestName, "");
    }
}

void showAvailableRooms() {
    printf("Available Rooms:\n");
    for (int i = 0; i < MAX_ROOMS; i++) {
        if (rooms[i].available) {
            printf("Room %d\n", rooms[i].roomNumber);
        }
    }
}

void showOccupiedRooms() {
    printf("Occupied Rooms:\n");
    for (int i = 0; i < MAX_ROOMS; i++) {
        if (!rooms[i].available) {
            printf("Room %d: %s\n", rooms[i].roomNumber, rooms[i].guestName);
        }
    }
}

void bookRoom(int roomNumber, char* guestName) {
    rooms[roomNumber - 1].available = false;
    strcpy(rooms[roomNumber - 1].guestName, guestName);
    printf("Room %d has been booked by %s\n", roomNumber, guestName);
}

void cancelBooking(int roomNumber) {
    rooms[roomNumber - 1].available = true;
    strcpy(rooms[roomNumber - 1].guestName, "");
    printf("Booking for Room %d has been cancelled\n", roomNumber);
}

int main() {
    int choice, roomNumber;
    char guestName[MAX_NAME_LENGTH];
    initializeRooms();
    do {
        printf("Welcome to the Hotel Management System\n");
        printf("1. Show available rooms\n");
        printf("2. Show occupied rooms\n");
        printf("3. Book a room\n");
        printf("4. Cancel a booking\n");
        printf("0. Exit the program\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                showAvailableRooms();
                break;
            case 2:
                showOccupiedRooms();
                break;
            case 3:
                printf("Enter the room number you want to book: ");
                scanf("%d", &roomNumber);
                printf("Enter your name: ");
                scanf("%s", guestName);
                bookRoom(roomNumber, guestName);
                break;
            case 4:
                printf("Enter the room number you want to cancel the booking for: ");
                scanf("%d", &roomNumber);
                cancelBooking(roomNumber);
                break;
            case 0:
                printf("Exiting the program\n");
                break;
            default:
                printf("Invalid choice, please try again\n");
                break;
        }
        printf("\n");
    } while (choice != 0);

    return 0;
}