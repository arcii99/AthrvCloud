//FormAI DATASET v1.0 Category: Hotel Management System ; Style: happy
#include <stdio.h>
#include <string.h>

/* This program is a Hotel Management System that allows you to register
and book rooms for customers. It keeps track of room availability and provides
information on hotel capacity.*/

struct Room {
    int roomNumber;
    char facility[50];
    int price;
    int availability;
} rooms[20];

void printRooms() {
    printf("\n--------------------------------------------------\n");
    printf("| Room Number | Facility | Price | Availability |\n");
    printf("--------------------------------------------------\n");
    for (int i = 0; i < 20; i++) {
        printf("| %11d | %8s | $%4d | %12s |\n", rooms[i].roomNumber,
        rooms[i].facility, rooms[i].price, 
        rooms[i].availability ? "Available" : "Booked");
    }
    printf("--------------------------------------------------\n");
}

int getRoomIndex(int roomNumber) {
    int index = -1;
    for (int i = 0; i < 20; i++) {
        if (rooms[i].roomNumber == roomNumber) {
            index = i;
            break;
        }
    }
    return index;
}

void registerRoom(int roomNumber, char facility[], int price) {
    int index = getRoomIndex(roomNumber);
    if (index == -1) {
        for (int i = 0; i < 20; i++) {
            if (rooms[i].availability == 0) {
                rooms[i].roomNumber = roomNumber;
                strcpy(rooms[i].facility, facility);
                rooms[i].price = price;
                rooms[i].availability = 1;
                printf("\nRoom %d has been registered.\n", roomNumber);
                break;
            }
        }
    } else {
        printf("\nRoom %d already registered.\n", roomNumber);
    }
}

void bookRoom(int roomNumber) {
    int index = getRoomIndex(roomNumber);
    if (index == -1) {
        printf("\nRoom %d does not exist.\n", roomNumber);
    } else {
        if (rooms[index].availability == 1) {
            rooms[index].availability = 0;
            printf("\nRoom %d has been booked.\n", roomNumber);
        } else {
            printf("\nSorry, room %d is not available.\n", roomNumber);
        }
    }
}

void checkIn() {
    int totalRooms = 0;
    int totalRevenue = 0;
    for (int i = 0; i < 20; i++) {
        if (rooms[i].availability == 0) {
            totalRooms++;
            totalRevenue += rooms[i].price;
        }
    }
    printf("\nTotal Rooms: %d\nTotal Revenue: $%d\n", totalRooms, totalRevenue);
}

int main() {
    for (int i = 0; i < 20; i++) {
        rooms[i].roomNumber = i + 1;
        strcpy(rooms[i].facility, "Standard Room");
        rooms[i].price = 50;
        rooms[i].availability = 1;
    }

    // Display Initial Room List
    printf("\nWELCOME TO HAPPY HOTEL MANAGEMENT SYSTEM\n");
    printf("==========================================\n");
    printRooms();

    int choice = -1;
    while(choice != 0) {
        printf("\nWhat would you like to do?\n");
        printf("1. Register a room\n");
        printf("2. Book a room\n");
        printf("3. Check In\n");
        printf("0. Exit\n");
        printf("Choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1: {
                int roomNumber, price;
                char facility[50];
                printf("\nEnter the room number: ");
                scanf("%d", &roomNumber);
                printf("Enter the facility (e.g Standard, Deluxe, Suite): ");
                scanf("%s", facility);
                printf("Enter the price: ");
                scanf("%d", &price);
                registerRoom(roomNumber, facility, price);
                printRooms();
                break;
            }
            case 2: {
                int roomNumber;
                printf("\nEnter the room number: ");
                scanf("%d", &roomNumber);
                bookRoom(roomNumber);
                printRooms();
                break;
            }
            case 3: {
                checkIn();
                break;
            }
            case 0: {
                printf("\nThank you for using HAPPY HOTEL MANAGEMENT SYSTEM!\n");
                break;
            }
            default: {
                printf("\nInvalid choice. Please try again.\n");
                break;
            }
        }
    }

    return 0;
}