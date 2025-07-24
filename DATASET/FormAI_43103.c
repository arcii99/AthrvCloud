//FormAI DATASET v1.0 Category: Hotel Management System ; Style: rigorous
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define MAX_N 100
#define HOTEL_NAME_LENGTH 50

enum Room_Type {
    SINGLE,
    DOUBLE,
    TWIN,
    SUITE
};

struct Room {
    int room_number;
    enum Room_Type type;
    int rate;
    int is_occupied;
};

struct Customer {
    char first_name[50];
    char last_name[50];
    int room_number;
};

struct Hotel {
    char name[HOTEL_NAME_LENGTH];
    int num_rooms;
    struct Room rooms[MAX_N];
    struct Customer customers[MAX_N];
};

void show_menu() {
     printf("\n\nWelcome to our C Hotel Management System\n\n");
     printf("1. Check in customer.\n");
     printf("2. Check out customer.\n");
     printf("3. Print hotel occupancy report.\n");
     printf("4. Exit the system.\n");
}

void initialize_hotel(struct Hotel* hotel) {
    hotel->num_rooms = 0;
    strcpy(hotel->name, "C Hotel");
}

void print_room(struct Room* room) {
    printf("%d\t%d\t%d\t", room->room_number, room->type, room->rate);
    if(room->is_occupied) {
        printf("OCCUPIED\n");
    }
    else {
        printf("VACANT\n");
    }
}

void print_customer(struct Customer* customer) {
    printf("%s\t%s\t%d\n", customer->first_name, customer->last_name, customer->room_number);
}

void print_hotel(struct Hotel* hotel) {
    printf("******** ROOMS ********\n");
    printf("Number\tType\tRate\tOccupancy\n");
    for(int i=0; i<hotel->num_rooms; i++) {
        print_room(&hotel->rooms[i]);
    }

    printf("\n\n******** CUSTOMERS ********\n");
    printf("First Name\tLast Name\tRoom Number\n");
    for(int i=0; i<hotel->num_rooms; i++) {
        if(hotel->rooms[i].is_occupied) {
            print_customer(&hotel->customers[i]);
        }
    }
}

void check_in(struct Hotel* hotel) {
    if(hotel->num_rooms == MAX_N) {
        printf("Hotel is at maximum occupancy.\n");
        return;
    }

    struct Customer customer;
    printf("Enter customer's first name: ");
    scanf("%s", &customer.first_name);
    printf("Enter customer's last name: ");
    scanf("%s", &customer.last_name);

    printf("Rooms Available:\n");
    for(int i=0; i<hotel->num_rooms; i++) {
        if(!(hotel->rooms[i].is_occupied)) {
            printf("%d\t%d\t%d\n", hotel->rooms[i].room_number, hotel->rooms[i].type, hotel->rooms[i].rate);
        }
    }

    int room_number;
    printf("Enter a room number to reserve: ");
    scanf("%d", &room_number);
    for(int i=0; i<hotel->num_rooms; i++) {
        if(hotel->rooms[i].room_number == room_number) {
            if(hotel->rooms[i].is_occupied) {
                printf("Room number %d is already occupied.\n", room_number);
                return;
            }
            hotel->rooms[i].is_occupied = 1;
            hotel->customers[i] = customer;
            printf("Customer %s %s has checked into room %d\n", customer.first_name, customer.last_name, room_number);
            return;
        }
    }
    printf("Room number %d not found.\n", room_number);
}

void check_out(struct Hotel* hotel) {
    int room_number;
    printf("Enter room number to checkout: ");
    scanf("%d", &room_number);
    for(int i=0; i<hotel->num_rooms; i++) {
        if(hotel->rooms[i].room_number == room_number) {
            if(hotel->rooms[i].is_occupied) {
                printf("Customer %s %s has checked out of room %d\n",
                    hotel->customers[i].first_name, hotel->customers[i].last_name, room_number);
                hotel->rooms[i].is_occupied = 0;
                return;
            }
            else {
                printf("Room number %d is not occupied.\n", room_number);
                return;
            }
        }
    }
    printf("Room number %d not found.\n", room_number);
}

int main() {
    struct Hotel hotel;
    initialize_hotel(&hotel);

    hotel.rooms[0] = (struct Room){100, SINGLE, 50, 0};
    hotel.rooms[1] = (struct Room){101, SINGLE, 50, 0};
    hotel.rooms[2] = (struct Room){102, SINGLE, 50, 0};
    hotel.num_rooms = 3;

    int choice = 0;
    while(choice != 4) {
        show_menu();
        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                check_in(&hotel);
                break;
            case 2:
                check_out(&hotel);
                break;
            case 3:
                print_hotel(&hotel);
                break;
            case 4:
                printf("\n\nExiting the system...\n\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
                break;
        }
    }

    return 0;
}