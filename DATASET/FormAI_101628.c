//FormAI DATASET v1.0 Category: Hotel Management System ; Style: careful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define constants for maximum number of guests and rooms
#define MAX_GUESTS 100
#define MAX_ROOMS 50

struct Guest {
    char name[30];
    int age;
    char address[50];
    int room_number;
};

struct Room {
    int number;
    int capacity;
    int price;
    int reserved;
};

int main() {
    struct Guest guests[MAX_GUESTS];
    struct Room rooms[MAX_ROOMS];

    int num_guests = 0, num_rooms = 0;

    // Initialize each room with default values
    for (int i = 0; i < MAX_ROOMS; i++) {
        rooms[i].number = i+1;
        rooms[i].capacity = 2;
        rooms[i].price = 50;
        rooms[i].reserved = 0;
        num_rooms++;
    }

    printf("Welcome to the C Hotel Management System!\n");

    while (1) {
        printf("\nMenu:\n");
        printf("1. Add Guest\n");
        printf("2. Reserve Room\n");
        printf("3. View Reservations\n");
        printf("4. Exit\n");
        printf("Enter choice: ");

        int choice;
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                // Add new guest
                if (num_guests == MAX_GUESTS) {
                    printf("Maximum number of guests exceeded. Cannot add anymore.\n");
                    break;
                }

                printf("Enter guest name: ");
                scanf("%s", guests[num_guests].name);

                printf("Enter guest age: ");
                scanf("%d", &guests[num_guests].age);

                printf("Enter guest address: ");
                scanf("%s", guests[num_guests].address);

                num_guests++;
                printf("Guest added successfully!\n");

                break;
            case 2:
                // Reserve a room
                printf("Enter guest name: ");
                char guest_name[30];
                scanf("%s", guest_name);

                int guest_index = -1;
                for (int i = 0; i < num_guests; i++) {
                    if (strcmp(guests[i].name, guest_name) == 0) {
                        guest_index = i;
                        break;
                    }
                }

                if (guest_index == -1) {
                    printf("Guest not found.\n");
                    break;
                }

                printf("Enter room number: ");
                int room_number;
                scanf("%d", &room_number);

                int room_index = -1;
                for (int i = 0; i < num_rooms; i++) {
                    if (rooms[i].number == room_number) {
                        room_index = i;
                        break;
                    }
                }

                if (room_index == -1) {
                    printf("Room not found.\n");
                    break;
                }

                if (rooms[room_index].reserved == 1) {
                    printf("Room is already reserved.\n");
                    break;
                }

                if (rooms[room_index].capacity < 2) {
                    printf("Room is too small for reservation.\n");
                    break;
                }

                // Assign room to guest
                guests[guest_index].room_number = room_number;
                rooms[room_index].reserved = 1;
                printf("Reservation successful!\n");

                break;
            case 3:
                // View all reservations
                printf("Reservations:\n");
                for (int i = 0; i < num_guests; i++) {
                    printf("Guest name: %s\n", guests[i].name);
                    printf("Guest age: %d\n", guests[i].age);
                    printf("Guest address: %s\n", guests[i].address);
                    printf("Room number: %d\n", guests[i].room_number);
                    printf("\n");
                }
                break;
            case 4:
                // Exit program
                printf("Thank you for using the C Hotel Management System! Goodbye.\n");
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
                break;
        }
    }

    return 0;
}