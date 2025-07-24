//FormAI DATASET v1.0 Category: Hotel Management System ; Style: futuristic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char name[50];
    int roomNumber;
    char roomType[10];
    double price;
    int availability;
} room;

typedef struct {
    char name[50];
    int age;
    char id[10];
    char roomType[10];
    int roomNumber;
    char checkInDate[11];
    char checkOutDate[11];
    double totalBill;
} guest;

void displayRooms(room rooms[], int length) {
    printf("\nAvailable rooms:\n");
    printf("Room No.  Room Type  Price\n");
    for(int i=0; i<length; i++) {
        if(rooms[i].availability == 1) {
            printf("%3d       %-10s %.2f\n", rooms[i].roomNumber, rooms[i].roomType, rooms[i].price);
        }
    }
}

int bookRoom(room rooms[], int length, guest guests[], int numGuests) {
    char name[50], roomType[10], checkInDate[11], checkOutDate[11];
    int age;
    double price;
    int roomNumber;
    printf("\nEnter customer name: ");
    scanf("%s", name);
    printf("Enter age: ");
    scanf("%d", &age);
    printf("Enter ID number: ");
    scanf("%s", guests[numGuests].id);
    printf("Choose room type: ");
    scanf("%s", roomType);
    int found = 0;
    for(int i=0; i<length; i++) {
        if(strcmp(roomType, rooms[i].roomType) == 0 && rooms[i].availability == 1) {
            found = 1;
            roomNumber = rooms[i].roomNumber;
            price = rooms[i].price;
            rooms[i].availability = 0;
            strcpy(guests[numGuests].roomType, roomType);
            guests[numGuests].roomNumber = roomNumber;
            break;
        }
    }
    if(found == 0) {
        printf("Sorry, no %s rooms are currently available.\n", roomType);
        return -1;
    }
    printf("Enter check-in date (YYYY-MM-DD): ");
    scanf("%s", checkInDate);
    strcpy(guests[numGuests].checkInDate, checkInDate);
    printf("Enter check-out date (YYYY-MM-DD): ");
    scanf("%s", checkOutDate);
    strcpy(guests[numGuests].checkOutDate, checkOutDate);
    double totalBill = price * 1.1 * 7.0;
    printf("\nBooking details:\n");
    printf("Name: %s\n", name);
    printf("Age: %d\n", age);
    printf("ID: %s\n", guests[numGuests].id);
    printf("Room Number: %d\n", roomNumber);
    guests[numGuests].totalBill = totalBill;
    printf("Total bill (incl. tax and service): %.2f\n", totalBill);
    return 0;
}

void displayGuests(guest guests[], int length) {
    printf("\nGuest details:\n");
    printf("Name       Room Number   Room Type     Check-In        Check-Out      Total Bill\n");
    for(int i=0; i<length; i++) {
        if(guests[i].age != 0) {
            printf("%-10s  %3d           %-10s     %s   %s    %.2f\n", guests[i].name, guests[i].roomNumber, guests[i].roomType, guests[i].checkInDate, guests[i].checkOutDate, guests[i].totalBill);
        }
    }
}

int main() {
    room rooms[10];
    for(int i=0; i<10; i++) {
        rooms[i].roomNumber = i+1;
        if(i%2 == 0) {
            strcpy(rooms[i].roomType, "Single");
            rooms[i].price = 50.00;
        }
        else {
            strcpy(rooms[i].roomType, "Double");
            rooms[i].price = 75.00;
        }
        rooms[i].availability = 1;
    }

    guest guests[10];
    for(int i=0; i<10; i++) {
        guests[i].age = 0;
    }

    printf("\nWelcome to Futuristic C Hotel Management System!");
    while(1) {
        printf("\n\nEnter 1 to display available rooms.\nEnter 2 to book a room.\nEnter 3 to display guest details.\nEnter 4 to exit.\n");
        int choice;
        scanf("%d", &choice);
        switch(choice) {
            case 1: {
                displayRooms(rooms, 10);
                break;
            }
            case 2: {
                int result = bookRoom(rooms, 10, guests, 0);
                if(result == -1) {
                    break;
                }
                else {
                    printf("Booking successful.\n");
                    printf("Enter customer name: ");
                    scanf("%s", guests[0].name);
                    printf("Guest added successfully with name %s.\n", guests[0].name);
                    break;
                }
            }
            case 3: {
                displayGuests(guests, 10);
                break;
            }
            case 4: {
                return 0;
            }
            default: {
                printf("Invalid choice. Please try again.\n");
                break;
            }
        }
    }

    return 0;
}