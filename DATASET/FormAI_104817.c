//FormAI DATASET v1.0 Category: Smart home light control ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define constants
#define LIGHT_OFF 0
#define LIGHT_ON 1
#define MAX_ROOMS 10

// Define room struct
typedef struct {
    int num;
    char name[20];
    int lights[MAX_ROOMS];
} Room;

// Function prototypes
void initialize(Room *room);
void printRooms(Room *room);
void toggleLight(Room *room, int roomNum, int lightNum);

int main() {
    int roomNum, lightNum;
    char input[50];
    Room rooms[MAX_ROOMS];

    // Initialize each room
    for (int i = 0; i < MAX_ROOMS; i++) {
        initialize(&rooms[i]);
    }

    // Loop until user exits
    while (1) {
        printf("\nEnter a room number (1-%d) or 'exit' to quit: ", MAX_ROOMS);
        fgets(input, 50, stdin);
        input[strcspn(input, "\n")] = 0; // Remove newline character

        // Exit program if user types "exit"
        if (strcmp(input, "exit") == 0) {
            printf("\nGoodbye!\n");
            exit(0);
        }

        // Convert input to integer
        roomNum = atoi(input);

        // Print room information if valid number
        if (roomNum >= 1 && roomNum <= MAX_ROOMS) {
            printRooms(&rooms[roomNum - 1]);
        } else {
            printf("\nInvalid input.\n");
        }

        // Prompt user to toggle lights
        printf("\nEnter a light number (1-%d) to toggle or 'back' to go back: ", MAX_ROOMS);
        fgets(input, 50, stdin);
        input[strcspn(input, "\n")] = 0; // Remove newline character

        // Leave current room if user types "back"
        if (strcmp(input, "back") == 0) {
            continue;
        }

        // Convert input to integer
        lightNum = atoi(input);

        // Toggle light if valid number
        if (lightNum >= 1 && lightNum <= MAX_ROOMS) {
            toggleLight(&rooms[roomNum - 1], roomNum, lightNum);
        } else {
            printf("\nInvalid input.\n");
        }
    }

    return 0;
}

// Initialize room with lights off
void initialize(Room *room) {
    room->num = 0;
    strcpy(room->name, "");
    for (int i = 0; i < MAX_ROOMS; i++) {
        room->lights[i] = LIGHT_OFF;
    }
}

// Print room information
void printRooms(Room *room) {
    printf("\nRoom %d - %s\n", room->num, room->name);
    for (int i = 0; i < MAX_ROOMS; i++) {
        printf("Light %d: %s\n", i + 1, (room->lights[i] == LIGHT_ON) ? "On" : "Off");
    }
}

// Toggle light status
void toggleLight(Room *room, int roomNum, int lightNum) {
    if (room->lights[lightNum - 1] == LIGHT_OFF) {
        room->lights[lightNum - 1] = LIGHT_ON;
        printf("\nRoom %d Light %d turned on.\n", roomNum, lightNum);
    } else {
        room->lights[lightNum - 1] = LIGHT_OFF;
        printf("\nRoom %d Light %d turned off.\n", roomNum, lightNum);
    }
}