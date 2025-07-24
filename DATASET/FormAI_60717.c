//FormAI DATASET v1.0 Category: Hotel Management System ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ROOMS 10
#define MAX_NAME_LENGTH 20

typedef struct {
    int room_number;
    char guest_name[MAX_NAME_LENGTH];
    int duration_of_stay;
} Room;

void print_menu() {
    printf("---------- Hotel Management System Menu ----------\n");
    printf("1. Check-in\n");
    printf("2. Check-out\n");
    printf("3. Print Current Guests\n");
    printf("4. Exit\n");
    printf("-------------------------------------------------\n");
}

void check_in(Room rooms[], int room_number) {
    if (rooms[room_number-1].guest_name[0] != '\0') {
        printf("Room %d is already occupied by %s.\n", room_number, rooms[room_number-1].guest_name);
        return;
    }
    char guest_name[MAX_NAME_LENGTH];
    int duration_of_stay;
    printf("Enter Guest Name: ");
    scanf("%s", guest_name);
    printf("Enter Duration of Stay: ");
    scanf("%d", &duration_of_stay);
    Room new_guest = {room_number, guest_name, duration_of_stay};
    rooms[room_number-1] = new_guest;
    printf("Guest %s checked into room %d for %d days.\n", guest_name, room_number, duration_of_stay);
}

void check_out(Room rooms[], int room_number) {
    if (rooms[room_number-1].guest_name[0] == '\0') {
        printf("Room %d is not currently occupied.\n", room_number);
        return;
    }
    printf("Guest %s checked out of room %d.\n", rooms[room_number-1].guest_name, room_number);
    Room empty = {room_number, "", 0};
    rooms[room_number-1] = empty;
}

void print_guests(Room rooms[]) {
    printf("-------------------------------------------------\n");
    printf("|%10s |%15s |%20s|\n", "Room Number", "Guest Name", "Duration of Stay");
    printf("-------------------------------------------------\n");
    for (int i = 0; i < MAX_ROOMS; i++) {
        if (rooms[i].guest_name[0] != '\0') {
            printf("|%10d |%15s |%20d|\n", rooms[i].room_number, rooms[i].guest_name, rooms[i].duration_of_stay);
        }
    }
    printf("-------------------------------------------------\n");
}

int main(void) {
    Room rooms[MAX_ROOMS];
    for (int i = 0; i < MAX_ROOMS; i++) {
        Room empty = {i+1, "", 0};
        rooms[i] = empty;
    }
    int choice = 0;
    do {
        print_menu();
        printf("Enter choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1: {
                int room_number;
                printf("Enter Room Number: ");
                scanf("%d", &room_number);
                if (room_number <= 0 || room_number > MAX_ROOMS) {
                    printf("Invalid room number.\n");
                    break;
                }
                check_in(rooms, room_number);
                break;
            }
            case 2: {
                int room_number;
                printf("Enter Room Number: ");
                scanf("%d", &room_number);
                if (room_number <= 0 || room_number > MAX_ROOMS) {
                    printf("Invalid room number.\n");
                    break;
                }
                check_out(rooms, room_number);
                break;
            }
            case 3:
                print_guests(rooms);
                break;
            case 4:
                break;
            default:
                printf("Invalid choice.\n");
                break;
        }
    } while (choice != 4);
    printf("Thank you for using the Hotel Management System.\n");
    return 0;
}