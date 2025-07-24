//FormAI DATASET v1.0 Category: Hotel Management System ; Style: artistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_ROOMS 100
#define MAX_NAME_LEN 50
#define MAX_RES_DATE_LEN 10
#define MAX_CHECK_IN_DATE_LEN 10
#define MAX_CHECK_OUT_DATE_LEN 10

struct room {
    int room_num;
    char guest_name[MAX_NAME_LEN];
    char reserved_date[MAX_RES_DATE_LEN];
    char check_in_date[MAX_CHECK_IN_DATE_LEN];
    char check_out_date[MAX_CHECK_OUT_DATE_LEN];
    char occupied;
};

void initialize_rooms(struct room rooms[]);
void print_menu();
void print_rooms(struct room rooms[]);
void reserve_room(struct room rooms[]);
void check_in(struct room rooms[]);
void check_out(struct room rooms[]);

int main() {
    struct room rooms[MAX_ROOMS];
    initialize_rooms(rooms);

    int choice;
    do {
        print_menu();
        scanf("%d", &choice);
        getchar(); // consume newline character

        switch (choice) {
            case 1: print_rooms(rooms); break;
            case 2: reserve_room(rooms); break;
            case 3: check_in(rooms); break;
            case 4: check_out(rooms); break;
            case 5: printf("Exiting program..."); break;
            default: printf("Invalid choice\n");
        }
        printf("\n");
    } while (choice != 5);

    return 0;
}

// initializes all rooms as unoccupied
void initialize_rooms(struct room rooms[]) {
    for (int i = 0; i < MAX_ROOMS; i++) {
        rooms[i].room_num = i + 1;
        memset(&(rooms[i].guest_name), 0, sizeof(rooms[i].guest_name));
        memset(&(rooms[i].reserved_date), 0, sizeof(rooms[i].reserved_date));
        memset(&(rooms[i].check_in_date), 0, sizeof(rooms[i].check_in_date));
        memset(&(rooms[i].check_out_date), 0, sizeof(rooms[i].check_out_date));
        rooms[i].occupied = 0;
    }
}

void print_menu() {
    printf("--------C Hotel Management System--------\n");
    printf("1 - See all room statuses\n");
    printf("2 - Reserve a room\n");
    printf("3 - Check in a guest\n");
    printf("4 - Check out a guest\n");
    printf("5 - Exit\n");
    printf("Enter choice: ");
}

void print_rooms(struct room rooms[]) {
    printf("--------Current Room Statuses--------\n");
    printf("Room Number  Guest Name  Reserve Date  Check In Date  Check Out Date  Occupied\n");
    for (int i = 0; i < MAX_ROOMS; i++) {
        printf("%-12d%-12s%-14s%-16s%-16s%c\n",
               rooms[i].room_num,
               rooms[i].guest_name,
               rooms[i].reserved_date,
               rooms[i].check_in_date,
               rooms[i].check_out_date,
               rooms[i].occupied ? 'Y' : 'N');
    }
}

void reserve_room(struct room rooms[]) {
    printf("--------Reserve Room--------\n");
    printf("Enter the room number to reserve: ");
    int room_num;
    scanf("%d", &room_num);
    getchar(); // consume newline character

    if (room_num < 1 || room_num > MAX_ROOMS) {
        printf("Invalid room number\n");
        return;
    }

    if (rooms[room_num - 1].occupied) {
        printf("Room is already occupied\n");
        return;
    }

    printf("Enter guest name: ");
    fgets(rooms[room_num - 1].guest_name, MAX_NAME_LEN, stdin);
    rooms[room_num - 1].guest_name[strcspn(rooms[room_num - 1].guest_name, "\n")] = 0; // remove newline character

    printf("Enter reservation date (mm/dd/yy): ");
    fgets(rooms[room_num - 1].reserved_date, MAX_RES_DATE_LEN, stdin);
    rooms[room_num - 1].reserved_date[strcspn(rooms[room_num - 1].reserved_date, "\n")] = 0; // remove newline character

    printf("Room %d has been reserved\n", room_num);
    rooms[room_num - 1].occupied = 1;
}

void check_in(struct room rooms[]) {
    printf("--------Check In Guest--------\n");
    printf("Enter the room number to check in: ");
    int room_num;
    scanf("%d", &room_num);
    getchar(); // consume newline character

    if (room_num < 1 || room_num > MAX_ROOMS) {
        printf("Invalid room number\n");
        return;
    }

    if (!rooms[room_num - 1].occupied) {
        printf("Room is not occupied\n");
        return;
    }

    printf("Enter check in date (mm/dd/yy): ");
    fgets(rooms[room_num - 1].check_in_date, MAX_CHECK_IN_DATE_LEN, stdin);
    rooms[room_num - 1].check_in_date[strcspn(rooms[room_num - 1].check_in_date, "\n")] = 0; // remove newline character

    printf("Guest has been checked in to room %d\n", room_num);
}

void check_out(struct room rooms[]) {
    printf("--------Check Out Guest--------\n");
    printf("Enter the room number to check out: ");
    int room_num;
    scanf("%d", &room_num);
    getchar(); // consume newline character

    if (room_num < 1 || room_num > MAX_ROOMS) {
        printf("Invalid room number\n");
        return;
    }

    if (!rooms[room_num - 1].occupied) {
        printf("Room is not occupied\n");
        return;
    }

    printf("Enter check out date (mm/dd/yy): ");
    fgets(rooms[room_num - 1].check_out_date, MAX_CHECK_OUT_DATE_LEN, stdin);
    rooms[room_num - 1].check_out_date[strcspn(rooms[room_num - 1].check_out_date, "\n")] = 0; // remove newline character

    printf("Guest has been checked out of room %d\n", room_num);
    rooms[room_num - 1].occupied = 0;
    memset(&(rooms[room_num - 1].guest_name), 0, sizeof(rooms[room_num - 1].guest_name));
    memset(&(rooms[room_num - 1].reserved_date), 0, sizeof(rooms[room_num - 1].reserved_date));
    memset(&(rooms[room_num - 1].check_in_date), 0, sizeof(rooms[room_num - 1].check_in_date));
    memset(&(rooms[room_num - 1].check_out_date), 0, sizeof(rooms[room_num - 1].check_out_date));
}