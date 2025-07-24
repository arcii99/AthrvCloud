//FormAI DATASET v1.0 Category: Hotel Management System ; Style: complete
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_HOTEL_SIZE 5
#define MAX_ROOM_TYPE 3

struct Room {
    int roomNumber;
    int occupancy; // 0: Available, 1: Occupied
    char* roomType;
    double price;
};

struct Hotel {
    char* name;
    int numOfRooms;
    int roomsOccupied;
    struct Room rooms[MAX_HOTEL_SIZE][MAX_ROOM_TYPE]; // A hotel can have at most 5 floors and 3 room types.
};

struct Hotel initializeHotel() {
    struct Hotel hotel;

    // Set hotel name
    hotel.name = "C Hotel";

    // Initialize rooms
    for(int i = 0; i < MAX_HOTEL_SIZE; i++) {
        for(int j = 0; j < MAX_ROOM_TYPE; j++) {
            hotel.rooms[i][j].roomNumber = (i+1)*100 + (j+1)*10; // Room numbers are assigned sequentially from 101 to 530
            hotel.rooms[i][j].occupancy = 0; // Initially, all rooms are available
            hotel.rooms[i][j].price = 100.0 + j*50; // Price increases with room type
        }
    }

    hotel.numOfRooms = MAX_HOTEL_SIZE * MAX_ROOM_TYPE;
    hotel.roomsOccupied = 0;

    return hotel;
}

void displayMenu() {
    printf("=====================================\n");
    printf("=          C Hotel Program          =\n");
    printf("=====================================\n");
    printf("[1] Check room availability\n");
    printf("[2] Reserve a room\n");
    printf("[3] Cancel room reservation\n");
    printf("[4] Display room information\n");
    printf("[5] Exit program\n");
}

void showRooms(struct Hotel hotel) {
    printf("======= Room Availability =======\n");
    for(int i = 0; i < MAX_HOTEL_SIZE; i++) {
        printf("Floor %d\n", i+1);
        for(int j = 0; j < MAX_ROOM_TYPE; j++) {
            printf("\tRoom %d - Type: %s - Status: %s - Price: %.2lf\n", hotel.rooms[i][j].roomNumber, hotel.rooms[i][j].roomType, hotel.rooms[i][j].occupancy == 0 ? "Available" : "Occupied", hotel.rooms[i][j].price);
        }
    }
}

void reserveRoom(struct Hotel* hotel) {
    int roomNumber;
    int roomTypeIndex;
    struct Room* room;

    showRooms(*hotel);

    printf("Enter the room number you want to reserve: ");
    scanf("%d", &roomNumber);

    // Find the index of the room's type
    if(roomNumber % 10 == 1) {
        roomTypeIndex = 0; // Single Room
    } else if (roomNumber % 10 == 2) {
        roomTypeIndex = 1; // Double Room
    } else {
        roomTypeIndex = 2; // Suite Room
    }

    // Get the room struct
    room = &hotel->rooms[(roomNumber/100)-1][roomTypeIndex];

    if(room->occupancy == 1) {
        printf("The room is already occupied.\n");
    } else {
        room->occupancy = 1;
        hotel->roomsOccupied++;
        printf("Reservation successful! Room %d is now occupied.\n", roomNumber);
    }
}

void cancelReservation(struct Hotel* hotel) {
    int roomNumber;
    int roomTypeIndex;
    struct Room* room;

    showRooms(*hotel);

    printf("Enter the room number you want to cancel the reservation for: ");
    scanf("%d", &roomNumber);

    // Find the index of the room's type
    if(roomNumber % 10 == 1) {
        roomTypeIndex = 0; // Single Room
    } else if (roomNumber % 10 == 2) {
        roomTypeIndex = 1; // Double Room
    } else {
        roomTypeIndex = 2; // Suite Room
    }

    // Get the room struct
    room = &hotel->rooms[(roomNumber/100)-1][roomTypeIndex];

    if(room->occupancy == 0) {
        printf("The room is already available.\n");
    } else {
        room->occupancy = 0;
        hotel->roomsOccupied--;
        printf("Reservation cancellation successful! Room %d is now available.\n", roomNumber);
    }
}

void displayRoomInformation(struct Hotel hotel) {
    int roomNumber;
    int roomTypeIndex;
    struct Room room;

    showRooms(hotel);

    printf("Enter the room number to display information: ");
    scanf("%d", &roomNumber);

    // Find the index of the room's type
    if(roomNumber % 10 == 1) {
        roomTypeIndex = 0; // Single Room
    } else if (roomNumber % 10 == 2) {
        roomTypeIndex = 1; // Double Room
    } else {
        roomTypeIndex = 2; // Suite Room
    }

    // Get the room struct
    room = hotel.rooms[(roomNumber/100)-1][roomTypeIndex];

    printf("======= Room Information =======\n");
    printf("Room Number: %d\n", roomNumber);
    printf("Room Type: %s\n", room.roomType);
    printf("Price: %.2lf\n", room.price);
    printf("Status: %s\n", room.occupancy == 0 ? "Available" : "Occupied");
}

int main() {
    struct Hotel hotel = initializeHotel();
    int option;

    do {
        displayMenu();
        printf("Enter an option: ");
        scanf("%d", &option);

        switch(option) {
            case 1:
                showRooms(hotel);
                break;
            case 2:
                reserveRoom(&hotel);
                break;
            case 3:
                cancelReservation(&hotel);
                break;
            case 4:
                displayRoomInformation(hotel);
                break;
            case 5:
                printf("Exiting program. Goodbye!\n");
                break;
            default:
                printf("Invalid option. Please try again.\n");
                break;
        }
    } while(option != 5);

    return 0;
}