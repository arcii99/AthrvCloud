//FormAI DATASET v1.0 Category: Hotel Management System ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>

#define MAX_ROOMS 50
#define MAX_GUESTS 100

struct room {
    int room_num;
    int occupancy;
    char guest_name[30];
    float rate;
};

struct guest {
    char name[30];
    int room_num;
    int nights_stayed;
    float total_bill;
};

int menu() {
    int choice;

    printf("\nWelcome to C Hotel Management\n");
    printf("1. Check in a guest\n");
    printf("2. Check out a guest\n");
    printf("3. View room status\n");
    printf("4. View guest list\n");
    printf("5. Exit\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);

    return choice;
}

void init_rooms(struct room rooms[]) {
    for (int i = 0; i < MAX_ROOMS; i++) {
        rooms[i].room_num = i+1;
        rooms[i].occupancy = 0;
        rooms[i].guest_name[0] = '\0';
        if (i < 10) {
            rooms[i].rate = 100.00;
        } else if (i < 20) {
            rooms[i].rate = 150.00;
        } else {
            rooms[i].rate = 200.00;
        }
    }
}

void check_in(struct room rooms[], struct guest guests[]) {
    int room_choice, guest_choice;
    char guest_name[30];
    int found_room = 0;
    int room_num;
    float bill = 0.00;

    printf("\n--Check in a guest--\n");

    // Input guest information
    printf("Enter guest name: ");
    scanf("%s", guest_name);

    // Check if there are available rooms
    for (int i = 0; i < MAX_ROOMS; i++) {
        if (rooms[i].occupancy == 0) {
            printf("Available room: %d\n", rooms[i].room_num);
            found_room = 1;
        }
    }

    if (found_room == 0) {
        printf("No available room.\n");
        return;
    }

    // Choose a room
    printf("Enter room number: ");
    scanf("%d", &room_choice);

    for (int i = 0; i < MAX_ROOMS; i++) {
        if (rooms[i].room_num == room_choice) {
            room_num = i;
            break;
        }
    }

    // Update room and guest information
    rooms[room_num].occupancy = 1;
    guests[MAX_GUESTS-1].room_num = room_choice;
    guests[MAX_GUESTS-1].nights_stayed = 0;
    guests[MAX_GUESTS-1].total_bill = 0.00;
    strcpy(guests[MAX_GUESTS-1].name, guest_name);
    strcpy(rooms[room_num].guest_name, guest_name);

    // Calculate and print bill
    if (room_choice < 10) {
        bill = 100.00;
    } else if (room_choice < 20) {
        bill = 150.00;
    } else {
        bill = 200.00;
    }
    printf("%s's bill for %d nights: $%.2f\n", guest_name, guests[MAX_GUESTS-1].nights_stayed+1, bill);
    guests[MAX_GUESTS-1].total_bill += bill;
}

void check_out(struct room rooms[], struct guest guests[]) {
    int room_choice, guest_choice;
    int room_num;
    float bill;

    printf("\n--Check out a guest--\n");

    // Check if there are occupied rooms
    int found_room = 0;
    for (int i = 0; i < MAX_ROOMS; i++) {
        if (rooms[i].occupancy == 1) {
            printf("Occupied room: %d\n", rooms[i].room_num);
            found_room = 1;
        }
    }

    if (found_room == 0) {
        printf("No occupied rooms.\n");
        return;
    }

    // Choose a room
    printf("Enter room number: ");
    scanf("%d", &room_choice);

    for (int i = 0; i < MAX_ROOMS; i++) {
        if (rooms[i].room_num == room_choice) {
            room_num = i;
            break;
        }
    }

    // Update room and guest information
    strcpy(rooms[room_num].guest_name, "");
    rooms[room_num].occupancy = 0;
    for (int i = 0; i < MAX_GUESTS; i++) {
        if (strcmp(guests[i].name, "") == 0 || guests[i].room_num != room_choice) {
            continue;
        }
        guest_choice = i;
        break;
    }
    bill = guests[guest_choice].total_bill;
    guests[guest_choice].name[0] = '\0';
    guests[guest_choice].room_num = 0;
    guests[guest_choice].nights_stayed = 0;
    guests[guest_choice].total_bill = 0.00;

    printf("Total bill for room %d: $%.2f\n", room_choice, bill);
}

void view_rooms(struct room rooms[]) {
    printf("\n--Room status--\n");

    for (int i = 0; i < MAX_ROOMS; i++) {
        if (rooms[i].occupancy == 1) {
            printf("Room %d is occupied by %s\n", rooms[i].room_num, rooms[i].guest_name);
        } else {
            printf("Room %d is available\n", rooms[i].room_num);
        }
    }
}

void view_guests(struct guest guests[]) {
    printf("\n--Guest list--\n");

    for (int i = 0; i < MAX_GUESTS; i++) {
        if (strcmp(guests[i].name, "") == 0) {
            continue;
        }
        printf("Guest: %s, Room: %d, Nights stayed: %d, Total bill: $%.2f\n", guests[i].name, guests[i].room_num, guests[i].nights_stayed, guests[i].total_bill);
    }
}

int main() {
    struct room rooms[MAX_ROOMS];
    struct guest guests[MAX_GUESTS];

    init_rooms(rooms);

    int choice;
    do {
        choice = menu();

        switch(choice) {
            case 1:
                check_in(rooms, guests);
                break;
            case 2:
                check_out(rooms, guests);
                break;
            case 3:
                view_rooms(rooms);
                break;
            case 4:
                view_guests(guests);
                break;
            case 5:
                printf("\nGoodbye!\n");
                exit(0);
            default:
                printf("\nInvalid choice. Please try again.\n");
                break;
        }
    } while (1);

    return 0;
}