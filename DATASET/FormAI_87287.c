//FormAI DATASET v1.0 Category: Hotel Management System ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* Define a struct for the hotel room */
typedef struct {
    int room_number;
    char type[20];
    float price;
    int occupied;
} Room;

/* Define a struct for the hotel guest */
typedef struct {
    char name[50];
    char address[100];
    char phone_number[20];
    int room_number;
} Guest;

/* Define global constants for available room types and prices */
const char* ROOM_TYPES[] = {"Single", "Double", "Suite"};
const float ROOM_PRICES[] = {50.0, 75.0, 100.0};
const int NUM_ROOM_TYPES = 3;

/* Declare functions */
void init_rooms(Room rooms[], int num_rooms);
void view_available_rooms(Room rooms[], int num_rooms);
void check_in(Guest* guest, Room rooms[], int num_rooms);
void check_out(Guest* guest, Room rooms[], int num_rooms);

/* Main function */
int main() {
    int num_rooms = 10;  /* number of hotel rooms */
    Room rooms[num_rooms];
    init_rooms(rooms, num_rooms);

    int choice;
    Guest guest;

    /* Loop through program until user chooses to exit */
    while (1) {
        printf("\nWelcome to the Hotel Management System!\n");
        printf("1. View available rooms\n");
        printf("2. Check in a guest\n");
        printf("3. Check out a guest\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                view_available_rooms(rooms, num_rooms);
                break;
            case 2:
                check_in(&guest, rooms, num_rooms);
                break;
            case 3:
                check_out(&guest, rooms, num_rooms);
                break;
            case 4:
                exit(0);
            default:
                printf("Invalid choice\n");
        }
    }

    return 0;
}

/* Initialize hotel rooms */
void init_rooms(Room rooms[], int num_rooms) {
    int i;
    for (i = 0; i < num_rooms; i++) {
        rooms[i].room_number = i + 1;
        strcpy(rooms[i].type, ROOM_TYPES[i % NUM_ROOM_TYPES]);
        rooms[i].price = ROOM_PRICES[i % NUM_ROOM_TYPES];
        rooms[i].occupied = 0;
    }
}

/* View available rooms */
void view_available_rooms(Room rooms[], int num_rooms) {
    int i, count = 0;
    printf("\nList of available rooms:\n");
    printf("Room No.\t Type\t\t Price\n");
    for (i = 0; i < num_rooms; i++) {
        if (!rooms[i].occupied) {
            count++;
            printf("%d\t\t %s\t $%.2f\n", rooms[i].room_number, rooms[i].type, rooms[i].price);
        }
    }
    if (!count) {
        printf("Sorry, no rooms are available at this time.\n");
    }
}

/* Check in a guest */
void check_in(Guest* guest, Room rooms[], int num_rooms) {
    char temp[20];
    int room_num, i;

    printf("\nEnter guest details:\n");
    printf("Name: ");
    getchar();  /* remove newline from input buffer */
    fgets(guest->name, sizeof(guest->name), stdin);
    guest->name[strcspn(guest->name, "\n")] = '\0';  /* remove trailing newline */
    printf("Address: ");
    fgets(guest->address, sizeof(guest->address), stdin);
    guest->address[strcspn(guest->address, "\n")] = '\0';  /* remove trailing newline */
    printf("Phone number: ");
    fgets(guest->phone_number, sizeof(guest->phone_number), stdin);
    guest->phone_number[strcspn(guest->phone_number, "\n")] = '\0';  /* remove trailing newline */

    printf("\nEnter room number to check in (0 to cancel): ");
    scanf("%d", &room_num);
    if (room_num == 0) {
        return;
    }

    /* Find the room and mark it as occupied */
    for (i = 0; i < num_rooms; i++) {
        if (rooms[i].room_number == room_num) {
            if (rooms[i].occupied) {
                printf("The room is already occupied. Please choose a different room.\n");
                return;
            }
            rooms[i].occupied = 1;
            guest->room_number = room_num;
            printf("Room checked in successfully.\n");
            return;
        }
    }

    /* Room number not found */
    printf("Room number not found. Please try again.\n");
}

/* Check out a guest */
void check_out(Guest* guest, Room rooms[], int num_rooms) {
    int i;

    printf("\nEnter room number to check out (0 to cancel): ");
    scanf("%d", &guest->room_number);
    if (guest->room_number == 0) {
        return;
    }

    /* Find the room and mark it as unoccupied */
    for (i = 0; i < num_rooms; i++) {
        if (rooms[i].room_number == guest->room_number) {
            if (!rooms[i].occupied) {
                printf("The room is not occupied. Please enter a valid room number.\n");
                return;
            }
            rooms[i].occupied = 0;
            printf("Guest checked out successfully.\n");
            return;
        }
    }

    /* Room number not found */
    printf("Room number not found. Please try again.\n");
}