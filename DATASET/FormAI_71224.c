//FormAI DATASET v1.0 Category: Hotel Management System ; Style: artistic
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

// Define a structure to represent the room information
struct room {
    int id;                     // Room number
    char type[20];              // Room type (single, double, suite)
    int price;                  // Room price per night
    char status[15];            // Room status (available, occupied, maintenance)
};

// Define a structure to represent the guest information
struct guest {
    char name[100];             // Guest name
    int age;                    // Guest age
};

int main() {
    // Initialize the hotel with 10 rooms
    struct room hotel[10];
    int i;

    // Set initial room information
    for(i=0; i<10; i++) {
        hotel[i].id = i+1;
        strcpy(hotel[i].type, "single");
        hotel[i].price = 50;
        strcpy(hotel[i].status, "available");
    }

    // Loop for main program interface
    int option = 1;
    while(option != 4) {
        // Display main menu
        printf("\n--------------------------------\n");
        printf("Welcome to the Hotel Management System\n");
        printf("--------------------------------\n");
        printf("1. Book a room\n");
        printf("2. Check out\n");
        printf("3. View room details\n");
        printf("4. Exit\n");
        printf("\nEnter an option: ");

        // Get user input
        scanf("%d", &option);

        // Switch statement for handling user options
        switch(option) {
            case 1:
                bookRoom(hotel);    // Call function to book a room
                break;
            case 2:
                checkOut(hotel);    // Call function to check out
                break;
            case 3:
                viewRoomDetails(hotel); // Call function to view room details
                break;
            case 4:
                printf("\nGoodbye!\n");
                break;
            default:
                printf("\nInvalid option. Please try again.\n");
                break;
        }
    }

    return 0;
}

// Function to book a room
void bookRoom(struct room hotel[]) {
    // Display available rooms
    int i;
    printf("\nAvailable Rooms:\n");
    for(i=0; i<10; i++) {
        if(strcmp(hotel[i].status, "available") == 0) {
            printf("%d. %s room - $%d\n", hotel[i].id, hotel[i].type, hotel[i].price);
        }
    }

    // Get room choice from user
    int choice;
    printf("Enter a room number to book: ");
    scanf("%d", &choice);

    // Confirm room availability and get guest information
    if(strcmp(hotel[choice-1].status, "available") == 0) {
        struct guest newGuest;
        printf("Enter guest name: ");
        scanf("%s", newGuest.name);
        printf("Enter guest age: ");
        scanf("%d", &newGuest.age);

        // Update room status and display booking confirmation
        strcpy(hotel[choice-1].status, "occupied");
        printf("\nBooking confirmed for room %d.\nGuest Name: %s\nGuest Age: %d\n\n", hotel[choice-1].id, newGuest.name, newGuest.age);
    }
    else {
        printf("\nRoom is not available. Please choose another room.\n");
    }
}

// Function to check out
void checkOut(struct room hotel[]) {
    // Display occupied rooms
    int i;
    printf("\nOccupied Rooms:\n");
    for(i=0; i<10; i++) {
        if(strcmp(hotel[i].status, "occupied") == 0) {
            printf("%d. %s room\n", hotel[i].id, hotel[i].type);
        }
    }

    // Get room choice from user
    int choice;
    printf("Enter a room number to check out: ");
    scanf("%d", &choice);

    // Confirm room is occupied and display bill
    if(strcmp(hotel[choice-1].status, "occupied") == 0) {
        int nights;
        printf("Enter number of nights: ");
        scanf("%d", &nights);
        int total = nights * hotel[choice-1].price;
        printf("\nBill for Room %d:\n%d nights at $%d per night = $%d\nThank you for staying with us!\n\n", hotel[choice-1].id, nights, hotel[choice-1].price, total);

        // Update room status
        strcpy(hotel[choice-1].status, "available");
    }
    else {
        printf("\nRoom is not occupied. Please choose another room.\n");
    }
}

// Function to view room details
void viewRoomDetails(struct room hotel[]) {
    // Display all room details
    int i;
    printf("\nRoom Details:\n");
    for(i=0; i<10; i++) {
        printf("Room %d - %s room - $%d per night - %s\n", hotel[i].id, hotel[i].type, hotel[i].price, hotel[i].status);
    }
}