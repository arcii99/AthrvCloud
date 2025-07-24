//FormAI DATASET v1.0 Category: Hotel Management System ; Style: scientific
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structures to be used in the management system
typedef struct {
    char name[50];
    char address[100];
    char phone[15];
} Guest;

typedef struct {
    int roomNumber;
    int floor;
    int capacity;
    int reserved;
    Guest guest;
} Room;

// Global constants
#define NUM_FLOORS 5
#define ROOMS_PER_FLOOR 10

// Function prototypes
void displayMenu();
void reserveRoom(Room rooms[NUM_FLOORS][ROOMS_PER_FLOOR]);
void cancelReservation(Room rooms[NUM_FLOORS][ROOMS_PER_FLOOR]);
void displayStatus(Room rooms[NUM_FLOORS][ROOMS_PER_FLOOR]);

// Main function
int main() {
    printf("Welcome to the C Hotel Management System!\n\n");

    // Initialize rooms
    Room rooms[NUM_FLOORS][ROOMS_PER_FLOOR];
    for (int i = 0; i < NUM_FLOORS; i++) {
        for (int j = 0; j < ROOMS_PER_FLOOR; j++) {
            rooms[i][j].roomNumber = i * ROOMS_PER_FLOOR + j + 1;
            rooms[i][j].floor = i + 1;
            rooms[i][j].capacity = rand() % 4 + 1; // Random capacity between 1 and 4
            rooms[i][j].reserved = 0;
        }
    }

    // Display menu and get user's choice
    int choice;
    do {
        displayMenu();
        scanf("%d", &choice);

        // Call corresponding function
        switch (choice) {
            case 1:
                reserveRoom(rooms);
                break;
            case 2:
                cancelReservation(rooms);
                break;
            case 3:
                displayStatus(rooms);
                break;
            case 4:
                printf("Thank you for using the C Hotel Management System!\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
                break;
        }
    } while (choice != 4);

    return 0;
}

// Function to display the menu
void displayMenu() {
    printf("Please choose an option:\n");
    printf("1. Reserve a room\n");
    printf("2. Cancel a reservation\n");
    printf("3. Display room status\n");
    printf("4. Exit\n");
}

// Function to reserve a room
void reserveRoom(Room rooms[NUM_FLOORS][ROOMS_PER_FLOOR]) {
    int roomNumber;
    printf("Please enter the room number: ");
    scanf("%d", &roomNumber);

    // Find room and check if it's available
    int found = 0;
    for (int i = 0; i < NUM_FLOORS; i++) {
        for (int j = 0; j < ROOMS_PER_FLOOR; j++) {
            if (rooms[i][j].roomNumber == roomNumber) {
                if (rooms[i][j].reserved) {
                    printf("Sorry, that room is already reserved.\n");
                } else {
                    printf("Please enter the guest's name: ");
                    scanf("%s", rooms[i][j].guest.name);
                    printf("Please enter the guest's address: ");
                    scanf("%s", rooms[i][j].guest.address);
                    printf("Please enter the guest's phone number: ");
                    scanf("%s", rooms[i][j].guest.phone);
                    rooms[i][j].reserved = 1;
                    printf("Room %d reserved for %s.\n", roomNumber, rooms[i][j].guest.name);
                }
                found = 1;
                break;
            }
        }
        if (found) {
            break;
        }
    }
    if (!found) {
        printf("Sorry, that room does not exist.\n");
    }
}

// Function to cancel a reservation
void cancelReservation(Room rooms[NUM_FLOORS][ROOMS_PER_FLOOR]) {
    int roomNumber;
    printf("Please enter the room number: ");
    scanf("%d", &roomNumber);

    // Find room and cancel reservation
    int found = 0;
    for (int i = 0; i < NUM_FLOORS; i++) {
        for (int j = 0; j < ROOMS_PER_FLOOR; j++) {
            if (rooms[i][j].roomNumber == roomNumber) {
                if (rooms[i][j].reserved) {
                    rooms[i][j].reserved = 0;
                    memset(&rooms[i][j].guest, 0, sizeof(Guest)); // Clear guest information
                    printf("Reservation for room %d cancelled.\n", roomNumber);
                } else {
                    printf("Sorry, that room is not currently reserved.\n");
                }
                found = 1;
                break;
            }
        }
        if (found) {
            break;
        }
    }
    if (!found) {
        printf("Sorry, that room does not exist.\n");
    }
}

// Function to display the status of the rooms
void displayStatus(Room rooms[NUM_FLOORS][ROOMS_PER_FLOOR]) {
    printf("Room Status\n");
    printf("------------\n");
    for (int i = 0; i < NUM_FLOORS; i++) {
        printf("Floor %d:\n", i + 1);
        for (int j = 0; j < ROOMS_PER_FLOOR; j++) {
            printf("Room %d: ", rooms[i][j].roomNumber);
            if (rooms[i][j].reserved) {
                printf("Reserved for %s\n", rooms[i][j].guest.name);
            } else {
                printf("Available\n");
            }
        }
    }
}