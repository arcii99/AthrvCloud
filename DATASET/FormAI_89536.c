//FormAI DATASET v1.0 Category: Hotel Management System ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ROOMS 20
#define MAX_NAME_LENGTH 20

typedef struct {
    int room_num;
    int num_guests;
    char guest_names[MAX_ROOMS][MAX_NAME_LENGTH];
    double room_rate;
    int days_stayed;
} Room;

Room rooms[MAX_ROOMS];

void print_menu() {
    printf("1. Book a Room\n");
    printf("2. View Room Status\n");
    printf("3. Check Out\n");
    printf("4. Exit\n");
}

int get_room_index(int room_num) {
    for (int i = 0; i < MAX_ROOMS; i++) {
        if (rooms[i].room_num == room_num) {
            return i;
        }
    }

    return -1;
}

void book_room() {
    int room_num;
    printf("Enter room number: ");
    scanf("%d", &room_num);

    int index = get_room_index(room_num);
    if (index < 0) {
        printf("Invalid room number.\n");
        return;
    }

    if (rooms[index].num_guests > 0) {
        printf("Room is already occupied.\n");
        return;
    }

    int num_guests;
    printf("Enter number of guests: ");
    scanf("%d", &num_guests);

    if (num_guests <= 0) {
        printf("Invalid number of guests.\n");
        return;
    }

    rooms[index].num_guests = num_guests;
    for (int i = 0; i < num_guests; i++) {
        printf("Enter name of guest %d: ", i+1);
        scanf("%s", rooms[index].guest_names[i]);
    }

    printf("Enter room rate: ");
    scanf("%lf", &rooms[index].room_rate);

    printf("Enter number of days stayed: ");
    scanf("%d", &rooms[index].days_stayed);

    printf("Room %d booked.\n", room_num);
}

void view_status() {
    printf("Room\tGuests\tRate\tDays\tTotal\n");
    for (int i = 0; i < MAX_ROOMS; i++) {
        if (rooms[i].num_guests > 0) {
            double total = rooms[i].days_stayed * rooms[i].room_rate;
            printf("%d\t%d\t%.2lf\t%d\t%.2lf\n", rooms[i].room_num, rooms[i].num_guests, rooms[i].room_rate, rooms[i].days_stayed, total);
        }
    }
}

void check_out() {
    int room_num;
    printf("Enter room number: ");
    scanf("%d", &room_num);

    int index = get_room_index(room_num);
    if (index < 0) {
        printf("Invalid room number.\n");
        return;
    }

    if (rooms[index].num_guests == 0) {
        printf("Room is not occupied.\n");
        return;
    }

    printf("Guests in room:\n");
    for (int i = 0; i < rooms[index].num_guests; i++) {
        printf("\t%s\n", rooms[index].guest_names[i]);
    }

    double total = rooms[index].days_stayed * rooms[index].room_rate;
    printf("Total: %.2lf\n", total);

    rooms[index].num_guests = 0;
    rooms[index].room_rate = 0;
    rooms[index].days_stayed = 0;

    printf("Room %d checked out.\n", room_num);
}

int main() {
    for (int i = 0; i < MAX_ROOMS; i++) {
        rooms[i].room_num = i + 1;
    }

    while (1) {
        print_menu();

        int choice;
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                book_room();
                break;
            case 2:
                view_status();
                break;
            case 3:
                check_out();
                break;
            case 4:
                printf("Exiting.\n");
                exit(0);
            default:
                printf("Invalid choice.\n");
        }
    }
    return 0;
}