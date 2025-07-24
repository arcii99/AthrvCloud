//FormAI DATASET v1.0 Category: Haunted House Simulator ; Style: modular
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_ROOMS 10

// Define room structure
typedef struct {
    int roomNum;
    int hasGhost;
    int hasTreasure;
    int north;
    int south;
    int east;
    int west;
} Room;

// Initialize the rooms
void initRooms(Room rooms[]) {
    for(int i=0; i<MAX_ROOMS; i++) {
        rooms[i].roomNum = i+1;
        rooms[i].hasGhost = 0;
        rooms[i].hasTreasure = 0;
        rooms[i].north = -1;
        rooms[i].south = -1;
        rooms[i].east = -1;
        rooms[i].west = -1;
    }
}

// Connect rooms together randomly
void connectRooms(Room rooms[]) {
    int randNum;
    for(int i=0; i<MAX_ROOMS; i++) {
        randNum = rand() % MAX_ROOMS;
        while(randNum == i) {
            randNum = rand() % MAX_ROOMS;
        }
        rooms[i].north = randNum;
        randNum = rand() % MAX_ROOMS;
        while(randNum == i) {
            randNum = rand() % MAX_ROOMS;
        }
        rooms[i].south = randNum;
        randNum = rand() % MAX_ROOMS;
        while(randNum == i) {
            randNum = rand() % MAX_ROOMS;
        }
        rooms[i].east = randNum;
        randNum = rand() % MAX_ROOMS;
        while(randNum == i) {
            randNum = rand() % MAX_ROOMS;
        }
        rooms[i].west = randNum;
    }
}

// Place ghost in a randomly chosen room
void placeGhost(Room rooms[]) {
    int randNum = rand() % MAX_ROOMS;
    rooms[randNum].hasGhost = 1;
}

// Place treasure in a randomly chosen room
void placeTreasure(Room rooms[]) {
    int randNum = rand() % MAX_ROOMS;
    rooms[randNum].hasTreasure = 1;
}

int main() {
    srand(time(NULL));
    Room rooms[MAX_ROOMS];
    initRooms(rooms);
    connectRooms(rooms);
    placeGhost(rooms);
    placeTreasure(rooms);

    int currentRoom = 0;
    printf("Welcome to the Haunted House Simulator!\n");
    while(1) {
        printf("You are currently in room %d.\n", currentRoom+1);
        printf("What would you like to do? (Enter 'n' for north, 's' for south, 'e' for east, 'w' for west): ");
        char direction;
        scanf("%c", &direction);
        getchar();
        switch(direction) {
            case 'n':
                if(rooms[currentRoom].north != -1) {
                    currentRoom = rooms[currentRoom].north;
                } else {
                    printf("There is no room in that direction!\n");
                }
                break;
            case 's':
                if(rooms[currentRoom].south != -1) {
                    currentRoom = rooms[currentRoom].south;
                } else {
                    printf("There is no room in that direction!\n");
                }
                break;
            case 'e':
                if(rooms[currentRoom].east != -1) {
                    currentRoom = rooms[currentRoom].east;
                } else {
                    printf("There is no room in that direction!\n");
                }
                break;
            case 'w':
                if(rooms[currentRoom].west != -1) {
                    currentRoom = rooms[currentRoom].west;
                } else {
                    printf("There is no room in that direction!\n");
                }
                break;
            default:
                printf("Invalid direction!\n");
        }

        if(rooms[currentRoom].hasGhost == 1) {
            printf("Oh no! You've stumbled upon a ghost! GAME OVER.\n");
            break;
        } else if(rooms[currentRoom].hasTreasure == 1) {
            printf("Congratulations! You've found the treasure and won the game!\n");
            break;
        }
    }
    return 0;
}