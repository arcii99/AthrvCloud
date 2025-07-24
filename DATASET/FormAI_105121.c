//FormAI DATASET v1.0 Category: Hotel Management System ; Style: systematic
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Structure for each room
typedef struct {
    int room_number;
    bool is_vacant;
    int price;
    bool has_tv;
    bool has_air_conditioning;
} Room;

// Structure for the hotel
typedef struct {
    Room rooms[10]; // A hotel with 10 rooms
    int num_of_guests;
    int total_revenue;
} Hotel;

// Initialises the hotel with empty rooms
void init_hotel(Hotel* hotel) {
    for (int i=0; i<10; i++) {
        hotel->rooms[i].room_number = i + 1;
        hotel->rooms[i].is_vacant = true;
        hotel->rooms[i].price = 100;
        hotel->rooms[i].has_tv = false;
        hotel->rooms[i].has_air_conditioning = false;
    }
    hotel->num_of_guests = 0;
    hotel->total_revenue = 0;
}

// Checks if a room is vacant
bool is_vacant(Room room) {
    return room.is_vacant;
}

// Books a room
void book_room(Room* room) {
    room->is_vacant = false;
}

// Unbooks a room
void unbook_room(Room* room) {
   room->is_vacant = true;
}

// Calculates the revenue from a room
int calculate_revenue(Room room) {
    int revenue = room.price;
    if (room.has_tv) {
        revenue += 10;
    }
    if (room.has_air_conditioning) {
        revenue += 20;
    }
    return revenue;
}

// Calculates the revenue for the entire hotel
int calculate_total_revenue(Hotel hotel) {
    int total_revenue = 0;
    for (int i=0; i<10; i++) {
        if (!hotel.rooms[i].is_vacant) {
            total_revenue += calculate_revenue(hotel.rooms[i]);
        }
    }
    return total_revenue;
}

// Adds a guest to the hotel
void add_guest(Hotel* hotel) {
    hotel->num_of_guests++;
}

// Removes a guest from the hotel
void remove_guest(Hotel* hotel) {
    if (hotel->num_of_guests > 0) {
        hotel->num_of_guests--;
    }
}

// Prints the current occupancy of the hotel
void print_occupancy(Hotel hotel) {
    int num_of_vacant_rooms = 0;
    int num_of_occupied_rooms = 0;
    for (int i=0; i<10; i++) {
        if (hotel.rooms[i].is_vacant) {
            num_of_vacant_rooms++;
        } else {
            num_of_occupied_rooms++;
        }
    }
    printf("There are %d vacant rooms and %d occupied rooms\n", num_of_vacant_rooms, num_of_occupied_rooms);
}

int main() {
    Hotel hotel;
    init_hotel(&hotel);

    // Book a room and add a guest
    printf("Booking room 3...\n");
    book_room(&hotel.rooms[2]);
    add_guest(&hotel);
    printf("Number of guests: %d\n", hotel.num_of_guests);
    printf("Occupancy:\n");
    print_occupancy(hotel);
    printf("Total revenue: $%d\n", calculate_total_revenue(hotel));

    // Book another room and add another guest
    printf("Booking room 5...\n");
    book_room(&hotel.rooms[4]);
    add_guest(&hotel);
    printf("Number of guests: %d\n", hotel.num_of_guests);
    printf("Occupancy:\n");
    print_occupancy(hotel);
    printf("Total revenue: $%d\n", calculate_total_revenue(hotel));

    // Unbook the first room and remove a guest
    printf("Un-booking room 3...\n");
    unbook_room(&hotel.rooms[2]);
    remove_guest(&hotel);
    printf("Number of guests: %d\n", hotel.num_of_guests);
    printf("Occupancy:\n");
    print_occupancy(hotel);
    printf("Total revenue: $%d\n", calculate_total_revenue(hotel));

    return 0;
}