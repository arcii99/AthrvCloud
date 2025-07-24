//FormAI DATASET v1.0 Category: Hotel Management System ; Style: invasive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Guest structure
typedef struct {
    char name[50];
    int age;
    char gender[10];
    char address[100];
    char phone[20];
    int room_number;
    int days_stayed;
    float bill;
} Guest;

// Room structure
typedef struct {
    int room_number;
    char room_type[20];
    char availability[10];
    int max_guests;
    int num_guests;
} Room;

// Array for rooms
Room rooms[50];

int main() {
    int i, j, n, choice, room_choice, num_guests, guest_found = 0, room_found = 0, room_index, guest_index;
    float room_price, total_price;
    Guest guests[50];
    printf("\nWelcome to the Hotel Management System!\n");

    // Initializing the rooms
    for(i=0; i<50; i++) {
        rooms[i].room_number = i+1;
        strcpy(rooms[i].room_type, "Regular");
        strcpy(rooms[i].availability, "Available");
        rooms[i].max_guests = 2;
        rooms[i].num_guests = 0;
    }

    while(1) {
        printf("\nPlease choose an option:\n1. Book a room\n2. Check out\n3. Display available rooms\n4. Display guest list\n5. Exit\n");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                // Booking a room
                printf("\nEnter the number of guests: ");
                scanf("%d", &num_guests);
                if(num_guests>2) {
                    printf("\nSorry, we do not have rooms for more than 2 guests.");
                    break;
                }
                printf("\nAvailable rooms:\n");
                for(i=0; i<50; i++) {
                    if(strcmp(rooms[i].availability, "Available") == 0) {
                        printf("%d. Room %d (Type: %s, Price: %.2f per night)\n", i+1, rooms[i].room_number, rooms[i].room_type, (float)rooms[i].num_guests*15.00);
                    }
                }
                printf("\nEnter the room number you want to book: ");
                scanf("%d", &room_choice);
                for(i=0; i<50; i++) {
                    if(room_choice == rooms[i].room_number) {
                        if(strcmp(rooms[i].availability, "Available") == 0) {
                            rooms[i].num_guests = num_guests;
                            strcpy(rooms[i].availability, "Occupied");
                            printf("\nEnter guest details:\n");
                            printf("Name: ");
                            scanf("%s", guests[i].name);
                            printf("Age: ");
                            scanf("%d", &guests[i].age);
                            printf("Gender: ");
                            scanf("%s", guests[i].gender);
                            printf("Address: ");
                            scanf("%s", guests[i].address);
                            printf("Phone number: ");
                            scanf("%s", guests[i].phone);
                            guests[i].room_number = room_choice;
                            printf("Number of days to stay: ");
                            scanf("%d", &guests[i].days_stayed);
                            rooms[i].max_guests = 2;
                            rooms[i].num_guests = num_guests;
                            room_found = 1;
                            break;
                        } else {
                            printf("\nSorry, this room is not available.");
                            room_found = 1;
                            break;
                        }
                    }
                }
                if(room_found == 0) {
                    printf("\nSorry, this room does not exist.");
                }
                break;
            case 2:
                // Checking out
                printf("\nEnter the guest name: ");
                scanf("%s", guests[i].name);
                for(i=0; i<50; i++) {
                    if(strcmp(guests[i].name, guests[i].name) == 0) {
                        guest_found = 1;
                        room_index = guests[i].room_number - 1;
                        rooms[room_index].num_guests = 0;
                        strcpy(rooms[room_index].availability, "Available");
                        total_price = guests[i].days_stayed * (float)rooms[room_index].num_guests * 15.00;
                        printf("\nBill for %s: %.2f", guests[i].name, total_price);
                        break;
                    }
                }
                if(guest_found == 0) {
                    printf("\nSorry, guest not found.");
                }
                break;
            case 3:
                // Displaying available rooms
                printf("\nAvailable rooms:\n");
                for(i=0; i<50; i++) {
                    if(strcmp(rooms[i].availability, "Available") == 0) {
                        printf("%d. Room %d (Type: %s, Price: %.2f per night)\n", i+1, rooms[i].room_number, rooms[i].room_type, (float)rooms[i].num_guests*15.00);
                    }
                }
                break;
            case 4:
                // Displaying guest list
                printf("\nGuest list:\n");
                printf("Name\t\tAge\tGender\tAddress\t\t\tPhone\t\tRoom Number\tDays Stayed\tBill\n");
                for(i=0; i<50; i++) {
                    if(guests[i].name[0] != '\0') {

                        // Calculating total bill
                        room_index = guests[i].room_number - 1;
                        room_price = (float)(rooms[room_index].num_guests * 15.00);
                        total_price = guests[i].days_stayed * room_price;

                        printf("%s\t\t%d\t%s\t%s\t\t%s\t\t%d\t\t%d\t\t%.2f\n", guests[i].name, guests[i].age, guests[i].gender, guests[i].address, guests[i].phone, guests[i].room_number, guests[i].days_stayed, total_price);
                    }
                }
                break;
            case 5:
                // Exiting
                printf("\nGoodbye!");
                exit(0);
            default:
                // Invalid input
                printf("\nInvalid input. Please enter a valid option.");
        }
    }
    return 0;
}