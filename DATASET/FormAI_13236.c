//FormAI DATASET v1.0 Category: Pathfinding algorithms ; Style: accurate
#include <stdio.h>
#include <stdlib.h>

#define SIZE 10 //size of map
#define WALL -1 //denotes a wall in the map
#define UNVISITED 0 //denotes an unvisited cell in the map
#define VISITED 1 //denotes a visited cell in the map

//structure for storing a cell's coordinates
typedef struct Coordinates{
    int row;
    int col;
}Coordinates;

//function to initialize the map to all unvisited cells
void initialize_map(int map[SIZE][SIZE]){
    int row, col;
    for(row=0;row<SIZE;row++){
        for(col=0;col<SIZE;col++){
            map[row][col] = UNVISITED;
        }
    }
}

//function to print the map to console
void print_map(int map[SIZE][SIZE]){
    int row, col;
    for(row=0;row<SIZE;row++){
        for(col=0;col<SIZE;col++){
            if(map[row][col] == WALL){
                printf("X "); //display wall
            }
            else if(map[row][col] == UNVISITED){
                printf("_ "); //display unvisited cell
            }
            else{
                printf("O "); //display visited cell
            }
        }
        printf("\n");
    }
    printf("\n");
}

//function to check if a given cell is a valid cell in the map
int is_valid(int row, int col){
    if(row<0 || row>=SIZE || col<0 || col>=SIZE){
        return 0; //cell is out of bounds
    }
    else{
        return 1; //cell is within bounds
    }
}

//function to mark a cell as a wall
void add_wall(int map[SIZE][SIZE], Coordinates wall){
    if(is_valid(wall.row, wall.col)){
        map[wall.row][wall.col] = WALL;
    }
}

//function to check if a cell is a wall
int is_wall(int map[SIZE][SIZE], Coordinates cell){
    if(is_valid(cell.row, cell.col)){
        if(map[cell.row][cell.col] == WALL){
            return 1; //cell is a wall
        }
    }
    return 0; //cell is not a wall
}

//function to check if a cell has been visited
int is_visited(int map[SIZE][SIZE], Coordinates cell){
    if(is_valid(cell.row, cell.col)){
        if(map[cell.row][cell.col] == VISITED){
            return 1; //cell has been visited
        }
    }
    return 0; //cell has not been visited
}

//function to mark a cell as visited
void mark_visited(int map[SIZE][SIZE], Coordinates cell){
    if(is_valid(cell.row, cell.col)){
        map[cell.row][cell.col] = VISITED;
    }
}

//function to mark a path on the map
void mark_path(int map[SIZE][SIZE], Coordinates start, Coordinates end){
    Coordinates current = end;
    while(current.row != start.row || current.col != start.col){
        if(!is_wall(map, current)){
            map[current.row][current.col] = 2; //mark path cell
        }
        if(current.row < start.row){
            current.row++;
        }
        else if(current.row > start.row){
            current.row--;
        }
        else if(current.col < start.col){
            current.col++;
        }
        else{
            current.col--;
        }
    }
}

//recursive function to find a path from start to end
int find_path(int map[SIZE][SIZE], Coordinates start, Coordinates end){
    if(start.row == end.row && start.col == end.col){ //we've reached our destination!
        mark_visited(map, start);
        return 1;
    }
    else if(is_wall(map, start) || is_visited(map, start)){ //don't revisit walls or visited cells
        return 0;
    }
    else{
        mark_visited(map, start); //mark current cell as visited
        if(find_path(map, (Coordinates){start.row-1, start.col}, end)){ //try moving up
            mark_path(map, start, end); //mark the path we took
            return 1;
        }
        else if(find_path(map, (Coordinates){start.row+1, start.col}, end)){ //try moving down
            mark_path(map, start, end); //mark the path we took
            return 1;
        }
        else if(find_path(map, (Coordinates){start.row, start.col-1}, end)){ //try moving left
            mark_path(map, start, end); //mark the path we took
            return 1;
        }
        else if(find_path(map, (Coordinates){start.row, start.col+1}, end)){ //try moving right
            mark_path(map, start, end); //mark the path we took
            return 1;
        }
        else{ //we can't move anywhere from this cell
            return 0;
        }
    }
}

int main(){
    int map[SIZE][SIZE];
    initialize_map(map); //initialize map to all unvisited cells
    add_wall(map, (Coordinates){1, 1}); //add walls to the map
    add_wall(map, (Coordinates){2, 1});
    add_wall(map, (Coordinates){3, 1});
    add_wall(map, (Coordinates){4, 1});
    add_wall(map, (Coordinates){5, 1});
    Coordinates start = (Coordinates){0, 0};
    Coordinates end = (Coordinates){9, 9};
    find_path(map, start, end); //find a path from start to end
    print_map(map); //print the map with the path to console
    return 0;
}