//FormAI DATASET v1.0 Category: Hotel Management System ; Style: safe
// C Hotel Management System Example Program

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the maximum number of rooms and guests
#define MAX_ROOMS 10
#define MAX_GUESTS 4

// Define struct for each guest with their information
typedef struct {
    char name[30];
    int age;
    char address[50];
} Guest;

// Define struct for each room with its information
typedef struct {
    int number;
    int occupancy;
    Guest guests[MAX_GUESTS];
} Room;

// Define an array of Rooms with initial values
Room rooms[MAX_ROOMS] = {
    {101, 2},
    {102, 3},
    {103, 4},
    {104, 1},
    {105, 2},
    {106, 3},
    {107, 4},
    {108, 1},
    {109, 2},
    {110, 3}
};

// Define function to display all room information
void displayRooms() {
    printf("Room\tOccupancy\tGuest Name(s)\n");
    for (int i = 0; i < MAX_ROOMS; i++) {
        printf("%d\t%d\t\t", rooms[i].number, rooms[i].occupancy);
        for (int j = 0; j < rooms[i].occupancy; j++) {
            printf("%s ", rooms[i].guests[j].name);
        }
        printf("\n");
    }
}

// Define function to add a new guest to a room
void addGuest(int roomNumber, char* name, int age, char* address) {
    for (int i = 0; i < MAX_ROOMS; i++) {
        if (rooms[i].number == roomNumber) {
            for (int j = 0; j < MAX_GUESTS; j++) {
                if (rooms[i].guests[j].name[0] == '\0') {
                    strcpy(rooms[i].guests[j].name, name);
                    rooms[i].guests[j].age = age;
                    strcpy(rooms[i].guests[j].address, address);
                    rooms[i].occupancy++;
                    printf("Guest %s added to room %d.\n", name, roomNumber);
                    return;
                }
            }
            printf("Room %d is already at maximum occupancy.\n", roomNumber);
            return;
        }
    }
    printf("Room %d not found.\n", roomNumber);
}

// Define function to remove a guest from a room 
void removeGuest(int roomNumber, char* name) {
    for (int i = 0; i < MAX_ROOMS; i++) {
        if (rooms[i].number == roomNumber) {
            for (int j = 0; j < MAX_GUESTS; j++) {
                if (strcmp(rooms[i].guests[j].name, name) == 0) {
                    strcpy(rooms[i].guests[j].name, "");
                    rooms[i].guests[j].age = 0;
                    strcpy(rooms[i].guests[j].address, "");
                    rooms[i].occupancy--;
                    printf("Guest %s removed from room %d.\n", name, roomNumber);
                    return;
                }
            }
            printf("Guest %s not found in room %d.\n", name, roomNumber);
            return;
        }
    }
    printf("Room %d not found.\n", roomNumber);
}

// Define main function
int main() {
    // Display initial room information
    displayRooms();
    
    // Add new guests to a room
    addGuest(101, "John Smith", 25, "123 Main Street");
    addGuest(101, "Jane Doe", 21, "456 Green Avenue");
    addGuest(102, "Bob Johnson", 30, "789 Orange Boulevard");
    
    // Display room information after adding guests
    printf("\n");
    displayRooms();
    
    // Remove a guest from a room
    removeGuest(101, "John Smith");
    
    // Display room information after removing a guest
    printf("\n");
    displayRooms();
    
    return 0;
}