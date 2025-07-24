//FormAI DATASET v1.0 Category: Hotel Management System ; Style: Linus Torvalds
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct room {
    int roomNumber;
    char guestName[30];
    int occupancyStatus;
};

struct hotel {
    char name[30];
    struct room rooms[10];
    int occupiedRooms;
    int totalRooms;
};

void initHotel(struct hotel * h, char * name, int total) {
    strcpy(h->name, name);
    h->occupiedRooms = 0;
    h->totalRooms = total;

    for(int i=0;i<total;i++) {
        h->rooms[i].roomNumber = i+1;
        h->rooms[i].occupancyStatus = 0;
        strcpy(h->rooms[i].guestName, "");
    }
}

void checkIn(struct hotel * h, char * guestName, int roomNumber) {
    if(h->rooms[roomNumber].occupancyStatus == 0) {
        strcpy(h->rooms[roomNumber].guestName, guestName);
        h->rooms[roomNumber].occupancyStatus = 1;
        h->occupiedRooms++;
        printf("%s has been checked into Room %d.\n", guestName, roomNumber+1);
    }
    else {
        printf("Room is already occupied.\n");
    }
}

void checkOut(struct hotel * h, int roomNumber) {
    if(h->rooms[roomNumber].occupancyStatus == 1) {
        printf("%s has checked out of Room %d.\n", h->rooms[roomNumber].guestName, roomNumber+1);
        h->occupiedRooms--;
        h->rooms[roomNumber].occupancyStatus = 0;
        strcpy(h->rooms[roomNumber].guestName, "");
    }
    else {
        printf("Room is not occupied.\n");
    }
}

void getAvailableRooms(struct hotel * h) {
    printf("Available Rooms:\n");

    for(int i=0;i<h->totalRooms;i++) {
        if(h->rooms[i].occupancyStatus == 0) {
            printf("Room %d\n", h->rooms[i].roomNumber);
        }
    }
}

void getOccupiedRooms(struct hotel * h) {
    printf("Occupied Rooms:\n");

    for(int i=0;i<h->totalRooms;i++) {
        if(h->rooms[i].occupancyStatus == 1) {
            printf("Room %d: %s\n", h->rooms[i].roomNumber, h->rooms[i].guestName);
        }
    }
}

int main() {
    struct hotel hotel1;
    initHotel(&hotel1, "Hotel California", 10);

    checkIn(&hotel1, "John Doe", 3);
    checkIn(&hotel1, "Jane Doe", 5);
    checkIn(&hotel1, "James Smith", 8);
    checkOut(&hotel1, 3);
    checkIn(&hotel1, "Jack Black", 3);

    getAvailableRooms(&hotel1);
    getOccupiedRooms(&hotel1);

    return 0;
}