//FormAI DATASET v1.0 Category: Hotel Management System ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#define MAX_NAME 50
#define MAX_GUESTS 10
#define ROOM_COUNT 20

struct Room {
    int number;
    int price;
    bool is_occupied;
    char guest_names[MAX_GUESTS][MAX_NAME];
    int num_of_guests;
};

struct Hotel {
    struct Room rooms[ROOM_COUNT];
};

void init_hotel(struct Hotel* hotel) {
    int room_number = 101, price = 50;
    for (int i = 0; i < ROOM_COUNT; ++i) {
        hotel->rooms[i].number = room_number++;
        hotel->rooms[i].price = price;
        hotel->rooms[i].is_occupied = false;
        hotel->rooms[i].num_of_guests = 0;
    }
}

void display_rooms(struct Hotel* hotel) {
    printf("ROOMS\n");
    printf("-----\n");
    for (int i = 0; i < ROOM_COUNT; ++i) {
        printf("%d. %s - $%d per night - %s\n", 
               hotel->rooms[i].number, 
               hotel->rooms[i].is_occupied ? "OCCUPIED" : "Available",
               hotel->rooms[i].price,
               hotel->rooms[i].is_occupied ? hotel->rooms[i].guest_names[0] : ""
              );
    }
    printf("\n");
}

bool is_valid_room_number(int room_number) {
    return room_number >= 101 && room_number <= 120;
}

void check_in(struct Hotel* hotel, int room_number, char* guest_name) {
    if (!is_valid_room_number(room_number)) {
        printf("Invalid room number %d. Room number should be between 101 and 120\n", room_number);
        return;
    }
    
    struct Room* room = &hotel->rooms[room_number - 101];
    if (room->is_occupied) {
        printf("%s is already staying in room %d\n", room->guest_names[0], room->number);
        return;
    }
    
    room->is_occupied = true;
    strcpy(room->guest_names[0], guest_name);
    room->num_of_guests = 1;
    
    printf("%s checked in to room %d\n", guest_name, room->number);
}

void add_guest_to_room(struct Hotel* hotel, int room_number, char* guest_name) {
    if (!is_valid_room_number(room_number)) {
        printf("Invalid room number %d. Room number should be between 101 and 120\n", room_number);
        return;
    }
    
    struct Room* room = &hotel->rooms[room_number - 101];
    if (!room->is_occupied) {
        printf("Room %d is not occupied\n", room->number);
        return;
    }
    
    if (room->num_of_guests >= MAX_GUESTS) {
        printf("Cannot add guest to room %d. Maximum number of guests reached\n", room->number);
        return;
    }
    
    strcpy(room->guest_names[room->num_of_guests++], guest_name);
    printf("%s added to room %d\n", guest_name, room->number);
}

void check_out(struct Hotel* hotel, int room_number) {
    if (!is_valid_room_number(room_number)) {
        printf("Invalid room number %d. Room number should be between 101 and 120\n", room_number);
        return;
    }
    
    struct Room* room = &hotel->rooms[room_number - 101];
    if (!room->is_occupied) {
        printf("Room %d is not occupied\n", room->number);
        return;
    }
    
    printf("Checking out %s from room %d\n", room->guest_names[0], room->number);
    room->is_occupied = false;
    room->num_of_guests = 0;
}

int main() {
    struct Hotel hotel;
    init_hotel(&hotel);
    
    display_rooms(&hotel);
    
    check_in(&hotel, 101, "John Doe");
    add_guest_to_room(&hotel, 101, "Jane Doe");
    add_guest_to_room(&hotel, 101, "Baby Doe");
    display_rooms(&hotel);
    
    check_in(&hotel, 102, "Smith");
    check_in(&hotel, 200, "Someone");
    display_rooms(&hotel);
    
    check_out(&hotel, 101);
    add_guest_to_room(&hotel, 101, "Emily Doe");
    display_rooms(&hotel);
    
    check_out(&hotel, 200);
    display_rooms(&hotel);
    
    return 0;
}