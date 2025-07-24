//FormAI DATASET v1.0 Category: Hotel Management System ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>

// Define the maximum number of hotel rooms
#define MAX_ROOMS 100

// Define the minimum and maximum number of guests per room
#define MIN_GUESTS 1
#define MAX_GUESTS 4

// Define the room structure
typedef struct room {
    int number;      // Room number
    int guests;      // Number of guests
    float cost;      // Cost of the room per night
    char occupied;   // Is the room occupied (1) or not (0)?
} Room;

// Define the hotel structure
typedef struct hotel {
    char name[50];        // Hotel name
    Room rooms[MAX_ROOMS];// Array of rooms
} Hotel;

// Define function prototypes
void init_hotel(Hotel *h, char *name);
void add_room(Hotel *h, int number, int guests, float cost);
void list_rooms(Hotel *h);
void book_room(Hotel *h, int room_number);
void unbook_room(Hotel *h, int room_number);
int total_cost(Hotel *h);

// The main function
int main() {
    // Initialize a new hotel
    Hotel h;
    init_hotel(&h, "Mathematical Hotel");

    // Add some rooms to the hotel
    add_room(&h, 101, 2, 100.0);
    add_room(&h, 102, 3, 150.0);
    add_room(&h, 103, 1, 75.0);
    add_room(&h, 201, 4, 200.0);
    add_room(&h, 202, 2, 100.0);

    // Print the list of available rooms
    printf("Available rooms at the %s:\n", h.name);
    list_rooms(&h);

    // Book a room
    book_room(&h, 101);
    book_room(&h, 201);

    // Print the list of available rooms again
    printf("Available rooms at the %s:\n", h.name);
    list_rooms(&h);

    // Unbook a room
    unbook_room(&h, 101);

    // Calculate the total cost of the occupied rooms
    int total = total_cost(&h);
    printf("Total cost of occupied rooms: %d\n", total);

    return 0;
}

// Initialize the hotel
void init_hotel(Hotel *h, char *name) {
    // Set the hotel name
    strcpy(h->name, name);

    // Set all rooms to unoccupied
    for (int i = 0; i < MAX_ROOMS; i++) {
        h->rooms[i].occupied = 0;
    }
}

// Add a new room to the hotel
void add_room(Hotel *h, int number, int guests, float cost) {
    // Find the first available slot in the room array
    int i;
    for (i = 0; i < MAX_ROOMS; i++) {
        if (!h->rooms[i].occupied) {
            break;
        }
    }

    // Set the room properties
    h->rooms[i].number = number;
    h->rooms[i].guests = guests;
    h->rooms[i].cost = cost;
    h->rooms[i].occupied = 0;
}

// Print the list of available rooms
void list_rooms(Hotel *h) {
    for (int i = 0; i < MAX_ROOMS; i++) {
        if (!h->rooms[i].occupied) {
            printf("Room %d: %d guests, $%.2f/night\n",
                   h->rooms[i].number, h->rooms[i].guests, h->rooms[i].cost);
        }
    }
}

// Book a room
void book_room(Hotel *h, int room_number) {
    for (int i = 0; i < MAX_ROOMS; i++) {
        if (h->rooms[i].number == room_number) {
            h->rooms[i].occupied = 1;
            printf("Room %d has been booked.\n", room_number);
            return;
        }
    }

    printf("Sorry, room %d is not available.\n", room_number);
}

// Unbook a room
void unbook_room(Hotel *h, int room_number) {
    for (int i = 0; i < MAX_ROOMS; i++) {
        if (h->rooms[i].number == room_number) {
            h->rooms[i].occupied = 0;
            printf("Room %d has been unbooked.\n", room_number);
            return;
        }
    }

    printf("Invalid room number.\n");
}

// Calculate the total cost of the occupied rooms
int total_cost(Hotel *h) {
    int total = 0;

    for (int i = 0; i < MAX_ROOMS; i++) {
        if (h->rooms[i].occupied) {
            total += h->rooms[i].cost;
        }
    }

    return total;
}