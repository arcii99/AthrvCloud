//FormAI DATASET v1.0 Category: Hotel Management System ; Style: ultraprecise
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_RESERVATIONS 100
#define MAX_ROOMS 50

typedef struct {
    int id;
    char type[20];
    double price;
} Room;

typedef struct {
    int id;
    char name[50];
    char email[50];
    char check_in[15]; // Format: DD/MM/YYYY
    char check_out[15]; // Format: DD/MM/YYYY
    Room *room;
    double total_price;
} Reservation;

void print_menu() {
    printf("\n\n");
    printf("Welcome to C Hotel Management System!\n");
    printf("MENU:\n");
    printf("1. Make a reservation\n");
    printf("2. Cancel a reservation\n");
    printf("3. View reservations\n");
    printf("4. Exit\n");
    printf("Please enter your choice (1-4): ");
}

void make_reservation(Room *rooms, Reservation *reservations, int *n_reservations) {
    if (*n_reservations == MAX_RESERVATIONS) {
        printf("Sorry, the hotel is fully booked.\n");
        return;
    }

    int room_id;
    char check_in[15], check_out[15], name[50], email[50];
    printf("Please enter your name: ");
    scanf("%s", name);
    printf("Please enter your email: ");
    scanf("%s", email);
    printf("Please enter the room id you want to reserve: ");
    scanf("%d", &room_id);
    while (rooms[room_id-1].id == 0) {
        printf("Invalid room id. Please enter a valid room id: ");
        scanf("%d", &room_id);
    }
    printf("Please enter the check-in date (DD/MM/YYYY): ");
    scanf("%s", check_in);
    printf("Please enter the check-out date (DD/MM/YYYY): ");
    scanf("%s", check_out);

    Reservation reservation;
    reservation.id = *n_reservations + 1;
    strcpy(reservation.name, name);
    strcpy(reservation.email, email);
    strcpy(reservation.check_in, check_in);
    strcpy(reservation.check_out, check_out);
    reservation.room = &(rooms[room_id-1]);
    reservation.total_price = (double)(atoi(check_out+6) - atoi(check_in+6)) * reservation.room->price; // Calculates the number of nights between check-in and check-out and multiplies it by the price per night
    reservations[*n_reservations] = reservation;
    *n_reservations += 1;

    printf("Reservation made successfully!\n");
}

void cancel_reservation(Reservation *reservations, int *n_reservations) {
    if (*n_reservations == 0) {
        printf("There are no reservations to cancel.\n");
        return;
    }

    int id;
    printf("Please enter the ID of the reservation you want to cancel: ");
    scanf("%d", &id);

    for (int i = 0; i < *n_reservations; i++) {
        if (reservations[i].id == id) {
            // Shifts all elements after the canceled reservation one position to the left
            for (int j = i; j < *n_reservations-1; j++) {
                reservations[j] = reservations[j+1];
            }
            *n_reservations -= 1;
            printf("Reservation canceled successfully!\n");
            return;
        }
    }

    printf("Reservation not found.\n");
}

void view_reservations(Reservation *reservations, int n_reservations) {
    if (n_reservations == 0) {
        printf("There are no reservations to display.\n");
        return;
    }

    printf("Reservations:\n");
    printf("ID\tName\tEmail\t\t\t\tRoom Type\tCheck-in\tCheck-out\tPrice\n");
    printf("-----------------------------------------------------------------------------------\n");

    for (int i = 0; i < n_reservations; i++) {
        Reservation reservation = reservations[i];
        printf("%d\t%s\t%s\t%s\t\t%s\t%s\t\t%.2f\n", reservation.id, reservation.name, reservation.email, reservation.room->type, reservation.check_in, reservation.check_out, reservation.total_price);
    }
}

int main() {
    // Initializes rooms
    Room rooms[MAX_ROOMS];
    for (int i = 0; i < MAX_ROOMS; i++) {
        Room room = {i+1, "Single", 50.0};
        rooms[i] = room;
    }
    rooms[9].type[0] = 'D'; strcpy(rooms[9].type+1, "ouble"); rooms[9].price = 75.0;
    rooms[19].type[0] = 'D'; strcpy(rooms[19].type+1, "ouble"); rooms[19].price = 75.0;
    rooms[29].type[0] = 'D'; strcpy(rooms[29].type+1, "ouble"); rooms[29].price = 75.0;
    rooms[39].type[0] = 'T'; strcpy(rooms[39].type+1, "riple"); rooms[39].price = 100.0;
    rooms[49].type[0] = 'T'; strcpy(rooms[49].type+1, "riple"); rooms[49].price = 100.0;

    Reservation reservations[MAX_RESERVATIONS];
    int n_reservations = 0;

    int choice;
    do {
        print_menu();
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                make_reservation(rooms, reservations, &n_reservations);
                break;
            case 2:
                cancel_reservation(reservations, &n_reservations);
                break;
            case 3:
                view_reservations(reservations, n_reservations);
                break;
            case 4:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice.\n");
                break;
        }
    } while (choice != 4);

    return 0;
}