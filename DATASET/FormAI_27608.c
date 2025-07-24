//FormAI DATASET v1.0 Category: Maze Route Finder ; Style: energetic
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

// Struct to store coordinates
typedef struct {
    int x;
    int y;
} Coord;

// Function to print the maze
void printMaze(char maze[12][23]) {
    for (int i = 0; i < 12; i++) {
        for (int j = 0; j < 23; j++) {
            printf("%c", maze[i][j]);
        }
        printf("\n");
    }
}

// Function to check if a move is valid
bool isValidMove(Coord pos, Coord move, char maze[12][23]) {
    Coord newPos = {pos.x + move.x, pos.y + move.y};
    if (newPos.x >= 0 && newPos.x < 12 && newPos.y >= 0 && newPos.y < 23 
        && maze[newPos.x][newPos.y] == ' ' || maze[newPos.x][newPos.y] == 'E') {
        return true;
    }
    return false;
}

// Function to find route through maze
int findRoute(Coord pos, char maze[12][23], Coord route[], int routeLength) {
    Coord moves[] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
    // Check if current position is the end
    if (maze[pos.x][pos.y] == 'E') {
        route[routeLength++] = pos;
        return routeLength;
    }
    // Check all possible moves
    for (int i = 0; i < 4; i++) {
        if (isValidMove(pos, moves[i], maze)) {
            // Add current position to route
            route[routeLength++] = pos;
            // Mark current position as visited
            maze[pos.x][pos.y] = '.';
            // Recursively find route
            routeLength = findRoute((Coord){pos.x + moves[i].x, pos.y + moves[i].y}, maze, route, routeLength);
            // If route is found, return route length
            if (routeLength > 0) {
                return routeLength;
            }
            // Remove previous move from route
            route[--routeLength] = (Coord){-1, -1};
            // Mark current position as unvisited
            maze[pos.x][pos.y] = ' ';
        }
    }
    return 0;
}

int main() {
    char maze[12][23] = {
        "+----------------------+", 
        "|                      |",
        "|    +-----+           |",
        "|    |     |   +---+   |",
        "|    |     |   |   |   |",
        "|    |     |   |   |   |",
        "|    |     |   |   |   |",
        "|    +-----+   |   |   |",
        "|              |   |   |",
        "|    +-----+   |   |   |",
        "|    |     |   |   |   |",
        "|    |     |---+   |   |",
        "+----------------------+"};
    Coord start = {1, 1};
    Coord end = {10, 21};
    Coord route[100] = {{-1, -1}};
    int routeLength = findRoute(start, maze, route, 0);
    // Print route through maze if found
    if (routeLength > 0) {
        for (int i = routeLength - 1; i >= 0; i--) {
            maze[route[i].x][route[i].y] = '*';
        }
        printf("Found Route:\n");
        printMaze(maze);
    } else {
        printf("Could Not Find Route\n");
    }
    return 0;
}