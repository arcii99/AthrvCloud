//FormAI DATASET v1.0 Category: Hotel Management System ; Style: shocked
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Room {
    char roomNum[10];
    char roomType[15];
    int occupied;
    float rate;
};

struct Guest {
    char name[30];
    char address[50];
    char contactNum[15];
    char roomNum[10];
    int numStay;
};

int main() {
    int choice;
    int numRooms = 10;
    int numGuests = 0;
    struct Room rooms[10];
    struct Guest guests[10];

    // Initialize rooms
    for (int i = 0; i < numRooms; i++) {
        sprintf(rooms[i].roomNum, "R%02d", i+1);
        strcpy(rooms[i].roomType, "Standard");
        rooms[i].occupied = 0;
        rooms[i].rate = 100.00;
    }

    do {
        printf("---------- HOTEL MANAGEMENT SYSTEM ----------\n");
        printf("1. Check-in a guest\n");
        printf("2. Check-out a guest\n");
        printf("3. Display all rooms\n");
        printf("4. Display all guests\n");
        printf("5. Quit\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1: {
                char room[10];
                int roomIndex;
                int foundRoom = 0;

                printf("----- CHECK-IN A GUEST -----\n");
                printf("Enter guest name: ");
                scanf("%s", guests[numGuests].name);
                printf("Enter guest address: ");
                scanf("%s", guests[numGuests].address);
                printf("Enter guest contact number: ");
                scanf("%s", guests[numGuests].contactNum);

                // Search for available room
                while(!foundRoom) {
                    printf("Enter room number: ");
                    scanf("%s", room);
                    for (int i = 0; i < numRooms; i++) {
                        if (strcmp(rooms[i].roomNum, room) == 0) {
                            if (rooms[i].occupied == 0) {
                                strcpy(guests[numGuests].roomNum, rooms[i].roomNum);
                                rooms[i].occupied = 1;
                                roomIndex = i;
                                foundRoom = 1;
                                break;
                            } else {
                                printf("Room is occupied. Please choose another room.\n");
                            }
                        }
                    }
                }

                printf("Enter number of days to stay: ");
                scanf("%d", &guests[numGuests].numStay);
                numGuests++;

                printf("\n----- CHECK-IN SUCCESSFUL -----\n");
                printf("Guest name: %s\n", guests[numGuests-1].name);
                printf("Guest address: %s\n", guests[numGuests-1].address);
                printf("Guest contact number: %s\n", guests[numGuests-1].contactNum);
                printf("Room number: %s\n", guests[numGuests-1].roomNum);
                printf("Room type: %s\n", rooms[roomIndex].roomType);
                printf("Room rate per day: %.2f\n", rooms[roomIndex].rate);
                printf("Number of days to stay: %d\n", guests[numGuests-1].numStay);
                break;
            }
            case 2: {
                char room[10];
                int guestIndex = -1;
                float totalBill;

                printf("----- CHECK-OUT A GUEST -----\n");
                printf("Enter room number: ");
                scanf("%s", room);

                // Search for guest
                for (int i = 0; i < numGuests; i++) {
                    if (strcmp(guests[i].roomNum, room) == 0) {
                        guestIndex = i;
                        break;
                    }
                }

                if (guestIndex == -1) {
                    printf("No guest found in that room.\n");
                } else {
                    printf("Guest name: %s\n", guests[guestIndex].name);
                    printf("Guest address: %s\n", guests[guestIndex].address);
                    printf("Guest contact number: %s\n", guests[guestIndex].contactNum);
                    printf("Number of days stayed: %d\n", guests[guestIndex].numStay);
                    printf("Room number: %s\n", guests[guestIndex].roomNum);

                    // Compute total bill
                    totalBill = rooms[guestIndex].rate * guests[guestIndex].numStay;
                    printf("Total bill: %.2f\n", totalBill);

                    // Free up the room
                    int roomIndex;
                    for (int i = 0; i < numRooms; i++) {
                        if (strcmp(rooms[i].roomNum, guests[guestIndex].roomNum) == 0) {
                            rooms[i].occupied = 0;
                            roomIndex = i;
                            break;
                        }
                    }

                    // Shift guests
                    for (int i = guestIndex; i < numGuests-1; i++) {
                        guests[i] = guests[i+1];
                    }
                    numGuests--;

                    printf("\n----- CHECK-OUT SUCCESSFUL -----\n");
                    printf("Room number: %s\n", rooms[roomIndex].roomNum);
                    printf("Room type: %s\n", rooms[roomIndex].roomType);
                    printf("Room rate per day: %.2f\n", rooms[roomIndex].rate);
                    printf("Number of days stayed: %d\n", guests[guestIndex].numStay);
                    printf("Total bill: %.2f\n", totalBill);
                }
                break;
            }
            case 3: {
                printf("----- LIST OF ALL ROOMS -----\n");
                for (int i = 0; i < numRooms; i++) {
                    printf("Room number: %s | Room type: %s | Room status: %s\n", rooms[i].roomNum, rooms[i].roomType, rooms[i].occupied == 0 ? "Available" : "Occupied");
                }
                break;
            }
            case 4: {
                printf("----- LIST OF ALL GUESTS -----\n");
                for (int i = 0; i < numGuests; i++) {
                    printf("Name: %s | Address: %s | Contact number: %s | Room number: %s | Number of days stayed: %d\n", guests[i].name, guests[i].address, guests[i].contactNum, guests[i].roomNum, guests[i].numStay);
                }
                break;
            }
            case 5: {
                printf("Exiting hotel management system...\n");
                break;
            }
            default: {
                printf("Invalid choice. Please choose again.\n");
                break;
            }
        }
        printf("\n");
    } while(choice != 5);

    return 0;
}