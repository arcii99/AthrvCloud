//FormAI DATASET v1.0 Category: Hotel Management System ; Style: futuristic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Room {
    int roomNumber;
    char roomType[50];
    double roomPrice;
    int isAvailable;
};

typedef struct Room Room;

void displayRooms(Room *rooms, int size) {
    printf("----------------------------------------------------------\n");
    printf("|\tRoom Number\t|\tRoom Type\t|\tRoom Price\t|\n");
    printf("----------------------------------------------------------\n");
    for(int i=0;i<size;i++) {
        printf("|\t%d\t\t|\t%s\t\t|\t%.2f\t\t|\n", rooms[i].roomNumber, rooms[i].roomType, rooms[i].roomPrice);
    }
    printf("----------------------------------------------------------\n");
}

int bookRoom(Room *rooms, int size, int roomNumber) {
    for(int i=0;i<size;i++) {
        if(rooms[i].roomNumber == roomNumber && rooms[i].isAvailable == 1) {
            rooms[i].isAvailable = 0;
            printf("The room has been booked!\n");
            return 1;
        }
    }
    printf("The room is either unavailable or does not exist!\n");
    return 0;
}

int main() {
    Room rooms[5];
    rooms[0].roomNumber = 101;
    strcpy(rooms[0].roomType, "Deluxe");
    rooms[0].roomPrice = 2500.00;
    rooms[0].isAvailable = 1;

    rooms[1].roomNumber = 102;
    strcpy(rooms[1].roomType, "Executive");
    rooms[1].roomPrice = 3500.00;
    rooms[1].isAvailable = 1;

    rooms[2].roomNumber = 103;
    strcpy(rooms[2].roomType, "Suite");
    rooms[2].roomPrice = 4500.00;
    rooms[2].isAvailable = 1;

    rooms[3].roomNumber = 104;
    strcpy(rooms[3].roomType, "Deluxe Plus");
    rooms[3].roomPrice = 5500.00;
    rooms[3].isAvailable = 1;

    rooms[4].roomNumber = 105;
    strcpy(rooms[4].roomType, "Presidential Suite");
    rooms[4].roomPrice = 6500.00;
    rooms[4].isAvailable = 1;

    while(1) {
        printf("Welcome to the C Hotel Management System!\n");
        printf("1. Display available rooms\n");
        printf("2. Book a room\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        int choice;
        scanf("%d", &choice);
        switch(choice) {
            case 1:
                displayRooms(rooms, 5);
                break;
            case 2:
                printf("Enter the room number to book: ");
                int roomNumber;
                scanf("%d", &roomNumber);
                bookRoom(rooms, 5, roomNumber);
                break;
            case 3:
                printf("Thank you for choosing C Hotel! Goodbye!\n");
                exit(0);
            default:
                printf("Invalid choice! Please try again.\n");
        }
    }
    return 0;
}