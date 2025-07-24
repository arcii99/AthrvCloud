//FormAI DATASET v1.0 Category: Hotel Management System ; Style: real-life
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the maximum length of strings used in the program
#define MAX_NAME_LEN 50
#define MAX_ROOMS 10

// Define a struct to represent a hotel guest
typedef struct {
    char name[MAX_NAME_LEN];
    int roomNumber;
} Guest;

// Define a struct to represent a hotel room
typedef struct {
    int occupied;
    Guest guest;
} Room;

// Function to display the hotel room status
void displayRooms(Room rooms[]) {
    printf("Hotel Room Status:\n");
    for(int i = 0; i < MAX_ROOMS; i++) {
        printf("Room %d: ", i+1);
        if(rooms[i].occupied) {
            printf("Occupied by %s\n", rooms[i].guest.name);
        } else {
            printf("Vacant\n");
        }
    }
}

// Function to check if a room is available
int isRoomAvailable(Room rooms[], int roomNumber) {
    if(rooms[roomNumber-1].occupied) {
        printf("Sorry, Room %d is already occupied.\n", roomNumber);
        return 0;
    } else {
        return 1;
    }
}

// Function to assign a room to a guest
void assignRoom(Room rooms[], char name[], int roomNumber) {
    strcpy(rooms[roomNumber-1].guest.name, name);
    rooms[roomNumber-1].occupied = 1;
    printf("%s has been assigned to Room %d.\n", name, roomNumber);
}

// Function to check out a guest and free up their room
void checkOut(Room rooms[], int roomNumber) {
    strcpy(rooms[roomNumber-1].guest.name, "");
    rooms[roomNumber-1].occupied = 0;
    printf("Room %d has been checked out.\n", roomNumber);
}

int main() {
    // Initialize the hotel's rooms
    Room rooms[MAX_ROOMS];
    for(int i = 0; i < MAX_ROOMS; i++) {
        rooms[i].occupied = 0;
        strcpy(rooms[i].guest.name, "");
    }

    // Start the main loop of the hotel management system
    while(1) {
        printf("\n----------\n");
        printf("1. Display Rooms\n");
        printf("2. Assign Room\n");
        printf("3. Check Out\n");
        printf("4. Exit\n");
        printf("Please enter your choice: ");

        int choice;
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                displayRooms(rooms);
                break;
            case 2:
                printf("Please enter guest name: ");
                char name[MAX_NAME_LEN];
                scanf("%s", name);
                printf("Please enter room number: ");
                int roomNumber;
                scanf("%d", &roomNumber);
                if(isRoomAvailable(rooms, roomNumber)) {
                    assignRoom(rooms, name, roomNumber);
                }
                break;
            case 3:
                printf("Please enter room number to check out: ");
                int checkoutRoomNumber;
                scanf("%d", &checkoutRoomNumber);
                checkOut(rooms, checkoutRoomNumber);
                break;
            case 4:
                printf("Thank you for using the hotel management system.\n");
                exit(0);
                break;
            default:
                printf("Invalid choice. Please choose again.\n");
        }
    }

    return 0;
}