//FormAI DATASET v1.0 Category: Hotel Management System ; Style: standalone
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// A structure to store the details of a room in the hotel
struct Room {
    int roomNumber;
    char guestName[50];
    int guestAge;
    int numberOfDays;
    float chargePerDay;
    float totalCharge;
};

// A function to display the details of a room
void displayRoom(struct Room r) {
    printf("Room Number: %d\n", r.roomNumber);
    printf("Guest Name: %s\n", r.guestName);
    printf("Guest Age: %d\n", r.guestAge);
    printf("Number of Days of Stay: %d\n", r.numberOfDays);
    printf("Charge per Day: %.2f\n", r.chargePerDay);
    printf("Total Charge: %.2f\n", r.totalCharge);
}

int main() {
    // Initializing the array of rooms
    struct Room rooms[10];
    for (int i = 0; i < 10; i++) {
        rooms[i].roomNumber = i + 1;
        strcpy(rooms[i].guestName, "");
        rooms[i].guestAge = 0;
        rooms[i].numberOfDays = 0;
        rooms[i].chargePerDay = 0;
        rooms[i].totalCharge = 0;
    }

    int choice;

    do {
        printf("\n\n--Hotel Management System--\n");
        printf("\n1. Check-in Guest");
        printf("\n2. Check-out Guest");
        printf("\n3. Display Room Details");
        printf("\n4. Exit");
        printf("\nEnter your choice: ");

        scanf("%d", &choice);

        switch (choice) {
            case 1: {
                int roomNumber;
                printf("Enter Room Number (1-10): ");
                scanf("%d", &roomNumber);

                if (rooms[roomNumber - 1].guestAge != 0) {
                    printf("\nRoom already occupied!");
                } else {
                    struct Room r;
                    r.roomNumber = roomNumber;
                    printf("Enter Guest Name: ");
                    scanf(" %[^\n]s", &r.guestName);
                    printf("Enter Guest Age: ");
                    scanf("%d", &r.guestAge);
                    printf("Enter Number of Days of Stay: ");
                    scanf("%d", &r.numberOfDays);
                    printf("Enter Charge per Day: ");
                    scanf("%f", &r.chargePerDay);

                    r.totalCharge = r.numberOfDays * r.chargePerDay;

                    rooms[roomNumber - 1] = r;

                    printf("\nCheck-in Successful!");
                    displayRoom(r);
                }
                break;
            }
            case 2: {
                int roomNumber;
                printf("Enter Room Number (1-10): ");
                scanf("%d", &roomNumber);

                if (rooms[roomNumber - 1].guestAge == 0) {
                    printf("\nRoom is empty!");
                } else {
                    printf("\nCheck-out Successful!");
                    displayRoom(rooms[roomNumber - 1]);
                    rooms[roomNumber - 1].roomNumber = roomNumber;
                    strcpy(rooms[roomNumber - 1].guestName, "");
                    rooms[roomNumber - 1].guestAge = 0;
                    rooms[roomNumber - 1].numberOfDays = 0;
                    rooms[roomNumber - 1].chargePerDay = 0;
                    rooms[roomNumber - 1].totalCharge = 0;
                }
                break;
            }
            case 3: {
                int roomNumber;
                printf("Enter Room Number (1-10): ");
                scanf("%d", &roomNumber);

                if (rooms[roomNumber - 1].guestAge == 0) {
                    printf("\nRoom is empty!");
                } else {
                    printf("\nRoom Details:");
                    displayRoom(rooms[roomNumber - 1]);
                }
                break;
            }
            case 4: {
                printf("\nExiting Hotel Management System...");
                break;
            }
            default: {
                printf("\nInvalid Choice!");
                break;
            }
        }
    } while (choice != 4);

    return 0;
}