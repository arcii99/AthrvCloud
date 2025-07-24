//FormAI DATASET v1.0 Category: Hotel Management System ; Style: Claude Shannon
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define structure for hotel rooms
typedef struct {
    int roomNo;
    char roomType[50];
    int noOfBeds;
    float rate;
    int booked;
    char guestName[50];
} room;

// Define function to display all available rooms
void displayRoomsAvailable(room rooms[], int numRooms) {
    printf("\nRoom No\tRoom Type\tNo. of Beds\tRate\tBooked\n");
    printf("---------------------------------------------------------\n");
    for(int i = 0; i < numRooms; i++) {
        if(!rooms[i].booked) {  // If room not booked
            printf("%d\t\t%s\t\t%d\t\t%.2f\tNo\n", rooms[i].roomNo, 
                   rooms[i].roomType, rooms[i].noOfBeds, rooms[i].rate);
        }
    }
}

// Define function to book a room
void bookRoom(room rooms[], int numRooms) {
    int roomNumber;
    printf("\nEnter the room number you want to book: ");
    scanf("%d", &roomNumber);
    // Search for the room with entered room number
    for(int i = 0; i < numRooms; i++) {
        if(rooms[i].roomNo == roomNumber) {  // If room number matched
            if(rooms[i].booked) {  // If room already booked
                printf("\nThis room is already booked\n");
            } else {
                printf("\nEnter guest name: ");
                scanf("%s", rooms[i].guestName);
                rooms[i].booked = 1;
                printf("\nRoom booked successfully\n");
            }
            return;
        }
    }
    // If entered room number not found
    printf("\nInvalid room number\n");
}

// Define function to display all booked rooms with their details
void displayBookedRooms(room rooms[], int numRooms) {
    printf("\nRoom No.\tGuest Name\tRoom Type\tNo. of Beds\tRate\n");
    printf("--------------------------------------------------------------\n");
    for(int i = 0; i < numRooms; i++) {
        if(rooms[i].booked) {  // If room booked
            printf("%d\t\t%s\t\t%s\t\t%d\t\t%.2f\n", rooms[i].roomNo, 
                   rooms[i].guestName, rooms[i].roomType, rooms[i].noOfBeds, rooms[i].rate);
        }
    }
}

int main() {
    int numRooms = 5;  // Number of hotel rooms
    // Define array of hotel rooms
    room rooms[numRooms];
    // Initialize hotel rooms with their details
    rooms[0].roomNo = 101;
    strcpy(rooms[0].roomType, "Single");
    rooms[0].noOfBeds = 1;
    rooms[0].rate = 1000.00;
    rooms[0].booked = 0;
    strcpy(rooms[0].guestName, "");
    rooms[1].roomNo = 102;
    strcpy(rooms[1].roomType, "Double");
    rooms[1].noOfBeds = 2;
    rooms[1].rate = 1500.00;
    rooms[1].booked = 0;
    strcpy(rooms[1].guestName, "");
    rooms[2].roomNo = 103;
    strcpy(rooms[2].roomType, "Single");
    rooms[2].noOfBeds = 1;
    rooms[2].rate = 1000.00;
    rooms[2].booked = 0;
    strcpy(rooms[2].guestName, "");
    rooms[3].roomNo = 104;
    strcpy(rooms[3].roomType, "Double");
    rooms[3].noOfBeds = 2;
    rooms[3].rate = 1500.00;
    rooms[3].booked = 1;
    strcpy(rooms[3].guestName, "John");
    rooms[4].roomNo = 105;
    strcpy(rooms[4].roomType, "Suite");
    rooms[4].noOfBeds = 3;
    rooms[4].rate = 2500.00;
    rooms[4].booked = 0;
    strcpy(rooms[4].guestName, "");
    // Display menu
    int choice;
    do {
        printf("\nHotel Management System\n");
        printf("1. View available rooms\n");
        printf("2. Book a room\n");
        printf("3. View booked rooms\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch(choice) {
            case 1:
                displayRoomsAvailable(rooms, numRooms);
                break;
            case 2:
                bookRoom(rooms, numRooms);
                break;
            case 3:
                displayBookedRooms(rooms, numRooms);
                break;
            case 4:
                printf("\nThank you\n");
                break;
            default:
                printf("\nInvalid choice\n");
        }
    } while(choice != 4);
    return 0;
}