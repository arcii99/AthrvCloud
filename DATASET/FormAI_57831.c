//FormAI DATASET v1.0 Category: Haunted House Simulator ; Style: brave
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_ROOMS 10     // maximum number of rooms
#define MAX_ITEMS 5      // maximum number of items per room
#define MAX_ITEM_NAME 20 // maximum length of item name
#define MAX_DESC_LEN 100 // maximum length of item description

// define the player struct
typedef struct Player {
    int room;              // current room number
    char inventory[MAX_ITEMS][MAX_ITEM_NAME];  // array of items in player's inventory
    int num_items;         // number of items in player's inventory
} Player;

// define the room struct
typedef struct Room {
    int number;           // room number
    char description[MAX_DESC_LEN];  // room description
    char items[MAX_ITEMS][MAX_ITEM_NAME];   // array of items in the room
    int num_items;        // number of items in the room
    int north;            // neighboring room numbers
    int south;
    int east;
    int west;
} Room;

// define the game function
void play_game() {
    // create an array of rooms
    Room rooms[MAX_ROOMS];
    // initialize the rooms
    rooms[0].number = 0;
    strcpy(rooms[0].description, "You are in the main hall of the haunted house.");
    strcpy(rooms[0].items[0], "candlestick"); rooms[0].num_items = 1;
    rooms[0].north = 1; rooms[0].south = -1; rooms[0].east = -1; rooms[0].west = -1;

    rooms[1].number = 1;
    strcpy(rooms[1].description, "You have entered the living room. There is a fireplace lit on the wall, casting shadows and a red glow throughout the room.");
    strcpy(rooms[1].items[0], "photo"); strcpy(rooms[1].items[1], "book"); rooms[1].num_items = 2;
    rooms[1].north = -1; rooms[1].south = 0; rooms[1].east = -1; rooms[1].west = -1;
    
    rooms[2].number = 2;
    strcpy(rooms[2].description, "You enter the kitchen. It is dark and smells of rotting food. You notice some items on the counter.");
    strcpy(rooms[2].items[0], "knife"); strcpy(rooms[2].items[1], "rotten apple"); rooms[2].num_items = 2;
    rooms[2].north = -1; rooms[2].south = 3; rooms[2].east = -1; rooms[2].west = -1;
    
    rooms[3].number = 3;
    strcpy(rooms[3].description, "You have entered the basement. It is damp and the air is thick. The sound of dripping water resonates throughout the room. You notice something sparkling on the floor.");
    strcpy(rooms[3].items[0], "key"); rooms[3].num_items = 1;
    rooms[3].north = 2; rooms[3].south = -1; rooms[3].east = -1; rooms[3].west = -1;

    // create the player
    Player player;
    player.room = 0;
    player.num_items = 0;

    // game loop
    while (1) {
        // print the room description to the screen
        printf("%s\n", rooms[player.room].description);

        // print the items in the room
        if (rooms[player.room].num_items > 0) {
            printf("You see the following items in the room:\n");
            for (int i = 0; i < rooms[player.room].num_items; i++) {
                printf("- %s\n", rooms[player.room].items[i]);
            }
        }
        else {
            printf("There are no items in this room.\n");
        }

        // print the player's inventory
        if (player.num_items > 0) {
            printf("You are carrying the following items:\n");
            for (int i = 0; i < player.num_items; i++) {
                printf("- %s\n", player.inventory[i]);
            }
        }
        else {
            printf("You are not carrying any items.\n");
        }

        // get user input
        char input[100];
        printf("What would you like to do? ");
        fgets(input, sizeof(input), stdin);

        // remove newline character from input
        input[strlen(input) - 1] = '\0';

        // parse input
        if (strcmp(input, "quit") == 0) {
            printf("Thanks for playing!\n");
            exit(0);
        }
        else if (strcmp(input, "north") == 0) {
            if (rooms[player.room].north != -1) {
                player.room = rooms[player.room].north;
            }
            else {
                printf("You cannot go that way.\n");
            }
        }
        else if (strcmp(input, "south") == 0) {
            if (rooms[player.room].south != -1) {
                player.room = rooms[player.room].south;
            }
            else {
                printf("You cannot go that way.\n");
            }
        }
        else if (strcmp(input, "east") == 0) {
            if (rooms[player.room].east != -1) {
                player.room = rooms[player.room].east;
            }
            else {
                printf("You cannot go that way.\n");
            }
        }
        else if (strcmp(input, "west") == 0) {
            if (rooms[player.room].west != -1) {
                player.room = rooms[player.room].west;
            }
            else {
                printf("You cannot go that way.\n");
            }
        }
        else if (strncmp(input, "take ", 5) == 0) {
            char item_name[MAX_ITEM_NAME];
            strcpy(item_name, input + 5);

            int found = 0;
            for (int i = 0; i < rooms[player.room].num_items; i++) {
                if (strcmp(item_name, rooms[player.room].items[i]) == 0) {
                    found = 1;
                    if (player.num_items < MAX_ITEMS) {
                        // add item to player inventory
                        strcpy(player.inventory[player.num_items], item_name);
                        player.num_items++;
                        printf("You have taken the %s.\n", item_name);
                        // remove item from room
                        for (int j = i; j < rooms[player.room].num_items - 1; j++) {
                            strcpy(rooms[player.room].items[j], rooms[player.room].items[j + 1]);
                        }
                        rooms[player.room].num_items--;
                    }
                    else {
                        printf("You cannot carry any more items.\n");
                    }
                    break;
                }
            }
            if (!found) {
                printf("Cannot find %s in this room.\n", item_name);
            }
        }
        else if (strncmp(input, "use ", 4) == 0) {
            char item_name[MAX_ITEM_NAME];
            strcpy(item_name, input + 4);
            if (player.num_items > 0) {
                int found = 0;
                for (int i = 0; i < player.num_items; i++) {
                    if (strcmp(item_name, player.inventory[i]) == 0) {
                        found = 1;
                        if (strcmp(item_name, "key") == 0 && player.room == 3) {
                            printf("You have successfully unlocked the basement door!\n");
                            exit(0);
                        }
                        else {
                            printf("You cannot use %s in this way.\n", item_name);
                        }
                        break;
                    }
                }
                if (!found) {
                    printf("Cannot find %s in your inventory.\n", item_name);
                }
            }
            else {
                printf("You are not carrying any items.\n");
            }
        }
        else {
            printf("Invalid input. Please try again.\n");
        }
    }
}

int main() {
    printf("\nWelcome to the Haunted House Simulator game!\n");
    printf("You will find yourself in a haunted house, filled with rooms and spooky surprises.\n");
    printf("Your goal is to explore the house and find your way out.\n");
    printf("Type 'quit' at any time to exit the game.\n\n");

    // seed the random number generator
    srand(time(NULL));

    // start the game
    play_game();

    return 0;
}