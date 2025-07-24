//FormAI DATASET v1.0 Category: Haunted House Simulator ; Style: excited
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <time.h>

#define MAX_ROOMS 10
#define MAX_TURNS 50

struct Room {
    char* description;
    bool isHaunted;
    int up, down, left, right;
};

void generateRooms(struct Room* rooms, int size);
void connectRooms(struct Room* rooms, int size);
void printRoomDescription(struct Room* room);
void simulateGame(struct Room* rooms, int size);

int main() {
    srand(time(NULL));
    struct Room rooms[MAX_ROOMS];
    generateRooms(rooms, MAX_ROOMS);
    connectRooms(rooms, MAX_ROOMS);
    simulateGame(rooms, MAX_ROOMS);

    return 0;
}

void generateRooms(struct Room* rooms, int size) {
    char* descriptions[] = {
        "You are now in the foyer. The walls are covered in cobwebs and the air is musty. You see a stairway going up and a door leading left.",
        "You enter the kitchen. The counters are covered in dust and the stove has not been used in years. You see a door leading down and a door leading right.",
        "You find yourself in the library. Books line the walls and the smell of old paper fills the air. You see a door leading left and a door leading right.",
        "You enter the living room. The furniture is covered in white sheets and the room is oddly cold. You see a door leading up and a door leading down.",
        "You find yourself in the dining room. The table is set for a meal, but the food is rotten and the plates are covered in mold. You see a door leading up and a door leading down.",
        "You enter the den. The room is filled with old furniture and the smell of mothballs. You see a door leading left and a door leading down.",
        "You find yourself in the music room. The piano is covered in dust and cobwebs hang from the ceiling. You see a door leading up and a door leading right.",
        "You enter the master bedroom. The bed is unmade and clothes are scattered about. You see a door leading left and a door leading up.",
        "You find yourself in the guest bedroom. The room is small and the sheets on the bed are stained. You see a door leading down and a door leading right.",
        "You enter the bathroom. The tub is stained and the sink is cracked. You see a door leading left and a door leading down."
    };

    for (int i = 0; i < size; i++) {
        struct Room room;
        room.description = descriptions[i];
        room.isHaunted = (rand() % 2 == 0) ? true : false;
        rooms[i] = room;
    }
}

void connectRooms(struct Room* rooms, int size) {
    int roomIndexes[size];
    for (int i = 0; i < size; i++) {
        roomIndexes[i] = i;
    }

    // Shuffle room indexes
    for (int i = size - 1; i > 0; i--) {
        int j = rand() % (i + 1);
        int temp = roomIndexes[i];
        roomIndexes[i] = roomIndexes[j];
        roomIndexes[j] = temp;
    }

    // Connect rooms
    for (int i = 0; i < size - 1; i++) {
        int current = roomIndexes[i];
        int next = roomIndexes[i + 1];

        // Up connection
        if (rooms[current].up == 0 && rooms[next].down == 0) {
            rooms[current].up = next;
            rooms[next].down = current;
        }
        
        // Down connection
        else if (rooms[current].down == 0 && rooms[next].up == 0) {
            rooms[current].down = next;
            rooms[next].up = current;
        }

        // Left connection
        else if (rooms[current].left == 0 && rooms[next].right == 0) {
            rooms[current].left = next;
            rooms[next].right = current;
        }

        // Right connection
        else if (rooms[current].right == 0 && rooms[next].left == 0) {
            rooms[current].right = next;
            rooms[next].left = current;
        }
    }
}

void printRoomDescription(struct Room* room) {
    printf("%s\n", room->description);

    if (room->isHaunted) {
        printf("Oh no! This room is haunted!\n");
    }
}

void simulateGame(struct Room* rooms, int size) {
    printf("Welcome to the haunted house simulator!\n");
    int currentRoom = (rand() % size);
    int numTurns = 0;

    while (numTurns < MAX_TURNS) {
        if (rooms[currentRoom].isHaunted) {
            printf("You have been scared to death by a ghost! Game Over.\n");
            break;
        }

        printRoomDescription(&rooms[currentRoom]);

        int direction;
        do {
            printf("Which direction would you like to go? (1: Up, 2: Down, 3: Left, 4: Right) ");
            scanf("%d", &direction);
        } while (direction < 1 || direction > 4);

        switch (direction) {
            case 1:
                if (rooms[currentRoom].up != 0) {
                    currentRoom = rooms[currentRoom].up;
                }
                else {
                    printf("You cannot go that way.\n");
                }
                break;
            case 2:
                if (rooms[currentRoom].down != 0) {
                    currentRoom = rooms[currentRoom].down;
                }
                else {
                    printf("You cannot go that way.\n");
                }
                break;
            case 3:
                if (rooms[currentRoom].left != 0) {
                    currentRoom = rooms[currentRoom].left;
                }
                else {
                    printf("You cannot go that way.\n");
                }
                break;
            case 4:
                if (rooms[currentRoom].right != 0) {
                    currentRoom = rooms[currentRoom].right;
                }
                else {
                    printf("You cannot go that way.\n");
                }
                break;
        }

        numTurns++;
    }

    if (numTurns == MAX_TURNS) {
        printf("You have run out of turns. Game over.\n");
    }

    printf("Thanks for playing!\n");
}