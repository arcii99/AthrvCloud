//FormAI DATASET v1.0 Category: Maze Route Finder ; Style: synchronous
#include<stdio.h>
#include<stdlib.h>

#define ROWS 10
#define COLS 10

char maze[ROWS][COLS] = {
                    {'#', '#', '#', '#', '#', '#', '#', '#', '#', '#'},
                    {'#', '.', '.', '.', '#', '.', '.', '.', '.', '#'},
                    {'#', '.', '#', '.', '#', '.', '#', '#', '#', '#'},
                    {'#', '#', '#', '.', '#', '.', '.', '.', '.', '#'},
                    {'#', '.', '.', '.', '.', '#', '#', '#', '.', '#'},
                    {'#', '#', '#', '#', '.', '#', '.', '#', '.', '#'},
                    {'#', '.', '.', '#', '.', '#', '.', '#', '.', '#'},
                    {'#', '#', '.', '#', '.', '.', '.', '#', '.', '#'},
                    {'#', '.', '.', '.', '#', '#', '.', '.', '.', '#'},
                    {'#', '#', '#', '#', '#', '#', '#', '#', '#', '#'}
                };

//structure for coordinates
typedef struct {
    int row;
    int col;
} coordinates;

//checks if the given coordinates are valid
int is_valid_coordinates(int row, int col) {
    if (row < ROWS && col < COLS && row >= 0 && col >= 0 && maze[row][col] != '#') {
        return 1;
    } else {
        return 0;
    }
}

//checks if the given coordinates are the destination
int is_destination(int row, int col, coordinates dest) {
    if (row == dest.row && col == dest.col) {
        return 1;
    } else {
        return 0;
    }
}

//finds the route from start to dest using recursive DFS algorithm
int find_route(coordinates start, coordinates dest) {
    if (!is_valid_coordinates(start.row, start.col)) {
        return 0; //if invalid coordinates, return false
    }
    if (is_destination(start.row, start.col, dest)) {
        return 1; //if destination is reached, return true
    }
    maze[start.row][start.col] = '#'; //set the current position to visited

    int found_route = 0;
    
    //check in all directions for a route
    if (!found_route && is_valid_coordinates(start.row+1, start.col)) { //down
        found_route = find_route((coordinates) {start.row+1, start.col}, dest);
    }

    if (!found_route && is_valid_coordinates(start.row, start.col+1)) { //right
        found_route = find_route((coordinates) {start.row, start.col+1}, dest);
    }

    if (!found_route && is_valid_coordinates(start.row, start.col-1)) { //left
        found_route = find_route((coordinates) {start.row, start.col-1}, dest);
    }

    if (!found_route && is_valid_coordinates(start.row-1, start.col)) { //up
        found_route = find_route((coordinates) {start.row-1, start.col}, dest);
    }

    return found_route;
}

int main() {

    coordinates start = {1, 1}; //start position
    coordinates dest = {8, 8}; //destination position

    printf("Maze Route Finder Example\n\n");

    int route_found = find_route(start, dest); //call the function to find the route

    if (route_found) {
        printf("A route was found!\n");
    } else {
        printf("No route was found.\n");
    }

    return 0;
}