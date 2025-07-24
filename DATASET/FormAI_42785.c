//FormAI DATASET v1.0 Category: Hotel Management System ; Style: distributed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_ROOMS 50
#define MAX_NAME 50

typedef struct {
    int roomNumber;
    char guestName[MAX_NAME];
    int occupancyStatus;
} Room;

void initializeRooms(Room roomList[], int numRooms) {
    int i;
    for(i = 0; i < numRooms; i++) {
        roomList[i].roomNumber = i + 1;
        strcpy(roomList[i].guestName, "EMPTY");
        roomList[i].occupancyStatus = 0;
    }
}

void printRooms(Room roomList[], int numRooms) {
    int i;
    printf("ROOM\tNAME\t\tOCCUPIED\n");
    for(i = 0; i < numRooms; i++) {
        printf("%d\t%s\t\t%s\n", roomList[i].roomNumber, roomList[i].guestName, roomList[i].occupancyStatus ? "YES" : "NO");
    }
}

int reserveRoom(Room roomList[], int numRooms) {
    int i, roomNumber;
    char guestName[MAX_NAME];
    printf("Enter room number: ");
    scanf("%d", &roomNumber);
    if(roomNumber > numRooms || roomNumber < 1) {
        printf("Invalid room number.\n");
        return -1;
    }

    printf("Enter guest name: ");
    scanf("%s", guestName);

    if(roomList[roomNumber-1].occupancyStatus) {
        printf("Room is already occupied.\n");
        return -1;
    }

    strcpy(roomList[roomNumber-1].guestName, guestName);
    roomList[roomNumber-1].occupancyStatus = 1;
    printf("Room %d has been reserved for %s.\n", roomNumber, guestName);
    return 0;
}

int main() {
    Room rooms[MAX_ROOMS];
    int menuChoice = -1;
    int numRooms = 10; // Change this to set how many rooms the hotel has
    initializeRooms(rooms, numRooms);

    printf("Welcome to the hotel management system.\n");

    while(menuChoice != 0) {
        printf("\nPlease choose an option:\n");
        printf("1. View rooms\n");
        printf("2. Reserve a room\n");
        printf("0. Exit\n");
        scanf("%d", &menuChoice);
        switch (menuChoice) {
            case 1:
                printRooms(rooms, numRooms);
                break;
            case 2:
                reserveRoom(rooms, numRooms);
                break;
            case 0:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid input.\n");
        }
    }

    return 0;
}