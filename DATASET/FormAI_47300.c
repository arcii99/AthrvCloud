//FormAI DATASET v1.0 Category: Hotel Management System ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ROOMS 50

typedef struct {
    int room_number;
    char guest_name[50];
} Room;

void view_all_rooms(Room rooms[], int num_rooms);
int find_room(Room rooms[], int num_rooms, int room_number);
void add_guest(Room rooms[], int num_rooms);
void remove_guest(Room rooms[], int num_rooms);
void menu();

int main() {
    Room rooms[MAX_ROOMS];
    int num_rooms = 5;
    
    rooms[0].room_number = 101;
    strcpy(rooms[0].guest_name, "");
    rooms[1].room_number = 102;
    strcpy(rooms[1].guest_name, "John Smith");
    rooms[2].room_number = 103;
    strcpy(rooms[2].guest_name, "Jane Doe");
    rooms[3].room_number = 104;
    strcpy(rooms[3].guest_name, "");
    rooms[4].room_number = 105;
    strcpy(rooms[4].guest_name, "");
    
    int choice;
    do {
        menu();
        scanf("%d", &choice);
        
        switch(choice) {
            case 1:
                view_all_rooms(rooms, num_rooms);
                break;
            case 2:
                add_guest(rooms, num_rooms);
                break;
            case 3:
                remove_guest(rooms, num_rooms);
                break;
            case 4:
                printf("Exiting program...\n");
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (1);
}

void view_all_rooms(Room rooms[], int num_rooms) {
    printf("Room\tGuest\n");
    for (int i = 0; i < num_rooms; i++) {
        printf("%d\t%s\n", rooms[i].room_number, rooms[i].guest_name);
    }
}

int find_room(Room rooms[], int num_rooms, int room_number) {
    for (int i = 0; i < num_rooms; i++) {
        if (rooms[i].room_number == room_number) {
            return i;
        }
    }
    return -1;
}

void add_guest(Room rooms[], int num_rooms) {
    int room_number;
    char guest_name[50];
    printf("Enter room number: ");
    scanf("%d", &room_number);
    int index = find_room(rooms, num_rooms, room_number);
    if (index == -1) {
        printf("Room not found.\n");
    } else if (strcmp(rooms[index].guest_name, "") != 0) {
        printf("Room is already occupied.\n");
    } else {
        printf("Enter guest name: ");
        scanf("%s", guest_name);
        strcpy(rooms[index].guest_name, guest_name);
        printf("Guest added to room %d.\n", room_number);
    }
}

void remove_guest(Room rooms[], int num_rooms) {
    int room_number;
    printf("Enter room number: ");
    scanf("%d", &room_number);
    int index = find_room(rooms, num_rooms, room_number);
    if (index == -1) {
        printf("Room not found.\n");
    } else if (strcmp(rooms[index].guest_name, "") == 0) {
        printf("Room is already unoccupied.\n");
    } else {
        strcpy(rooms[index].guest_name, "");
        printf("Guest removed from room %d.\n", room_number);
    }
}

void menu() {
    printf("\nMENU\n");
    printf("1. View all rooms\n");
    printf("2. Add guest\n");
    printf("3. Remove guest\n");
    printf("4. Exit\n");
    printf("Enter choice: ");
}