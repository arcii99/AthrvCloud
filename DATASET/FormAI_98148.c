//FormAI DATASET v1.0 Category: Haunted House Simulator ; Style: active
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <time.h>

#define MAX_ROOMS 10
#define ROOM_SIZE 5

// Function to print the maze
void print_maze(char maze[][ROOM_SIZE]) {
    for (int i = 0; i < ROOM_SIZE; i++) {
        for (int j = 0; j < ROOM_SIZE; j++) {
            printf("%c ", maze[i][j]);
        }
        printf("\n");
    }
}

int main() {
    char maze[ROOM_SIZE][ROOM_SIZE];
    // Initialize the maze with walls and empty spaces
    for (int i = 0; i < ROOM_SIZE; i++) {
        for (int j = 0; j < ROOM_SIZE; j++) {
            if (i == 0 || j == 0 || i == ROOM_SIZE - 1 || j == ROOM_SIZE - 1) {
                maze[i][j] = '#';
            } else {
                maze[i][j] = ' ';
            }
        }
    }

    // Randomly place the door, start, and end points
    srand(time(NULL));
    maze[0][rand() % (ROOM_SIZE - 2) + 1] = '|'; // door
    maze[ROOM_SIZE - 1][rand() % (ROOM_SIZE - 2) + 1] = 'S'; // start point
    maze[rand() % (ROOM_SIZE - 2) + 1][ROOM_SIZE - 1] = 'E'; // end point

    // Randomly place the obstacles and decorations
    for (int i = 0; i < MAX_ROOMS; i++) {
        int x = rand() % (ROOM_SIZE - 2) + 1;
        int y = rand() % (ROOM_SIZE - 2) + 1;
        if (maze[x][y] != ' ' || (x == ROOM_SIZE/2 && y == ROOM_SIZE/2)) {
            i--;
            continue;
        }
        maze[x][y] = rand() <= RAND_MAX/2 ? '#' : (rand() <= RAND_MAX/2 ? 'P' : 'D');
    }

    // Print the initial maze
    printf("Welcome to the Haunted House Simulator!\n");
    printf("You find yourself in a spooky, dark room...\n");
    print_maze(maze);

    // Start the game loop
    int x = ROOM_SIZE - 2;
    int y = rand() % (ROOM_SIZE - 2) + 1; // start at a random point on the left side of the maze
    while (true) {
        char input;
        printf("Enter 'w' to move up, 's' to move down, 'a' to move left, or 'd' to move right: ");
        scanf(" %c", &input);

        if (input == 'w' && maze[x - 1][y] != '#') {
            x--;
        } else if (input == 's' && maze[x + 1][y] != '#') {
            x++;
        } else if (input == 'a' && maze[x][y - 1] != '#') {
            y--;
        } else if (input == 'd' && maze[x][y + 1] != '#') {
            y++;
        } else {
            printf("You hit a wall! Try again.\n");
            continue;
        }

        if (maze[x][y] == '#') {
            printf("You hit a wall! Try again.\n");
            x = ROOM_SIZE - 2;
            y = rand() % (ROOM_SIZE - 2) + 1; // start at a random point on the left side of the maze
            continue;
        } else if (maze[x][y] == 'E') {
            printf("Congratulations, you made it through the haunted house alive!\n");
            break;
        } else if (maze[x][y] == 'P') {
            printf("You encountered a poltergeist! It flings you across the room and you lose your balance.\n");
        } else if (maze[x][y] == 'D') {
            printf("You stumble into a room filled with demonic dolls. They start moving and you have to run away.\n");
        }

        maze[x][y] = 'X'; // mark current location with 'X'
        print_maze(maze);
    }

    return 0;
}