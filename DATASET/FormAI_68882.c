//FormAI DATASET v1.0 Category: Haunted House Simulator ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/* Structure for the rooms in the haunted house */
typedef struct Room {
    char* name;
    char* description;
    struct Room* north;
    struct Room* south;
    struct Room* east;
    struct Room* west;
    int isHaunted;
} Room;

/* Function signatures */
Room* createRoom(char** roomNames, char** roomDescriptions);
void connectRooms(Room* room1, Room* room2, char direction);
void hauntRoom(Room* room);
int main();

/* Function to create a room with a name and description */
Room* createRoom(char** roomNames, char** roomDescriptions) {
    Room* newRoom = (Room*) malloc(sizeof(Room));
    newRoom->name = roomNames[rand() % 5];
    newRoom->description = roomDescriptions[rand() % 5];
    newRoom->north = NULL;
    newRoom->south = NULL;
    newRoom->east = NULL;
    newRoom->west = NULL;

    /* 50/50 chance of room being haunted */
    newRoom->isHaunted = rand() % 2;

    return newRoom;
}

/* Function to connect two rooms in a given direction */
void connectRooms(Room* room1, Room* room2, char direction) {
    switch(direction) {
        case 'N':
            room1->north = room2;
            room2->south = room1;
            break;
        case 'S':
            room1->south = room2;
            room2->north = room1;
            break;
        case 'E':
            room1->east = room2;
            room2->west = room1;
            break;
        case 'W':
            room1->west = room2;
            room2->east = room1;
            break;
    }
}

/* Function to randomly haunt a room */
void hauntRoom(Room* room) {
    if(room->isHaunted) {
        printf("\n%s is haunted!\n", room->name);
        printf("You feel a chill run down your spine...\n");
    }
}

int main() {
    srand(time(NULL));

    /* Arrays of possible room names and descriptions */
    char* roomNames[] = {"Foyer", "Kitchen", "Living Room", "Bedroom", "Basement"};
    char* roomDescriptions[] = {"A grand entrance into a large house.",
                                "A messy area with pots and pans all over the place.",
                                "A homely space with comfortable couches and a TV set.",
                                "A quaint bedroom with a four poster bed.",
                                "A damp and dark basement with cobwebs in the corner."};

    /* Create rooms */
    Room* foyer = createRoom(roomNames, roomDescriptions);
    Room* kitchen = createRoom(roomNames, roomDescriptions);
    Room* livingRoom = createRoom(roomNames, roomDescriptions);
    Room* bedroom = createRoom(roomNames, roomDescriptions);
    Room* basement = createRoom(roomNames, roomDescriptions);

    /* Connect rooms */
    connectRooms(foyer, livingRoom, 'N');
    connectRooms(livingRoom, kitchen, 'E');
    connectRooms(livingRoom, bedroom, 'S');
    connectRooms(livingRoom, basement, 'W');

    /* Print game instructions */
    printf("Welcome to the Haunted House Simulator!\n");
    printf("Move around the house by typing 'N', 'S', 'E', or 'W'.\n");
    printf("Type 'quit' to exit the game.\n");

    Room* currentRoom = foyer;

    while(1) {
        /* Print room name and description */
        printf("\nYou are in the %s.\n", currentRoom->name);
        printf("%s\n", currentRoom->description);

        /* Check if room is haunted */
        hauntRoom(currentRoom);

        /* Get user input */
        char input[5];
        printf("\nWhere would you like to go? ");
        scanf("%s", input);

        /* Move to new room */
        if(strcmp(input, "N") == 0 && currentRoom->north != NULL) {
            currentRoom = currentRoom->north;
        } else if(strcmp(input, "S") == 0 && currentRoom->south != NULL) {
            currentRoom = currentRoom->south;
        } else if(strcmp(input, "E") == 0 && currentRoom->east != NULL) {
            currentRoom = currentRoom->east;
        } else if(strcmp(input, "W") == 0 && currentRoom->west != NULL) {
            currentRoom = currentRoom->west;
        } else if(strcmp(input, "quit") == 0) {
            break;
        } else {
            printf("\nInvalid direction, try again.\n");
        }
    }

    /* Free memory */
    free(foyer);
    free(kitchen);
    free(livingRoom);
    free(bedroom);
    free(basement);

    return 0;
}