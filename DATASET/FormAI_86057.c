//FormAI DATASET v1.0 Category: Text-Based Adventure Game ; Style: complex
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#define MAX_COMMAND_LENGTH 100
#define MAX_ROOM_DESCRIPTION 500

// Possible actions
typedef enum {
    ACTION_UNKNOWN,
    ACTION_LOOK,
    ACTION_GO,
    ACTION_TAKE
} Action;

// Possible directions
typedef enum {
    DIRECTION_UNKNOWN,
    DIRECTION_NORTH,
    DIRECTION_SOUTH,
    DIRECTION_EAST,
    DIRECTION_WEST
} Direction;

// Possible objects
typedef enum {
    OBJECT_UNKNOWN,
    OBJECT_KEY,
    OBJECT_NOTE,
    OBJECT_SWORD
} Object;

// Possible rooms
typedef enum {
    ROOM_UNKNOWN,
    ROOM_HALLWAY,
    ROOM_KITCHEN,
    ROOM_LIBRARY,
    ROOM_TREASURE_CHAMBER
} Room;

// Data for each room
typedef struct {
    Room room;
    char description[MAX_ROOM_DESCRIPTION];
    Object object;
    Room north;
    Room south;
    Room east;
    Room west;
} RoomData;

// Game state
RoomData currentRoom;
bool hasSword = false;
bool hasKey = false;
bool hasNote = false;
char command[MAX_COMMAND_LENGTH];

// Print the current room description
void printDescription() {
    printf("%s\n", currentRoom.description);
}

// Process the user's command
void processCommand() {
    Action action = ACTION_UNKNOWN;
    Direction direction = DIRECTION_UNKNOWN;
    Object object = OBJECT_UNKNOWN;
    
    // Split the command into its parts
    char *part = strtok(command, " ");
    if (part != NULL) {
        // Determine the action
        if (strcmp(part, "look") == 0) {
            action = ACTION_LOOK;
        } else if (strcmp(part, "go") == 0) {
            action = ACTION_GO;
        } else if (strcmp(part, "take") == 0) {
            action = ACTION_TAKE;
        }
        
        // Determine the direction
        part = strtok(NULL, " ");
        if (part != NULL) {
            if (strcmp(part, "north") == 0) {
                direction = DIRECTION_NORTH;
            } else if (strcmp(part, "south") == 0) {
                direction = DIRECTION_SOUTH;
            } else if (strcmp(part, "east") == 0) {
                direction = DIRECTION_EAST;
            } else if (strcmp(part, "west") == 0) {
                direction = DIRECTION_WEST;
            }
            
            // Determine the object
            part = strtok(NULL, " ");
            if (part != NULL) {
                if (strcmp(part, "key") == 0) {
                    object = OBJECT_KEY;
                } else if (strcmp(part, "note") == 0) {
                    object = OBJECT_NOTE;
                } else if (strcmp(part, "sword") == 0) {
                    object = OBJECT_SWORD;
                }
            }
        }
    }
    
    // Process the action
    switch (action) {
        case ACTION_UNKNOWN:
            printf("I don't understand.\n");
            break;
            
        case ACTION_LOOK:
            printDescription();
            break;
            
        case ACTION_GO:
            switch (direction) {
                case DIRECTION_UNKNOWN:
                    printf("Where do you want to go?\n");
                    break;
                    
                case DIRECTION_NORTH:
                    if (currentRoom.north == ROOM_UNKNOWN) {
                        printf("You can't go that way.\n");
                    } else {
                        currentRoom = (RoomData){currentRoom.north};
                        printDescription();
                    }
                    break;
                    
                case DIRECTION_SOUTH:
                    if (currentRoom.south == ROOM_UNKNOWN) {
                        printf("You can't go that way.\n");
                    } else {
                        currentRoom = (RoomData){currentRoom.south};
                        printDescription();
                    }
                    break;
                    
                case DIRECTION_EAST:
                    if (currentRoom.east == ROOM_UNKNOWN) {
                        printf("You can't go that way.\n");
                    } else {
                        currentRoom = (RoomData){currentRoom.east};
                        printDescription();
                    }
                    break;
                    
                case DIRECTION_WEST:
                    if (currentRoom.west == ROOM_UNKNOWN) {
                        printf("You can't go that way.\n");
                    } else {
                        currentRoom = (RoomData){currentRoom.west};
                        printDescription();
                    }
                    break;
            }
            break;
            
        case ACTION_TAKE:
            switch (object) {
                case OBJECT_UNKNOWN:
                    printf("What do you want to take?\n");
                    break;
                
                case OBJECT_KEY:
                    if (currentRoom.object != OBJECT_KEY) {
                        printf("There is no key here.\n");
                    } else {
                        hasKey = true;
                        printf("You have taken the key.\n");
                    }
                    break;
                
                case OBJECT_NOTE:
                    if (currentRoom.object != OBJECT_NOTE) {
                        printf("There is no note here.\n");
                    } else {
                        hasNote = true;
                        printf("You have taken the note.\n");
                    }
                    break;
                
                case OBJECT_SWORD:
                    if (currentRoom.object != OBJECT_SWORD) {
                        printf("There is no sword here.\n");
                    } else {
                        hasSword = true;
                        printf("You have taken the sword.\n");
                    }
                    break;
            }
            break;
    }
}

int main() {
    // Initialize the rooms
    RoomData hallway = {
        .room = ROOM_HALLWAY,
        .description = "You are in a dark hallway. There are doors to the north and east.",
        .north = ROOM_KITCHEN,
        .east = ROOM_LIBRARY
    };
    
    RoomData kitchen = {
        .room = ROOM_KITCHEN,
        .description = "You are in a dirty kitchen. There is a key on the table and a door to the south.",
        .object = OBJECT_KEY,
        .south = ROOM_HALLWAY
    };
    
    RoomData library = {
        .room = ROOM_LIBRARY,
        .description = "You are in a dusty library. There is a note on the desk and a door to the west.",
        .object = OBJECT_NOTE,
        .west = ROOM_HALLWAY,
        .north = ROOM_TREASURE_CHAMBER
    };
    
    RoomData treasureChamber = {
        .room = ROOM_TREASURE_CHAMBER,
        .description = "You have found the treasure chamber! But there is a dragon guarding it. You need a sword to defeat it. There is a door to the south.",
        .south = ROOM_LIBRARY
    };
    
    // Start the game in the hallway
    currentRoom = hallway;
    
    // Print the instructions
    printf("Welcome to the adventure game!\n");
    printf("Commands: look, go [north | south | east | west], take [key | note | sword]\n");
    printf("Type 'quit' to end the game.\n");
    
    // Main game loop
    while (true) {
        // Get the user's command
        printf("> ");
        fgets(command, sizeof(command), stdin);
        command[strcspn(command, "\n")] = '\0';
        
        // Quit the game
        if (strcmp(command, "quit") == 0) {
            printf("Goodbye!\n");
            break;
        }
        
        // Process the command
        processCommand();
    }
    
    return 0;
}