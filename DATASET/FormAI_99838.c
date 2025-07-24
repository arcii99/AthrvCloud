//FormAI DATASET v1.0 Category: Haunted House Simulator ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// Define room size
#define ROOM_SIZE 5

// Define max number of ghosts
#define MAX_GHOSTS 3

// Define max number of items
#define MAX_ITEMS 3

// Define ghost structure
typedef struct {
    int id;
    int position;
    int scared;
} Ghost;

// Define item structure
typedef struct {
    int id;
    int position;
    int picked;
} Item;

// Define player structure
typedef struct {
    int position;
    int health;
    int items_collected[MAX_ITEMS];
} Player;

// Define room structure
typedef struct {
    int id;
    Ghost ghosts[MAX_GHOSTS];
    Item items[MAX_ITEMS];
    int exits[ROOM_SIZE];
} Room;

// Define game state structure
typedef struct {
    Player player;
    Room rooms[ROOM_SIZE];
    int current_room;
} GameState;

// Define function to initialize game state
void initialize_game(GameState *state) {
    // Initialize player
    state->player.position = 0;
    state->player.health = 100;
    memset(state->player.items_collected, 0, sizeof(int) * MAX_ITEMS);
    
    // Initialize rooms
    for (int i = 0; i < ROOM_SIZE; i++) {
        state->rooms[i].id = i;
        
        for (int j = 0; j < MAX_GHOSTS; j++) {
            state->rooms[i].ghosts[j].id = j;
            state->rooms[i].ghosts[j].position = rand() % 10;
            state->rooms[i].ghosts[j].scared = 0;
        }
        
        for (int k = 0; k < MAX_ITEMS; k++) {
            state->rooms[i].items[k].id = k;
            state->rooms[i].items[k].position = rand() % 10;
            state->rooms[i].items[k].picked = 0;
        }
        
        for (int l = 0; l < ROOM_SIZE; l++) {
            state->rooms[i].exits[l] = rand() % 5;
        }
    }
    
    // Set current room to first room
    state->current_room = 0;
}

// Define function to print game status
void print_game(GameState state) {
    printf("Current room: %d\n", state.current_room);
    printf("Player position: %d\n", state.player.position);
    printf("Player health: %d\n", state.player.health);
    printf("Items collected: ");
    
    for (int i = 0; i < MAX_ITEMS; i++) {
        if (state.player.items_collected[i]) {
            printf("%d ", i);
        }
    }
    
    printf("\nGhosts: ");
    
    for (int i = 0; i < MAX_GHOSTS; i++) {
        if (state.rooms[state.current_room].ghosts[i].position == state.player.position) {
            if (state.rooms[state.current_room].ghosts[i].scared) {
                printf("Ghost %d (scared) ", i);
            } else {
                printf("Ghost %d ", i);
            }
        }
    }
    
    printf("\nItems: ");
    
    for (int i = 0; i < MAX_ITEMS; i++) {
        if (state.rooms[state.current_room].items[i].position == state.player.position && !state.rooms[state.current_room].items[i].picked) {
            printf("Item %d ", i);
        }
    }
    
    printf("\nExits: ");
    
    for (int i = 0; i < ROOM_SIZE; i++) {
        if (state.rooms[state.current_room].exits[i]) {
            printf("%d ", i);
        }
    }
    
    printf("\n");
}

// Define function to handle player input
void handle_input(GameState *state, char input) {
    switch (input) {
        case 'w':
            if (state->rooms[state->current_room].exits[0]) {
                state->player.position--;
            }
            break;
        case 'a':
            if (state->rooms[state->current_room].exits[1]) {
                state->player.position -= ROOM_SIZE;
            }
            break;
        case 's':
            if (state->rooms[state->current_room].exits[2]) {
                state->player.position++;
            }
            break;
        case 'd':
            if (state->rooms[state->current_room].exits[3]) {
                state->player.position += ROOM_SIZE;
            }
            break;
        case '1':
            if (state->rooms[state->current_room].items[0].position == state->player.position && !state->rooms[state->current_room].items[0].picked) {
                state->rooms[state->current_room].items[0].picked = 1;
                state->player.items_collected[0] = 1;
            }
            break;
        case '2':
            if (state->rooms[state->current_room].items[1].position == state->player.position && !state->rooms[state->current_room].items[1].picked) {
                state->rooms[state->current_room].items[1].picked = 1;
                state->player.items_collected[1] = 1;
            }
            break;
        case '3':
            if (state->rooms[state->current_room].items[2].position == state->player.position && !state->rooms[state->current_room].items[2].picked) {
                state->rooms[state->current_room].items[2].picked = 1;
                state->player.items_collected[2] = 1;
            }
            break;
        case '4':
            for (int i = 0; i < MAX_GHOSTS; i++) {
                if (state->rooms[state->current_room].ghosts[i].position == state->player.position) {
                    state->rooms[state->current_room].ghosts[i].scared = 1;
                }
            }
            break;
        default:
            printf("Invalid input\n");
            break;
    }
}

// Define function to update game state
void update(GameState *state) {
    // Check for collision with ghosts
    for (int i = 0; i < MAX_GHOSTS; i++) {
        if (state->rooms[state->current_room].ghosts[i].position == state->player.position && !state->rooms[state->current_room].ghosts[i].scared) {
            state->player.health -= 10;
        }
    }
    
    // Check for win condition
    int all_items_collected = 1;
    
    for (int i = 0; i < MAX_ITEMS; i++) {
        if (!state->player.items_collected[i]) {
            all_items_collected = 0;
            break;
        }
    }
    
    if (all_items_collected) {
        printf("You win!\n");
        exit(0);
    }
    
    // Check for lose condition
    if (state->player.health <= 0) {
        printf("You lose!\n");
        exit(0);
    }
}

// Define main function
int main() {
    srand(time(NULL));
    GameState state;
    initialize_game(&state);
    
    while (1) {
        print_game(state);
        
        char input;
        printf("Enter input: ");
        scanf(" %c", &input);
        
        handle_input(&state, input);
        update(&state);
        
        system("clear");
    }
    
    return 0;
}