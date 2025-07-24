//FormAI DATASET v1.0 Category: Hotel Management System ; Style: complex
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ROOMS 100
#define MAX_NAME_LENGTH 50
#define MAX_CHECK_IN_TIME 6

// Define a struct to represent a guest
typedef struct {
    char name[MAX_NAME_LENGTH];
    int room_no;
    int check_in_time;
    int days_stay;
} Guest;

// Define a struct to represent a room
typedef struct {
    int room_no;
    int occupancy;
} Room;

// Declare global arrays to store guests and rooms
Guest guests[MAX_ROOMS];
Room rooms[MAX_ROOMS];

// Declare global variables to keep track of the number of guests and rooms
int num_guests = 0;
int num_rooms = 0;

// Function to check if a given room number is available
int is_room_available(int room_no) {
    for (int i = 0; i < num_rooms; i++) {
        if (rooms[i].room_no == room_no && rooms[i].occupancy == 0) {
            return 1;
        }
    }
    return 0;
}

// Function to check if a given name is already registered
int is_name_registered(char* name) {
    for (int i = 0; i < num_guests; i++) {
        if (strcmp(guests[i].name, name) == 0) {
            return 1;
        }
    }
    return 0;
}

// Function to add a new guest to the system
void add_guest() {
    char name[MAX_NAME_LENGTH];
    int room_no;
    int check_in_time;
    int days_stay;

    printf("\nEnter guest name: ");
    scanf("%s", name);
    if (is_name_registered(name)) {
        printf("\n%s is already registered in the system.\n", name);
        return;
    }

    printf("\nEnter room number: ");
    scanf("%d", &room_no);
    if (!is_room_available(room_no)) {
        printf("\nRoom number %d is not available.\n", room_no);
        return;
    }

    printf("\nEnter check-in time (24-hour format): ");
    scanf("%d", &check_in_time);
    if (check_in_time > MAX_CHECK_IN_TIME) {
        printf("\nCheck-in time cannot be later than %d:00.\n", MAX_CHECK_IN_TIME);
        return;
    }

    printf("\nEnter number of days to stay: ");
    scanf("%d", &days_stay);

    for (int i = 0; i < num_rooms; i++) {
        if (rooms[i].room_no == room_no) {
            rooms[i].occupancy = 1;
        }
    }

    guests[num_guests].room_no = room_no;
    guests[num_guests].check_in_time = check_in_time;
    guests[num_guests].days_stay = days_stay;
    strcpy(guests[num_guests].name, name);
    num_guests++;

    printf("\nGuest %s has been successfully added to the system!\n", name);
}

// Function to remove a guest from the system
void remove_guest() {
    char name[MAX_NAME_LENGTH];

    printf("\nEnter name of guest to be removed: ");
    scanf("%s", name);

    int guest_found = 0;
    for (int i = 0; i < num_guests; i++) {
        if (strcmp(guests[i].name, name) == 0) {
            for (int j = 0; j < num_rooms; j++) {
                if (rooms[j].room_no == guests[i].room_no) {
                    rooms[j].occupancy = 0;
                }
            }
            for (int j = i; j < num_guests - 1; j++) {
                guests[j] = guests[j + 1];
            }
            num_guests--;
            guest_found = 1;
            break;
        }
    }
    if (guest_found) {
        printf("\nGuest %s has been successfully removed from the system!\n", name);
    } else {
        printf("\nGuest %s is not registered in the system.\n", name);
    }
}

// Function to print out the list of guests in the system
void print_guest_list() {
    printf("\n List of Guests: \n");
    printf("Name \t Room Number \t Check-in time \t Days to stay \n");
    for (int i = 0; i < num_guests; i++) {
        printf("%s \t %d \t\t %d \t\t %d \n", guests[i].name, guests[i].room_no, guests[i].check_in_time, guests[i].days_stay);
    }
}

// Function to print out the list of available rooms in the system
void print_available_rooms() {
    printf("\n List of Available Rooms: \n");
    for (int i = 0; i < num_rooms; i++) {
        if (rooms[i].occupancy == 0) {
            printf("%d ", rooms[i].room_no);
        }
    }
    printf("\n");
}

int main() {
    // Initialize the rooms
    for (int i = 0; i < MAX_ROOMS; i++) {
        rooms[i].room_no = i + 1;
        rooms[i].occupancy = 0;
    }
    num_rooms = MAX_ROOMS;

    // Print the welcome message
    printf("Welcome to the Hotel Management System!\n");

    int choice;

    do {
        printf("\nMAIN MENU\n");
        printf("1. Add Guest\n");
        printf("2. Remove Guest\n");
        printf("3. View Guest List\n");
        printf("4. View Available Rooms\n");
        printf("5. Exit\n");

        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                add_guest();
                break;
            case 2:
                remove_guest();
                break;
            case 3:
                print_guest_list();
                break;
            case 4:
                print_available_rooms();
                break;
            case 5:
                exit(0);
            default:
                printf("\nInvalid choice. Please try again.\n");
        }
    } while (1);

    return 0;
}