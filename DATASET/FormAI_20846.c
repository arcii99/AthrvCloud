//FormAI DATASET v1.0 Category: Hotel Management System ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct room {
    int room_number;
    char room_type[10];
    int occupancy;
    int price;
};

struct booking {
    int room_number;
    char guest_name[50];
    char check_in_date[20];
    char check_out_date[20];
};

struct hotel {
    char name[50];
    char location[50];
    struct room rooms[50];
    struct booking bookings[50];
    int num_rooms;
    int num_bookings;
};

void initialize_hotel(struct hotel *h) {
    strcpy(h->name, "Mystery Hotel");
    strcpy(h->location, "Unknown");
    h->num_rooms = 0;
    h->num_bookings = 0;
}

void add_room(struct hotel *h, int room_number, char *room_type, int occupancy, int price) {
    struct room new_room;
    new_room.room_number = room_number;
    strcpy(new_room.room_type, room_type);
    new_room.occupancy = occupancy;
    new_room.price = price;
    h->rooms[h->num_rooms++] = new_room;
}

void create_booking(struct hotel *h) {
    if (h->num_bookings == h->num_rooms) {
        printf("All rooms are booked!\n");
        return;
    }
    int room_number, choice, valid;
    do {
        printf("Enter room number: ");
        scanf("%d", &room_number);
        valid = 0;
        for (int i = 0; i < h->num_rooms; i++) {
            if (h->rooms[i].room_number == room_number) {
                if (h->rooms[i].occupancy > 0) {
                    printf("Room is occupied!\n");
                }
                else {
                    valid = 1;
                }
                break;
            }
        }
        if (!valid) {
            printf("Room not found or invalid input!\n");
        }
    } while (!valid);
    h->rooms[room_number-1].occupancy = 1;
    h->bookings[h->num_bookings].room_number = room_number;
    printf("Enter guest name: ");
    getchar();
    fgets(h->bookings[h->num_bookings].guest_name, 50, stdin);
    printf("Enter check-in date (DD/MM/YYYY): ");
    fgets(h->bookings[h->num_bookings].check_in_date, 20, stdin);
    printf("Enter check-out date (DD/MM/YYYY): ");
    fgets(h->bookings[h->num_bookings].check_out_date, 20, stdin);
    printf("Booking created successfully!\n");
    h->num_bookings++;
}

void display_bookings(struct hotel *h) {
    if (h->num_bookings == 0) {
        printf("No bookings to display!\n");
        return;
    }
    printf("Room\tGuest Name\tCheck-in Date\tCheck-out Date\n");
    for (int i = 0; i < h->num_bookings; i++) {
        printf("%d\t%s\t%s\t%s\n", h->bookings[i].room_number, h->bookings[i].guest_name, h->bookings[i].check_in_date, h->bookings[i].check_out_date);
    }
}

int main() {
    struct hotel h;
    initialize_hotel(&h);
    add_room(&h, 101, "Single", 1, 1000);
    add_room(&h, 102, "Single", 1, 1000);
    add_room(&h, 103, "Double", 2, 2000);
    add_room(&h, 104, "Double", 2, 2000);
    add_room(&h, 105, "Deluxe", 2, 3000);
    add_room(&h, 106, "Deluxe", 2, 3000);
    int choice;
    do {
        printf("======== Mystery Hotel Booking System =======\n");
        printf("1. Create Booking\n");
        printf("2. Display Bookings\n");
        printf("3. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                create_booking(&h);
                break;
            case 2:
                display_bookings(&h);
                break;
            case 3:
                printf("Thank you for using Mystery Hotel Booking System!\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 3);
    return 0;
}