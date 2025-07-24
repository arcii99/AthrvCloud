//FormAI DATASET v1.0 Category: Hotel Management System ; Style: artistic
#include <stdio.h>
#include <stdlib.h>

#define MAX_ROOMS 100

struct room {
    int room_number;
    int capacity;
    int isOccupied;
    float price;
};

struct hotel {
    char name[50];
    int numRooms;
    struct room rooms[MAX_ROOMS];
};

struct hotel initHotel(char name[], int numRooms) {
    struct hotel h;
    strcpy(h.name, name);
    h.numRooms = numRooms;
    for (int i = 0; i < numRooms; i++) {
        h.rooms[i].room_number = i + 1;
        h.rooms[i].capacity = rand() % 5 + 1;
        h.rooms[i].isOccupied = 0;
        h.rooms[i].price = (rand() % 100 + 50) / 10.0;
    }
    return h;
}

void printRooms(struct hotel h) {
    printf("\nRoom\tCapacity\tPrice\n");
    for (int i = 0; i < h.numRooms; i++) {
        printf("%3d\t\t%2d\t\t%.2f\n", h.rooms[i].room_number, h.rooms[i].capacity, h.rooms[i].price);
    }
}

int checkIn(struct hotel *h, int room_number) {
    if (h->rooms[room_number - 1].isOccupied) {
        printf("\nRoom %d is already occupied.\n", room_number);
        return 0;
    }
    h->rooms[room_number - 1].isOccupied = 1;
    return 1;
}

void checkOut(struct hotel *h, int room_number) {
    if (!h->rooms[room_number - 1].isOccupied) {
        printf("\nRoom %d is not occupied.\n", room_number);
        return;
    }
    h->rooms[room_number - 1].isOccupied = 0;
}

void main() {
    srand(time(NULL));
    struct hotel h = initHotel("Artistic Hotel", 10);
    int choice = 0;
    int room_number = 0;
    while (choice != 4) {
        printf("\n%s Hotel Management System\n", h.name);
        printf("1. View Rooms\n");
        printf("2. Check In\n");
        printf("3. Check Out\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
        case 1:
            printRooms(h);
            break;
        case 2:
            printf("\nEnter room number: ");
            scanf("%d", &room_number);
            if (checkIn(&h, room_number)) {
                printf("\nRoom %d checked in.\n", room_number);
            }
            break;
        case 3:
            printf("\nEnter room number: ");
            scanf("%d", &room_number);
            checkOut(&h, room_number);
            printf("\nRoom %d checked out.\n", room_number);
            break;
        case 4:
            printf("\nGoodbye!\n");
            break;
        default:
            printf("\nInvalid choice. Please try again.\n");
            break;
        }
    }
}