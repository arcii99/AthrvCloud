//FormAI DATASET v1.0 Category: Hotel Management System ; Style: safe
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#define MAX_ROOMS 100 // maximum rooms the hotel can have
#define MAX_NAME_LENGTH 50 // maximum length of guest name

typedef struct {
    int roomNumber;
    int numOfGuests;
    bool isBooked;
    char guestName[MAX_NAME_LENGTH];
} Room;

void initializeRooms(Room hotel[]) {
    for (int i = 0; i < MAX_ROOMS; i++) {
        hotel[i].roomNumber = i+1;
        hotel[i].isBooked = false;
        hotel[i].numOfGuests = 0;
        strcpy(hotel[i].guestName, "");
    }
    printf("Rooms initialized successfully!\n");
}

void displayRooms(Room hotel[]) {
    printf("ROOMS:\n");
    for (int i = 0; i < MAX_ROOMS; i++) {
        printf("Room %d -> ", hotel[i].roomNumber);
        if (hotel[i].isBooked == true) {
            printf("Booked by %s", hotel[i].guestName);
        }
        else {
            printf("Available");
        }
        printf("\n");
    }
}

void bookRoom(Room hotel[]) {
    int roomNum;
    printf("Enter room number: ");
    scanf("%d", &roomNum);
    if (hotel[roomNum-1].isBooked == true) {
        printf("Sorry, Room %d is already booked.\n", roomNum);
    }
    else {
        printf("Enter guest name: ");
        scanf("%s", hotel[roomNum-1].guestName);
        printf("Enter number of guests: ");
        scanf("%d", &hotel[roomNum-1].numOfGuests);
        hotel[roomNum-1].isBooked = true;
        printf("Room %d booked successfully to %s with %d guests.\n", roomNum, hotel[roomNum-1].guestName, hotel[roomNum-1].numOfGuests);
    }
}

void checkoutRoom(Room hotel[]) {
    int roomNum;
    printf("Enter room number: ");
    scanf("%d", &roomNum);
    if (hotel[roomNum-1].isBooked == false) {
        printf("Sorry, Room %d is not currently booked.\n", roomNum);
    }
    else {
        printf("%s has checked out of Room %d.\n", hotel[roomNum-1].guestName, roomNum);
        hotel[roomNum-1].isBooked = false;
        hotel[roomNum-1].numOfGuests = 0;
        strcpy(hotel[roomNum-1].guestName, "");
    }
}

int main() {
    printf("Welcome to the C Hotel Management System!\n");
    Room hotel[MAX_ROOMS];
    initializeRooms(hotel);
    bool running = true;
    while (running) {
        printf("\n");
        printf("Please choose an option:\n");
        printf("1. Display rooms\n");
        printf("2. Book a room\n");
        printf("3. Checkout of a room\n");
        printf("4. Exit\n");
        int choice;
        printf("Choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                displayRooms(hotel);
                break;
            case 2:
                bookRoom(hotel);
                break;
            case 3:
                checkoutRoom(hotel);
                break;
            case 4:
                running = false;
                printf("Goodbye!\n");
                break;
            default:
                printf("Invalid choice\n");
                break;
        }
    }
    return 0;
}