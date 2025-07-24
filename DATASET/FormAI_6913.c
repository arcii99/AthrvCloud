//FormAI DATASET v1.0 Category: Hotel Management System ; Style: irregular
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

// Define structure for a hotel room
struct room {
    int number;
    char type[20];
    float price;
    int booked;
};

// Define structure for a hotel customer
struct customer {
    char name[20];
    int room_number;
    int days_stayed;
};

// Declare variables and pointers
int num_rooms;
int num_customers;
struct room *rooms;
struct customer *customers;

// Function to display a menu of options to the user
void display_menu() {
    printf("\n");
    printf("Welcome to the C Hotel Management System!\n");
    printf("Please select an option:\n");
    printf("1. View rooms\n");
    printf("2. Book a room\n");
    printf("3. View customers\n");
    printf("4. Check out a customer\n");
    printf("5. Exit\n");
}

// Function to initialize the hotel with some rooms
void init_hotel() {
    num_rooms = 5;
    rooms = (struct room *)malloc(num_rooms * sizeof(struct room));
    rooms[0].number = 101;
    strcpy(rooms[0].type, "Single");
    rooms[0].price = 50;
    rooms[0].booked = 0;
    rooms[1].number = 102;
    strcpy(rooms[1].type, "Double");
    rooms[1].price = 75;
    rooms[1].booked = 0;
    rooms[2].number = 201;
    strcpy(rooms[2].type, "Suite");
    rooms[2].price = 100;
    rooms[2].booked = 0;
    rooms[3].number = 202;
    strcpy(rooms[3].type, "Deluxe");
    rooms[3].price = 125;
    rooms[3].booked = 0;
    rooms[4].number = 301;
    strcpy(rooms[4].type, "Penthouse");
    rooms[4].price = 150;
    rooms[4].booked = 0;
}

// Function to display all the rooms in the hotel
void view_rooms() {
    printf("\nRooms available at C Hotel:\n");
    for(int i = 0; i < num_rooms; i++) {
        printf("Room Number: %d\n", rooms[i].number);
        printf("Room Type: %s\n", rooms[i].type);
        printf("Room Price: %.2f\n", rooms[i].price);
        printf("Booked: %s\n", rooms[i].booked ? "Yes" : "No");
        printf("\n");
    }
}

// Function to book a room for a customer
void book_room() {
    int room_number;
    int days_stayed;
    char name[20];

    printf("\nPlease enter your name: ");
    scanf("%s", name);
    printf("Please enter the room number you wish to book: ");
    scanf("%d", &room_number);
    printf("Please enter the number of days you wish to stay: ");
    scanf("%d", &days_stayed);

    for(int i = 0; i < num_rooms; i++) {
        if(rooms[i].number == room_number) {
            if(rooms[i].booked) {
                printf("Room is already booked!\n");
                return;
            }
            else {
                strcpy(customers[num_customers].name, name);
                customers[num_customers].room_number = room_number;
                customers[num_customers].days_stayed = days_stayed;
                num_customers++;
                rooms[i].booked = 1;
                printf("Room booked successfully!\n");
                return;
            }
        }
    }

    printf("No room with number %d found!\n", room_number);
}

// Function to view all the customers in the hotel
void view_customers() {
    printf("\nList of customers at C Hotel:\n");
    for(int i = 0; i < num_customers; i++) {
        printf("Customer Name: %s\n", customers[i].name);
        printf("Room Number: %d\n", customers[i].room_number);
        printf("Days Stayed: %d\n", customers[i].days_stayed);
        printf("\n");
    }
}

// Function to check out a customer and free up their room
void check_out() {
    int room_number;
    printf("\nPlease enter the room number of the customer who is checking out: ");
    scanf("%d", &room_number);

    for(int i = 0; i < num_customers; i++) {
        if(customers[i].room_number == room_number) {
            for(int j = 0; j < num_rooms; j++) {
                if(rooms[j].number == room_number) {
                    rooms[j].booked = 0;
                    printf("%s has checked out successfully and their room has been freed up!\n", customers[i].name);
                    customers[i] = customers[num_customers-1];
                    num_customers--;
                    return;
                }
            }
        }
    }

    printf("Room number %d not found!\n", room_number);
}

int main() {
    init_hotel();
    customers = (struct customer *)malloc(num_rooms * sizeof(struct customer));
    num_customers = 0;

    int choice;

    while(1) {
        display_menu();
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                view_rooms();
                break;
            case 2:
                book_room();
                break;
            case 3:
                view_customers();
                break;
            case 4:
                check_out();
                break;
            case 5:
                printf("Thank you for using C Hotel Management System!\n");
                free(rooms);
                free(customers);
                return 0;
            default:
                printf("Invalid choice! Please try again.\n");
        }
    }

    return 0;
}