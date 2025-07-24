//FormAI DATASET v1.0 Category: Hotel Management System ; Style: active
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Constants
#define MAX_ROOMS 10
#define MAX_OCCUPANCY 4
#define MAX_NAME_LENGTH 20

// Structs
typedef struct {
    int room_number;
    char guest_names[MAX_OCCUPANCY][MAX_NAME_LENGTH];
    int occupancy;
    float rate;
} room;

typedef struct {
    int num_rooms;
    float total_revenue;
    room rooms[MAX_ROOMS];
} hotel;

// Function prototypes
void check_in(hotel *h);
void check_out(hotel *h);
void print_status(hotel *h);
void print_menu();
void clear_input_buffer();

// Helper functions
void clear_input_buffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF) { }
}

// Main function
int main() {
    // Initialize hotel
    hotel my_hotel;
    my_hotel.num_rooms = MAX_ROOMS;
    my_hotel.total_revenue = 0;
    for (int i = 0; i < MAX_ROOMS; i++) {
        my_hotel.rooms[i].room_number = i+1;
        my_hotel.rooms[i].occupancy = 0;
        my_hotel.rooms[i].rate = 100.0;
        for (int j = 0; j < MAX_OCCUPANCY; j++) {
            strcpy(my_hotel.rooms[i].guest_names[j], "");
        }
    }

    // Prompt user for action
    int action;
    do {
        print_menu();
        scanf("%d", &action);
        clear_input_buffer();

        switch (action) {
            case 1:
                check_in(&my_hotel);
                break;
            case 2:
                check_out(&my_hotel);
                break;
            case 3:
                print_status(&my_hotel);
                break;
            case 4:
                printf("Exiting program.\n");
                return 0;
            default:
                printf("Invalid input. Please try again.\n");
                break;
        }

    } while (action != 4);

    return 0;
}

// Function implementations
void check_in(hotel *h) {
    int room_num, num_guests;
    char guest_name[MAX_NAME_LENGTH];

    // Get room number and validate
    printf("Enter the room number: ");
    scanf("%d", &room_num);
    clear_input_buffer();
    if (room_num < 1 || room_num > h->num_rooms) {
        printf("Invalid room number. Please try again.\n");
        return;
    }

    // Get number of guests and validate
    printf("Enter the number of guests: ");
    scanf("%d", &num_guests);
    clear_input_buffer();
    if (num_guests < 1 || num_guests > MAX_OCCUPANCY) {
        printf("Invalid number of guests. Please try again.\n");
        return;
    }

    // Get guest names
    int i;
    for (i = 0; i < num_guests; i++) {
        printf("Enter the name of guest #%d: ", i+1);
        fgets(guest_name, MAX_NAME_LENGTH, stdin);
        guest_name[strlen(guest_name)-1] = 0; // remove newline character
        strcpy(h->rooms[room_num-1].guest_names[i], guest_name);
    }
    for (; i < MAX_OCCUPANCY; i++) {
        strcpy(h->rooms[room_num-1].guest_names[i], "");
    }

    // Update occupancy and revenue
    h->rooms[room_num-1].occupancy = num_guests;
    h->total_revenue += h->rooms[room_num-1].rate;

    printf("Check-in successful!\n");
}

void check_out(hotel *h) {
    int room_num;

    // Get room number and validate
    printf("Enter the room number: ");
    scanf("%d", &room_num);
    clear_input_buffer();
    if (room_num < 1 || room_num > h->num_rooms || h->rooms[room_num-1].occupancy == 0) {
        printf("Invalid room number or no guests in room. Please try again.\n");
        return;
    }

    // Print guest names and update occupancy
    printf("Guests in room %d:\n", room_num);
    for (int i = 0; i < h->rooms[room_num-1].occupancy; i++) {
        printf("%d. %s\n", i+1, h->rooms[room_num-1].guest_names[i]);
        strcpy(h->rooms[room_num-1].guest_names[i], "");
    }
    h->rooms[room_num-1].occupancy = 0;

    printf("Check-out successful!\n");
}

void print_status(hotel *h) {
    printf("Total number of rooms: %d\n", h->num_rooms);
    printf("Total revenue: $ %.2f\n", h->total_revenue);
    printf("Room status:\n");
    printf("--------------\n");
    printf("Room\tOccupancy\tGuest names\n");
    for (int i = 0; i < h->num_rooms; i++) {
        printf("%d\t%d/%d\t\t", h->rooms[i].room_number, h->rooms[i].occupancy, MAX_OCCUPANCY);
        if (h->rooms[i].occupancy == 0) {
            printf("N/A");
        } else {
            for (int j = 0; j < h->rooms[i].occupancy-1; j++) {
                printf("%s, ", h->rooms[i].guest_names[j]);
            }
            printf("%s", h->rooms[i].guest_names[h->rooms[i].occupancy-1]);
        }
        printf("\n");
    }
}

void print_menu() {
    printf("-----------------------------\n");
    printf("Welcome to the Hotel System!\n");
    printf("-----------------------------\n");
    printf("Please select an action:\n");
    printf("1. Check-in\n");
    printf("2. Check-out\n");
    printf("3. Print room status\n");
    printf("4. Quit\n");
    printf("> ");
}