//FormAI DATASET v1.0 Category: Hotel Management System ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Struct to store guest information
struct Guest {
    char name[50];
    int roomNumber;
    int numNights;
    float costPerNight;
};

// Struct to store room information
struct Room {
    int roomNumber;
    int numBeds;
    float costPerNight;
    char amenities[50];
    int available;
};

// Function to print the main menu
void printMainMenu() {
    printf("\n\nWelcome to the C Hotel Management System!\n");
    printf("1. Make a reservation\n");
    printf("2. View room availability\n");
    printf("3. Check out a guest\n");
    printf("4. Exit\n");
}

// Function to display available rooms
void displayAvailableRooms(struct Room rooms[], int numRooms) {
    printf("\n\nAvailable Rooms:\n");
    printf("Room Number\tNumber of Beds\tCost per Night\tAmenities\n");
    for (int i = 0; i < numRooms; i++) {
        if (rooms[i].available == 1) {
            printf("%d\t\t%d\t\t%.2f\t\t%s\n", rooms[i].roomNumber, rooms[i].numBeds,
                   rooms[i].costPerNight, rooms[i].amenities);
        }
    }
}

int main() {
    // Create an array of Room structs to store room information
    int numRooms = 10;
    struct Room rooms[numRooms];
    for (int i = 0; i < numRooms; i++) {
        rooms[i].roomNumber = i+1;
        rooms[i].numBeds = 2;
        rooms[i].costPerNight = 100.00;
        strcpy(rooms[i].amenities, "TV, Wi-Fi, Fridge");
        rooms[i].available = 1;
    }

    // Create an array of Guest structs to store guest information
    int numGuests = 10;
    struct Guest guests[numGuests];
    for (int i = 0; i < numGuests; i++) {
        strcpy(guests[i].name, "");
        guests[i].roomNumber = -1;
        guests[i].numNights = 0;
        guests[i].costPerNight = 0.00;
    }

    // Main loop
    int choice = 0;
    while (choice != 4) {
        printMainMenu();
        printf("Enter your choice: ");
        scanf("%d", &choice);

        if (choice == 1) { // Make a reservation
            char name[50];
            int roomNumber, numNights;

            // Get guest information
            printf("\n\nEnter guest name: ");
            scanf("%s", name);

            printf("Enter room number (1-10): ");
            scanf("%d", &roomNumber);

            // Check if room number is valid and available
            if (roomNumber < 1 || roomNumber > numRooms) {
                printf("Invalid room number.\n");
                continue;
            } else if (rooms[roomNumber-1].available == 0) {
                printf("Room is not available.\n");
                continue;
            }

            printf("Enter number of nights: ");
            scanf("%d", &numNights);

            // Update guest and room information
            strcpy(guests[roomNumber-1].name, name);
            guests[roomNumber-1].roomNumber = roomNumber;
            guests[roomNumber-1].numNights = numNights;
            guests[roomNumber-1].costPerNight = rooms[roomNumber-1].costPerNight;

            rooms[roomNumber-1].available = 0;

            printf("Reservation successful.\n");
        } else if (choice == 2) { // View room availability
            displayAvailableRooms(rooms, numRooms);
        } else if (choice == 3) { // Check out a guest
            int roomNumber;

            printf("\nEnter room number to check out: ");
            scanf("%d", &roomNumber);

            // Check if room number is valid and occupied
            if (roomNumber < 1 || roomNumber > numRooms) {
                printf("Invalid room number.\n");
                continue;
            } else if (rooms[roomNumber-1].available == 1) {
                printf("Room is not occupied.\n");
                continue;
            }

            // Calculate total cost and display receipt
            float totalCost = guests[roomNumber-1].numNights * guests[roomNumber-1].costPerNight;
            printf("\n\nGuest Name: %s\n", guests[roomNumber-1].name);
            printf("Room Number: %d\n", guests[roomNumber-1].roomNumber);
            printf("Number of Nights: %d\n", guests[roomNumber-1].numNights);
            printf("Cost per Night: %.2f\n", guests[roomNumber-1].costPerNight);
            printf("Total Cost: %.2f\n", totalCost);

            // Reset guest and room information
            strcpy(guests[roomNumber-1].name, "");
            guests[roomNumber-1].roomNumber = -1;
            guests[roomNumber-1].numNights = 0;
            guests[roomNumber-1].costPerNight = 0.00;

            rooms[roomNumber-1].available = 1;

        } else if (choice == 4) { // Exit
            printf("\nGoodbye!\n");
        } else { // Invalid choice
            printf("\n\nInvalid choice. Please try again.\n");
        }
    }

    return 0;
}