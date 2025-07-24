//FormAI DATASET v1.0 Category: Hotel Management System ; Style: safe
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_HOTEL_NAME_LEN 100
#define MAX_ROOM_NUM 10000
#define MAX_BOOKING_NUM 100000

typedef struct room {
    int room_number;
    char room_type; // S (single), D (double), T (triple)
    int bed_count;
    int floor;
    double price_per_night;
    int booked;
} Room;

typedef struct booking {
    int booking_id;
    int room_number;
    int guest_id;
    char check_in_date[11];
    char check_out_date[11];
    int nights_count;
    double total_price;
} Booking;

typedef struct guest {
    int guest_id;
    char name[101];
    char email[101];
    char phone_number[21];
    int bookings_count;
} Guest;

typedef struct hotel {
    char name[MAX_HOTEL_NAME_LEN];
    Room rooms[MAX_ROOM_NUM];
    int rooms_count;
    Booking bookings[MAX_BOOKING_NUM];
    int bookings_count;
    Guest guests[MAX_BOOKING_NUM];
    int guests_count;
} Hotel;

/**
 * Function that adds a new room to the hotel's database
 * @param h - pointer to the Hotel
 */
void add_room(Hotel *h) {
    int room_number, bed_count, floor;
    char room_type;
    double price_per_night;
    printf("\nEnter room number: ");
    scanf("%d", &room_number);
    if (room_number < 0 || room_number >= MAX_ROOM_NUM) {
        printf("\nInvalid room number");
        return;
    }
    if (h->rooms[room_number].room_number == room_number) {
        printf("\nRoom already exists");
        return;
    }
    printf("\nEnter room type (S for single, D for double, T for triple): ");
    scanf(" %c", &room_type);
    if (room_type != 'S' && room_type != 'D' && room_type != 'T') {
        printf("\nInvalid room type");
        return;
    }
    printf("\nEnter bed count: ");
    scanf("%d", &bed_count);
    printf("\nEnter floor: ");
    scanf("%d", &floor);
    printf("\nEnter price per night: ");
    scanf("%lf", &price_per_night);
    h->rooms[room_number].room_number = room_number;
    h->rooms[room_number].room_type = room_type;
    h->rooms[room_number].bed_count = bed_count;
    h->rooms[room_number].floor = floor;
    h->rooms[room_number].price_per_night = price_per_night;
    h->rooms_count++;
    printf("\nRoom added successfully");
}

/**
 * Function that displays all the rooms in the hotel's database
 * @param h - pointer to the Hotel
 */
void display_all_rooms(Hotel *h) {
    printf("\nRooms:\n");
    for (int i = 0; i < MAX_ROOM_NUM; i++) {
        if (h->rooms[i].room_number == i) {
            printf("%d, %c, %d, %d, %.2f per night\n", h->rooms[i].room_number,
                   h->rooms[i].room_type, h->rooms[i].bed_count,
                   h->rooms[i].floor, h->rooms[i].price_per_night);
        }
    }
}

/**
 * Function that searches for a room with a specific room number in the hotel's database
 * @param h - pointer to the Hotel
 */
void search_room(Hotel *h) {
    int room_number;
    printf("\nEnter room number: ");
    scanf("%d", &room_number);
    if (h->rooms[room_number].room_number == room_number) {
        printf("\n%d, %c, %d, %d, %.2f per night\n", h->rooms[room_number].room_number,
               h->rooms[room_number].room_type, h->rooms[room_number].bed_count,
               h->rooms[room_number].floor, h->rooms[room_number].price_per_night);
    } else {
        printf("\nRoom not found");
    }
}

/**
 * Function that books a room for a guest in the hotel
 * @param h - pointer to the Hotel
 */
