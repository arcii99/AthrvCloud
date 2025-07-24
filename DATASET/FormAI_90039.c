//FormAI DATASET v1.0 Category: Hotel Management System ; Style: genious
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

// Structure definition for storing hotel room information
struct room {
    int roomNumber;
    char roomType[10];
    float roomRent;
    int isOccupied;
    char customerName[20];
    char customerPhoneNumber[12];
};

// Function prototypes
void displayRooms(struct room[], int);
void searchRooms(struct room[], int);
void bookRoom(struct room[], int);
void checkoutRoom(struct room[], int);

// Main function
int main() {
    // Initialize hotel rooms
    struct room hotelRooms[10];
    for (int i = 0; i < 10; i++) {
        hotelRooms[i].roomNumber = i+1;
        strcpy(hotelRooms[i].roomType, "Standard");
        hotelRooms[i].roomRent = 1000.0;
        hotelRooms[i].isOccupied = 0;
        strcpy(hotelRooms[i].customerName, "");
        strcpy(hotelRooms[i].customerPhoneNumber, "");
    }

    int choice;
    do {
        // Display menu and get user choice
        printf("\n===== Hotel Management System =====\n");
        printf("1. Display Rooms\n");
        printf("2. Search Rooms\n");
        printf("3. Book Room\n");
        printf("4. Checkout Room\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        // Call appropriate function based on user choice
        switch (choice) {
            case 1:
                displayRooms(hotelRooms, 10);
                break;
            case 2:
                searchRooms(hotelRooms, 10);
                break;
            case 3:
                bookRoom(hotelRooms, 10);
                break;
            case 4:
                checkoutRoom(hotelRooms, 10);
                break;
            case 5:
                printf("\nExiting...\n");
                exit(0);
            default:
                printf("\nInvalid choice. Please enter a number between 1 and 5.\n");
        }
    } while (1);

    return 0;
}

// Function to display all rooms in the hotel
void displayRooms(struct room hotelRooms[], int numRooms) {
    printf("\n===== List of Rooms =====\n");
    printf("%-10s %-10s %-10s %-20s %s\n", "Room No.", "Type", "Rent", "Customer Name", "Phone Number");
    for (int i = 0; i < numRooms; i++) {
        printf("%-10d %-10s %-10.2f ", hotelRooms[i].roomNumber, hotelRooms[i].roomType, hotelRooms[i].roomRent);
        if (hotelRooms[i].isOccupied) {
            printf("%-20s %s\n", hotelRooms[i].customerName, hotelRooms[i].customerPhoneNumber);
        } else {
            printf("%-20s %s\n", "-", "-");
        }
    }
}

// Function to search for a room by room number
void searchRooms(struct room hotelRooms[], int numRooms) {
    int roomNumber;
    printf("\nEnter room number to search for: ");
    scanf("%d", &roomNumber);
    for (int i = 0; i < numRooms; i++) {
        if (hotelRooms[i].roomNumber == roomNumber) {
            printf("\n===== Room Details =====\n");
            printf("%-10s %-10s %-10s %-20s %s\n", "Room No.", "Type", "Rent", "Customer Name", "Phone Number");
            printf("%-10d %-10s %-10.2f ", hotelRooms[i].roomNumber, hotelRooms[i].roomType, hotelRooms[i].roomRent);
            if (hotelRooms[i].isOccupied) {
                printf("%-20s %s\n", hotelRooms[i].customerName, hotelRooms[i].customerPhoneNumber);
            } else {
                printf("%-20s %s\n", "-", "-");
            }
            return;
        }
    }
    printf("\nRoom not found.\n");
}

// Function to book a room
void bookRoom(struct room hotelRooms[], int numRooms) {
    int roomNumber;
    printf("\nEnter room number to book: ");
    scanf("%d", &roomNumber);
    for (int i = 0; i < numRooms; i++) {
        if (hotelRooms[i].roomNumber == roomNumber) {
            if (hotelRooms[i].isOccupied) {
                printf("\nRoom is already occupied.\n");
                return;
            }
            printf("\nEnter customer name: ");
            scanf("%s", hotelRooms[i].customerName);
            printf("Enter customer phone number: ");
            scanf("%s", hotelRooms[i].customerPhoneNumber);
            hotelRooms[i].isOccupied = 1;
            printf("\nRoom booked successfully.\n");
            return;
        }
    }
    printf("\nRoom not found.\n");
}

// Function to checkout a room
void checkoutRoom(struct room hotelRooms[], int numRooms) {
    int roomNumber;
    printf("\nEnter room number to checkout: ");
    scanf("%d", &roomNumber);
    for (int i = 0; i < numRooms; i++) {
        if (hotelRooms[i].roomNumber == roomNumber) {
            if (!hotelRooms[i].isOccupied) {
                printf("\nRoom is already vacant.\n");
                return;
            }
            hotelRooms[i].isOccupied = 0;
            strcpy(hotelRooms[i].customerName, "");
            strcpy(hotelRooms[i].customerPhoneNumber, "");
            printf("\nRoom checkout successful.\n");
            return;
        }
    }
    printf("\nRoom not found.\n");
}