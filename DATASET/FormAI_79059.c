//FormAI DATASET v1.0 Category: Hotel Management System ; Style: happy
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ROOMS 50
#define MAX_GUESTS 100

// Struct for guests
typedef struct Guest {
    char name[30];
    int age;
    char gender;
} Guest;

// Struct for rooms
typedef struct Room {
    int roomNumber;
    int capacity;
    int currentGuests;
    Guest guests[MAX_GUESTS];
} Room;

// Function to initialize rooms
void initializeRooms(Room rooms[]) {
    int i;
    for(i = 0; i < MAX_ROOMS; i++) {
        rooms[i].roomNumber = i + 1;
        rooms[i].capacity = rand() % 5 + 1;
        rooms[i].currentGuests = 0;
    }
}

// Function to check if there is an available room for the given number of guests
int findAvailableRoom(Room rooms[], int numGuests) {
    int i;
    for(i = 0; i < MAX_ROOMS; i++) {
        if(rooms[i].capacity >= numGuests && rooms[i].currentGuests == 0) {
            return i;
        }
    }
    return -1;
}

// Function to add a guest to a room
void addGuest(Room *room, Guest guest) {
    room->guests[room->currentGuests] = guest;
    room->currentGuests++;
}

// Function to display all the guests in a room
void displayGuests(Room room) {
    int i;
    printf("Guests in Room %d:\n", room.roomNumber);
    for(i = 0; i < room.currentGuests; i++) {
        printf("%s (%d %c)\n", room.guests[i].name, room.guests[i].age, room.guests[i].gender);
    }
}

int main() {
    srand(time(0));
    Room rooms[MAX_ROOMS];
    initializeRooms(rooms);
    int choice = 0;
    while(choice != 3) {
        printf("1. Check-In\n");
        printf("2. Display Guests\n");
        printf("3. Exit\n");
        printf("Enter Your Choice: ");
        scanf("%d", &choice);
        switch(choice) {
            case 1: {
                printf("Enter Guest Details:\n");
                Guest guest;
                printf("Name: ");
                scanf("%s", guest.name);
                printf("Age: ");
                scanf("%d", &guest.age);
                printf("Gender (M/F): ");
                scanf(" %c", &guest.gender);
                int numGuests = 1;
                int roomIndex = findAvailableRoom(rooms, numGuests);
                if(roomIndex == -1) {
                    printf("Sorry, no available rooms.\n");
                }
                else {
                    addGuest(&rooms[roomIndex], guest);
                    printf("Room %d has been assigned to %s.\n", rooms[roomIndex].roomNumber, guest.name);
                }
                break;
            }
            case 2: {
                int i;
                for(i = 0; i < MAX_ROOMS; i++) {
                    if(rooms[i].currentGuests > 0) {
                        displayGuests(rooms[i]);
                    }
                }
                break;
            }
            case 3:
                printf("Thank you for choosing our hotel!\n");
                break;
            default:
                printf("Invalid Choice.\n");
        }
    }
    return 0;
}