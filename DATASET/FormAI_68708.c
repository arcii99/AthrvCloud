//FormAI DATASET v1.0 Category: Maze Route Finder ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <unistd.h>

#define ROW 15
#define COL 20

char MAZE[ROW][COL+1] = {
    "||||||||||||||||||",
    "| |  |    |       |",
    "| |||| |||| ||| |||",
    "|          |    | |",
    "|||| ||| |||||| |||",
    "|    ||| |    |   |",
    "||| ||||| ||| |||||",
    "|   |      |      |",
    "||| |||||| ||||||||",
    "| |        |     | |",
    "|   |||||| ||| | ||",
    "|||          |||  |",
    "|  | ||| ||||||||| |",
    "|    |           | |",
    "||||||||||||||||| |",
};

int INITIAL_X = 1;
int INITIAL_Y = 13;
int TARGET_X = 13;
int TARGET_Y = 1;

// Define a struct for tracking current position
struct position {
    int x;
    int y;
};

// Define a function for printing the current state of the maze
void print_maze() {
    system("clear"); // Clear the terminal screen
    for (int i = 0; i < ROW; i++) {
        printf("%s\n", MAZE[i]);
    }
    printf("\n");
}

// Define a function for moving the player to a new position
bool move_player(struct position * current_pos, int move_x, int move_y) {
    int new_x = current_pos->x + move_x;
    int new_y = current_pos->y + move_y;
    if (new_x >= 0 && new_x < ROW && new_y >= 0 && new_y < COL && MAZE[new_x][new_y] != '|') {
        // Update current_pos to the new position
        current_pos->x = new_x;
        current_pos->y = new_y;
        return true;
    } else {
        return false;
    }
}

// Define a recursive function for finding the route to the target
bool find_route(struct position current_pos) {
    // Base case: if the current position is the target position, return true
    if (current_pos.x == TARGET_X && current_pos.y == TARGET_Y) {
        return true;
    }
    int moves[4][2] = {{0,-1},{0,1},{-1,0},{1,0}}; // Define the possible moves
    for (int i = 0; i < 4; i++) {
        // Make a move and update current_pos
        struct position new_pos = current_pos;
        move_player(&new_pos, moves[i][0], moves[i][1]);
        if (find_route(new_pos)) { // Recursively continue searching
            MAZE[current_pos.x][current_pos.y] = 'O'; // Mark the current position as part of the solution
            print_maze();
            usleep(100000); // Sleep for 100 milliseconds
            return true;
        }
    }
    return false;
}

int main() {
    print_maze();
    struct position current_pos = {INITIAL_X, INITIAL_Y};
    if (find_route(current_pos)) {
        MAZE[INITIAL_X][INITIAL_Y] = 'X'; // Mark the initial position
        MAZE[TARGET_X][TARGET_Y] = 'T'; // Mark the target position
        printf("Route found!\n");
    } else {
        printf("Route not found :(\n");
    }
    print_maze();
    return 0;
}