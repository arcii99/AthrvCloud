//FormAI DATASET v1.0 Category: Text-Based Adventure Game ; Style: ephemeral
#include <stdio.h>
#include <string.h>

struct Room {
    char name[100];
    char description[200];
    struct Room* north;
    struct Room* south;
    struct Room* east;
    struct Room* west;
};

int main() {
    struct Room room1, room2, room3, room4, room5;
    strcpy(room1.name, "Room 1");
    strcpy(room1.description, "You enter a dark room, there's a faint smell of rotten food. You hear a faint noise coming from the north.");
    room1.north = &room2;
    room1.south = NULL;
    room1.east = &room4;
    room1.west = NULL;

    strcpy(room2.name, "Room 2");
    strcpy(room2.description, "You enter a brightly lit room, there's a strange feeling of energy in the air. You find a key on the ground.");
    room2.north = &room3;
    room2.south = &room1;
    room2.east = NULL;
    room2.west = NULL;

    strcpy(room3.name, "Room 3");
    strcpy(room3.description, "You enter a room filled with books. A wise-looking old man greets you. 'Welcome traveler, I can answer one of your questions for a price.'");
    room3.north = NULL;
    room3.south = &room2;
    room3.east = NULL;
    room3.west = NULL;

    strcpy(room4.name, "Room 4");
    strcpy(room4.description, "You enter a small room with a locked door to the north and a window to the east, overlooking a beautiful garden.");
    room4.north = NULL;
    room4.south = NULL;
    room4.east = &room5;
    room4.west = &room1;

    strcpy(room5.name, "Room 5");
    strcpy(room5.description, "You enter a room with a treasure chest in the center. However, there are also monsters guarding it!");
    room5.north = NULL;
    room5.south = NULL;
    room5.east = NULL;
    room5.west = &room4;

    struct Room* currentRoom = &room1;
    char input[10];

    printf("%s\n", currentRoom->description);
    while (1) {
        scanf("%s", input);
        if (strcmp(input, "north") == 0) {
            if (currentRoom->north == NULL) {
                printf("You can't go that way.\n");
            } else {
                currentRoom = currentRoom->north;
                printf("%s\n", currentRoom->description);
            }
        } else if (strcmp(input, "south") == 0) {
            if (currentRoom->south == NULL) {
                printf("You can't go that way.\n");
            } else {
                currentRoom = currentRoom->south;
                printf("%s\n", currentRoom->description);
            }
        } else if (strcmp(input, "east") == 0) {
            if (currentRoom->east == NULL) {
                printf("You can't go that way.\n");
            } else {
                currentRoom = currentRoom->east;
                printf("%s\n", currentRoom->description);
            }
        } else if (strcmp(input, "west") == 0) {
            if (currentRoom->west == NULL) {
                printf("You can't go that way.\n");
            } else {
                currentRoom = currentRoom->west;
                printf("%s\n", currentRoom->description);
            }
        } else if (strcmp(input, "quit") == 0) {
            printf("Thanks for playing!\n");
            break;
        } else if (strcmp(input, "take") == 0) {
            if (strcmp(currentRoom->name, "Room 2") == 0) {
                printf("You took the key.\n");
            } else {
                printf("There's nothing to take in this room.\n");
            }
        } else if (strcmp(input, "ask") == 0) {
            if (strcmp(currentRoom->name, "Room 3") == 0) {
                printf("'What is the meaning of life?' The old man thinks for a moment. 'The meaning of life is what you make of it, traveler.'\n");
            } else {
                printf("There's no one to ask here.\n");
            }
        } else if (strcmp(input, "open") == 0) {
            if (strcmp(currentRoom->name, "Room 4") == 0) {
                printf("You unlock the door with the key.\n");
                currentRoom->north = &room5;
            } else {
                printf("There's nothing to open in this room.\n");
            }
        } else if (strcmp(input, "fight") == 0) {
            if (strcmp(currentRoom->name, "Room 5") == 0) {
                printf("You defeated the monsters and took the treasure from the chest!\n");
                printf("Thanks for playing!\n");
                break;
            } else {
                printf("There's no one to fight here.\n");
            }
        } else {
            printf("Invalid input.\n");
        }
    }

    return 0;
}