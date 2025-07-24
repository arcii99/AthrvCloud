//FormAI DATASET v1.0 Category: Hotel Management System ; Style: protected
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define MAX_ROOMS 50
#define MAX_NAME_LENGTH 50

struct Room {
    int roomNumber;
    bool occupied;
    char guestName[MAX_NAME_LENGTH];
};

typedef struct Room Room;

int main() {
    Room hotelRooms[MAX_ROOMS];
    int numRooms = 0;

    // Initialize all rooms as unoccupied
    for (int i = 0; i < MAX_ROOMS; i++) {
        hotelRooms[i].roomNumber = i + 1;
        hotelRooms[i].occupied = false;
        memset(hotelRooms[i].guestName, 0, MAX_NAME_LENGTH);
    }

    // Display main menu
    int choice;
    do {
        printf("\n\n\n\tHotel Management System\n");
        printf("\n\n\t1. Check in a guest");
        printf("\n\n\t2. Check out a guest");
        printf("\n\n\t3. Display room status");
        printf("\n\n\t4. Exit");
        printf("\n\n\tEnter your choice (1-4): ");
        scanf("%d", &choice);
        switch (choice) {
            case 1: { // Check in a guest
                int roomNum;
                char name[MAX_NAME_LENGTH];
                printf("Enter room number: ");
                scanf("%d", &roomNum);
                if (hotelRooms[roomNum - 1].occupied) {
                    printf("Sorry, that room is already occupied.");
                } else {
                    printf("Enter guest name: ");
                    scanf(" %[^\n]s", name);
                    hotelRooms[roomNum - 1].occupied = true;
                    strcpy(hotelRooms[roomNum - 1].guestName, name);
                    printf("Guest %s checked into room %d.", name, roomNum);
                }
                break;
            }
            case 2: { // Check out a guest
                int roomNum;
                printf("Enter room number: ");
                scanf("%d", &roomNum);
                if (!hotelRooms[roomNum - 1].occupied) {
                    printf("Sorry, that room is not currently occupied.");
                } else {
                    printf("Guest %s checked out of room %d.", hotelRooms[roomNum - 1].guestName, roomNum);
                    hotelRooms[roomNum - 1].occupied = false;
                    memset(hotelRooms[roomNum - 1].guestName, 0, MAX_NAME_LENGTH);
                }
                break;
            }
            case 3: { // Display room status
                printf("\nRoom Status\n");
                printf("Room Number\tGuest Name\tStatus\n");
                for (int i = 0; i < MAX_ROOMS; i++) {
                    printf("%d\t", hotelRooms[i].roomNumber);
                    if (hotelRooms[i].occupied) {
                        printf("%s\tChecked In\n", hotelRooms[i].guestName);
                    } else {
                        printf("N/A\t\tAvailable\n");
                    }
                }
                break;
            }
        }
    } while (choice != 4);

    return 0;
}