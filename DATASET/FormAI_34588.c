//FormAI DATASET v1.0 Category: Hotel Management System ; Style: ultraprecise
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ROOMS 100
#define MAX_NAME_LENGTH 50

struct Room {
    int roomNumber;
    char name[MAX_NAME_LENGTH];
    int isBooked;
    int price;
};

struct Room rooms[MAX_ROOMS];
int numberOfRooms = 0;

void addRoom(int roomNumber, char* name, int price) {
    if (numberOfRooms >= MAX_ROOMS) {
        printf("Unable to add room, maximum capacity reached.\n");
        return;
    }

    rooms[numberOfRooms].roomNumber = roomNumber;
    strcpy(rooms[numberOfRooms].name, name);
    rooms[numberOfRooms].isBooked = 0;
    rooms[numberOfRooms].price = price;

    numberOfRooms++;
}

void bookRoom(int roomNumber) {
    for (int i = 0; i < numberOfRooms; i++) {
        if (rooms[i].roomNumber == roomNumber) {
            if (rooms[i].isBooked) {
                printf("The room is already booked.\n");
                return;
            }

            rooms[i].isBooked = 1;

            printf("Room %d has been booked by %s for $%d/night.\n", roomNumber, rooms[i].name, rooms[i].price);
            return;
        }
    }

    printf("Room %d does not exist.\n", roomNumber);
}

void unbookRoom(int roomNumber) {
    for (int i = 0; i < numberOfRooms; i++) {
        if (rooms[i].roomNumber == roomNumber) {
            if (!rooms[i].isBooked) {
                printf("The room is not booked.\n");
                return;
            }

            rooms[i].isBooked = 0;

            printf("Room %d has been unbooked.\n", roomNumber);
            return;
        }
    }

    printf("Room %d does not exist.\n", roomNumber);
}

void displayRooms() {
    printf("Room\tName\t\tPrice ($/night)\tStatus\n");
    
    for (int i = 0; i < numberOfRooms; i++) {
        printf("%d\t%s\t\t%d\t\t%s\n", rooms[i].roomNumber, rooms[i].name, rooms[i].price, rooms[i].isBooked ? "Booked" : "Available");
    }
}

int main() {
    addRoom(101, "John Doe", 50);
    addRoom(102, "Jane Doe", 60);
    addRoom(103, "Foo Bar", 70);

    displayRooms();

    bookRoom(101);
    bookRoom(102);
    bookRoom(104);

    displayRooms();

    unbookRoom(102);

    displayRooms();

    unbookRoom(105);

    return 0;
}