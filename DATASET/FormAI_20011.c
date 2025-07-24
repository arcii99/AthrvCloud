//FormAI DATASET v1.0 Category: Haunted House Simulator ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// Define constants
#define MAX_INPUT 20
#define MIN_INPUT 1
#define MAX_ROOMS 10
#define MIN_ROOMS 5
#define MAX_GHOSTS 5
#define MIN_GHOSTS 2
#define MAX_TURNS 15

// Define room structures
typedef struct {
    int id;
    char description[50];
    int east;
    int west;
    int north;
    int south;
    int ghosts;
} Room;

// Define ghost structures
typedef struct {
    int id;
} Ghost;

// Define player structure
typedef struct {
    int current_room;
    int turns_left;
} Player;

// Define function prototypes
void create_rooms(Room[]);
void create_ghosts(Ghost[]);
void print_room(Room[], Player);
void start_game(Room[], Ghost[], Player);
void change_room(Room[], Player);
void search_for_ghost(Room[], Ghost[], Player);
void print_ghost(Ghost[], int);
void lose_game();
void win_game();

int main() {
    // Initialize variables
    Room rooms[MAX_ROOMS];
    Ghost ghosts[MAX_GHOSTS];
    Player player = {0, MAX_TURNS};
    
    // Create rooms and ghosts
    create_rooms(rooms);
    create_ghosts(ghosts);

    // Start game
    start_game(rooms, ghosts, player);

    return 0;
}

// Function to create rooms
void create_rooms(Room rooms[]) {
    int i;

    // Set random seed
    srand(time(NULL));

    // Loop through and create rooms
    for (i = 0; i < MAX_ROOMS; i++) {
        rooms[i].id = i;

        switch(rand() % 3) {
            case 0:
                strcpy(rooms[i].description, "You enter a dusty room with a creaky floorboard.");
                break;
            case 1:
                strcpy(rooms[i].description, "You enter a dimly lit room with spider webs in the corners.");
                break;
            case 2:
                strcpy(rooms[i].description, "You enter a room with broken furniture and shattered windows.");
                break;
        }

        // Set random room connections
        rooms[i].east = i == MAX_ROOMS - 1 ? -1 : rand() % (MAX_ROOMS - i - 1) + i + 1;
        rooms[i].west = i == 0 ? -1 : rand() % i;
        rooms[i].north = rand() % 3 - 1 == 0 ? -1 : rand() % (MAX_ROOMS - i - 1) + i + 1;
        rooms[i].south = rand() % 3 - 1 == 0 ? -1 : rand() % i;

        // Set random number of ghosts
        rooms[i].ghosts = rand() % (MAX_GHOSTS - MIN_GHOSTS + 1) + MIN_GHOSTS;
    }
}

// Function to create ghosts
void create_ghosts(Ghost ghosts[]) {
    int i;

    // Loop through and create ghosts
    for (i = 0; i < MAX_GHOSTS; i++) {
        ghosts[i].id = i;
    }
}

// Function to print current room description
void print_room(Room rooms[], Player player) {
    printf("\n You are in room %d. %s\n", rooms[player.current_room].id, rooms[player.current_room].description);

    // Print room connections
    printf("You can go: ");

    if (rooms[player.current_room].east != -1) {
        printf("East ");
    }

    if (rooms[player.current_room].west != -1) {
        printf("West ");
    }

    if (rooms[player.current_room].north != -1) {
        printf("North ");
    }

    if (rooms[player.current_room].south != -1) {
        printf("South ");
    }

    printf("\n");
}

// Function to start game
void start_game(Room rooms[], Ghost ghosts[], Player player) {
    // Print intro message
    printf("\nWelcome to the Haunted House Simulator!\n\n");

    // Loop through turns
    while (player.turns_left > 0) {
        // Print current room description
        print_room(rooms, player);

        // Get user input and take appropriate action
        printf("Enter a direction (e.g. East, West, North, South) or 'search': ");
        char input[MAX_INPUT];
        scanf("%s", input);

        if (strcmp(input, "search") == 0) {
            search_for_ghost(rooms, ghosts, player);
        } else {
            change_room(rooms, player);
        }
    }

    // Player has lost
    lose_game();
}

// Function to change rooms
void change_room(Room rooms[], Player player) {
    // Check if player can go in the chosen direction
    char direction[MAX_INPUT];
    scanf("%s", direction);

    int new_room = -1;

    // Change room if possible
    if (strcmp(direction, "East") == 0 && rooms[player.current_room].east != -1) {
        new_room = rooms[player.current_room].east;
    } else if (strcmp(direction, "West") == 0 && rooms[player.current_room].west != -1) {
        new_room = rooms[player.current_room].west;
    } else if (strcmp(direction, "North") == 0 && rooms[player.current_room].north != -1) {
        new_room = rooms[player.current_room].north;
    } else if (strcmp(direction, "South") == 0 && rooms[player.current_room].south != -1) {
        new_room = rooms[player.current_room].south;
    } else {
        printf("You can't go in that direction.\n");
    }

    if (new_room != -1) {
        // Move to new room
        player.current_room = new_room;

        // Decrement turn counter
        player.turns_left--;

        // Check if player has won
        if (player.current_room == MAX_ROOMS - 1) {
            win_game();
        }
    }
}

// Function to search for ghost
void search_for_ghost(Room rooms[], Ghost ghosts[], Player player) {
    // Check if ghosts are present in the room
    if (rooms[player.current_room].ghosts == 0) {
        printf("\nThere are no ghosts in this room.\n");
    } else {
        // Print ghost descriptions
        int i;
        for (i = 0; i < rooms[player.current_room].ghosts; i++) {
            print_ghost(ghosts, i);
        }

        // Decrement number of ghosts
        rooms[player.current_room].ghosts--;

        // Decrement turn counter
        player.turns_left--;
    }
}

// Function to print ghost description
void print_ghost(Ghost ghosts[], int index) {
    printf("\nA ghost appears before you. It looks like ghost %d.\n", ghosts[index].id);
}

// Function when player loses
void lose_game() {
    printf("\nYou have run out of turns. You lose.\n");
}

// Function when player wins
void win_game() {
    printf("\nCongratulations! You reached the final room and have won the game!\n");
}