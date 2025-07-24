//FormAI DATASET v1.0 Category: Pathfinding algorithms ; Style: Cryptic
// The murky paths of the underworld call for a pathfinding algorithm
// Let the depths be illuminated by my code, as I navigate the labyrinthine underworld

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define ROWS 10
#define COLS 10

typedef struct {
    int row;
    int col;
} Position;

// Beneath the Earth lies a maze of corridors and caverns
char maze[ROWS][COLS] = {
    {'#', '#', '#', '#', '#', '#', '#', '#', '#', '#'},
    {'#', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '#', '#'},
    {'#', '#', '#', ' ', ' ', ' ', '#', ' ', '#', '#'},
    {'#', ' ', ' ', ' ', ' ', '#', '#', ' ', '#', '#'},
    {'#', ' ', '#', ' ', '#', '#', '#', '#', '#', '#'},
    {'#', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '#'},
    {'#', '#', ' ', '#', ' ', '#', '#', '#', ' ', '#'},
    {'#', ' ', ' ', '#', ' ', ' ', '#', ' ', ' ', '#'},
    {'#', ' ', '#', '#', ' ', '#', '#', ' ', '#', '#'},
    {'#', '#', '#', '#', '#', '#', '#', '#', '#', '#'}
};

// The maze holds mysteries that can only be unlocked by traversing carefully
bool visited[ROWS][COLS] = {false};

// The Pathfinding Algorithm to guide the lost through the darkness
bool pathfind(Position *start, Position *end) {
    // Base Cases:
    // The journey has already ended
    if (start->row == end->row && start->col == end->col) {
        return true;
    }
    
    // The path has led into a dead end
    if (maze[start->row][start->col] == '#' || visited[start->row][start->col]) {
        return false;
    }
    
    // Mark the current location as visited
    visited[start->row][start->col] = true;
    
    // Recursive Case:
    // Explore surrounding options for the right path
    bool pathExists = pathfind(&(Position){start->row-1, start->col}, end); // Up
    if (!pathExists) {
        pathExists = pathfind(&(Position){start->row, start->col+1}, end); // Right
    }
    if (!pathExists) {
        pathExists = pathfind(&(Position){start->row+1, start->col}, end); // Down
    }
    if (!pathExists) {
        pathExists = pathfind(&(Position){start->row, start->col-1}, end); // Left
    }
    
    // If a path exists, mark the current location as a successful route
    if (pathExists) {
        maze[start->row][start->col] = '.';
    }
    
    return pathExists;
}

// To the lost traveler, the pathfinding algorithm is a beacon of hope
int main() {
    Position start = {1, 1}; // Starting Point
    Position end = {ROWS-2, COLS-2}; // Ending Point
    
    if (pathfind(&start, &end)) {
        printf("The path to salvation has been found!");
    } else {
        printf("The path to salvation remains shrouded in mystery.");
    }
    
    return 0;
}