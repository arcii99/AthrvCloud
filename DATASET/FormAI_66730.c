//FormAI DATASET v1.0 Category: Hotel Management System ; Style: Dennis Ritchie
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define MAX_GUESTS 500
#define MAX_ROOMS 250

struct guest {
    char name[50];
    int age;
    int room_number;
};

struct room {
    int room_number;
    int capacity;
    int price;
    int occupied;
};

struct hotel {
    struct room rooms[MAX_ROOMS];
    struct guest guests[MAX_GUESTS];
    int num_rooms;
    int num_guests;
};

void initialize(struct hotel *h) {
    h->num_rooms = 0; 
    h->num_guests = 0;
}

int add_room(struct hotel *h, int room_number, int capacity, int price) {
    if(h->num_rooms >= MAX_ROOMS) {
        printf("Error: maximum number of rooms exceeded.\n");
        return 0;
    }
    struct room r;
    r.room_number = room_number;
    r.capacity = capacity;
    r.price = price;
    r.occupied = 0;
    h->rooms[h->num_rooms] = r;
    h->num_rooms++;
    return 1;
}

int add_guest(struct hotel *h, char name[], int age, int room_number) {
    if(h->num_guests >= MAX_GUESTS) {
        printf("Error: maximum number of guests exceeded.\n");
        return 0;
    }
    struct guest g;
    strcpy(g.name, name);
    g.age = age;
    g.room_number = room_number;
    int i;
    for(i = 0; i < h->num_rooms; i++) {
        if(h->rooms[i].room_number == room_number) {
            if(h->rooms[i].occupied) {
                printf("Error: room already occupied.\n");
                return 0;
            }
            else {
                h->rooms[i].occupied = 1;
                break;
            }
        }
    }
    if(i == h->num_rooms) {
        printf("Error: room not found.\n");
        return 0;
    }
    h->guests[h->num_guests] = g;
    h->num_guests++;
    return 1;
}

void print_guests_by_room(struct hotel *h, int room_number) {
    int i;
    for(i = 0; i < h->num_guests; i++) {
        if(h->guests[i].room_number == room_number) {
            printf("%s (age %d)\n", h->guests[i].name, h->guests[i].age);
        }
    }
}

void print_available_rooms(struct hotel *h) {
    int i;
    for(i = 0; i < h->num_rooms; i++) {
        if(!h->rooms[i].occupied) {
            printf("Room %d (capacity %d, $%d per night)\n", h->rooms[i].room_number, h->rooms[i].capacity, h->rooms[i].price);
        }
    }
}

int main() {
    struct hotel h;
    initialize(&h);

    add_room(&h, 101, 2, 100);
    add_room(&h, 102, 3, 150);
    add_room(&h, 103, 1, 75);

    add_guest(&h, "John Doe", 35, 101);
    add_guest(&h, "Jane Smith", 42, 102);
    add_guest(&h, "Bob Johnson", 27, 102);

    printf("Guests in room 102:\n");
    print_guests_by_room(&h, 102);

    printf("Available rooms:\n");
    print_available_rooms(&h);

    return 0;
}