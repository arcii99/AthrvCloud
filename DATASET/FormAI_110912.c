//FormAI DATASET v1.0 Category: Hotel Management System ; Style: ultraprecise
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

// Define a structure to hold details of a single hotel room
typedef struct {
    int room_number;
    char guest_name[50];
    char guest_phone[15];
} hotel_room;

// Define a function that initializes all hotel rooms to empty
void initialize_rooms(hotel_room rooms[], int num_rooms) {
    int i;
    for(i = 0; i < num_rooms; i++) {
        rooms[i].room_number = i + 1;
        strcpy(rooms[i].guest_name, "");
        strcpy(rooms[i].guest_phone, "");
    }
}

// Define a function that prints the details of a single hotel room
void print_room_details(hotel_room room) {
    printf("\n Room Number: %d", room.room_number);
    printf("\n Guest Name: %s", room.guest_name);
    printf("\n Guest Phone: %s", room.guest_phone);
}

// Define a function that prints the details of all hotel rooms
void print_all_rooms(hotel_room rooms[], int num_rooms) {
    int i;
    for(i = 0; i < num_rooms; i++) {
        print_room_details(rooms[i]);
    }
}

int main() {
    int num_rooms = 10;  // Assumed number of rooms
    hotel_room rooms[num_rooms];   // Array to hold all rooms' details
    int choice = 0;  // Integer variable to store user's choice
    int room_number;  // Integer variable to store the room number
    char guest_name[50];   // String variable to store the guest name
    char guest_phone[15];  // String variable to store the guest phone number
    
    // Initialize all rooms as empty
    initialize_rooms(rooms, num_rooms);

    // Print the initial status of all rooms
    printf("\n Initial status of rooms:");
    print_all_rooms(rooms, num_rooms);
    
    // Start the main loop of the program
    while(choice != 4) {
        printf("\n\n --------------");
        printf("\n HOTEL MANAGEMENT");
        printf("\n --------------");
        printf("\n 1. Check-in");
        printf("\n 2. Check-out");
        printf("\n 3. View all rooms");
        printf("\n 4. Exit");
        printf("\n Enter your choice (1-4): ");
        
        // Take the user's choice as input
        scanf("%d", &choice);
        
        // Take appropriate action based on the user's choice
        switch(choice) {
            case 1: // Check-in
                printf("\n Enter the room number: ");
                scanf("%d", &room_number);
                if(room_number < 1 || room_number > num_rooms) {
                    printf("\n Invalid room number. Room number should be between 1 and %d", num_rooms);
                    break;
                }
                if(strlen(rooms[room_number-1].guest_name) > 0) {
                    printf("\n Room %d is already occupied by %s", room_number, rooms[room_number-1].guest_name);
                    break;
                }
                printf("\n Enter the guest name: ");
                scanf("%s", guest_name);
                printf("\n Enter the guest phone: ");
                scanf("%s", guest_phone);
                strcpy(rooms[room_number-1].guest_name, guest_name);
                strcpy(rooms[room_number-1].guest_phone, guest_phone);
                printf("\n Room %d has been checked-in by %s", room_number, guest_name);
                break;
                
            case 2: // Check-out
                printf("\n Enter the room number: ");
                scanf("%d", &room_number);
                if(room_number < 1 || room_number > num_rooms) {
                    printf("\n Invalid room number. Room number should be between 1 and %d", num_rooms);
                    break;
                }
                if(strlen(rooms[room_number-1].guest_name) == 0) {
                    printf("\n Room %d is already vacant", room_number);
                    break;
                }
                printf("\n %s has checked-out from room %d", rooms[room_number-1].guest_name, room_number);
                strcpy(rooms[room_number-1].guest_name, "");
                strcpy(rooms[room_number-1].guest_phone, "");
                break;
                
            case 3: // View all rooms
                printf("\n Status of all rooms:");
                print_all_rooms(rooms, num_rooms);
                break;
                
            case 4: // Exit
                break;
                
            default: // Invalid choice
                printf("\n Invalid choice. Please choose between 1 and 4");
        }
        
    }
    
    return 0;
}