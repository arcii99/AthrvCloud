//FormAI DATASET v1.0 Category: Hotel Management System ; Style: introspective
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_GUESTS 1000

struct hotel_room {
    int room_number;
    int num_guests;
    char guest_name[50][50];
    int occupied;
    int room_price;
};

void initialize(struct hotel_room* rooms, int num_of_rooms) {
    int i;

    for (i = 0; i < num_of_rooms; i++) {
        rooms[i].room_number = i + 1;
        rooms[i].occupied = 0;
        rooms[i].num_guests = 0;
        rooms[i].room_price = 50; // price in dollars
    }
}

void print_menu() {
    printf("\n==============================");
    printf("\n HOTEL MANAGEMENT SYSTEM MENU ");
    printf("\n==============================\n");
    printf("1. View all rooms\n");
    printf("2. Search for guest\n");
    printf("3. Check in a guest\n");
    printf("4. Check out a guest\n");
    printf("5. Exit\n");
    printf("\nEnter choice: ");
}

void view_all_rooms(struct hotel_room* rooms, int num_of_rooms) {
    int i;

    printf("Room Number\tOccupied\tGuest Name(s)\n");

    for (i = 0; i < num_of_rooms; i++) {
        printf("%d\t\t", rooms[i].room_number);

        if (rooms[i].occupied) {
            printf("Yes\t\t");

            for (int j = 0; j < rooms[i].num_guests; j++) {
                printf("%s, ", rooms[i].guest_name[j]);
            }
        }
        else {
            printf("No");
        }

        printf("\n");
    }
}

int search_guest(struct hotel_room* rooms, int num_of_rooms, char* guest_name) {
    int i, j;

    for (i = 0; i < num_of_rooms; i++) {
        if (rooms[i].occupied) {
            for (j = 0; j < rooms[i].num_guests; j++) {
                if (strcmp(rooms[i].guest_name[j], guest_name) == 0) {
                    printf("%s is in room %d\n", guest_name, rooms[i].room_number);
                    return 1;
                }
            }
        }
    }

    printf("Guest not found\n");
    return 0;
}

void check_in_guest(struct hotel_room* rooms, int num_of_rooms) {
    int i, j;
    char guest[50];

    printf("\nEnter guest name: ");
    scanf("%s", guest);

    for (i = 0; i < num_of_rooms; i++) {
        if (!rooms[i].occupied) {
            strcpy(rooms[i].guest_name[0], guest);
            rooms[i].num_guests = 1;

            printf("Successfully checked in %s to room %d\n", guest, rooms[i].room_number);
            rooms[i].occupied = 1;
            return;
        }
    }

    printf("No available rooms\n");
}

void check_out_guest(struct hotel_room* rooms, int num_of_rooms, char* guest_name) {
    int i, j;

    for (i = 0; i < num_of_rooms; i++) {
        if (rooms[i].occupied) {
            for (j = 0; j < rooms[i].num_guests; j++) {
                if (strcmp(rooms[i].guest_name[j], guest_name) == 0) {
                    printf("%s checked out of room %d\n", guest_name, rooms[i].room_number);
                    rooms[i].occupied = 0;
                    rooms[i].num_guests = 0;
                    strcpy(rooms[i].guest_name[0], "");
                    return;
                }
            }
        }
    }

    printf("Guest not found\n");
}

int main() {
    struct hotel_room rooms[MAX_GUESTS];
    int num_of_rooms = 10;
    char guest_name[50];
    int choice;

    initialize(rooms, num_of_rooms);

    do {
        print_menu();
        scanf("%d", &choice);

        switch (choice) {
        case 1:
            view_all_rooms(rooms, num_of_rooms);
            break;
        case 2:
            printf("\nEnter guest name: ");
            scanf("%s", guest_name);
            search_guest(rooms, num_of_rooms, guest_name);
            break;
        case 3:
            check_in_guest(rooms, num_of_rooms);
            break;
        case 4:
            printf("\nEnter guest name: ");
            scanf("%s", guest_name);
            check_out_guest(rooms, num_of_rooms, guest_name);
            break;
        case 5:
            printf("\nExiting...\n");
            break;
        default:
            printf("\nInvalid choice\n");
        }
    } while (choice != 5);

    return 0;
}