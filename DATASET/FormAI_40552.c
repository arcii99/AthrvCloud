//FormAI DATASET v1.0 Category: Hotel Management System ; Style: Claude Shannon
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the struct for holding guest information
struct guest {
    char name[50];
    int age;
    char address[100];
    char email[50];
    int roomNumber;
};

// Define maximum number of rooms
#define MAX_ROOMS 50

// Declare a global array of guests
struct guest guests[MAX_ROOMS];

// Declare function for displaying main menu
void displayMenu() {
    printf("\n=====================");
    printf("\nHotel Management System");
    printf("\n=====================\n");
    printf("1. Check in\n");
    printf("2. Check out\n");
    printf("3. Display guests\n");
    printf("4. Exit system\n");
}

// Declare function for checking in a guest
void checkIn() {
    printf("\nEnter guest name: ");
    char name[50];
    scanf("%s", &name);

    printf("Enter guest age: ");
    int age;
    scanf("%d", &age);

    printf("Enter guest address: ");
    char address[100];
    scanf("%s", &address);

    printf("Enter guest email: ");
    char email[50];
    scanf("%s", &email);

    int roomNumber;

    // Find an empty room for the guest
    for (int i = 0; i < MAX_ROOMS; i++) {
        if (guests[i].roomNumber == 0) {
            roomNumber = i + 1;
            guests[i].roomNumber = roomNumber;
            break;
        }
    }

    // Create the guest struct and add to the global array
    struct guest newGuest;
    strcpy(newGuest.name, name);
    newGuest.age = age;
    strcpy(newGuest.address, address);
    strcpy(newGuest.email, email);
    newGuest.roomNumber = roomNumber;

    guests[roomNumber - 1] = newGuest;

    printf("\nGuest checked in to room %d.\n", roomNumber);
}

// Declare function for checking out a guest
void checkOut() {
    printf("\nEnter room number of guest to check out: ");
    int roomNumber;
    scanf("%d", &roomNumber);

    // Look up the guest by room number and clear the guest struct
    for (int i = 0; i < MAX_ROOMS; i++) {
        if (guests[i].roomNumber == roomNumber) {
            guests[i].roomNumber = 0;
            printf("\nGuest checked out of room %d.\n", roomNumber);
            return;
        }
    }

    printf("\nRoom number not found.\n");
}

// Declare function for displaying list of guests
void displayGuests() {
    printf("\nGuests:\n");
    for (int i = 0; i < MAX_ROOMS; i++) {
        if (guests[i].roomNumber != 0) {
            printf("%d. %s, %d, %s, %s\n", guests[i].roomNumber, guests[i].name, guests[i].age, guests[i].address, guests[i].email);
        }
    }
}

// Declare the main function
int main() {

    // Initialize the global array of guests
    for (int i = 0; i < MAX_ROOMS; i++) {
        guests[i].roomNumber = 0;
    }

    while (1) {
        // Display the main menu and get user input
        displayMenu();
        int choice;
        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        // Handle user input based on their menu choice
        switch (choice) {
            case 1:
                checkIn();
                break;
            case 2:
                checkOut();
                break;
            case 3:
                displayGuests();
                break;
            case 4:
                printf("\nExiting system.\n");
                exit(0);
            default:
                printf("\nInvalid input.\n");
        }
    }
}