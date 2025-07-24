//FormAI DATASET v1.0 Category: Hotel Management System ; Style: statistical
#include <stdio.h>

/* Struct for storing hotel room information */
struct Room {
    int roomNumber;
    char roomType[20];
    int numberOfBeds;
    float rate;
    float occupancyRate;
};

#define NUM_ROOMS 20

/* Array of hotel rooms */
struct Room rooms[NUM_ROOMS];

/* Function to initialize hotel room data */
void initializeRooms() {
    for (int i = 0; i < NUM_ROOMS; i++) {
        rooms[i].roomNumber = i+1;
        if (i % 2 == 0) {
            strcpy(rooms[i].roomType, "single");
            rooms[i].numberOfBeds = 1;
            rooms[i].rate = 100.0;
        }
        else {
            strcpy(rooms[i].roomType, "double");
            rooms[i].numberOfBeds = 2;
            rooms[i].rate = 150.0;
        }
        rooms[i].occupancyRate = 0.0;
    }
}

/* Function to display hotel room data */
void displayRooms() {
    printf("Room Number\tRoom Type\tNumber of Beds\tRate\tOccupancy Rate\n");
    for (int i = 0; i < NUM_ROOMS; i++) {
        printf("%d\t\t%s\t\t%d\t\t%.2f\t%.2f%%\n", rooms[i].roomNumber, rooms[i].roomType, rooms[i].numberOfBeds, rooms[i].rate, rooms[i].occupancyRate * 100.0);
    }
}

/* Function to check room availability */
int isRoomAvailable(int roomNumber) {
    if (rooms[roomNumber-1].occupancyRate == 0.0) {
        return 1;
    }
    else {
        return 0;
    }
}

/* Function to book a room */
void bookRoom(int roomNumber) {
    if (isRoomAvailable(roomNumber)) {
        rooms[roomNumber-1].occupancyRate = 1.0;
        printf("Room %d is booked.\n", roomNumber);
    }
    else {
        printf("Room %d is not available.\n", roomNumber);
    }
}

/* Function to calculate occupancy rate */
float calculateOccupancyRate() {
    float totalOccupied = 0.0;
    for (int i = 0; i < NUM_ROOMS; i++) {
        if (rooms[i].occupancyRate == 1.0) {
            totalOccupied += 1.0;
        }
    }
    return totalOccupied / NUM_ROOMS;
}

/* Main function */
int main() {
    initializeRooms();
    int choice = 0;
    while (choice != 4) {
        printf("\n1. Display Room Information\n");
        printf("2. Book a Room\n");
        printf("3. Calculate Occupancy Rate\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice)
        {
            case 1:
                displayRooms();
                break;
            case 2:
                int roomNumber;
                printf("Enter room number: ");
                scanf("%d", &roomNumber);
                bookRoom(roomNumber);
                break;
            case 3:
                printf("Occupancy rate: %.2f%%\n", calculateOccupancyRate() * 100.0);
                break;
            case 4:
                break;
            default:
                printf("Invalid choice.\n");
                break;
        }
    }
    return 0;
}