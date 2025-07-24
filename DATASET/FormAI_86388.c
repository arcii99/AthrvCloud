//FormAI DATASET v1.0 Category: Hotel Management System ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ROOMS 200
#define MAX_NAME_LENGTH 30

// Room struct to hold room details
typedef struct Room {
    int room_number;
    char guest_name[MAX_NAME_LENGTH];
    int is_occupied;
} Room;

// Function to display menu options
void display_menu() {
    printf("Welcome to C Hotel Management System\n");
    printf("------------------------------------\n");
    printf("1. View all rooms\n");
    printf("2. Book a room\n");
    printf("3. Check out of a room\n");
    printf("4. Exit\n");
    printf("------------------------------------\n");
}

// Function to initialize all rooms to empty
void initialize_rooms(Room rooms[], int num_rooms) {
    for (int i = 0; i < num_rooms; i++) {
        rooms[i].room_number = i + 1;
        rooms[i].is_occupied = 0;
        memset(rooms[i].guest_name, 0, MAX_NAME_LENGTH);
    }
}

// Function to display all rooms and their occupancy status
void display_all_rooms(Room rooms[], int num_rooms) {
    printf("Room Number\tGuest Name\tOccupied\n");
    for (int i = 0; i < num_rooms; i++) {
        printf("%d\t\t", rooms[i].room_number);
        if (rooms[i].is_occupied) {
            printf("%s\t\t", rooms[i].guest_name);
            printf("Yes\n");
        } else {
            printf("--------\t");
            printf("No\n");
        }
    }
}

// Function to check if a room is available and book it
void book_room(Room rooms[], int num_rooms) {
    int room_number;
    printf("Enter the room number you want to book: ");
    scanf("%d", &room_number);
    if (room_number < 1 || room_number > num_rooms) {
        printf("Invalid room number\n");
        return;
    }
    if (rooms[room_number - 1].is_occupied) {
        printf("Room is already occupied\n");
        return;
    }
    printf("Enter your name: ");
    scanf("%s", rooms[room_number - 1].guest_name);
    rooms[room_number - 1].is_occupied = 1;
    printf("Room booked successfully\n");
}

// Function to check out of a room and mark it as empty
void check_out(Room rooms[], int num_rooms) {
    int room_number;
    printf("Enter the room number you want to check out of: ");
    scanf("%d", &room_number);
    if (room_number < 1 || room_number > num_rooms) {
        printf("Invalid room number\n");
        return;
    }
    if (!rooms[room_number - 1].is_occupied) {
        printf("Room is not occupied\n");
        return;
    }
    memset(rooms[room_number - 1].guest_name, 0, MAX_NAME_LENGTH);
    rooms[room_number - 1].is_occupied = 0;
    printf("Checked out successfully\n");
}

int main() {
    int choice;
    int num_rooms = MAX_ROOMS;
    Room rooms[MAX_ROOMS];
    initialize_rooms(rooms, num_rooms);

    do {
        display_menu();
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                display_all_rooms(rooms, num_rooms);
                break;
            case 2:
                book_room(rooms, num_rooms);
                break;
            case 3:
                check_out(rooms, num_rooms);
                break;
            case 4:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice\n");
        }
    } while (choice != 4);

    return 0;
}