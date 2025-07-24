//FormAI DATASET v1.0 Category: Hotel Management System ; Style: curious
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ROOMS 50
#define MAX_NAME_LENGTH 50
#define MAX_PHONE_LENGTH 10

typedef struct {
    int roomNumber;
    char guestName[MAX_NAME_LENGTH];
    char guestPhone[MAX_PHONE_LENGTH];
    int occupied;
} Room;

Room hotelRooms[MAX_ROOMS];

void initializeRooms() {
    for (int i = 0; i < MAX_ROOMS; i++) {
        hotelRooms[i].roomNumber = i + 1;
        hotelRooms[i].occupied = 0;
    }
}

void showRooms() {
    printf("Hotel Room Occupation Status\n");
    for (int i = 0; i < MAX_ROOMS; i++) {
        printf("Room %d: ", hotelRooms[i].roomNumber);
        if (hotelRooms[i].occupied) {
            printf("Guest Name: %s, Phone Number: %s\n", hotelRooms[i].guestName, hotelRooms[i].guestPhone);
        } else {
            printf("Not Occupied\n");
        }
    }
}

void checkIn() {
    int roomNumber;
    char guestName[MAX_NAME_LENGTH];
    char guestPhone[MAX_PHONE_LENGTH];

    printf("Enter room number: ");
    scanf("%d", &roomNumber);

    if (roomNumber < 1 || roomNumber > MAX_ROOMS) {
        printf("Invalid room number.\n");
        return;
    }

    if (hotelRooms[roomNumber - 1].occupied) {
        printf("Room already occupied.\n");
        return;
    }

    printf("Enter guest name: ");
    scanf("%s", guestName);

    printf("Enter guest phone number: ");
    scanf("%s", guestPhone);

    strcpy(hotelRooms[roomNumber - 1].guestName, guestName);
    strcpy(hotelRooms[roomNumber - 1].guestPhone, guestPhone);
    hotelRooms[roomNumber - 1].occupied = 1;

    printf("Guest checked in successfully.\n");
}

void checkOut() {
    int roomNumber;

    printf("Enter room number: ");
    scanf("%d", &roomNumber);

    if (roomNumber < 1 || roomNumber > MAX_ROOMS) {
        printf("Invalid room number.\n");
        return;
    }

    if (!hotelRooms[roomNumber - 1].occupied) {
        printf("Room not occupied.\n");
        return;
    }

    hotelRooms[roomNumber - 1].occupied = 0;

    printf("Guest checked out successfully.\n");
}

int main() {
    initializeRooms();

    int choice;
    do {
        printf("Hotel Management System\n");
        printf("1. Show Rooms\n");
        printf("2. Check In\n");
        printf("3. Check Out\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: showRooms(); break;
            case 2: checkIn(); break;
            case 3: checkOut(); break;
            case 4: break; // do nothing, will exit loop
            default: printf("Invalid choice.\n");
        }
    } while (choice != 4);

    printf("Thank you for using our Hotel Management System.\n");

    return 0;
}