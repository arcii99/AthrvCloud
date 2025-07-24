//FormAI DATASET v1.0 Category: Hotel Management System ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char name[50];
    int room_number;
    int occupied;
    float room_rate;
} Room;

void display_menu() {
    printf("\n\n*** Hotel Management System ***\n");
    printf("1. Display All Rooms\n");
    printf("2. Check In\n");
    printf("3. Check Out\n");
    printf("4. Search Room\n");
    printf("5. Exit\n");
}

int display_all_rooms(Room rooms[], int num_rooms) {
    printf("\n\nRooms:\n");
    printf("------------------------------\n");
    printf("| Room No. |  Name   | Status |\n");
    printf("------------------------------\n");
    int i;
    for (i=0; i<num_rooms; i++) {
        printf("|   %3d    |  %-10s |  %5s  |\n", 
               rooms[i].room_number, rooms[i].name,
               rooms[i].occupied ? "Occupied" : "Vacant");
    }
    printf("------------------------------\n");
    return 0;
}

int check_in(Room rooms[], int num_rooms) {
    int room_no, i;
    printf("\n\nCheck In:\n");
    printf("------------------------------\n");
    printf("Enter Room No.: ");
    scanf("%d", &room_no);
    for (i=0; i<num_rooms; i++) {
        if (rooms[i].room_number == room_no) {
            if (rooms[i].occupied) {
                printf("\nRoom is already occupied.\n");
                return -1;
            }
            printf("Enter Customer Name: ");
            scanf("%s", rooms[i].name);
            printf("Enter Room Rate: ");
            scanf("%f", &rooms[i].room_rate);
            rooms[i].occupied = 1;
            printf("\nCheck In Successful.\n");
            return 0;
        }
    }
    printf("\nRoom not found.\n");
    return -1;
}

int check_out(Room rooms[], int num_rooms) {
    int room_no, i;
    printf("\n\nCheck Out:\n");
    printf("------------------------------\n");
    printf("Enter Room No.: ");
    scanf("%d", &room_no);
    for (i=0; i<num_rooms; i++) {
        if (rooms[i].room_number == room_no) {
            if (!rooms[i].occupied) {
                printf("\nRoom is not occupied.\n");
                return -1;
            }
            printf("Customer Name: %s\n", rooms[i].name);
            printf("Room Rate: %.2f\n", rooms[i].room_rate);
            printf("Total Amount Due: %.2f\n", rooms[i].room_rate);
            rooms[i].occupied = 0;
            printf("\nCheck Out Successful.\n");
            return 0;
        }
    }
    printf("\nRoom not found.\n");
    return -1;
}

int search_room(Room rooms[], int num_rooms) {
    int room_no, i;
    printf("\n\nSearch Room:\n");
    printf("------------------------------\n");
    printf("Enter Room No.: ");
    scanf("%d", &room_no);
    for (i=0; i<num_rooms; i++) {
        if (rooms[i].room_number == room_no) {
            printf("\nRoom Found:\n");
            printf("Room No.: %d\n", rooms[i].room_number);
            printf("Customer Name: %s\n", rooms[i].name);
            printf("Room Rate: %.2f\n", rooms[i].room_rate);
            printf("Status: %s\n", rooms[i].occupied ? "Occupied" : "Vacant");
            return 0;
        }
    }
    printf("\nRoom not found.\n");
    return -1;
}

int main() {
    Room rooms[10];
    int i;
    for (i=0; i<10; i++) {
        rooms[i].room_number = i+1;
        rooms[i].occupied = 0;
        sprintf(rooms[i].name, "Room %d", i+1);
        rooms[i].room_rate = 1000.0;
    }
    while (1) {
        int choice;
        display_menu();
        printf("Enter Choice (1-5): ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                display_all_rooms(rooms, 10);
                break;
            case 2:
                check_in(rooms, 10);
                break;
            case 3:
                check_out(rooms, 10);
                break;
            case 4:
                search_room(rooms, 10);
                break;
            case 5:
                printf("\nGoodbye!\n");
                exit(0);
            default:
                printf("\nInvalid Choice.\n");
        }
    }
    return 0;
}