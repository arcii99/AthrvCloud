//FormAI DATASET v1.0 Category: Text-Based Adventure Game ; Style: scientific
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_NAME_LEN 20
#define MAX_INPUT_LEN 50
#define NUM_ROOMS 5

typedef struct room {
    char name[MAX_NAME_LEN];
    char description[MAX_INPUT_LEN];
    int connections[NUM_ROOMS];
} Room;

void createRooms(Room rooms[]) {
    // Create the rooms
    strcpy(rooms[0].name, "Laboratory");
    strcpy(rooms[0].description, "A room filled with scientific equipment");
    // Connections: 1=Test Chamber, 2=Control Room
    rooms[0].connections[1] = 1;
    rooms[0].connections[2] = 1;

    strcpy(rooms[1].name, "Test Chamber");
    strcpy(rooms[1].description, "A room where experiments are conducted");
    // Connections: 0=Laboratory, 2=Control Room
    rooms[1].connections[0] = 1;
    rooms[1].connections[2] = 1;

    strcpy(rooms[2].name, "Control Room");
    strcpy(rooms[2].description, "A room with control panels for various experiments");
    // Connections: 0=Laboratory, 1=Test Chamber, 3=Observation Deck
    rooms[2].connections[0] = 1;
    rooms[2].connections[1] = 1;
    rooms[2].connections[3] = 1;

    strcpy(rooms[3].name, "Observation Deck");
    strcpy(rooms[3].description, "A room with a large window overlooking the testing area");
    // Connections: 2=Control Room, 4=Escape Pod
    rooms[3].connections[2] = 1;
    rooms[3].connections[4] = 1;

    strcpy(rooms[4].name, "Escape Pod");
    strcpy(rooms[4].description, "A small pod for escaping the facility");
    // Connections: 3=Observation Deck
    rooms[4].connections[3] = 1;
}

int main() {
    srand(time(NULL));
    Room rooms[NUM_ROOMS];
    createRooms(rooms);

    // Select a random starting room
    int currentRoom = rand() % NUM_ROOMS;

    // Game loop
    while (1) {
        printf("\n---------------\n%s\n---------------\n", rooms[currentRoom].name);
        printf("%s\n", rooms[currentRoom].description);

        // Get user input
        char input[MAX_INPUT_LEN];
        printf("\nWhere do you want to go?\n");
        scanf("%s", input);

        int found = 0;
        for (int i = 0; i < NUM_ROOMS; i++) {
            if (rooms[currentRoom].connections[i] && strcmp(input, rooms[i].name) == 0) {
                found = 1;
                currentRoom = i;
                break;
            }
        }

        if (!found) {
            printf("\nInvalid direction. Try another.\n");
        }

        // Check if the player has won
        if (currentRoom == 4) {
            printf("\nCongratulations! You have escaped the facility.\n");
            return 0;
        }
    }
    return 0;
}