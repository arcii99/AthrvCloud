//FormAI DATASET v1.0 Category: Hotel Management System ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>

// Define the maximum number of rooms available
#define MAX_ROOMS 50

// Room structure to hold room number and availability status
typedef struct {
    int roomNo;
    int isAvailable;
} Room;

// Function to generate the initial list of rooms
void generateRooms(Room* rooms) {
    for(int i = 0; i < MAX_ROOMS; i++) {
        rooms[i].roomNo = i+1;
        rooms[i].isAvailable = 1; // 1 for available, 0 for booked
    }
}

// Function to display the list of available rooms
void displayAvailableRooms(Room* rooms) {
    printf("\nAvailable Rooms:\n");
    printf("Room No.\tStatus\n");
    for(int i = 0; i < MAX_ROOMS; i++) {
        if(rooms[i].isAvailable) {
            printf("%d\t\tAvailable\n", rooms[i].roomNo);
        }
    }
}

// Function to book a room
void bookRoom(Room* rooms, int roomNo) {
    if(rooms[roomNo-1].isAvailable) {
        rooms[roomNo-1].isAvailable = 0;
        printf("\nRoom %d has been booked successfully!\n", roomNo);
    } else {
        printf("\nSorry, Room %d is not available.\n", roomNo);
    }
}

// Function to check out of a room
void checkOut(Room* rooms, int roomNo) {
    if(!rooms[roomNo-1].isAvailable) {
        rooms[roomNo-1].isAvailable = 1;
        printf("\nThank you for staying with us in Room %d. Hope you had a pleasant stay!\n", roomNo);
    } else {
        printf("\nSorry, Room %d is already available.\n", roomNo);
    }
}

int main() {
    Room rooms[MAX_ROOMS];
    generateRooms(rooms);

    int choice;
    int roomNo;

    // Display the main menu
    printf("Welcome to C Hotel Management System!\n");
    do {
        printf("\n1. Display available rooms\n2. Book a room\n3. Check out of a room\n4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch(choice) {
            case 1:
                displayAvailableRooms(rooms);
                break;
            case 2:
                printf("\nEnter the room number you want to book: ");
                scanf("%d", &roomNo);
                bookRoom(rooms, roomNo);
                break;
            case 3:
                printf("\nEnter the room number you want to check out of: ");
                scanf("%d", &roomNo);
                checkOut(rooms, roomNo);
                break;
            case 4:
                printf("\nThank you for using C Hotel Management System! Have a nice day!\n");
                break;
            default:
                printf("\nInvalid choice! Please try again.\n");
        }
    } while(choice != 4);

    return 0;
}