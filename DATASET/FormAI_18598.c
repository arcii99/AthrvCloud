//FormAI DATASET v1.0 Category: Hotel Management System ; Style: creative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define structure for setting room details
struct Room {
    int roomNumber;
    char roomType[20];
    int floorNumber;
    int numOfBeds;
    float pricePerNight;
    int isOccupied;
};

// Function to initialize the room details
void initRooms(struct Room rooms[], int numOfRooms) {
    for (int i = 0; i < numOfRooms; i++) {
        rooms[i].roomNumber = i + 1;
        strcpy(rooms[i].roomType, "Standard");
        rooms[i].floorNumber = i / 10 + 1;
        rooms[i].numOfBeds = 2;
        rooms[i].pricePerNight = 100.00;
        rooms[i].isOccupied = 0;
    }
}

// Function to display the available rooms
void displayAvailableRooms(struct Room rooms[], int numOfRooms) {
    int availableRoomsCount = 0;
    printf("\nAvailable Rooms:\n");
    printf("Room Num  Room Type  Floor No.  Num of Beds  Price/Night\n");
    for (int i = 0; i < numOfRooms; i++) {
        if (rooms[i].isOccupied == 0) {
            printf("%6d    %-10s       %d         %2d              %.2f\n", rooms[i].roomNumber, rooms[i].roomType, rooms[i].floorNumber, rooms[i].numOfBeds, rooms[i].pricePerNight);
            availableRoomsCount++;
        }
    }
    if (availableRoomsCount == 0) {
        printf("No available rooms at this time.\n");
    }
}

// Function to book a room
void bookRoom(struct Room rooms[], int numOfRooms) {
    int roomNum;
    printf("\nEnter the room number you wish to book: ");
    scanf("%d", &roomNum);
    if (roomNum > 0 && roomNum <= numOfRooms && rooms[roomNum - 1].isOccupied == 0) {
        rooms[roomNum - 1].isOccupied = 1;
        printf("\nRoom %d has been booked successfully.\n", roomNum);
    } else {
        printf("\nError: Room %d is either already occupied or does not exist.\n", roomNum);
    }
}

// Function to display the booked rooms
void displayBookedRooms(struct Room rooms[], int numOfRooms) {
    int bookedRoomsCount = 0;
    printf("\nBooked Rooms:\n");
    printf("Room Num  Room Type  Floor No.  Num of Beds  Price/Night\n");
    for (int i = 0; i < numOfRooms; i++) {
        if (rooms[i].isOccupied == 1) {
            printf("%6d    %-10s       %d         %2d              %.2f\n", rooms[i].roomNumber, rooms[i].roomType, rooms[i].floorNumber, rooms[i].numOfBeds, rooms[i].pricePerNight);
            bookedRoomsCount++;
        }
    }
    if (bookedRoomsCount == 0) {
        printf("No booked rooms at this time.\n");
    }
}

int main() {
    int numOfRooms = 30;
    struct Room rooms[numOfRooms];

    // Initialize the room details
    initRooms(rooms, numOfRooms);

    int choice;
    do {
        printf("\n\nWelcome to the C Hotel Management System\n");
        printf("1. Display Available Rooms\n");
        printf("2. Book a Room\n");
        printf("3. Display Booked Rooms\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                displayAvailableRooms(rooms, numOfRooms);
                break;
            case 2:
                bookRoom(rooms, numOfRooms);
                break;
            case 3:
                displayBookedRooms(rooms, numOfRooms);
                break;
            case 4:
                printf("\nThank you for using the C Hotel Management System.\n");
                exit(0);
                break;
            default:
                printf("\nError: Invalid choice. Please try again.\n");
        }
    } while (1);

    return 0;
}