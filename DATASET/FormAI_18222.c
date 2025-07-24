//FormAI DATASET v1.0 Category: Hotel Management System ; Style: mind-bending
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct room {
    int roomNumber;
    char roomType[50];
    int beds;
    float price;
    int booked;
};

struct guest {
    char name[50];
    int roomNumber;
    int days;
    float total;
};

int main() {
    struct room rooms[10];
    for(int i = 0; i < 10; i++) {
        rooms[i].roomNumber = i + 1;
        strcpy(rooms[i].roomType, "Standard");
        rooms[i].beds = 2;
        rooms[i].price = 50.0;
        rooms[i].booked = 0;
    }

    struct guest guests[10];
    int numGuests = 0;

    int choice = 0;
    while(choice != 4) {
        printf("\nWelcome to the Hotel Management System\n");
        printf("1. Book a room\n");
        printf("2. Check out a guest\n");
        printf("3. Display room information\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1: 
                printf("\nEnter guest name: ");
                scanf("%s", guests[numGuests].name);
                printf("Available Rooms:\n");
                for(int i = 0; i < 10; i++) {
                    if(rooms[i].booked == 0) {
                        printf("%d. Room %d - %s - %d beds - $%.2f per night\n", i+1, rooms[i].roomNumber, rooms[i].roomType, rooms[i].beds, rooms[i].price);
                    }
                }
                printf("Enter room number: ");
                scanf("%d", &guests[numGuests].roomNumber);
                printf("Enter number of days: ");
                scanf("%d", &guests[numGuests].days);
                guests[numGuests].total = rooms[guests[numGuests].roomNumber - 1].price * guests[numGuests].days;
                rooms[guests[numGuests].roomNumber - 1].booked = 1;
                numGuests++;
                printf("Guest checked in successfully!\n");
                break;
            case 2:
                printf("\nEnter room number: ");
                int roomNum;
                scanf("%d", &roomNum);
                for(int i = 0; i < numGuests; i++) {
                    if(guests[i].roomNumber == roomNum) {
                        printf("Guest Name: %s\n", guests[i].name);
                        printf("Room Number: %d\n", guests[i].roomNumber);
                        printf("Days Stayed: %d\n", guests[i].days);
                        printf("Total Bill: $%.2f\n", guests[i].total);
                        rooms[guests[i].roomNumber - 1].booked = 0;
                        for(int j = i; j < numGuests-1; j++) {
                            guests[j] = guests[j+1];
                        }
                        numGuests--;
                        printf("Guest checked out successfully!\n");
                        break;
                    }
                    else if(i == numGuests-1) {
                        printf("Room not found or guest has already checked out!\n");
                    }
                }
                break;
            case 3:
                printf("\nRoom Information:\n");
                for(int i = 0; i < 10; i++) {
                    printf("Room %d - %s - %d beds - $%.2f per night - ", rooms[i].roomNumber, rooms[i].roomType, rooms[i].beds, rooms[i].price);
                    if(rooms[i].booked == 1) {
                        printf("Booked\n");
                    } else {
                        printf("Available\n");
                    }
                }
                break;
            case 4: 
                printf("\nExiting program, goodbye!\n");
                break;
            default:
                printf("\nInvalid choice, please try again!\n");
                break;
        }
    }

    return 0;
}