//FormAI DATASET v1.0 Category: Text-Based Adventure Game ; Style: inquisitive
#include <stdio.h>
#include <string.h>

// Declare the player structure
struct Player {
    char name[20];
    int health;
    int strength;
    int intelligence;
};

// Declare the room structure
struct Room {
    char description[200];
    int exit[3];
};

int main() {
    // Initialize the player
    struct Player player;
    player.health = 100;
    player.strength = 10;
    player.intelligence = 10;

    // Initialize the rooms
    struct Room room[3];
    strcpy(room[0].description, "You are in a dark room. There is a door to the north.");
    room[0].exit[0] = 1;
    room[0].exit[1] = -1;
    room[0].exit[2] = -1;

    strcpy(room[1].description, "You are in a brightly lit room. There are doors to the north, east, and west.");
    room[1].exit[0] = 2;
    room[1].exit[1] = 0;
    room[1].exit[2] = 3;

    strcpy(room[2].description, "You are in a room with a trap door on the floor. There is a door to the south.");
    room[2].exit[0] = -1;
    room[2].exit[1] = 1;
    room[2].exit[2] = -1;

    strcpy(room[3].description, "You are in a room filled with treasure. There is a door to the west.");
    room[3].exit[0] = -1;
    room[3].exit[1] = -1;
    room[3].exit[2] = 1;

    // Start the game
    int current_room = 0;
    printf("Welcome to the Adventure Game!\n");
    printf("What is your name?\n");
    scanf("%s", player.name);

    while (1) {
        printf("%s\n", room[current_room].description);
        printf("What do you want to do? ");
        char action[20];
        scanf("%s", action);

        if (strcmp(action, "north") == 0) {
            if (room[current_room].exit[0] != -1) {
                current_room = room[current_room].exit[0];
            } else {
                printf("There is no exit to the north.\n");
            }
        } else if (strcmp(action, "east") == 0) {
            if (room[current_room].exit[1] != -1) {
                current_room = room[current_room].exit[1];
            } else {
                printf("There is no exit to the east.\n");
            }
        } else if (strcmp(action, "south") == 0) {
            if (room[current_room].exit[2] != -1) {
                current_room = room[current_room].exit[2];
            } else {
                printf("There is no exit to the south.\n");
            }
        } else if (strcmp(action, "status") == 0) {
            printf("Name: %s\n", player.name);
            printf("Health: %d\n", player.health);
            printf("Strength: %d\n", player.strength);
            printf("Intelligence: %d\n", player.intelligence);
        } else {
            printf("I don't understand that command.\n");
        }
    }

    return 0;
}