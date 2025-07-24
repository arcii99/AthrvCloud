//FormAI DATASET v1.0 Category: Hotel Management System ; Style: Ada Lovelace
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ROOMS 20

struct guest {
    char name[100];
    int age;
    int room_number;
};

struct room {
    int number;
    int capacity;
    int is_vacant;
    struct guest current_guest;
};

struct hotel {
    char name[100];
    struct room rooms[MAX_ROOMS];
    int num_rooms;
};

void initialize_hotel(struct hotel* h, char* name) {
    int i;
    strcpy(h->name, name);
    h->num_rooms = MAX_ROOMS;
    for (i = 0; i < MAX_ROOMS; i++) {
        h->rooms[i].number = i + 1;
        h->rooms[i].capacity = 2;
        h->rooms[i].is_vacant = 1;
    }
}

int find_vacant_room(struct hotel* h) {
    int i;
    for (i = 0; i < h->num_rooms; i++) {
        if (h->rooms[i].is_vacant == 1) {
            return h->rooms[i].number;
        }
    }
    return -1;
}

int check_in(struct hotel* h, char* name, int age) {
    int room_number = find_vacant_room(h);
    if (room_number != -1) {
        h->rooms[room_number - 1].is_vacant = 0;
        strcpy(h->rooms[room_number - 1].current_guest.name, name);
        h->rooms[room_number - 1].current_guest.age = age;
        printf("%s has been checked in to room %d.\n", name, room_number);
        return 1;
    } else {
        printf("Sorry, no vacant rooms available at the moment.\n");
        return 0;
    }
}

int check_out(struct hotel* h, int room_number) {
    if (room_number > h->num_rooms || room_number < 1) {
        printf("Invalid room number.\n");
        return 0;
    } else if (h->rooms[room_number - 1].is_vacant == 1) {
        printf("Room %d is already vacant.\n", room_number);
        return 0;
    } else {
        printf("%s has checked out from room %d.\n", h->rooms[room_number - 1].current_guest.name, room_number);
        h->rooms[room_number - 1].is_vacant = 1;
        strcpy(h->rooms[room_number - 1].current_guest.name, "");
        h->rooms[room_number - 1].current_guest.age = 0;
        return 1;
    }
}

void print_room_status(struct hotel* h, int room_number) {
    if (room_number > h->num_rooms || room_number < 1) {
        printf("Invalid room number.\n");
    } else if (h->rooms[room_number - 1].is_vacant == 1) {
        printf("Room %d is vacant.\n", room_number);
    } else {
        printf("Room %d is occupied by %s (%d).\n", room_number, h->rooms[room_number - 1].current_guest.name, h->rooms[room_number - 1].current_guest.age);
    }
}

int main() {
    struct hotel h;
    int choice;
    char name[100];
    int age, room_number;

    initialize_hotel(&h, "Hotel Lovelace");

    printf("Welcome to %s!\n", h.name);

    do {
        printf("\n");
        printf("Menu:\n");
        printf("1. Check in a guest\n");
        printf("2. Check out a guest\n");
        printf("3. Print room status\n");
        printf("4. Exit program\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        printf("\n");

        switch (choice) {
            case 1:
                printf("Enter guest name: ");
                scanf("%s", name);
                printf("Enter guest age: ");
                scanf("%d", &age);
                check_in(&h, name, age);
                break;
            case 2:
                printf("Enter room number: ");
                scanf("%d", &room_number);
                check_out(&h, room_number);
                break;
            case 3:
                printf("Enter room number: ");
                scanf("%d", &room_number);
                print_room_status(&h, room_number);
                break;
            case 4:
                printf("Exiting program. Thank you for using %s!\n", h.name);
                break;
            default:
                printf("Invalid choice.\n");
        }
    } while (choice != 4);

    return 0;
}