//FormAI DATASET v1.0 Category: Hotel Management System ; Style: introspective
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct room {
    int room_number;
    int capacity;
    char status[10];
};

struct reservation {
    int reservation_number;
    char guest_name[50];
    int room_number;
    char check_in_date[15];
    char check_out_date[15];
};

int main() {
    int option;
    int num_of_rooms = 10;
    int num_of_reservations = 0;

    struct room rooms[num_of_rooms];
    struct reservation reservations[num_of_reservations];

    // Initialize rooms with default values
    for (int i = 0; i < num_of_rooms; i++) {
        rooms[i].room_number = i + 1;
        rooms[i].capacity = 2;
        strcpy(rooms[i].status, "Available");
    }

    while (1) {
        // Prompt user for options
        printf("\nWelcome to C Hotel Management System!\n");
        printf("1. Reserve a room\n");
        printf("2. Check availability\n");
        printf("3. View reservations\n");
        printf("4. Exit\n");
        printf("Choose an option: ");
        scanf("%d", &option);

        switch (option) {
            case 1:
                // Reserve a room
                printf("\nEnter your details:\n");
                printf("Name: ");
                char guest_name[50];
                scanf("%s", guest_name);

                printf("Check in date (dd-mm-yyyy): ");
                char check_in_date[15];
                scanf("%s", check_in_date);

                printf("Check out date (dd-mm-yyyy): ");
                char check_out_date[15];
                scanf("%s", check_out_date);

                printf("\nAvailable rooms:\n");
                for (int i = 0; i < num_of_rooms; i++) {
                    if (strcmp(rooms[i].status, "Available") == 0) {
                        printf("%d. Room %d (Capacity: %d)\n", i + 1, rooms[i].room_number, rooms[i].capacity);
                    }
                }

                printf("\nChoose a room: ");
                int room_choice;
                scanf("%d", &room_choice);

                if (strcmp(rooms[room_choice - 1].status, "Available") == 0) {
                    // Add reservation
                    struct reservation new_reservation;
                    new_reservation.reservation_number = num_of_reservations + 1;
                    strcpy(new_reservation.guest_name, guest_name);
                    new_reservation.room_number = rooms[room_choice - 1].room_number;
                    strcpy(new_reservation.check_in_date, check_in_date);
                    strcpy(new_reservation.check_out_date, check_out_date);

                    reservations[num_of_reservations] = new_reservation;
                    num_of_reservations += 1;

                    // Update room status
                    strcpy(rooms[room_choice - 1].status, "Booked");

                    printf("\nReservation successful!\n");
                } else {
                    printf("\nThis room is not available.\n");
                }

                break;
            case 2:
                // Check availability
                printf("\nAvailable rooms:\n");
                for (int i = 0; i < num_of_rooms; i++) {
                    if (strcmp(rooms[i].status, "Available") == 0) {
                        printf("Room %d (Capacity: %d)\n", rooms[i].room_number, rooms[i].capacity);
                    }
                }

                break;
            case 3:
                // View reservations
                printf("\nReservations:\n");
                for (int i = 0; i < num_of_reservations; i++) {
                    printf("%d. %s - Room %d (Check in: %s, Check out: %s)\n", 
                            reservations[i].reservation_number, 
                            reservations[i].guest_name, 
                            reservations[i].room_number, 
                            reservations[i].check_in_date, 
                            reservations[i].check_out_date);
                }

                break;
            case 4:
                // Exit
                exit(0);
                break;
            default:
                printf("\nInvalid option. Please choose again.\n");
                break;
        }
    }
    
    return 0;
}