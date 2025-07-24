//FormAI DATASET v1.0 Category: Hotel Management System ; Style: Donald Knuth
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* Data Structure to store information about hotel rooms */
struct Room {
    int room_number;
    char room_type[20];
    float room_price;
    int is_booked;
    char guest_name[50];
    char guest_phone[20];
};

void display_menu() {
    printf("1. Show all available rooms\n");
    printf("2. Book a room\n");
    printf("3. Release a room\n");
    printf("4. Search for a room by room number\n");
    printf("5. Exit\n");
}

void show_rooms(struct Room rooms[], int num_rooms) {
    printf("Room List:\n");
    for(int i=0; i<num_rooms; i++) {
        printf("[%d] %s - $%.2f per night - %s\n", rooms[i].room_number, rooms[i].room_type, rooms[i].room_price, (rooms[i].is_booked == 0) ? "Available" : "Booked");
    }
}

void book_room(struct Room rooms[], int num_rooms) {
    int room_number;
    printf("Enter the room number to book: ");
    scanf("%d", &room_number);
    struct Room *room = &rooms[room_number-1];
    if(room->is_booked == 1) {
        printf("Room already booked.\n");
        return;
    }
    printf("Enter guest name: ");
    scanf("%s", room->guest_name);
    printf("Enter guest phone number: ");
    scanf("%s", room->guest_phone);
    room->is_booked = 1;
    printf("Room booked successfully.\n");
}

void release_room(struct Room rooms[], int num_rooms) {
    int room_number;
    printf("Enter the room number to release: ");
    scanf("%d", &room_number);
    struct Room *room = &rooms[room_number-1];
    if(room->is_booked == 0) {
        printf("Room not booked.\n");
        return;
    }
    memset(room->guest_name, 0, sizeof(room->guest_name));
    memset(room->guest_phone, 0, sizeof(room->guest_phone));
    room->is_booked = 0;
    printf("Room released successfully.\n");
}

void search_room(struct Room rooms[], int num_rooms) {
    int room_number;
    printf("Enter the room number to search: ");
    scanf("%d", &room_number);
    struct Room *room = &rooms[room_number-1];
    if(room->is_booked == 0) {
        printf("Room available.\n");
    } else {
        printf("Room booked by %s (%s).\n", room->guest_name, room->guest_phone);
    }
}

int main() {
    struct Room rooms[10];
    for(int i=0; i<10; i++) {
        rooms[i].room_number = i+1;
        strcpy(rooms[i].room_type, "Standard");
        rooms[i].room_price = 75.0;
        rooms[i].is_booked = 0;
        memset(rooms[i].guest_name, 0, sizeof(rooms[i].guest_name));
        memset(rooms[i].guest_phone, 0, sizeof(rooms[i].guest_phone));
    }
    
    int choice;
    do {
        display_menu();
        printf("Enter your choice: ");
        scanf("%d", &choice);
        
        switch(choice) {
            case 1:
                show_rooms(rooms, 10);
                break;
            case 2:
                book_room(rooms, 10);
                break;
            case 3:
                release_room(rooms, 10);
                break;
            case 4:
                search_room(rooms, 10);
                break;
            case 5:
                printf("Exiting...\n");
                exit(0);
            default:
                printf("Invalid choice. Try again.\n");
        }
    } while(choice != 5);
    
    return 0;
}