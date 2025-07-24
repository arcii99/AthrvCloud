//FormAI DATASET v1.0 Category: Hotel Management System ; Style: immersive
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// Define maximum number of rooms and guests
#define MAX_ROOMS 50
#define MAX_GUESTS 200

// Struct for individual guest details
struct guest {
    char name[30];
    char address[50];
    int room_number;
    int num_of_nights;
};

// Struct for individual room details
struct room {
    int room_number;
    int capacity;
    int occupied;
};

// Function to initialize all rooms in the hotel
void initialize_rooms(struct room rooms[]) {
    for(int i = 0; i < MAX_ROOMS; i++) {
        rooms[i].room_number = i+1;
        rooms[i].capacity = 2;
        rooms[i].occupied = 0;
    }
}

// Function to check if a given room number is valid
int is_valid_room(int room_number) {
    if(room_number > 0 && room_number <= MAX_ROOMS)
        return 1;
    else
        return 0;
}

// Function to check if a given room is available
int is_room_available(struct room rooms[], int room_number) {
    for(int i = 0; i < MAX_ROOMS; i++) {
        if(rooms[i].room_number == room_number) {
            if(rooms[i].occupied == 0)
                return 1;
            else
                return 0;
        }
    }
}

// Function to check if a given guest name is valid
int is_valid_guest_name(char name[]) {
    if(strlen(name) < 5 || strlen(name) > 30)
        return 0;
    else
        return 1;
}

// Function to add a guest to a given room
void add_guest(struct guest guests[], struct room rooms[], int room_number, char name[], char address[], int num_of_nights) {
    int i;
    for(i = 0; i < MAX_GUESTS; i++) {
        if(guests[i].room_number == 0) {
            guests[i].room_number = room_number;
            strcpy(guests[i].name, name);
            strcpy(guests[i].address, address);
            guests[i].num_of_nights = num_of_nights;
            break;
        }
    }
    for(i = 0; i < MAX_ROOMS; i++) {
        if(rooms[i].room_number == room_number) {
            rooms[i].occupied = 1;
            break;
        }
    }
}

// Function to remove a guest from a given room
void remove_guest(struct guest guests[], struct room rooms[], int room_number) {
    int i;
    for(i = 0; i < MAX_GUESTS; i++) {
        if(guests[i].room_number == room_number) {
            guests[i].room_number = 0;
            strcpy(guests[i].name, "");
            strcpy(guests[i].address, "");
            guests[i].num_of_nights = 0;
            break;
        }
    }
    for(i = 0; i < MAX_ROOMS; i++) {
        if(rooms[i].room_number == room_number) {
            rooms[i].occupied = 0;
            break;
        }
    }
}

// Function to print a single guest's details
void print_guest(struct guest guest) {
    printf("%-20s%-30s%10d%20d\n", guest.name, guest.address, guest.room_number, guest.num_of_nights);
}

// Function to print the details of all guests in the hotel
void print_all_guests(struct guest guests[]) {
    printf("%-20s%-30s%-20s%-20s\n", "Name", "Address", "Room Number", "No. of Nights");
    for(int i = 0; i < MAX_GUESTS; i++) {
        if(guests[i].room_number != 0)
            print_guest(guests[i]);
    }
}

// Function to print the details of all available rooms in the hotel
void print_available_rooms(struct room rooms[]) {
    printf("%-20s%-20s\n", "Room Number", "Capacity");
    for(int i = 0; i < MAX_ROOMS; i++) {
        if(rooms[i].occupied == 0) {
            printf("%-20d%-20d\n", rooms[i].room_number, rooms[i].capacity);
        }
    }
}

// Main function
int main() {
    struct room rooms[MAX_ROOMS];
    struct guest guests[MAX_GUESTS];
    
    char name[30], address[50];
    int room_number, num_of_nights;
    
    printf("Welcome to the Hotel Management System!\n");
    
    // Initialize the rooms in the hotel
    initialize_rooms(rooms);
    
    // Loop for taking user input
    while(1) {
        int choice;
        
        printf("\n1. Add Guest\n");
        printf("2. Remove Guest\n");
        printf("3. Print All Guests\n");
        printf("4. Print Available Rooms\n");
        printf("5. Exit\n");
        
        printf("\nEnter your choice: ");
        scanf("%d", &choice);
        
        switch(choice) {
            
            case 1:
                printf("\nEnter the guest name (5-30 characters): ");
                scanf("%s", &name);
                
                if(!is_valid_guest_name(name)) {
                    printf("\nInvalid name. Try again!\n");
                    break;
                }
                
                printf("Enter the guest address: ");
                scanf("%s", &address);
                
                printf("Enter the room number (1-50): ");
                scanf("%d", &room_number);
                
                if(!is_valid_room(room_number)) {
                    printf("\nInvalid room number. Try again!\n");
                    break;
                }
                
                if(!is_room_available(rooms, room_number)) {
                    printf("\nRoom %d is already occupied. Try again!\n", room_number);
                    break;
                }
                
                printf("Enter the number of nights the guest will be staying: ");
                scanf("%d", &num_of_nights);
                
                add_guest(guests, rooms, room_number, name, address, num_of_nights);
                
                printf("\nGuest added successfully!\n");
                
                break;
                
            case 2:
                printf("\nEnter the room number of the guest to be removed: ");
                scanf("%d", &room_number);
                
                if(!is_valid_room(room_number)) {
                    printf("\nInvalid room number. Try again!\n");
                    break;
                }
                
                if(is_room_available(rooms, room_number)) {
                    printf("\nRoom %d is currently unoccupied. Try again!\n", room_number);
                    break;
                }
                
                remove_guest(guests, rooms, room_number);
                
                printf("\nGuest removed successfully!\n");
                
                break;
                
            case 3:
                printf("\nGuest Details:\n");
                print_all_guests(guests);
                break;
                
            case 4:
                printf("\nAvailable Rooms:\n");
                print_available_rooms(rooms);
                break;
                
            case 5:
                printf("\nExiting Hotel Management System. Goodbye!\n");
                exit(0);
                
            default:
                printf("\nInvalid choice. Try again!\n");
        }
    }
    
    return 0;
}