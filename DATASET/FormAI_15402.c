//FormAI DATASET v1.0 Category: Hotel Management System ; Style: brave
#include <stdio.h>
#include <stdlib.h>

#define MAX_ROOMS 50 // Maximum number of rooms in the hotel
#define MAX_NAME_LENGTH 50 // Maximum length of a guest's name

// Struct to represent a guest
typedef struct guest {
    char name[MAX_NAME_LENGTH];
    int room_number;
} Guest;

// Struct to represent a room in the hotel
typedef struct room {
    int number;
    Guest *guest;
} Room;

// Struct to represent the hotel
typedef struct hotel {
    int num_rooms;
    Room rooms[MAX_ROOMS];
} Hotel;

// Function to check if a room is empty
int is_room_empty(Room r) {
    return r.guest == NULL;
}

// Function to check if a guest is already checked in
int is_guest_checked_in(Hotel h, char *name) {
    for (int i = 0; i < h.num_rooms; i++) {
        if (h.rooms[i].guest != NULL && strcmp(h.rooms[i].guest->name, name) == 0) {
            return 1;
        }
    }
    return 0;
}

// Function to check a guest into a room
void check_in_guest(Hotel *h, char *name, int room_num) {
    if (room_num < 1 || room_num > h->num_rooms) {
        printf("Invalid room number\n");
        return;
    }
    if (!is_room_empty(h->rooms[room_num-1])) {
        printf("Room is already occupied\n");
        return;
    }
    if (is_guest_checked_in(*h, name)) {
        printf("%s is already checked in\n", name);
        return;
    }
    Guest *g = malloc(sizeof(Guest));
    strncpy(g->name, name, MAX_NAME_LENGTH);
    g->room_number = room_num;
    h->rooms[room_num-1].guest = g;
    printf("%s has been checked into room %d\n", name, room_num);
}

// Function to check a guest out of a room
void check_out_guest(Hotel *h, char *name) {
    for (int i = 0; i < h->num_rooms; i++) {
        if (h->rooms[i].guest != NULL && strcmp(h->rooms[i].guest->name, name) == 0) {
            free(h->rooms[i].guest);
            h->rooms[i].guest = NULL;
            printf("%s has been checked out of room %d\n", name, i+1);
            return;
        }
    }
    printf("%s is not currently checked in\n", name);
}

// Function to print the current status of the hotel
void print_hotel_status(Hotel h) {
    printf("Current hotel status:\n");
    for (int i = 0; i < h.num_rooms; i++) {
        printf("Room %d: ", i+1);
        if (is_room_empty(h.rooms[i])) {
            printf("Empty\n");
        } else {
            printf("Occupied by %s\n", h.rooms[i].guest->name);
        }
    }
}

int main() {
    Hotel h;
    h.num_rooms = 5;

    // Initialize the hotel with empty rooms
    for (int i = 0; i < h.num_rooms; i++) {
        h.rooms[i].number = i+1;
        h.rooms[i].guest = NULL;
    }

    printf("Welcome to the Brave Hotel Management System!\n");
    
    int choice = 0;
    char name[MAX_NAME_LENGTH];
    int room_num;

    do {
        printf("\nWhat would you like to do?\n");
        printf("1. Check in a guest\n");
        printf("2. Check out a guest\n");
        printf("3. Print current status\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter guest name: ");
                scanf("%s", name);
                printf("Enter room number: ");
                scanf("%d", &room_num);
                check_in_guest(&h, name, room_num);
                break;
            case 2:
                printf("Enter guest name: ");
                scanf("%s", name);
                check_out_guest(&h, name);
                break;
            case 3:
                print_hotel_status(h);
                break;
            case 4:
                printf("Exiting program...\n");
                break;
            default:
                printf("Invalid choice\n");
                break;
        }
    } while (choice != 4);

    return 0;
}