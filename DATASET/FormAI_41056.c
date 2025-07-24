//FormAI DATASET v1.0 Category: Hotel Management System ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Room {
    int num;
    char type[10];
    int price;
    int isOccupied;
};

struct Reservation {
    int id;
    char guestName[30];
    int roomNum;
    char checkInDate[11];
    char checkOutDate[11];
};

struct Room rooms[10];
struct Reservation reservations[10];
int reservationCount = 0;

void initializeRooms() {
    for(int i=0; i<10; i++) {
        rooms[i].num = i+1;
        strcpy(rooms[i].type, "Double");
        rooms[i].price = 100;
        rooms[i].isOccupied = 0;
    }
}

void printRooms() {
    printf("Room#\tType\tPrice\tStatus\n");
    for(int i=0; i<10; i++) {
        printf("%d\t%s\t%d\t%s\n", rooms[i].num, rooms[i].type, 
               rooms[i].price, (rooms[i].isOccupied)?"Occupied":"Vacant");
    }
}

void addReservation() {
    int roomNum;
    char guestName[30];
    char checkInDate[11], checkOutDate[11];
    printf("Enter guest name: ");
    scanf("%s", guestName);
    printf("Enter check-in date (yyyy-mm-dd): ");
    scanf("%s", checkInDate);
    printf("Enter check-out date (yyyy-mm-dd): ");
    scanf("%s", checkOutDate);
    printRooms();
    printf("Enter room number: ");
    scanf("%d", &roomNum);
    if(rooms[roomNum-1].isOccupied) {
        printf("Room is already occupied\n");
    } else {
        reservations[reservationCount].id = reservationCount+1;
        strcpy(reservations[reservationCount].guestName, guestName);
        strcpy(reservations[reservationCount].checkInDate, checkInDate);
        strcpy(reservations[reservationCount].checkOutDate, checkOutDate);
        reservations[reservationCount].roomNum = roomNum;
        rooms[roomNum-1].isOccupied = 1;
        reservationCount++;
        printf("Reservation added successfully\n");
    }
}

void listReservations() {
    printf("Reservation#\tGuest\tRoom#\tCheckIn\tCheckOut\n");
    for(int i=0; i<reservationCount; i++) {
        printf("%d\t\t%s\t%d\t%s\t%s\n", reservations[i].id, 
               reservations[i].guestName, reservations[i].roomNum,
               reservations[i].checkInDate, reservations[i].checkOutDate);
    }
}

int main() {
    initializeRooms();
    int choice;
    do {
        printf("\n==========\n");
        printf("Menu:\n");
        printf("1. Add reservation\n");
        printf("2. List reservations\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch(choice) {
            case 1:
                addReservation();
                break;
            case 2:
                listReservations();
                break;
            case 3:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice\n");
        }
    } while(choice!=3);
    return 0;
}