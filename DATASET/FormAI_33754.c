//FormAI DATASET v1.0 Category: Hotel Management System ; Style: mind-bending
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Room {
    int roomNumber;
    int occupancy;
    char guestName[50];
    float rate;
};

struct Room rooms[10];

void initializeRooms() {
    int i;
    for(i=0; i<10; i++) {
        rooms[i].roomNumber = i+1;
        rooms[i].occupancy = 0;
        strcpy(rooms[i].guestName, "empty");
        rooms[i].rate = 100.0;
    }
}

void printRooms() {
    int i;
    printf("Room Number\tGuest Name\tOccupancy\tRate\n");
    for(i=0; i<10; i++) {
        printf("%d\t\t%s\t\t%d\t\t%.2f\n", rooms[i].roomNumber, rooms[i].guestName, rooms[i].occupancy, rooms[i].rate);
    }
}

int getAvailableRoom() {
    int i;
    for(i=0; i<10; i++) {
        if(rooms[i].occupancy == 0) {
            return i;
        }
    }
    return -1;
}

void checkIn() {
    int roomNumber;
    char guestName[50];
    int i, availableRoom;

    printf("Enter Room Number: ");
    scanf("%d", &roomNumber);

    for(i=0; i<10; i++) {
        if(rooms[i].roomNumber == roomNumber) {
            printf("Room Occupied\n");
            return;
        }
    }

    availableRoom = getAvailableRoom();

    if(availableRoom == -1) {
        printf("No Rooms Available\n");
        return;
    }

    printf("Enter Guest Name: ");
    scanf("%s", guestName);

    rooms[availableRoom].roomNumber = roomNumber;
    rooms[availableRoom].occupancy = 1;
    strcpy(rooms[availableRoom].guestName, guestName);

    printf("Checked In Successfully\n");
}

void checkOut() {
    int roomNumber;
    int i;

    printf("Enter Room Number: ");
    scanf("%d", &roomNumber);

    for(i=0; i<10; i++) {
        if(rooms[i].roomNumber == roomNumber) {
            rooms[i].occupancy = 0;
            strcpy(rooms[i].guestName, "empty");

            printf("Checked Out Successfully\n");
            return;
        }
    }

    printf("Room Not Found\n");
}

int main() {
    int choice;

    initializeRooms();

    do {
        printf("\n========== Hotel Management System ==========\n");
        printf("\t1 - Check In\n");
        printf("\t2 - Check Out\n");
        printf("\t3 - View Rooms\n");
        printf("\t0 - Exit\n");
        printf("==============================================\n");
        printf("Enter Choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                checkIn();
                break;
            case 2:
                checkOut();
                break;
            case 3:
                printRooms();
                break;
            case 0:
                printf("Goodbye!\n");
                exit(0);
            default:
                printf("Invalid Choice!\n");
                break;
        }
    } while(1);

    return 0;
}