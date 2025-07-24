//FormAI DATASET v1.0 Category: Hotel Management System ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct roomData {
    int roomNumber;
    int numOfGuests;
    char guestNames[3][20];
    int occupied;
} rooms[10];

int main() {
    int menuChoice = 0;
    int i = 0;
    int roomNumber = 0;
    int numOfGuests = 0;
    char guestName[20];
    int guestNum = 0;
    int exit = 0;
    
    for (i = 0; i < 10; i++) {
        rooms[i].roomNumber = i + 1;
        rooms[i].numOfGuests = 0;
        rooms[i].occupied = 0;
        memset(rooms[i].guestNames, 0, sizeof(rooms[i].guestNames));
    }
    
    while(!exit) {
        printf("Welcome to the Hotel Management System\n");
        printf("--------------------------------------\n");
        printf("1. Check In\n");
        printf("2. Check Out\n");
        printf("3. Display Occupied Rooms\n");
        printf("4. Display Available Rooms\n");
        printf("5. Exit\n");
        printf("Please enter your choice: ");
        scanf("%d", &menuChoice);
        
        switch (menuChoice) {
            case 1:
                printf("Enter room number: ");
                scanf("%d", &roomNumber);
                
                if (roomNumber >= 1 && roomNumber <= 10) {
                    if (rooms[roomNumber-1].occupied == 0) {
                        printf("Enter number of guests: ");
                        scanf("%d", &numOfGuests);
                        
                        if (numOfGuests > 0 && numOfGuests <= 3) {
                            for (i = 0; i < numOfGuests; i++) {
                                printf("Enter name for guest %d: ", i+1);
                                scanf("%s", guestName);
                                strcpy(rooms[roomNumber-1].guestNames[i], guestName);
                            }
                            
                            rooms[roomNumber-1].numOfGuests = numOfGuests;
                            rooms[roomNumber-1].occupied = 1;
                            printf("Room number %d has been checked in.\n", roomNumber);
                        } else {
                            printf("Invalid number of guests.\n");
                        }
                    } else {
                        printf("Room is already occupied.\n");
                    }
                } else {
                    printf("Invalid room number.\n");
                }
                
                break;
            case 2:
                printf("Enter room number: ");
                scanf("%d", &roomNumber);
                
                if (roomNumber >= 1 && roomNumber <= 10) {
                    if (rooms[roomNumber-1].occupied == 1) {
                        printf("Guests in room number %d: ", roomNumber);
                        for (i = 0; i < rooms[roomNumber-1].numOfGuests; i++) {
                            printf("%s ", rooms[roomNumber-1].guestNames[i]);
                        }
                        printf("\n");
                        
                        rooms[roomNumber-1].numOfGuests = 0;
                        rooms[roomNumber-1].occupied = 0;
                        memset(rooms[roomNumber-1].guestNames, 0, sizeof(rooms[roomNumber-1].guestNames));
                        printf("Room number %d has been checked out.\n", roomNumber);
                    } else {
                        printf("Room is not occupied.\n");
                    }
                } else {
                    printf("Invalid room number.\n");
                }
                
                break;
            case 3:
                printf("Occupied rooms:\n");
                for (i = 0; i < 10; i++) {
                    if (rooms[i].occupied == 1) {
                        printf("Room %d: ", rooms[i].roomNumber);
                        for (guestNum = 0; guestNum < rooms[i].numOfGuests; guestNum++) {
                            printf("%s ", rooms[i].guestNames[guestNum]);
                        }
                        printf("\n");
                    }
                }
                
                break;
            case 4:
                printf("Available rooms:\n");
                for (i = 0; i < 10; i++) {
                    if (rooms[i].occupied == 0) {
                        printf("Room %d\n", rooms[i].roomNumber);
                    }
                }
                
                break;
            case 5:
                printf("Exiting...\n");
                exit = 1;
                break;
            default:
                printf("Invalid choice.\n");
                break;
        }
    }
    
    return 0;
}