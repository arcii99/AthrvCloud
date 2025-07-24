//FormAI DATASET v1.0 Category: Hotel Management System ; Style: authentic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ROOMS 100
#define MAX_GUESTS 200

typedef struct {
    int roomNumber;
    char roomType[20];
    double roomRate;
    int isBooked;
    int isOccupied;
} Room;

typedef struct {
    int guestID;
    char guestName[50];
    char guestContact[20];
    char checkInDate[15];
    char checkOutDate[15];
    int roomNumber;
    double roomRate;
    int isBooked;
    int isOccupied;
} Guest;

Room rooms[MAX_ROOMS];
Guest guests[MAX_GUESTS];
int numRooms = 0;
int numGuests = 0;

void initRooms() {
    for (int i = 0; i < MAX_ROOMS; i++) {
        rooms[i].roomNumber = i + 1;
        strcpy(rooms[i].roomType, "");
        rooms[i].roomRate = 0;
        rooms[i].isBooked = 0;
        rooms[i].isOccupied = 0;
    }
    
    rooms[0].roomRate = 100.0;
    rooms[1].roomRate = 150.0;
    rooms[2].roomRate = 200.0;
    rooms[3].roomRate = 250.0;
  
    numRooms = 4;
}

void bookRoom() {
    char guestName[50], guestContact[20], checkInDate[15], checkOutDate[15];
    int roomNumber;
    
    printf("Enter guest name: ");
    scanf("%s", guestName);
    
    printf("Enter guest contact: ");
    scanf("%s", guestContact);
    
    printf("Enter check in date (DD-MM-YYYY): ");
    scanf("%s", checkInDate);
    
    printf("Enter check out date (DD-MM-YYYY): ");
    scanf("%s", checkOutDate);
    
    printf("Available rooms:\n");
    for (int i = 0; i < numRooms; i++) {
        if (!rooms[i].isBooked) {
            printf("%d. Room %d (%s) - $%.2f per day.\n", i + 1, rooms[i].roomNumber, rooms[i].roomType, rooms[i].roomRate);
        }
    }
    
    printf("Enter room number to book: ");
    scanf("%d", &roomNumber);
    
    if (roomNumber < 1 || roomNumber > numRooms) {
        printf("Invalid room number.\n");
        return;
    }
    
    Room *room = &rooms[roomNumber - 1];
    
    if (room->isBooked) {
        printf("Room is already booked.\n");
        return;
    }
    
    room->isBooked = 1;

    Guest guest;
    guest.guestID = numGuests + 1;
    strcpy(guest.guestName, guestName);
    strcpy(guest.guestContact, guestContact);
    strcpy(guest.checkInDate, checkInDate);
    strcpy(guest.checkOutDate, checkOutDate);
    guest.roomNumber = roomNumber;
    guest.roomRate = room->roomRate;
    guest.isBooked = 1;
    guest.isOccupied = 0;
    
    guests[numGuests++] = guest;

    printf("Room booked successfully.\n");
}

void checkIn() {
    int guestID;
    
    printf("Enter guest ID: ");
    scanf("%d", &guestID);
    
    if (guestID < 1 || guestID > numGuests) {
        printf("Invalid guest ID.\n");
        return;
    }
    
    Guest *guest = &guests[guestID - 1];
    
    if (!guest->isBooked || guest->isOccupied) {
        printf("Guest has not booked a room or is already checked in.\n");
        return;
    }
    
    guest->isOccupied = 1;
    rooms[guest->roomNumber - 1].isOccupied = 1;
    
    printf("Check in successful.\n");
}

void checkOut() {
    int guestID;
    
    printf("Enter guest ID: ");
    scanf("%d", &guestID);
    
    if (guestID < 1 || guestID > numGuests) {
        printf("Invalid guest ID.\n");
        return;
    }
    
    Guest *guest = &guests[guestID - 1];
    
    if (!guest->isOccupied) {
        printf("Guest has not checked in.\n");
        return;
    }
    
    guest->isOccupied = 0;
    guest->isBooked = 0;
    rooms[guest->roomNumber - 1].isBooked = 0;
    rooms[guest->roomNumber - 1].isOccupied = 0;
    
    double totalBill = (atof(guest->checkOutDate) - atof(guest->checkInDate)) * guest->roomRate;
    
    printf("Guest Name: %s\n", guest->guestName);
    printf("Guest Contact: %s\n", guest->guestContact);
    printf("Check In Date: %s\n", guest->checkInDate);
    printf("Check Out Date: %s\n", guest->checkOutDate);
    printf("Room Number: %d\n", guest->roomNumber);
    printf("Room Rate: $%.2f per day\n", guest->roomRate);
    printf("Total Bill: $%.2f\n", totalBill);
}

int main() {
    initRooms();
    
    int choice = 0;
    
    while (choice != 4) {
        printf("1. Book Room\n");
        printf("2. Check In\n");
        printf("3. Check Out\n");
        printf("4. Exit\n");
        
        printf("Enter your choice: ");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                bookRoom();
                break;
            case 2:
                checkIn();
                break;
            case 3:
                checkOut();
                break;
            case 4:
                printf("Goodbye!");
                break;
            default:
                printf("Invalid choice.\n");
        }
        
        printf("Press enter to continue...");
        getchar();
        getchar();
        system("clear");
    }
    
    return 0;
}