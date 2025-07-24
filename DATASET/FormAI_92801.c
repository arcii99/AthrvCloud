//FormAI DATASET v1.0 Category: Hotel Management System ; Style: post-apocalyptic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Hotel struct to hold information about each room
typedef struct {
    int room_number;
    char guest_name[50];
    int occupied;
} Hotel;

// Function to initialize hotel rooms
void initHotel(Hotel *hotel, int size) {
    for (int i = 0; i < size; i++) {
        hotel[i].room_number = i+1;
        strcpy(hotel[i].guest_name, "");
        hotel[i].occupied = 0;
    }
}

// Function to display menu and get user input
int menu() {
    int choice;
    printf("\nEnter a number to select an option:\n\n");
    printf("1. Check in\n");
    printf("2. Check out\n");
    printf("3. View occupied rooms\n");
    printf("4. View available rooms\n");
    printf("5. Exit\n");
    printf("\nEnter choice: ");
    scanf("%d", &choice);
    return choice;
}

// Function to check user into a hotel room
void checkIn(Hotel *hotel, int size) {
    int room_num;
    char guest_name[50];
    printf("\nEnter room number: ");
    scanf("%d", &room_num);
    if (room_num < 1 || room_num > size) {
        printf("\nInvalid room number.\n");
        return;
    }
    if (hotel[room_num-1].occupied == 1) {
        printf("\nRoom is already occupied.\n");
        return;
    }
    hotel[room_num-1].room_number = room_num;
    printf("\nEnter guest name: ");
    scanf("%s", guest_name);
    strcpy(hotel[room_num-1].guest_name, guest_name);
    hotel[room_num-1].occupied = 1;
    printf("\nChecked in successfully.\n");
}

// Function to check user out of a hotel room
void checkOut(Hotel *hotel, int size) {
    int room_num;
    printf("\nEnter room number: ");
    scanf("%d", &room_num);
    if (room_num < 1 || room_num > size) {
        printf("\nInvalid room number.\n");
        return;
    }
    if (hotel[room_num-1].occupied == 0) {
        printf("\nRoom is already unoccupied.\n");
        return;
    }
    strcpy(hotel[room_num-1].guest_name, "");
    hotel[room_num-1].occupied = 0;
    printf("\nChecked out successfully.\n");
}

// Function to view occupied hotel rooms
void viewOccupiedRooms(Hotel *hotel, int size) {
    printf("\nOccupied rooms:\n");
    for (int i = 0; i < size; i++) {
        if (hotel[i].occupied == 1) {
            printf("Room %d: %s\n", hotel[i].room_number, hotel[i].guest_name);
        }
    }
}

// Function to view available hotel rooms
void viewAvailableRooms(Hotel *hotel, int size) {
    printf("\nAvailable rooms:\n");
    for (int i = 0; i < size; i++) {
        if (hotel[i].occupied == 0) {
            printf("Room %d\n", hotel[i].room_number);
        }
    }
}

int main() {
    // Create hotel with 10 rooms
    Hotel hotel[10];
    initHotel(hotel, 10);

    // Display menu and get user input
    int choice;
    do {
        choice = menu();
        switch (choice) {
            case 1:
                checkIn(hotel, 10);
                break;
            case 2:
                checkOut(hotel, 10);
                break;
            case 3:
                viewOccupiedRooms(hotel, 10);
                break;
            case 4:
                viewAvailableRooms(hotel, 10);
                break;
            case 5:
                printf("\nExiting hotel management system...\n");
                break;
            default:
                printf("\nInvalid choice.\n");
                break;
        }
    } while (choice != 5);

    return 0;
}