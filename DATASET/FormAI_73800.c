//FormAI DATASET v1.0 Category: Hotel Management System ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ROOMS 100

typedef struct {
    int room_number;
    char guest_name[50];
    char guest_contact[20];
    int is_occupied;
} Room;

Room hotel_rooms[MAX_ROOMS];

// Initializes all the hotel rooms as unoccupied
void initialize_rooms() {
    for (int i = 0; i < MAX_ROOMS; i++) {
        hotel_rooms[i].room_number = i + 1;
        hotel_rooms[i].is_occupied = 0;
    }
}

// Checks if a room number is valid (between 1 and MAX_ROOMS)
int is_valid_room_number(int room_number) {
    return (room_number >= 1 && room_number <= MAX_ROOMS);
}

// Checks if a room is occupied
int is_room_occupied(int room_number) {
    return hotel_rooms[room_number - 1].is_occupied;
}

// Books a room for a guest
void book_room(int room_number, char* guest_name, char* guest_contact) {
    if (!is_valid_room_number(room_number)) {
        printf("Invalid room number\n");
    } else if (is_room_occupied(room_number)) {
        printf("Room is already occupied\n");
    } else {
        hotel_rooms[room_number - 1].is_occupied = 1;
        strcpy(hotel_rooms[room_number - 1].guest_name, guest_name);
        strcpy(hotel_rooms[room_number - 1].guest_contact, guest_contact);
        printf("Room %d has been booked for %s (%s)\n", room_number, guest_name, guest_contact);
    }
}

// Unbooks a room
void unbook_room(int room_number) {
    if (!is_valid_room_number(room_number)) {
        printf("Invalid room number\n");
    } else if (!is_room_occupied(room_number)) {
        printf("Room is already unoccupied\n");
    } else {
        hotel_rooms[room_number - 1].is_occupied = 0;
        memset(hotel_rooms[room_number - 1].guest_name, 0, sizeof(hotel_rooms[room_number - 1].guest_name));
        memset(hotel_rooms[room_number - 1].guest_contact, 0, sizeof(hotel_rooms[room_number - 1].guest_contact));
        printf("Room %d has been unbooked\n", room_number);
    }
}

// Lists all the hotel rooms and their status
void list_rooms() {
    printf("Room\tGuest Name\tGuest Contact\tOccupied\n");
    for (int i = 0; i < MAX_ROOMS; i++) {
        printf("%d\t%s\t%s\t%d\n", hotel_rooms[i].room_number, 
                                    hotel_rooms[i].guest_name,
                                    hotel_rooms[i].guest_contact,
                                    hotel_rooms[i].is_occupied);
    }
}

int main() {
    initialize_rooms();
    int choice = 0;
    while (choice != 5) {
        printf("Choose an option:\n");
        printf("1. Book a room\n");
        printf("2. Unbook a room\n");
        printf("3. List all rooms\n");
        printf("4. Exit\n");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                printf("Enter room number: ");
                int room_number;
                scanf("%d", &room_number);
                printf("Enter guest name: ");
                char guest_name[50];
                scanf("%s", guest_name);
                printf("Enter guest contact: ");
                char guest_contact[20];
                scanf("%s", guest_contact);
                book_room(room_number, guest_name, guest_contact);
                break;
            case 2:
                printf("Enter room number: ");
                scanf("%d", &room_number);
                unbook_room(room_number);
                break;
            case 3:
                list_rooms();
                break;
            case 4:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice\n");
                break;
        }
    }
    return 0;
}