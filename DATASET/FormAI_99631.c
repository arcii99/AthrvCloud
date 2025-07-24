//FormAI DATASET v1.0 Category: Hotel Management System ; Style: complex
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define MAX_GUESTS 100
#define MAX_DATES 365

struct guest {
    int id;
    char name[50];
    char address[100];
    char phone[20];
    char email[100];
    int rooms_booked[MAX_DATES];
};

struct room {
    int id;
    char type[20];
    char status[MAX_DATES];
};

struct booking {
    int id;
    int guest_id;
    int room_id;
    int start_date;
    int end_date;
};

struct hotel {
    char name[50];
    int num_rooms;
    struct room rooms[100];
    int num_guests;
    struct guest guests[MAX_GUESTS];
    int num_bookings;
    struct booking bookings[MAX_GUESTS];
};

int main() {
    struct hotel hotel1;
    strcpy(hotel1.name, "Hotel Atlantis");
    hotel1.num_rooms = 50;
    hotel1.num_guests = 0;
    hotel1.num_bookings = 0;

    // Initialize rooms
    for (int i = 0; i < hotel1.num_rooms; i++) {
        struct room room1;
        room1.id = i+1;
        strcpy(room1.type, "Double");
        memset(room1.status, '.', sizeof(room1.status));
        hotel1.rooms[i] = room1;
    }

    // Print room status
    printf("Room availability:\n");
    for (int i = 0; i < hotel1.num_rooms; i++) {
        struct room room1 = hotel1.rooms[i];
        printf("%d(%s): %s\n", room1.id, room1.type, room1.status);
    }

    // Add guest
    struct guest guest1;
    guest1.id = hotel1.num_guests+1;
    strcpy(guest1.name, "John Doe");
    strcpy(guest1.address, "123 Main St., Anytown, USA");
    strcpy(guest1.phone, "555-1234");
    strcpy(guest1.email, "john.doe@email.com");
    for (int i = 0; i < MAX_DATES; i++) {
        guest1.rooms_booked[i] = 0;
    }
    hotel1.guests[hotel1.num_guests] = guest1;
    hotel1.num_guests++;

    // Add booking
    struct booking booking1;
    booking1.id = hotel1.num_bookings+1;
    booking1.guest_id = guest1.id;
    booking1.room_id = 1;
    booking1.start_date = 5;
    booking1.end_date = 7;
    hotel1.bookings[hotel1.num_bookings] = booking1;
    hotel1.num_bookings++;

    // Update room status
    struct room room1 = hotel1.rooms[booking1.room_id-1];
    for (int i = booking1.start_date-1; i < booking1.end_date; i++) {
        room1.status[i] = 'X';
    }
    hotel1.rooms[booking1.room_id-1] = room1;

    // Print updated room status
    printf("\nUpdated room availability:\n");
    for (int i = 0; i < hotel1.num_rooms; i++) {
        struct room room1 = hotel1.rooms[i];
        printf("%d(%s): %s\n", room1.id, room1.type, room1.status);
    }

    // Print guest details
    printf("\nGuest details:\n");
    struct guest guest2 = hotel1.guests[0];
    printf("ID: %d\n", guest2.id);
    printf("Name: %s\n", guest2.name);
    printf("Address: %s\n", guest2.address);
    printf("Phone: %s\n", guest2.phone);
    printf("Email: %s\n", guest2.email);
    printf("Booked rooms: ");
    for (int i = 0; i < MAX_DATES; i++) {
        if (guest2.rooms_booked[i] != 0) {
            printf("%d, ", guest2.rooms_booked[i]);
        }
    }
    printf("\n");

    // Print booking details
    printf("\nBooking details:\n");
    struct booking booking2 = hotel1.bookings[0];
    printf("ID: %d\n", booking2.id);
    printf("Guest ID: %d\n", booking2.guest_id);
    printf("Room ID: %d\n", booking2.room_id);
    printf("Start date: %d\n", booking2.start_date);
    printf("End date: %d\n", booking2.end_date);

    return 0;
}