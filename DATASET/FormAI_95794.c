//FormAI DATASET v1.0 Category: Hotel Management System ; Style: decentralized
#include <stdio.h>
#include <string.h>

// Define the maximum number of rooms in the hotel
#define MAX_ROOMS 100

// Define the maximum length of the room number
#define ROOM_NUMBER_LENGTH 4

// Declare the Room struct
struct Room {
    char room_number[ROOM_NUMBER_LENGTH + 1];
    int occupancy;
};

int num_rooms = 10; // Set the initial number of rooms

// Declare the rooms array
struct Room rooms[MAX_ROOMS];

// Define the function to print the room status message
void print_room_status(int room_index) {
    printf("Room %s is currently %s.\n", rooms[room_index].room_number, rooms[room_index].occupancy ? "occupied" : "vacant");
}

int main() {
    // Initialize the room data
    for(int i = 0; i < num_rooms; i++) {
        sprintf(rooms[i].room_number, "%03d", i+1); // Fill the room number with leading zeros
        rooms[i].occupancy = 0; // Set the occupancy to 0 (vacant)
    }

    // Print the welcome message
    printf("Welcome to the Hotel Management System.\n");
    printf("There are currently %d rooms in the hotel.\n", num_rooms);

    // Loop until the user chooses to exit
    while(1) {
        // Print the main menu
        printf("\n");
        printf("Main Menu\n");
        printf("1. View Room Status\n");
        printf("2. Book Room\n");
        printf("3. Check Out\n");
        printf("4. Exit\n");

        // Get the user's choice
        int choice;
        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1: {
                // View Room Status
                printf("\n");
                for(int i = 0; i < num_rooms; i++) {
                    print_room_status(i);
                }
                break;
            }
            case 2: {
                // Book Room
                printf("\n");
                printf("Enter the room number: ");
                char room_number[ROOM_NUMBER_LENGTH + 1];
                scanf("%s", room_number);

                int booking_successful = 0;
                for(int i = 0; i < num_rooms; i++) {
                    if(strcmp(rooms[i].room_number, room_number) == 0) {
                        if(rooms[i].occupancy == 0) {
                            rooms[i].occupancy = 1; // Set the occupancy to 1 (occupied)
                            printf("Room successfully booked.\n");
                            booking_successful = 1;
                        } else {
                            printf("Room is already occupied.\n");
                        }
                        break;
                    }
                }

                if(!booking_successful) {
                    printf("Invalid room number.\n");
                }

                break;
            }
            case 3: {
                // Check Out
                printf("\n");
                printf("Enter the room number: ");
                char room_number[ROOM_NUMBER_LENGTH + 1];
                scanf("%s", room_number);

                int check_out_successful = 0;
                for(int i = 0; i < num_rooms; i++) {
                    if(strcmp(rooms[i].room_number, room_number) == 0) {
                        if(rooms[i].occupancy == 1) {
                            rooms[i].occupancy = 0; // Set the occupancy to 0 (vacant)
                            printf("Check-out successful.\n");
                            check_out_successful = 1;
                        } else {
                            printf("Room is already vacant.\n");
                        }
                        break;
                    }
                }

                if(!check_out_successful) {
                    printf("Invalid room number.\n");
                }

                break;
            }
            case 4: {
                // Exit
                printf("\n");
                printf("Thank you for using the Hotel Management System.\n");
                return 0;
            }
            default: {
                printf("\n");
                printf("Invalid choice. Please try again.\n");
            }
        }
    }
}