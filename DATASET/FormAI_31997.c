//FormAI DATASET v1.0 Category: Haunted House Simulator ; Style: Claude Shannon
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define MAX_ROOMS 10

typedef struct room {
    char name[20];
    struct room *north;
    struct room *east;
    struct room *south;
    struct room *west;
    int ghost_present;
} Room;

void initialize_rooms(Room *rooms) {
    for (int i = 0; i < MAX_ROOMS; i++) {
        sprintf(rooms[i].name, "room%d", i+1);
        rooms[i].north = NULL;
        rooms[i].east = NULL;
        rooms[i].south = NULL;
        rooms[i].west = NULL;
        rooms[i].ghost_present = 0;
    }
}

void connect_rooms(Room *rooms) {
    srand(time(0));
    for (int i = 0; i < MAX_ROOMS; i++) {
        int random_north = rand() % MAX_ROOMS;
        int random_east = rand() % MAX_ROOMS;
        int random_south = rand() % MAX_ROOMS;
        int random_west = rand() % MAX_ROOMS;
        while (random_north == i) {
            random_north = rand() % MAX_ROOMS;
        }
        while (random_east == i || random_east == random_north) {
            random_east = rand() % MAX_ROOMS;
        }
        while (random_south == i || random_south == random_north || random_south == random_east) {
            random_south = rand() % MAX_ROOMS;
        }
        while (random_west == i || random_west == random_north || random_west == random_east || random_west == random_south) {
            random_west = rand() % MAX_ROOMS;
        }
        rooms[i].north = &rooms[random_north];
        rooms[i].east = &rooms[random_east];
        rooms[i].south = &rooms[random_south];
        rooms[i].west = &rooms[random_west];
    }
}

void place_ghosts(Room *rooms) {
    srand(time(0));
    int num_ghosts = rand() % (MAX_ROOMS/2) + 1;
    for (int i = 0; i < num_ghosts; i++) {
        int ghost_room = rand() % MAX_ROOMS;
        rooms[ghost_room].ghost_present = 1;
    }
}

void display_room(Room *current_room) {
    printf("You are in %s\n", current_room->name);
    if (current_room->ghost_present) {
        printf("You hear a strange noise\n");
    }
    printf("You see exits to the following directions:");
    if (current_room->north != NULL) {
        printf(" north");
    }
    if (current_room->east != NULL) {
        printf(" east");
    }
    if (current_room->south != NULL) {
        printf(" south");
    }
    if (current_room->west != NULL) {
        printf(" west");
    }
    printf("\n");
}

int main() {
    Room rooms[MAX_ROOMS];
    initialize_rooms(rooms);
    connect_rooms(rooms);
    place_ghosts(rooms);
    
    Room *current_room = &rooms[0];
    char input[20];
    while (1) {
        display_room(current_room);
        printf("Enter the direction you want to go (or quit): ");
        scanf("%s", input);
        if (strcmp(input, "quit") == 0) {
            printf("Thanks for playing!\n");
            break;
        } else if (strcmp(input, "north") == 0 && current_room->north != NULL) {
            current_room = current_room->north;
        } else if (strcmp(input, "east") == 0 && current_room->east != NULL) {
            current_room = current_room->east;
        } else if (strcmp(input, "south") == 0 && current_room->south != NULL) {
            current_room = current_room->south;
        } else if (strcmp(input, "west") == 0 && current_room->west != NULL) {
            current_room = current_room->west;
        } else {
            printf("Invalid direction. Try again.\n");
        }
        if (current_room->ghost_present) {
            printf("A ghost appeared and scared you! You lost the game!\n");
            break;
        }
        if (current_room == &rooms[MAX_ROOMS-1]) {
            printf("Congrats! You escaped the haunted house!\n");
            break;
        }
    }
    return 0;
}