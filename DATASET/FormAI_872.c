//FormAI DATASET v1.0 Category: Hotel Management System ; Style: Donald Knuth
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_GUESTS 1000
#define MAX_ROOMS 100

typedef struct {
    int room_number;
    int occupancy;
    char guest_name[100];
} Room;

Room rooms[MAX_ROOMS];
int num_rooms = 0;

void add_room(int room_number) {
    if (num_rooms >= MAX_ROOMS) {
        printf("Unable to add room - maximum number of rooms reached\n");
        return;
    }
    rooms[num_rooms].room_number = room_number;
    rooms[num_rooms].occupancy = 0;
    num_rooms++;
}

void add_guest(int room_number, char *guest_name) {
    int i;
    for (i = 0; i < num_rooms; i++) {
        if (rooms[i].room_number == room_number) {
            if (rooms[i].occupancy != 0) {
                printf("Unable to add guest - room already occupied\n");
                return;
            }
            rooms[i].occupancy = 1;
            strcpy(rooms[i].guest_name, guest_name);
            printf("Guest %s added to room %d\n", guest_name, room_number);
            return;
        }
    }
    printf("Unable to add guest - room not found\n");
}

void remove_guest(int room_number) {
    int i;
    for (i = 0; i < num_rooms; i++) {
        if (rooms[i].room_number == room_number) {
            if (rooms[i].occupancy == 0) {
                printf("Unable to remove guest - room already unoccupied\n");
                return;
            }
            printf("Guest %s removed from room %d\n", rooms[i].guest_name, room_number);
            rooms[i].occupancy = 0;
            strcpy(rooms[i].guest_name, "");
            return;
        }
    }
    printf("Unable to remove guest - room not found\n");
}

void print_guests(void) {
    int i;
    printf("Room Number\tGuest Name\n");
    for (i = 0; i < num_rooms; i++) {
        printf("%d\t\t%s\n", rooms[i].room_number, rooms[i].guest_name);
    }
}

int main(void) {
    add_room(101);
    add_room(102);
    add_room(103);

    add_guest(101, "Alice");
    add_guest(103, "Bob");
    add_guest(102, "Charlie");
    add_guest(101, "Dave");

    remove_guest(103);
    add_guest(102, "Eve");

    print_guests();

    return 0;
}