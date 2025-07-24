//FormAI DATASET v1.0 Category: Hotel Management System ; Style: visionary
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Global Variables
int rooms[100] = {0}; // Number of rooms available
char guest_names[100][50];
int guest_checkin[100] = {0}; // Used to keep track of when guests checked in
int guest_checkout[100] = {0}; // Used to keep track of when guests checked out

// Function Prototypes
void display_menu();
void book_room();
void view_bookings();
void checkout();

int main() {
    int choice;
    
    // Initialize all available rooms
    for (int i = 0; i < 100; i++) {
        rooms[i] = 1;
    }
    
    printf("\n------------------------------\n");
    printf("          WELCOME TO          \n");
    printf("     C HOTEL MANAGEMENT SYSTEM \n");
    printf("------------------------------\n");
    
    do {
        display_menu();
        scanf("%d", &choice);
        
        switch(choice) {
            case 1:
                book_room();
                break;
            case 2:
                view_bookings();
                break;
            case 3:
                checkout();
                break;
            case 4:
                printf("Thank you for using C Hotel Management System!\n");
                exit(0);
            default:
                printf("Invalid choice!\n");
                break;
        }
    } while (1);
    
    return 0;
}

// Function Definitions
void display_menu() {
    printf("\n-----------------------------\n");
    printf("           MENU\n");
    printf("-----------------------------\n");
    printf("1. Book a Room\n");
    printf("2. View Bookings\n");
    printf("3. Checkout\n");
    printf("4. Exit\n");
}

void book_room() {
    int room_num, days;
    char name[50];
    
    printf("Enter your name: ");
    scanf("%s", name);
    
    printf("Enter the room number you want to book: ");
    scanf("%d", &room_num);
    
    if (rooms[room_num] == 0) {
        printf("Sorry, the room is already booked!\n");
        return;
    }
    
    printf("Enter the number of days you want to stay: ");
    scanf("%d", &days);
    
    // Update Global Variables
    strcpy(guest_names[room_num], name);
    guest_checkin[room_num] = 1;
    guest_checkout[room_num] = days;
    rooms[room_num] = 0;
    
    printf("Room %d has been booked successfully for %d days!\n", room_num, days);
}

void view_bookings() {
    printf("_________________________________________________________\n");
    printf("| Room Number | Guest Name              | Checkout Date |\n");
    printf("_________________________________________________________\n");
    for (int i = 0; i < 100; i++) {
        if (guest_checkin[i] == 1) {
            printf("| %-11d | %-23s | %-12d |\n", i, guest_names[i], guest_checkout[i]);
        }
    }
    printf("_________________________________________________________\n");
}

void checkout() {
    int room_num;
    
    printf("Enter the room number to checkout: ");
    scanf("%d", &room_num);
    
    if (guest_checkin[room_num] == 0) {
        printf("Room %d is not booked!\n", room_num);
        return;
    }
    
    printf("Guest Name: %s\n", guest_names[room_num]);
    printf("Checkout Date: %d\n", guest_checkout[room_num]);
    printf("Total Bill: Rs. %d\n", 1000 * guest_checkout[room_num]);
    
    // Update Global Variables
    guest_checkin[room_num] = 0;
    guest_checkout[room_num] = 0;
    rooms[room_num] = 1;
    
    printf("Checkout Successful!\n");
}