void book_room(Hotel *h) {
    int room_number, guest_id, nights_count;
    char check_in_date[11], check_out_date[11], guest_name[101], guest_email[101], guest_phone_number[21];
    double total_price;
    printf("\nRoom booking:\n");
    printf("\nEnter room number: ");
    scanf("%d", &room_number);
    if (h->rooms[room_number].room_number != room_number) {
        printf("\nRoom not found");
        return;
    }
    if (h->rooms[room_number].booked == 1) {
        printf("\nRoom is already booked");
        return;
    }
    printf("\nEnter check-in date (YYYY-MM-DD): ");
    scanf("%s", check_in_date);
    printf("\nEnter check-out date (YYYY-MM-DD): ");
    scanf("%s", check_out_date);
    printf("\nEnter guest ID: ");
    scanf("%d", &guest_id);
    if (guest_id < 0 || guest_id >= MAX_BOOKING_NUM) {
        printf("\nInvalid guest ID");
        return;
    }
    printf("\nEnter guest name: ");
    scanf("%s", guest_name);
    printf("\nEnter guest email: ");
    scanf("%s", guest_email);
    printf("\nEnter guest phone number: ");
    scanf("%s", guest_phone_number);
    printf("\nEnter nights count: ");
    scanf("%d", &nights_count);
    total_price = nights_count * h->rooms[room_number].price_per_night;
    h->bookings[h->bookings_count].booking_id = h->bookings_count;
    h->bookings[h->bookings_count].room_number = room_number;
    h->bookings[h->bookings_count].guest_id = guest_id;
    strcpy(h->bookings[h->bookings_count].check_in_date, check_in_date);
    strcpy(h->bookings[h->bookings_count].check_out_date, check_out_date);
    h->bookings[h->bookings_count].nights_count = nights_count;
    h->bookings[h->bookings_count].total_price = total_price;
    h->rooms[room_number].booked = 1;
    if (h->guests[guest_id].guest_id != guest_id) {
        h->guests[guest_id].guest_id = guest_id;
        strcpy(h->guests[guest_id].name, guest_name);
        strcpy(h->guests[guest_id].email, guest_email);
        strcpy(h->guests[guest_id].phone_number, guest_phone_number);
        h->guests[guest_id].bookings_count = 1;
    } else {
        h->guests[guest_id].bookings_count++;
    }
    h->rooms_count++;
    printf("\nRoom booked successfully");
}

/**
 * Function that displays all the bookings in the hotel
 * @param h - pointer to the Hotel
 */
void display_all_bookings(Hotel *h) {
    printf("\nBookings:\n");
    for (int i = 0; i < h->bookings_count; i++) {
        printf("Booking %d: Room %d, Guest %d, %s to %s, %d nights, total price %.2f\n",
               h->bookings[i].booking_id, h->bookings[i].room_number,
               h->bookings[i].guest_id, h->bookings[i].check_in_date,
               h->bookings[i].check_out_date, h->bookings[i].nights_count,
               h->bookings[i].total_price);
    }
}

/**
 * Function that displays all the bookings of a specific guest
 * @param h - pointer to the Hotel
 */
void display_guest_bookings(Hotel *h) {
    int guest_id;
    printf("\nEnter guest ID: ");
    scanf("%d", &guest_id);
    if (h->guests[guest_id].guest_id != guest_id) {
        printf("\nGuest not found");
        return;
    }
    printf("\nGuest %s's bookings:\n", h->guests[guest_id].name);
    for (int i = 0; i < h->bookings_count; i++) {
        if (h->bookings[i].guest_id == guest_id) {
            printf("Booking %d: Room %d, %s to %s, %d nights, total price %.2f\n",
                   h->bookings[i].booking_id, h->bookings[i].room_number,
                   h->bookings[i].check_in_date, h->bookings[i].check_out_date,
                   h->bookings[i].nights_count, h->bookings[i].total_price);
        }
    }
}

int main() {
    Hotel h;
    memset(&h, 0, sizeof(Hotel));
    strcpy(h.name, "The Grand Hotel");
    int option;
    do {
        printf("\n--- Welcome to %s management system! ---\n", h.name);
        printf("\n1. Add room");
        printf("\n2. Display all rooms");
        printf("\n3. Search room");
        printf("\n4. Book room");
        printf("\n5. Display all bookings");
        printf("\n6. Display guest bookings");
        printf("\n7. Exit");
        printf("\n\nChoose an option: ");
        scanf("%d", &option);
        switch (option) {
            case 1: add_room(&h); break;
            case 2: display_all_rooms(&h); break;
            case 3: search_room(&h); break;
            case 4: book_room(&h); break;
            case 5: display_all_bookings(&h); break;
            case 6: display_guest_bookings(&h); break;
            case 7: printf("\nGoodbye!"); break;
            default: printf("\nInvalid option");
        }
    } while (option != 7);
    return 0;
}