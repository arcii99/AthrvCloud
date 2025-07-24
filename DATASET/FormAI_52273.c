//FormAI DATASET v1.0 Category: Hotel Management System ; Style: creative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_ROOMS 100
#define MAX_CUSTOMERS_PER_ROOM 2

typedef struct customer_t {
    char name[50];
    int age;
    char address[100];
} customer;

typedef struct room_t {
    int room_number;
    customer customers[MAX_CUSTOMERS_PER_ROOM];
} room;

room rooms[MAX_ROOMS];
int num_rooms_occupied = 0;

void add_customer_to_room(int room_number, customer c) {
    int i;
    for(i = 0; i < MAX_CUSTOMERS_PER_ROOM; i++) {
        if(strlen(rooms[room_number].customers[i].name) == 0) {
            rooms[room_number].customers[i] = c;
            return;
        }
    }
}

void book_room(int room_number, customer c) {
    if(num_rooms_occupied == MAX_ROOMS) {
        printf("All rooms are occupied!\n");
        return;
    }
    if(strlen(rooms[room_number].customers[0].name) != 0) {
        printf("Room is already occupied!\n");
        return;
    }
    rooms[room_number].room_number = room_number;
    add_customer_to_room(room_number, c);
    num_rooms_occupied++;
    printf("Room booked successfully!\n");
}

void checkout_room(int room_number) {
    if(strlen(rooms[room_number].customers[0].name) == 0) {
        printf("Room is not occupied!\n");
        return;
    }
    rooms[room_number].customers[0].name[0] = '\0';
    rooms[room_number].customers[0].age = 0;
    rooms[room_number].customers[0].address[0] = '\0';
    printf("Room checked out successfully!\n");
    num_rooms_occupied--;
    return;
}

void print_customer_details(customer c) {
    printf("\nName: %s", c.name);
    printf("\nAge: %d", c.age);
    printf("\nAddress: %s", c.address);
}

void print_room_details(room r) {
    printf("\nRoom Number: %d", r.room_number);
    if(strlen(r.customers[0].name) != 0) {
        printf("\nCustomer 1:");
        print_customer_details(r.customers[0]);
    }
    if(strlen(r.customers[1].name) != 0) {
        printf("\nCustomer 2:");
        print_customer_details(r.customers[1]);
    }
    printf("\n");
}

void list_all_rooms() {
    int i;
    for(i = 0; i < MAX_ROOMS; i++) {
        printf("Room %d:", i+1);
        print_room_details(rooms[i]);
    }
}

int main() {

    // Empty all rooms.
    int i;
    for(i = 0; i < MAX_ROOMS; i++) {
        rooms[i].room_number = i+1;
        rooms[i].customers[0].name[0] = '\0';
        rooms[i].customers[0].age = 0;
        rooms[i].customers[0].address[0] = '\0';
        rooms[i].customers[1].name[0] = '\0';
        rooms[i].customers[1].age = 0;
        rooms[i].customers[1].address[0] = '\0';
    }

    // Keep showing the menu until the user quits.
    int choice = 0, room_number = 0;
    customer c;
    while(choice != 5) {
        printf("\n\n1. Book a room.");
        printf("\n2. Checkout a room.");
        printf("\n3. List all occupied rooms.");
        printf("\n4. Show details of a specific room.");
        printf("\n5. Quit.");
        printf("\n\nEnter your choice: ");
        scanf("%d", &choice);

        if(choice == 1) {
            printf("\nEnter the room number to book: ");
            scanf("%d", &room_number);
            printf("\nEnter the name of customer 1: ");
            scanf("%s", c.name);
            printf("\nEnter the age of customer 1: ");
            scanf("%d", &c.age);
            printf("\nEnter the address of customer 1: ");
            scanf("%s", c.address);
            book_room(room_number-1, c);
        }
        else if(choice == 2) {
            printf("\nEnter the room number to checkout: ");
            scanf("%d", &room_number);
            checkout_room(room_number-1);
        }
        else if(choice == 3) {
            printf("\nList of all occupied rooms:\n");
            for(i = 0; i < MAX_ROOMS; i++) {
                if(strlen(rooms[i].customers[0].name) != 0) {
                    printf("Room %d:", i+1);
                    print_room_details(rooms[i]);
                }
            }
        }
        else if(choice == 4) {
            printf("\nEnter the room number to show details: ");
            scanf("%d", &room_number);
            print_room_details(rooms[room_number-1]);
        }
    }

    return 0;
}