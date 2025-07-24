//FormAI DATASET v1.0 Category: Hotel Management System ; Style: genious
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define maximum capacity of the system
#define MAX_CAPACITY 100

// Define the structure for a guest
typedef struct {
    char name[50];
    char address[100];
    int room_number;
    int nights;
} Guest;

// Define the structure for a room
typedef struct {
    int room_number;
    int capacity;
    int occupied;
    float price_per_night;
} Room;

// Declare an array to store the guests
Guest guests[MAX_CAPACITY];

// Declare an array to store the rooms
Room rooms[MAX_CAPACITY];

// Declare the number of guests and rooms currently in the system
int num_guests = 0;
int num_rooms = 0;

// Add a guest to the system
void add_guest(char* name, char* address, int room_number, int nights) {
    // Create a new guest
    Guest new_guest;
    strncpy(new_guest.name, name, sizeof(name));
    strncpy(new_guest.address, address, sizeof(address));
    new_guest.room_number = room_number;
    new_guest.nights = nights;
    
    // Add the guest to the array
    guests[num_guests] = new_guest;
    num_guests++;
    
    // Mark the room as occupied
    for (int i = 0; i < num_rooms; i++) {
        if (rooms[i].room_number == room_number) {
            rooms[i].occupied = 1;
            break;
        }
    }
    
    printf("Guest added successfully!\n");
}

// Remove a guest from the system
void remove_guest(char* name) {
    // Find the guest to remove
    int found = 0;
    for (int i = 0; i < num_guests; i++) {
        if (strcmp(guests[i].name, name) == 0) {
            // Mark the room as unoccupied
            for (int j = 0; j < num_rooms; j++) {
                if (rooms[j].room_number == guests[i].room_number) {
                    rooms[j].occupied = 0;
                    break;
                }
            }
            
            // Remove the guest
            for (int k = i; k < num_guests - 1; k++) {
                guests[k] = guests[k + 1];
            }
            num_guests--;
            found = 1;
            break;
        }
    }
    
    if (found) {
        printf("Guest removed successfully!\n");
    } else {
        printf("Guest not found!\n");
    }
}

// Add a new room to the system
void add_room(int room_number, int capacity, float price_per_night) {
    // Create a new room
    Room new_room;
    new_room.room_number = room_number;
    new_room.capacity = capacity;
    new_room.occupied = 0;
    new_room.price_per_night = price_per_night;
    
    // Add the room to the array
    rooms[num_rooms] = new_room;
    num_rooms++;
    
    printf("Room added successfully!\n");
}

// Remove a room from the system
void remove_room(int room_number) {
    // Find the room to remove
    int found = 0;
    for (int i = 0; i < num_rooms; i++) {
        if (rooms[i].room_number == room_number) {
            // Remove the room
            for (int j = i; j < num_rooms - 1; j++) {
                rooms[j] = rooms[j + 1];
            }
            num_rooms--;
            found = 1;
            break;
        }
    }
    
    if (found) {
        printf("Room removed successfully!\n");
    } else {
        printf("Room not found!\n");
    }
}

// Print the list of guests
void list_guests() {
    printf("Guest List:\n");
    for (int i = 0; i < num_guests; i++) {
        printf("Name: %s\n", guests[i].name);
        printf("Address: %s\n", guests[i].address);
        printf("Room Number: %d\n", guests[i].room_number);
        printf("Nights: %d\n", guests[i].nights);
        printf("\n");
    }
}

// Print the list of available rooms
void list_available_rooms() {
    printf("Available Rooms:\n");
    for (int i = 0; i < num_rooms; i++) {
        if (!rooms[i].occupied) {
            printf("Room Number: %d\n", rooms[i].room_number);
            printf("Capacity: %d\n", rooms[i].capacity);
            printf("Price Per Night: $%.2f\n", rooms[i].price_per_night);
            printf("\n");
        }
    }
}

// Main function
int main() {
    // Add some initial rooms to the system
    add_room(101, 2, 59.99);
    add_room(102, 2, 59.99);
    add_room(103, 4, 99.99);
    add_room(104, 4, 99.99);
    
    // Test the system
    add_guest("John Doe", "123 Main St", 101, 2);
    add_guest("Jane Smith", "456 Oak Ave", 103, 3);
    list_guests();
    list_available_rooms();
    remove_guest("John Doe");
    remove_room(101);
    list_guests();
    list_available_rooms();
    
    return 0;
}