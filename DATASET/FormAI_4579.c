//FormAI DATASET v1.0 Category: Hotel Management System ; Style: calm
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define MAX_ROOMS 100
#define MAX_GUESTS 200

// Placeholder structs for Rooms and Guests
typedef struct Room {
    int room_number;
    bool is_occupied;
    char guest_name[50];
} Room;

typedef struct Guest {
    char name[50];
    int age;
    char nationality[50];
} Guest;

// Function Prototypes
void display_menu(Room rooms[], int num_rooms);
void display_vacant_rooms(Room rooms[], int num_rooms);
void display_occupied_rooms(Room rooms[], int num_rooms);
void display_guest_list(Guest guests[], int num_guests);
void book_room(Room rooms[], int num_rooms, Guest guests[], int num_guests);
void checkout_room(Room rooms[], int num_rooms, Guest guests[], int num_guests);

int main() {
    // Initialize Rooms array
    Room rooms[MAX_ROOMS];
    for (int i = 0; i < MAX_ROOMS; i++) {
        rooms[i].room_number = i+1;
        rooms[i].is_occupied = false;
        strcpy(rooms[i].guest_name, "");
    }

    // Initialize Guests array
    Guest guests[MAX_GUESTS];
    int num_guests = 0;

    // Display Menu and get user choice
    int choice;
    do {
        display_menu(rooms, MAX_ROOMS);
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                display_vacant_rooms(rooms, MAX_ROOMS);
                break;
            case 2:
                display_occupied_rooms(rooms, MAX_ROOMS);
                break;
            case 3:
                display_guest_list(guests, num_guests);
                break;
            case 4:
                book_room(rooms, MAX_ROOMS, guests, num_guests);
                num_guests++;
                break;
            case 5:
                checkout_room(rooms, MAX_ROOMS, guests, num_guests);
                break;
            case 6:
                printf("Exiting Program...\n");
                break;
            default:
                printf("Invalid Choice. Please try again.\n");
                break;
        }
    } while (choice != 6);

    return 0;
}

// Function Definitions
void display_menu(Room rooms[], int num_rooms) {
    printf("\n\tWelcome to C Hotel Management System\n");
    printf("\t------------------------------------\n");
    printf("\t1. Display vacant rooms\n");
    printf("\t2. Display occupied rooms\n");
    printf("\t3. Display guest list\n");
    printf("\t4. Book a room\n");
    printf("\t5. Check out a room\n");
    printf("\t6. Exit\n");
    printf("\n\tPlease enter your choice: ");
}

void display_vacant_rooms(Room rooms[], int num_rooms) {
    printf("\n\tVacant Rooms\n");
    printf("\t-------------\n");

    for (int i = 0; i < num_rooms; i++) {
        if (!rooms[i].is_occupied) {
            printf("\tRoom Number: %d\n", rooms[i].room_number);
        }
    }
}

void display_occupied_rooms(Room rooms[], int num_rooms) {
    printf("\n\tOccupied Rooms\n");
    printf("\t---------------\n");

    for (int i = 0; i < num_rooms; i++) {
        if (rooms[i].is_occupied) {
            printf("\tRoom Number: %d\n", rooms[i].room_number);
            printf("\tGuest Name: %s\n", rooms[i].guest_name);
        }
    }
}

void display_guest_list(Guest guests[], int num_guests) {
    printf("\n\tGuest List\n");
    printf("\t----------\n");

    for (int i = 0; i < num_guests; i++) {
        printf("\tGuest Name: %s\n", guests[i].name);
        printf("\tAge: %d\n", guests[i].age);
        printf("\tNationality: %s\n", guests[i].nationality);
        printf("\n");
    }
}

void book_room(Room rooms[], int num_rooms, Guest guests[], int num_guests) {
    printf("\n\tBooking Room\n");
    printf("\t------------\n");

    // Get Guest Details
    printf("\tEnter Guest Name: ");
    scanf("%s", guests[num_guests].name);

    printf("\tEnter Guest Age: ");
    scanf("%d", &guests[num_guests].age);

    printf("\tEnter Guest Nationality: ");
    scanf("%s", guests[num_guests].nationality);

    // Display Vacant Rooms and get user choice
    int choice;
    do {
        display_vacant_rooms(rooms, num_rooms);
        printf("\tPlease choose a room number: ");
        scanf("%d", &choice);

        // Check if room is vacant
        if (!rooms[choice-1].is_occupied) {
            printf("\tRoom booked successfully!\n");

            // Update Room Status and Guest Name
            rooms[choice-1].is_occupied = true;
            strcpy(rooms[choice-1].guest_name, guests[num_guests].name);
        } else {
            printf("\tRoom is already occupied. Please choose another.\n");
        }
    } while (rooms[choice-1].is_occupied);
}

void checkout_room(Room rooms[], int num_rooms, Guest guests[], int num_guests) {
    printf("\n\tChecking Out Room\n");
    printf("\t-----------------\n");

    // Get Room Number to Checkout
    int room_num;
    printf("\tPlease enter room number to check out: ");
    scanf("%d", &room_num);

    // Check if Room Number is Valid
    if (room_num > num_rooms || room_num < 1) {
        printf("\tInvalid Room Number. Please try again.\n");
        return;
    }

    // Check if Room is Occupied
    if (!rooms[room_num-1].is_occupied) {
        printf("\tRoom is already vacant. No checkout necessary.\n");
    } else {
        // Display Guest Info and Check Out Room
        for (int i = 0; i < num_guests; i++) {
            if (strcmp(guests[i].name, rooms[room_num-1].guest_name) == 0) {
                printf("\tGuest Name: %s\n", guests[i].name);
                printf("\tAge: %d\n", guests[i].age);
                printf("\tNationality: %s\n", guests[i].nationality);

                // Check if Guest Wants to Make Another Booking
                char choice;
                printf("\tWould you like to make another booking? (y/n): ");
                scanf(" %c", &choice);
                if (choice == 'y') {
                    printf("\tRedirecting to Booking...\n");
                    rooms[room_num-1].is_occupied = false;
                    rooms[room_num-1].guest_name[0] = '\0';
                    return;
                } else {
                    printf("\tThank you for staying with us!\n");

                    // Clear Room Status and Guest Name
                    rooms[room_num-1].is_occupied = false;
                    rooms[room_num-1].guest_name[0] = '\0';
                    return;
                }
            }
        }

        // If Guest with Room Number does not exist
        printf("\tGuest does not exist in our database.\n");
    }
}