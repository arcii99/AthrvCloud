//FormAI DATASET v1.0 Category: Hotel Management System ; Style: artistic
#include <stdio.h>
#include <stdlib.h>

struct room {
    int room_number;
    char guest_name[50];
    int reserved; //1 if reserved, 0 if not
};

struct room hotel[10]; //array of 10 rooms

void initialize_rooms() {
    int i;
    for (i = 0; i < 10; i++) {
        hotel[i].room_number = i+1;
        hotel[i].reserved = 0;
    }
}

void reserve_room() {
    int room_num, i;
    char name[50];

    printf("Enter room number: ");
    scanf("%d", &room_num);

    if (hotel[room_num-1].reserved == 1) { //if reserved
        printf("Room is already reserved.\n");
    } else { //if not reserved
        hotel[room_num-1].reserved = 1;
        printf("Enter guest name: ");
        scanf("%s", name);
        strcpy(hotel[room_num-1].guest_name, name);
        printf("Reserved room %d for %s.\n", room_num, hotel[room_num-1].guest_name);
    }
}

void cancel_reservation() {
    int room_num;

    printf("Enter room number: ");
    scanf("%d", &room_num);

    if (hotel[room_num-1].reserved == 0) { //if not reserved
        printf("Room is not reserved.\n");
    } else { //if reserved
        hotel[room_num-1].reserved = 0;
        strcpy(hotel[room_num-1].guest_name, "");
        printf("Cancelled reservation for room %d.\n", room_num);
    }
}

void print_reservations() {
    int i;

    printf("Room\tGuest Name\n");
    for (i = 0; i < 10; i++) {
        if (hotel[i].reserved == 1) {
            printf("%d\t%s\n", hotel[i].room_number, hotel[i].guest_name);
        }
    }
}

int main() {
    int choice;

    initialize_rooms();

    do {
        printf("\n");
        printf("1. Reserve a room\n");
        printf("2. Cancel a reservation\n");
        printf("3. View all reservations\n");
        printf("4. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                reserve_room();
                break;
            case 2:
                cancel_reservation();
                break;
            case 3:
                print_reservations();
                break;
            case 4:
                printf("Goodbye!\n");
                exit(0);
        }
    } while (choice != 4);

    return 0;
}