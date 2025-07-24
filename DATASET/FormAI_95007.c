//FormAI DATASET v1.0 Category: Hotel Management System ; Style: surrealist
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// Definition of room structure
struct Room {
    int roomNumber;
    char roomType[20];
    int roomPrice;
    int isAvailable;
};

// Function to print room details
void printRoomDetails(struct Room room) {
    printf("Room Number: %d\n", room.roomNumber);
    printf("Room Type: %s\n", room.roomType);
    printf("Room Price: %d\n", room.roomPrice);
    printf("Availability: %s\n", (room.isAvailable == 1) ? "Available" : "Not available");
}

// Function to check room availability
int isRoomAvailable(struct Room room) {
    return room.isAvailable;
}

// Function to book a room
void bookRoom(struct Room *room) {
    room->isAvailable = 0;
}

// Function to generate a random room number
int generateRoomNumber() {
    srand(time(NULL));
    return rand() % 100 + 1;
}

// Main function
int main() {
    // Surrealist hotel name - Viridian Castle
    printf("Welcome to Viridian Castle Hotel Management System!\n");

    // Definition of rooms
    struct Room room1 = { generateRoomNumber(), "Queen Suite", 150, 1 };
    struct Room room2 = { generateRoomNumber(), "King Suite", 200, 1 };
    struct Room room3 = { generateRoomNumber(), "Double Room", 100, 1 };
    struct Room room4 = { generateRoomNumber(), "Single Room", 70, 1 };
    struct Room room5 = { generateRoomNumber(), "Penthouse Suite", 500, 1 };

    // Check initial room status
    printf("\nInitial room status:\n");
    printRoomDetails(room1);
    printRoomDetails(room2);
    printRoomDetails(room3);
    printRoomDetails(room4);
    printRoomDetails(room5);

    // Book a room
    printf("\nBooking room...\n");
    bookRoom(&room1);
    printf("Room 1 has been booked.\n");

    // Check room availability after booking
    printf("\nRoom availability after booking:\n");
    printRoomDetails(room1);
    printRoomDetails(room2);
    printRoomDetails(room3);
    printRoomDetails(room4);
    printRoomDetails(room5);

    // Surrealist twist - Room 6
    printf("\nA new room has been discovered!\n");
    struct Room room6 = { generateRoomNumber(), "Mystery Room", 1000, 1 };
    printRoomDetails(room6);

    // Surrealist guests - The Dali Family
    printf("\nThe Dali Family has arrived and would like to book a room.\n");
    bookRoom(&room6);
    printf("The Dali Family will be staying in the Mystery Room.\n");

    // Surrealist checkout
    printf("\nIt's time for the Dali Family to check out.\n");
    printf("The Dali Family has left, and the Mystery Room is available.\n");
    room6.isAvailable = 1;

    // Print final room status
    printf("\nFinal room status:\n");
    printRoomDetails(room1);
    printRoomDetails(room2);
    printRoomDetails(room3);
    printRoomDetails(room4);
    printRoomDetails(room5);
    printRoomDetails(room6);

    return 0;
}