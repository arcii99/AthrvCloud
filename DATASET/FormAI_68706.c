//FormAI DATASET v1.0 Category: Hotel Management System ; Style: standalone
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_ROOMS 100

struct Room {
    int id;
    char type[20];
    int price;
    int is_booked;
};

struct Customer {
    int id;
    char name[50];
    char phone[20];
    int booked_room_id;
};

struct Room rooms[MAX_ROOMS];
struct Customer customers[MAX_ROOMS];
int num_rooms = 0;
int num_customers = 0;

void add_room() {
    int id, price;
    char type[20];
    printf("Enter room ID: ");
    scanf("%d", &id);
    printf("Enter room type: ");
    scanf("%s", type);
    printf("Enter room price: ");
    scanf("%d", &price);
    struct Room r = {id, type, price, 0};
    rooms[num_rooms++] = r;
    printf("Room added successfully!\n");
}

void display_rooms() {
    for (int i = 0; i < num_rooms; i++) {
        printf("Room ID: %d, Type: %s, Price: %d, Status: %s\n", 
               rooms[i].id, rooms[i].type, rooms[i].price, 
               rooms[i].is_booked ? "Booked" : "Available");
    }
}

void book_room() {
    int room_id, customer_id;
    printf("Enter room ID to book: ");
    scanf("%d", &room_id);
    struct Room *r = NULL;
    for (int i = 0; i < num_rooms; i++) {
        if (rooms[i].id == room_id) {
            r = &rooms[i];
            break;
        }
    }
    if (r == NULL) {
        printf("No room found with ID %d!\n", room_id);
        return;
    }
    if (r->is_booked) {
        printf("Room with ID %d is already booked!\n", room_id);
        return;
    }
    printf("Enter customer ID: ");
    scanf("%d", &customer_id);
    struct Customer c = {customer_id, "", "", room_id};
    customers[num_customers++] = c;
    r->is_booked = 1;
    printf("Room with ID %d booked successfully for customer with ID %d!\n", room_id, customer_id);
}

void display_bookings() {
    for (int i = 0; i < num_customers; i++) {
        struct Customer *c = &customers[i];
        struct Room *r = NULL;
        for (int j = 0; j < num_rooms; j++) {
            if (rooms[j].id == c->booked_room_id) {
                r = &rooms[j];
                break;
            }
        }
        if (r == NULL) {
            printf("Customer ID %d has booked a non-existent room with ID %d!\n", c->id, c->booked_room_id);
        } else {
            printf("Customer ID: %d, Room ID: %d, Type: %s, Price: %d\n", 
                   c->id, r->id, r->type, r->price);
        }
    }
}

void display_menu() {
    printf("---- C Hotel Management System ----\n");
    printf("1. Add room\n");
    printf("2. Display rooms\n");
    printf("3. Book room\n");
    printf("4. Display bookings\n");
    printf("5. Exit\n");
    printf("Enter your choice: ");
}

int main() {
    int choice;
    do {
        display_menu();
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                add_room();
                break;
            case 2:
                display_rooms();
                break;
            case 3:
                book_room();
                break;
            case 4:
                display_bookings();
                break;
            case 5:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice!\n");
        }
    } while (choice != 5);
    return 0;
}