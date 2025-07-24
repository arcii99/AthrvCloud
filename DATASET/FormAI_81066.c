//FormAI DATASET v1.0 Category: Hotel Management System ; Style: invasive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

// Define maximum limits
#define MAX_GUESTS 100
#define MAX_ROOMS 50
#define MAX_CHARS 50

// Define struct for room object
typedef struct {
    int room_number;
    int price;
    char type[MAX_CHARS];
    int status; // 0 - vacant, 1 - occupied
} Room;

// Define struct for guest object
typedef struct {
    int guest_id;
    char name[MAX_CHARS];
    char email[MAX_CHARS];
    int room_number;
} Guest;

// Define global variables
Room rooms[MAX_ROOMS];
Guest guests[MAX_GUESTS];
int number_of_guests = 0;
int number_of_rooms = 0;

// Function prototypes
void add_room();
void display_available_rooms();
void add_guest();
void display_guests();
void checkout_guest();

int main() {
    // Initialize the rooms to vacant status
    for (int i = 0; i < MAX_ROOMS; i++) {
        Room new_room = {
            i+1, // Room number
            (i%5 + 1) * 100, // Price
            "single", // Type
            0 // Status (vacant)
        };
        rooms[i] = new_room;
        number_of_rooms++;
    }
    
    // Run the program in a loop
    char input[MAX_CHARS];
    while(1) {
        printf("Welcome to C Hotel Management System!\n\n");
        printf("Please choose an option:\n");
        printf("1. Add a new room\n");
        printf("2. Display available rooms\n");
        printf("3. Add a new guest\n");
        printf("4. Display guests\n");
        printf("5. Checkout a guest\n");
        printf("6. Exit program\n\n");
        
        printf("Choice: ");
        fgets(input, sizeof(input), stdin);
        int choice = 0;
        if (sscanf(input, "%d", &choice) != 1) {
            printf("Invalid input, please try again.\n\n");
            continue; // Start again from the top of the loop
        }
        
        switch (choice) {
            case 1:
                add_room();
                break;
            case 2:
                display_available_rooms();
                break;
            case 3:
                add_guest();
                break;
            case 4:
                display_guests();
                break;
            case 5:
                checkout_guest();
                break;
            case 6:
                printf("Thank you for using C Hotel Management System!\n");
                exit(0); // End the program
            default:
                printf("Invalid input, please try again.\n\n");
        }
    }
    
    return 0;
}

void add_room() {
    // Check if there is room to add another room
    if (number_of_rooms >= MAX_ROOMS) {
        printf("The hotel is currently at maximum capacity.\n\n");
        return;
    }
    
    // Ask for details
    int room_number = number_of_rooms + 1; // Automatic room number
    int price = 0;
    char type[MAX_CHARS] = "single"; // Default type
    printf("Adding new room:\n");
    printf("Room number: %d\n", room_number);
    printf("Price per night (in dollars): ");
    char input[MAX_CHARS];
    fgets(input, sizeof(input), stdin);
    if (sscanf(input, "%d", &price) != 1) {
        printf("Invalid input, returning to main menu.\n\n");
        return;
    }
    printf("Room type (single/double/suite): ");
    fgets(input, sizeof(input), stdin);
    sscanf(input, "%s", type);
    for (int i = 0; type[i]; i++) {
        type[i] = tolower(type[i]); // Convert to lowercase
    }
    
    // Create new room object
    Room new_room = {
        room_number,
        price,
        type,
        0 // Status (vacant)
    };
    rooms[number_of_rooms] = new_room;
    number_of_rooms++;
    
    printf("New room added successfully.\n\n");
}

void display_available_rooms() {
    // Check if there are any rooms in the hotel
    if (number_of_rooms == 0) {
        printf("There are no rooms in the hotel.\n\n");
        return;
    }
    
    // Iterate through rooms and display only the vacant ones
    printf("List of available rooms:\n");
    printf("Room No.  Type       Price\n");
    for (int i = 0; i < number_of_rooms; i++) {
        if (rooms[i].status == 0) { // Vacant room
            printf("%-9d %-10s %d\n", 
                   rooms[i].room_number, 
                   rooms[i].type, 
                   rooms[i].price);
        }
    }
    printf("\n");
}

void add_guest() {
    // Check if there is room to add another guest
    if (number_of_guests >= MAX_GUESTS) {
        printf("The hotel is currently at maximum capacity.\n\n");
        return;
    }
    
    // Ask for details
    int guest_id = number_of_guests + 1; // Automatic guest ID
    char name[MAX_CHARS];
    char email[MAX_CHARS];
    int room_number = 0; // Default value
    printf("Adding new guest:\n");
    printf("Guest ID: %d\n", guest_id);
    printf("Guest name: ");
    char input[MAX_CHARS];
    fgets(input, sizeof(input), stdin);
    sscanf(input, "%[^\n]s", name); // Read entire input until newline
    printf("Guest email address: ");
    fgets(input, sizeof(input), stdin);
    sscanf(input, "%s", email);
    printf("Room number: ");
    fgets(input, sizeof(input), stdin);
    if (sscanf(input, "%d", &room_number) != 1) {
        printf("Invalid input, returning to main menu.\n\n");
        return;
    }
    
    // Verify that the room is available
    int room_index = room_number - 1;
    if (room_index < number_of_rooms && rooms[room_index].status == 0) {
        rooms[room_index].status = 1; // Occupy the room
    } else {
        printf("The room is not available, please choose another room.\n\n");
        return;
    }
    
    // Create new guest object
    Guest new_guest = {
        guest_id,
        name,
        email,
        room_number
    };
    guests[number_of_guests] = new_guest;
    number_of_guests++;
    
    printf("New guest added successfully.\n\n");
}

void display_guests() {
    // Check if there are any guests in the hotel
    if (number_of_guests == 0) {
        printf("There are no guests in the hotel.\n\n");
        return;
    }
    
    // Iterate through guests and display their details
    printf("List of guests:\n");
    printf("Guest ID  Name                 Email                 Room No.\n");
    for (int i = 0; i < number_of_guests; i++) {
        printf("%-9d %-20s %-20s %-7d\n",
               guests[i].guest_id,
               guests[i].name,
               guests[i].email,
               guests[i].room_number);
    }
    printf("\n");
}

void checkout_guest() {
    // Check if there are any guests in the hotel
    if (number_of_guests == 0) {
        printf("There are no guests in the hotel.\n\n");
        return;
    }
    
    // Ask for the room number
    int room_number = 0;
    printf("Checking out a guest:\n");
    printf("Room number: ");
    char input[MAX_CHARS];
    fgets(input, sizeof(input), stdin);
    if (sscanf(input, "%d", &room_number) != 1) {
        printf("Invalid input, returning to main menu.\n\n");
        return;
    }
    
    // Verify that the room is occupied
    int room_index = room_number - 1;
    if (room_index < number_of_rooms && rooms[room_index].status == 1) {
        rooms[room_index].status = 0; // Vacate the room
        
        // Find the corresponding guest and remove them
        for (int i = 0; i < number_of_guests; i++) {
            if (guests[i].room_number == room_number) {
                // Move all the guests after this one up one position
                for (int j = i+1; j < number_of_guests; j++) {
                    guests[j-1] = guests[j];
                }
                number_of_guests--;
                printf("Guest checked out successfully.\n\n");
                return;
            }
        }
    } else {
        printf("The room is not occupied, please try again.\n\n");
        return;
    }
}