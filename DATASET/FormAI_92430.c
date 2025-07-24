//FormAI DATASET v1.0 Category: Hotel Management System ; Style: visionary
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Create a structure for holding hotel information
typedef struct {
    char name[50];
    int number_of_rooms;
    float price_per_night;
} Hotel;

// Create a structure for holding guest information
typedef struct {
    char name[50];
    int room_number;
    float total_bill;
} Guest;

// Create an array of hotel rooms
int rooms[100];

// Initialize all rooms to be available
void initialize_rooms() {
    int i;
    for (i = 0; i < 100; i++) {
        rooms[i] = 0;
    }
}

// Display the main menu
void display_main_menu() {
    printf("1. View available rooms\n");
    printf("2. Book a room\n");
    printf("3. View guest information\n");
    printf("4. Check out guest\n");
    printf("5. Exit\n");
    printf("Please enter your choice: ");
}

// Display the available rooms menu
void display_available_rooms(Hotel hotels[], int num_hotels) {
    int i, j;
    printf("Available Rooms\n");
    for (i = 0; i < num_hotels; i++) {
        printf("%s\n", hotels[i].name);
        for (j = 0; j < hotels[i].number_of_rooms; j++) {
            if (rooms[j] == 0) {
                printf("Room %d\n", j + 1);
            }
        }
        printf("\n");
    }
}

// Book a room for a guest
void book_room(Hotel hotels[], int num_hotels, Guest guests[], int *num_guests) {
    char hotel_name[50];
    int room_number;
    int hotel_index = -1;
    int i, j;
    printf("Please enter the name of the hotel: ");
    scanf("%s", hotel_name);
    for (i = 0; i < num_hotels; i++) {
        if (strcmp(hotels[i].name, hotel_name) == 0) {
            hotel_index = i;
            break;
        }
    }
    if (hotel_index == -1) {
        printf("Invalid hotel name\n");
        return;
    }
    printf("Please enter the room number: ");
    scanf("%d", &room_number);
    if (room_number < 1 || room_number > hotels[hotel_index].number_of_rooms) {
        printf("Invalid room number\n");
        return;
    }
    if (rooms[room_number - 1] == 1) {
        printf("Room is already booked\n");
        return;
    }
    rooms[room_number - 1] = 1;
    guests[*num_guests].room_number = room_number;
    guests[*num_guests].total_bill = hotels[hotel_index].price_per_night;
    printf("Please enter your name: ");
    scanf("%s", guests[*num_guests].name);
    printf("Booking successful\n");
    (*num_guests)++;
}

// Display guest information
void display_guest_info(Guest guests[], int num_guests) {
    int i;
    for (i = 0; i < num_guests; i++) {
        printf("Name: %s\n", guests[i].name);
        printf("Room Number: %d\n", guests[i].room_number);
        printf("Total Bill: %.2f\n", guests[i].total_bill);
        printf("\n");
    }
}

// Check out a guest and print the final bill
void check_out_guest(Guest guests[], int *num_guests) {
    int room_number;
    int guest_index = -1;
    int i;
    float total_bill;
    printf("Please enter the room number of the guest: ");
    scanf("%d", &room_number);
    for (i = 0; i < *num_guests; i++) {
        if (guests[i].room_number == room_number) {
            guest_index = i;
            break;
        }
    }
    if (guest_index == -1) {
        printf("Guest not found\n");
        return;
    }
    total_bill = guests[guest_index].total_bill;
    printf("Name: %s\n", guests[guest_index].name);
    printf("Room Number: %d\n", guests[guest_index].room_number);
    printf("Total Bill: %.2f\n", total_bill);
    printf("Thank you for staying with us!\n");
    (*num_guests)--;
    rooms[room_number - 1] = 0;
}

int main() {
    // Initialize hotels array
    Hotel hotels[3] = {
        {"The Grand Hotel", 50, 85.00},
        {"The Plaza Hotel", 75, 100.00},
        {"The Ritz Hotel", 100, 125.00}
    };
    int num_hotels = 3;

    // Initialize guests array
    Guest guests[100];
    int num_guests = 0;

    // Initialize rooms
    initialize_rooms();

    // Display main menu
    int choice;
    do {
        display_main_menu();
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                display_available_rooms(hotels, num_hotels);
                break;
            case 2:
                book_room(hotels, num_hotels, guests, &num_guests);
                break;
            case 3:
                display_guest_info(guests, num_guests);
                break;
            case 4:
                check_out_guest(guests, &num_guests);
                break;
            case 5:
                printf("Goodbye!\n");
                break;
            default:
                printf("Invalid choice\n");
                break;
        }
        printf("\n");
    } while (choice != 5);

    return 0;
}