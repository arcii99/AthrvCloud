//FormAI DATASET v1.0 Category: Hotel Management System ; Style: brave
#include <stdio.h>

// Define the maximum number of rooms available
#define MAX_ROOMS 100

// Define the structure for a single room
struct Room {
    int roomNumber;
    int occupancy;
    float rate;
    char guestName[50];
};

// Define the array of rooms as a global variable
struct Room rooms[MAX_ROOMS];

int main() {
    int choice, roomNum, occupancy;
    float rate;
    char guestName[50];

    // Initialize all rooms to empty
    for (int i = 0; i < MAX_ROOMS; i++) {
        rooms[i].roomNumber = i + 1;
        rooms[i].occupancy = 0;
        rooms[i].rate = 0.0;
        strcpy(rooms[i].guestName, "");
    }

    do {
        printf("\n\n\n***** Hotel Management System *****\n");
        printf("1. Check In\n");
        printf("2. Check Out\n");
        printf("3. Display Room Status\n");
        printf("4. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("\nEnter room number: ");
                scanf("%d", &roomNum);

                if (rooms[roomNum - 1].occupancy == 1) {
                    printf("\nRoom is already occupied!");
                } else {
                    printf("\nEnter guest name: ");
                    scanf("%s", guestName);
                    printf("Enter occupancy (1 - Single, 2 - Double): ");
                    scanf("%d", &occupancy);

                    if (occupancy == 1) {
                        printf("Enter rate (per day): ");
                        scanf("%f", &rate);
                        rooms[roomNum - 1].rate = rate;
                    } else {
                        rooms[roomNum - 1].rate = 80.00;
                    }

                    rooms[roomNum - 1].occupancy = 1;
                    strcpy(rooms[roomNum - 1].guestName, guestName);

                    printf("\nRoom has been checked in successfully!");
                }

                break;
            case 2:
                printf("\nEnter room number: ");
                scanf("%d", &roomNum);

                if (rooms[roomNum - 1].occupancy == 0) {
                    printf("\nRoom is already empty!");
                } else {
                    float totalBill = rooms[roomNum - 1].rate;

                    printf("\nGuest Name: %s", rooms[roomNum - 1].guestName);

                    if (rooms[roomNum - 1].occupancy == 1) {
                        printf("\nOccupancy: Single");
                        printf("\nRate (per day): %.2f", rooms[roomNum - 1].rate);
                    } else {
                        printf("\nOccupancy: Double");
                        printf("\nRate (per day): %.2f", 80.00);
                        totalBill *= 2;
                    }

                    printf("\nTotal Bill: %.2f", totalBill);

                    rooms[roomNum - 1].occupancy = 0;
                    rooms[roomNum - 1].rate = 0.0;
                    strcpy(rooms[roomNum - 1].guestName, "");

                    printf("\n\nRoom has been checked out successfully!");
                }

                break;
            case 3:
                printf("\n\nRoom\tStatus");
                printf("\n----\t------");

                for (int i = 0; i < MAX_ROOMS; i++) {
                    printf("\n%d\t", rooms[i].roomNumber);

                    if (rooms[i].occupancy == 1) {
                        printf("Occupied by %s", rooms[i].guestName);
                    } else {
                        printf("Empty");
                    }
                }

                break;
            case 4:
                printf("\nExiting program...");
                break;
            default:
                printf("\nInvalid choice! Please try again.");
        }
    } while (choice != 4);

    return 0;
}