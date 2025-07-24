//FormAI DATASET v1.0 Category: Hotel Management System ; Style: scientific
// This program implements a hotel management system where the user can make bookings, 
// check-in to their rooms, check-out, view room availability, and display occupied rooms.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_ROOMS 10

// Structure to hold details of a room
typedef struct {
    char room_no[10];
    char guest_name[30];
    int status;
}room;

// Function prototypes
void book_room(room []);
void check_in(room []);
void check_out(room []);
void view_availability(room []);
void display_occupied_rooms(room []);

int main() {
    int choice;
    room hotel_rooms[MAX_ROOMS];
    for(int i = 0; i < MAX_ROOMS; i++){
        sprintf(hotel_rooms[i].room_no, "%d", i + 1); // Assigning initial room numbers to the rooms
        hotel_rooms[i].guest_name[0] = '\0'; // Setting guest name as empty initially
        hotel_rooms[i].status = 0; // Setting room status as available initially
    }

    do {
        printf("\n\n Hotel Management System \n");
        printf(" ------------------------\n");
        printf("1. Book a room\n");
        printf("2. Check in\n");
        printf("3. Check out\n");
        printf("4. View room availability\n");
        printf("5. Display occupied rooms\n");
        printf("6. Exit\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: book_room(hotel_rooms); break;
            case 2: check_in(hotel_rooms); break;
            case 3: check_out(hotel_rooms); break;
            case 4: view_availability(hotel_rooms); break;
            case 5: display_occupied_rooms(hotel_rooms); break;
            case 6: exit(0);
            default: printf("Invalid choice! Please try again.\n");
        }
    } while(choice != 6);

    return 0;
}

// Function to book a room
void book_room(room rooms[]) {
    int room_no;
    char guest_name[30];
    printf("\nEnter the room number: ");
    scanf("%d", &room_no);

    if(room_no > MAX_ROOMS || room_no < 1) {
        printf("Invalid room number entered!\n");
        return;
    }

    if(rooms[room_no - 1].status == 1) {
        printf("Room %d is already booked.\n", room_no);
        return;
    }
    printf("Enter guest name: ");
    scanf("%s", guest_name);
    strcpy(rooms[room_no - 1].guest_name, guest_name);
    rooms[room_no - 1].status = 1;
    printf("Room %d has been booked for %s.\n", room_no, rooms[room_no - 1].guest_name);
}

// Function to check in to a room
void check_in(room rooms[]) {
    int room_no;
    printf("\nEnter the room number: ");
    scanf("%d", &room_no);

    if(room_no > MAX_ROOMS || room_no < 1) {
        printf("Invalid room number entered!\n");
        return;
    }

    if(rooms[room_no - 1].status == 0) {
        printf("Room %d is not yet booked.\n", room_no);
        return;
    }

    printf("%s has checked in to Room %d.\n", rooms[room_no - 1].guest_name, room_no);
    rooms[room_no - 1].status = 2;
}

// Function to check out from a room
void check_out(room rooms[]) {
    int room_no;
    printf("\nEnter the room number: ");
    scanf("%d", &room_no);

    if(room_no > MAX_ROOMS || room_no < 1) {
        printf("Invalid room number entered!\n");
        return;
    }

    if(rooms[room_no - 1].status == 0) {
        printf("Room %d is not yet booked.\n", room_no);
        return;
    } else if(rooms[room_no - 1].status == 1) {
        printf("Guest has not checked in to Room %d yet.\n", room_no);
        return;
    }

    printf("%s has checked out of Room %d.\n", rooms[room_no - 1].guest_name, room_no);
    rooms[room_no - 1].guest_name[0] = '\0';
    rooms[room_no - 1].status = 0;
}

// Function to view room availability
void view_availability(room rooms[]) {
    printf("\nRoom Availability\n");
    printf("-------------------\n");
    for(int i = 0; i < MAX_ROOMS; i++){
        printf("Room %d: ", i+1);
        if(rooms[i].status==0)
            printf("Available\n");
        else
            printf("Booked\n");
    }
}

// Function to display occupied rooms
void display_occupied_rooms(room rooms[]) {
    printf("\nOccupied Rooms\n");
    printf("---------------------\n");
    for(int i = 0; i < MAX_ROOMS; i++){
        if(rooms[i].status==2)
            printf("Room %d: %s\n", i+1, rooms[i].guest_name);
    }
}