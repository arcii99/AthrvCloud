//FormAI DATASET v1.0 Category: Hotel Management System ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Constants
#define NUM_ROOMS 50
#define MAX_NAME_LENGTH 20
#define MAX_OCCUPANTS 4

// Structures
typedef struct {
    int number;
    char name[MAX_NAME_LENGTH];
    int occupants[MAX_OCCUPANTS];
} Room;

// Function declarations
void displayMenu();
void initializeRooms(Room rooms[]);
void displayRooms(Room rooms[]);
void addOccupant(Room *room, int occupant);
void removeOccupant(Room *room, int occupant);

// Main function
int main() {
    Room rooms[NUM_ROOMS];
    int choice, roomNumber, occupant, i;
    char name[MAX_NAME_LENGTH];
    initializeRooms(rooms);

    do {
        displayMenu();
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                displayRooms(rooms);
                break;
            case 2:
                printf("Enter the room number: ");
                scanf("%d", &roomNumber);
                printf("Enter the name of the occupant: ");
                scanf("%s", name);
                printf("Enter the number of occupants: ");
                scanf("%d", &occupant);
                for (i = 0; i < NUM_ROOMS; i++) {
                    if (rooms[i].number == roomNumber) {
                        addOccupant(&rooms[i], occupant);
                        strcpy(rooms[i].name, name);
                        printf("%s added to room %d\n", name, roomNumber);
                        break;
                    }
                }
                if (i == NUM_ROOMS) {
                    printf("Room %d not found.\n", roomNumber);
                }
                break;
            case 3:
                printf("Enter the room number: ");
                scanf("%d", &roomNumber);
                for (i = 0; i < NUM_ROOMS; i++) {
                    if (rooms[i].number == roomNumber) {
                        printf("Enter the number of occupants to remove: ");
                        scanf("%d", &occupant);
                        removeOccupant(&rooms[i], occupant);
                        break;
                    }
                }
                if (i == NUM_ROOMS) {
                    printf("Room %d not found.\n", roomNumber);
                }
                break;
            case 4:
                printf("Thank you for using the hotel management system!\n");
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
                break;
        }
    } while (1);
}

// Function definitions
void displayMenu() {
    printf("\n========================\n");
    printf("Hotel Management System\n");
    printf("========================\n");
    printf("1 - Display Rooms\n");
    printf("2 - Add Occupant to Room\n");
    printf("3 - Remove Occupant from Room\n");
    printf("4 - Exit\n\n");
    printf("Enter your choice: ");
}

void initializeRooms(Room rooms[]) {
    int i, j;
    for (i = 0; i < NUM_ROOMS; i++) {
        rooms[i].number = i+1;
        strcpy(rooms[i].name, "");
        for (j = 0; j < MAX_OCCUPANTS; j++) {
            rooms[i].occupants[j] = 0;
        }
    }
}

void displayRooms(Room rooms[]) {
    int i, j;
    printf("\nRoom\tName\tOccupants\n");
    printf("----\t----\t---------\n");
    for (i = 0; i < NUM_ROOMS; i++) {
        printf("%d\t%s\t", rooms[i].number, rooms[i].name);
        for (j = 0; j < MAX_OCCUPANTS; j++) {
            printf("%d ", rooms[i].occupants[j]);
        }
        printf("\n");
    }
    printf("\n");
}

void addOccupant(Room *room, int occupant) {
    int i;
    for (i = 0; i < MAX_OCCUPANTS; i++) {
        if (room->occupants[i] == 0) {
            room->occupants[i] = occupant;
            break;
        }
    }
}

void removeOccupant(Room *room, int occupant) {
    int i;
    for (i = 0; i < MAX_OCCUPANTS; i++) {
        if (room->occupants[i] == occupant) {
            room->occupants[i] = 0;
            break;
        }
    }
}