//FormAI DATASET v1.0 Category: Hotel Management System ; Style: Dennis Ritchie
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define MAX_ROOMS 50
#define MAX_GUESTS 100

struct guest {
    char name[50];
    char address[100];
    int phone_number;
    int room_number;
};

struct room {
    int room_number;
    int capacity;
    int is_available;
};

int num_rooms = 0;
struct room rooms[MAX_ROOMS];

int num_guests = 0;
struct guest guests[MAX_GUESTS];

void add_room(int room_num, int capacity) {
    if(num_rooms >= MAX_ROOMS) {
        printf("Error: Maximum number of rooms reached\n");
        return;
    }
    
    struct room new_room;
    new_room.room_number = room_num;
    new_room.capacity = capacity;
    new_room.is_available = 1;
    rooms[num_rooms++] = new_room;
}

void add_guest(char name[], char address[], int phone_num, int room_num) {
    if(num_guests >= MAX_GUESTS) {
        printf("Error: Maximum number of guests reached\n");
        return;
    }
    
    int room_index = -1;
    for(int i = 0; i < num_rooms; i++) {
        if(rooms[i].room_number == room_num && rooms[i].is_available) {
            room_index = i;
            break;
        }
    }
    
    if(room_index == -1) {
        printf("Error: Room not available or does not exist\n");
        return;
    }
    
    struct guest new_guest;
    strcpy(new_guest.name, name);
    strcpy(new_guest.address, address);
    new_guest.phone_number = phone_num;
    new_guest.room_number = room_num;
    guests[num_guests++] = new_guest;
    rooms[room_index].is_available = 0;
    
    printf("Guest added successfully!\n");
}

void remove_guest(char name[]) {
    int guest_index = -1;
    
    for(int i = 0; i < num_guests; i++) {
        if(strcmp(guests[i].name, name) == 0) {
            guest_index = i;
            break;
        }
    }
    
    if(guest_index == -1) {
        printf("Error: Guest not found\n");
        return;
    }
    
    int room_num = guests[guest_index].room_number;
    for(int i = 0; i < num_rooms; i++) {
        if(rooms[i].room_number == room_num) {
            rooms[i].is_available = 1;
            break;
        }
    }
    
    for(int i = guest_index; i < num_guests-1; i++) {
        guests[i] = guests[i+1];
    }
    num_guests--;
    
    printf("Guest removed successfully!\n");
}

void guest_list() {
    printf("Guest List:\n");
    for(int i = 0; i < num_guests; i++) {
        printf("%d. %s, Room %d\n", i+1, guests[i].name, guests[i].room_number);
    }
}

void room_list() {
    printf("Room List:\n");
    for(int i = 0; i < num_rooms; i++) {
        printf("%d. Room %d: Capacity %d, Available: %s\n", i+1, rooms[i].room_number, rooms[i].capacity, rooms[i].is_available ? "Yes" : "No");
    }
}

int main() {
    add_room(101, 2);
    add_room(102, 4);
    add_room(103, 1);
    
    add_guest("John Doe", "123 Main St", 5551234, 102);
    add_guest("Jane Smith", "456 Oak St", 5555678, 101);
    
    guest_list();
    room_list();
    
    remove_guest("John Doe");
    
    guest_list();
    room_list();
    
    return 0;
}