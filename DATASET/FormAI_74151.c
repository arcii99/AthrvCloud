//FormAI DATASET v1.0 Category: Hotel Management System ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_HOTEL 100
#define MAX_ROOM 1000

struct Room {
    int roomNumber;
    int roomType; // 1: Single, 2: Double, 3: Family
    float price;
    char status[10]; // "AVAILABLE" or "BOOKED"
    char guestName[20];
};

struct Hotel {
    int hotelID;
    char name[50];
    char address[100];
    int numberOfRooms;
    struct Room rooms[MAX_ROOM];
};

struct Hotel hotels[MAX_HOTEL];
int numberOfHotels = 0;

void addHotel() {
    if (numberOfHotels >= MAX_HOTEL) {
        printf("Sorry, the system can only support up to %d hotels.\n", MAX_HOTEL);
        return;
    }
    struct Hotel newHotel;
    newHotel.hotelID = numberOfHotels + 1;
    printf("Enter the name of the hotel: ");
    scanf("%s", newHotel.name);
    printf("Enter the address of the hotel: ");
    fgets(newHotel.address, 100, stdin);
    printf("Enter the number of rooms in the hotel: ");
    scanf("%d", &newHotel.numberOfRooms);
    for (int i = 0; i < newHotel.numberOfRooms; i++) {
        struct Room newRoom;
        newRoom.roomNumber = i + 1;
        printf("Enter the type of the room (1: Single, 2: Double, 3: Family): ");
        scanf("%d", &newRoom.roomType);
        if (newRoom.roomType == 1) {
            newRoom.price = 50.0;
        } else if (newRoom.roomType == 2) {
            newRoom.price = 80.0;
        } else {
            newRoom.price = 120.0;
        }
        strcpy(newRoom.status, "AVAILABLE");
        strcpy(newRoom.guestName, "");
        newHotel.rooms[i] = newRoom;
    }
    hotels[numberOfHotels] = newHotel;
    numberOfHotels++;
}

void listHotels() {
    if (numberOfHotels == 0) {
        printf("There are no hotels in the system.\n");
        return;
    }
    printf("List of hotels in the system:\n");
    printf("ID | Name | Address | Number of Rooms\n");
    for (int i = 0; i < numberOfHotels; i++) {
        printf("%d | %s | %s | %d\n", hotels[i].hotelID, hotels[i].name, hotels[i].address, hotels[i].numberOfRooms);
    }
}

void viewHotel(int hotelID) {
    int index = -1;
    for (int i = 0; i < numberOfHotels; i++) {
        if (hotels[i].hotelID == hotelID) {
            index = i;
            break;
        }
    }
    if (index == -1) {
        printf("Hotel with ID %d not found in the system.\n", hotelID);
        return;
    }
    struct Hotel hotel = hotels[index];
    printf("Details of hotel %s:\n", hotel.name);
    printf("ID: %d\n", hotel.hotelID);
    printf("Address: %s\n", hotel.address);
    printf("Number of rooms: %d\n", hotel.numberOfRooms);
    printf("List of rooms:\n");
    printf("Room Number | Room Type | Price | Status | Guest Name\n");
    for (int i = 0; i < hotel.numberOfRooms; i++) {
        struct Room room = hotel.rooms[i];
        printf("%d | %d | %.2f | %s | %s\n", room.roomNumber, room.roomType, room.price, room.status, room.guestName);
    }
}

void bookRoom(int hotelID, int roomNumber, char guestName[]) {
    int hotelIndex = -1;
    int roomIndex = -1;
    for (int i = 0; i < numberOfHotels; i++) {
        if (hotels[i].hotelID == hotelID) {
            hotelIndex = i;
            break;
        }
    }
    if (hotelIndex == -1) {
        printf("Hotel with ID %d not found in the system.\n", hotelID);
        return;
    }
    struct Hotel hotel = hotels[hotelIndex];
    if (roomNumber <= 0 || roomNumber > hotel.numberOfRooms) {
        printf("Invalid room number.\n");
        return;
    }
    struct Room room = hotel.rooms[roomNumber - 1];
    if (strcmp(room.status, "BOOKED") == 0) {
        printf("The room is already booked.\n");
        return;
    }
    strcpy(room.status, "BOOKED");
    strcpy(room.guestName, guestName);
    hotel.rooms[roomNumber - 1] = room;
    hotels[hotelIndex] = hotel;
    printf("Room %d in hotel %s has been booked by %s successfully.\n", roomNumber, hotel.name, guestName);
}

int main() {
    int choice;
    do {
        printf("Hotel Management System\n");
        printf("1. Add hotel\n");
        printf("2. List hotels\n");
        printf("3. View hotel details\n");
        printf("4. Book a room\n");
        printf("5. Exit\n");
        printf("Enter your choice (1-5): ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                addHotel();
                break;
            case 2:
                listHotels();
                break;
            case 3: {
                int hotelID;
                printf("Enter the ID of the hotel: ");
                scanf("%d", &hotelID);
                viewHotel(hotelID);
                break;
            }
            case 4: {
                int hotelID, roomNumber;
                char guestName[20];
                printf("Enter the ID of the hotel: ");
                scanf("%d", &hotelID);
                printf("Enter the room number: ");
                scanf("%d", &roomNumber);
                printf("Enter guest name: ");
                scanf("%s", guestName);
                bookRoom(hotelID, roomNumber, guestName);
                break;
            }
            case 5:
                printf("Goodbye!\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
                break;
        }
    } while (choice != 5);
    return 0;
}