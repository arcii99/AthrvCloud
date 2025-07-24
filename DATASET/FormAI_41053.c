//FormAI DATASET v1.0 Category: Text-Based Adventure Game ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <string.h>

// Room struct to hold room information
typedef struct Room {
    char* name;
    char* description;
    struct Room** connected_rooms;
    int num_connected_rooms;
} Room;

// Player struct to hold player information
typedef struct Player {
    char* name;
    struct Room* current_room;
} Player;

// Global variables
Room* rooms[5];
Player* player;
pthread_mutex_t player_mutex;

// Function declarations
void* move_player(void* arg);
void print_room_info(Room* room);
void create_rooms();
void destroy_rooms();
void create_player();
void destroy_player();

int main() {
    // Initialize mutex
    pthread_mutex_init(&player_mutex, NULL);

    // Create game resources
    create_rooms();
    create_player();

    // Print welcome message
    printf("Welcome to the Text-Based Adventure Game!\n\n");

    // Main game loop
    while (1) {
        // Print current room information
        print_room_info(player->current_room);
        
        // Get user input
        char input[50];
        printf("Enter a command (move [room name], quit): ");
        fgets(input, 50, stdin);

        // Parse user input
        strtok(input, "\n");
        char* command = strtok(input, " ");
        char* arg = strtok(NULL, " ");

        // Handle commands
        if (strcmp(command, "move") == 0) {
            // Move player
            pthread_t thread;
            if (pthread_create(&thread, NULL, move_player, arg) != 0) {
                printf("Error: Could not create thread.\n");
                continue;
            }

            pthread_join(thread, NULL);
        } else if (strcmp(command, "quit") == 0) {
            // Quit game
            printf("Goodbye!\n");
            break;
        } else {
            // Invalid command
            printf("Error: Invalid command.\n");
        }
    }

    // Destroy game resources
    destroy_player();
    destroy_rooms();

    // Destroy mutex
    pthread_mutex_destroy(&player_mutex);

    return 0;
}

void* move_player(void* arg) {
    char* room_name = (char*) arg;

    // Search for requested room
    int i;
    Room* next_room = NULL;
    for (i = 0; i < player->current_room->num_connected_rooms; i++) {
        Room* connected_room = player->current_room->connected_rooms[i];
        if (strcmp(connected_room->name, room_name) == 0) {
            next_room = connected_room;
            break;
        }
    }

    if (next_room == NULL) {
        printf("Error: Room not found.\n");
        return NULL;
    }

    // Move player to next room
    pthread_mutex_lock(&player_mutex);
    player->current_room = next_room;
    pthread_mutex_unlock(&player_mutex);

    printf("You have moved to the %s.\n", next_room->name);

    return NULL;
}

void print_room_info(Room* room) {
    printf("Current Room:\n");
    printf("Name: %s\n", room->name);
    printf("Description: %s\n", room->description);
    printf("Connected Rooms: ");
    int i;
    for (i = 0; i < room->num_connected_rooms; i++) {
        printf("%s ", room->connected_rooms[i]->name);
    }
    printf("\n");
}

void create_rooms() {
    // Create room 1
    Room* room1 = malloc(sizeof(Room));
    room1->name = "Entryway";
    room1->description = "You are standing in an entryway. There are doors to the north, east, and west.";
    room1->connected_rooms = malloc(sizeof(Room*) * 3);
    room1->num_connected_rooms = 3;

    // Create room 2
    Room* room2 = malloc(sizeof(Room));
    room2->name = "Library";
    room2->description = "You have entered a library. There are bookshelves lining the walls and a table with a lamp in the center of the room.";
    room2->connected_rooms = malloc(sizeof(Room*) * 2);
    room2->num_connected_rooms = 2;

    // Create room 3
    Room* room3 = malloc(sizeof(Room));
    room3->name = "Bedroom";
    room3->description = "You are in a bedroom. There is a bed, a dresser, and a window on the wall facing west.";
    room3->connected_rooms = malloc(sizeof(Room*) * 2);
    room3->num_connected_rooms = 2;

    // Create room 4
    Room* room4 = malloc(sizeof(Room));
    room4->name = "Kitchen";
    room4->description = "You find yourself in a kitchen. There is a stove, a refrigerator, and a sink along the walls.";
    room4->connected_rooms = malloc(sizeof(Room*) * 1);
    room4->num_connected_rooms = 1;

    // Create room 5
    Room* room5 = malloc(sizeof(Room));
    room5->name = "Bathroom";
    room5->description = "You are in a bathroom. There is a sink, a toilet, and a bathtub with a showerhead.";
    room5->connected_rooms = malloc(sizeof(Room*) * 1);
    room5->num_connected_rooms = 1;

    // Connect rooms
    room1->connected_rooms[0] = room2;
    room1->connected_rooms[1] = room3;
    room1->connected_rooms[2] = room4;
    room2->connected_rooms[0] = room1;
    room2->connected_rooms[1] = room5;
    room3->connected_rooms[0] = room1;
    room3->connected_rooms[1] = room4;
    room4->connected_rooms[0] = room1;
    room5->connected_rooms[0] = room2;

    // Add rooms to global array
    rooms[0] = room1;
    rooms[1] = room2;
    rooms[2] = room3;
    rooms[3] = room4;
    rooms[4] = room5;
}

void destroy_rooms() {
    int i;
    for (i = 0; i < 5; i++) {
        Room* room = rooms[i];
        free(room->connected_rooms);
        free(room);
    }
}

void create_player() {
    // Create player
    player = malloc(sizeof(Player));
    player->name = "Player";
    player->current_room = rooms[0];
}

void destroy_player() {
    free(player);
}