//FormAI DATASET v1.0 Category: Hotel Management System ; Style: mind-bending
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

// defining structure for hotel rooms
struct Room {
    int roomNumber;
    int beds;
    int price;
    char occupied[10];
} rooms[100];

// function to add rooms
void addRooms(int roomNumber, int beds, int price) {
    rooms[roomNumber - 1].roomNumber = roomNumber;
    rooms[roomNumber - 1].beds = beds;
    rooms[roomNumber - 1].price = price;
    strcpy(rooms[roomNumber - 1].occupied, "No");
}

// function to check room availability
void checkRoom(int roomNumber) {
    if(strcmp(rooms[roomNumber - 1].occupied, "No") == 0) {
        printf("\nRoom %d is available for booking.", roomNumber);
    }
    else {
        printf("\nRoom %d is already occupied.", roomNumber);
    }
}

// function to book a room
void bookRoom(int roomNumber) {
    if(strcmp(rooms[roomNumber - 1].occupied, "No") == 0) {
        printf("\nEnter guest name: ");
        char name[20];
        scanf("%s", name);
        printf("\nEnter number of guests: ");
        int guests;
        scanf("%d", &guests);
        rooms[roomNumber - 1].beds = guests;
        printf("\nEnter number of days of stay: ");
        int days;
        scanf("%d", &days);
        rooms[roomNumber - 1].price = rooms[roomNumber - 1].price * days;
        strcpy(rooms[roomNumber - 1].occupied, "Yes");
        printf("\nRoom %d booked successfully.\n", roomNumber);
        printf("Guest Name: %s\nNumber of Guests: %d\nNumber of Days of Stay: %d\n", name, guests, days);
        printf("Total Amount: %d\n", rooms[roomNumber - 1].price);
    }
    else {
        printf("\nSorry, room %d is already occupied.\n", roomNumber);
    }
}

// function to display all rooms
void displayRooms() {
    printf("\nRoom Number\tBeds\tPrice\tOccupied");
    printf("\n----------------------------------------");
    for(int i=0;i<100;i++) {
        if(rooms[i].roomNumber != 0) {
            printf("\n%d\t\t%d\t%d\t%s", rooms[i].roomNumber, rooms[i].beds, rooms[i].price, rooms[i].occupied);
        }
    }
}

int main() {

    // initializing all rooms as empty
    for(int i=0;i<100;i++) {
        rooms[i].roomNumber = 0;
    }

    printf("Welcome to C Hotel Management System!\n\n");

    while(1) {
        printf("\n1. Add Rooms\n2. Check Room Availability\n3. Book Room\n4. Display All Rooms\n5. Quit");
        printf("\nEnter your choice (1-5): ");
        int choice;
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                printf("\nHow many rooms do you want to add? ");
                int numRooms;
                scanf("%d", &numRooms);
                for(int i=0;i<numRooms;i++) {
                    int roomNumber, beds, price;
                    printf("\nEnter Room Number: ");
                    scanf("%d", &roomNumber);
                    printf("Enter Number of Beds in Room %d: ", roomNumber);
                    scanf("%d", &beds);
                    printf("Enter Price of Room %d (per day): ", roomNumber);
                    scanf("%d", &price);
                    addRooms(roomNumber, beds, price);
                    printf("\nRoom %d added successfully.\n", roomNumber);
                }
                break;
            case 2:
                printf("\nEnter Room Number: ");
                int roomNumber;
                scanf("%d", &roomNumber);
                checkRoom(roomNumber);
                break;
            case 3:
                printf("\nEnter Room Number: ");
                int bookRoomNumber;
                scanf("%d", &bookRoomNumber);
                bookRoom(bookRoomNumber);
                break;
            case 4:
                displayRooms();
                break;
            case 5:
                printf("\nThanks for using C Hotel Management System!\n");
                return 0;
            default:
                printf("\nInvalid choice. Please try again.\n");
        }
    }
    return 0;
}