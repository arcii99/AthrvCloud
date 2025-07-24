//FormAI DATASET v1.0 Category: Maze Route Finder ; Style: retro
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 20
#define COLS 50

char maze[ROWS][COLS];

typedef struct {
    int row;
    int col;
} Position;

void fill_maze();
void print_maze();
void create_path();
void get_valid_moves(int row, int col, int valid_moves[]);
int move(Position * pos, int direction);

int main() {
    // initialize random number generator
    srand(time(0));
    
    // fill maze with walls and paths
    fill_maze();
    
    // create a path rom the starting position to the end
    create_path();
    
    // print the maze
    print_maze();
    
    return 0;
}

// fill maze with walls and paths
void fill_maze() {
    int row, col;
    
    // fill with walls
    for(row = 0; row < ROWS; row++) {
        for(col = 0; col < COLS; col++) {
            maze[row][col] = '#';
        }
    }
    
    // add start and end positions
    maze[1][0] = 'S';
    maze[ROWS-2][COLS-1] = 'E';
}

// create a path from start to end using recursive backtracking
void create_path() {
    Position curr_pos = {1,0};
    int num_moves;
    int valid_moves[4];
    int chosen_move;

    while(curr_pos.row != ROWS-2 || curr_pos.col != COLS-1) {
        get_valid_moves(curr_pos.row, curr_pos.col, valid_moves);
        num_moves = 0;
        
        // count the number of valid moves
        while(valid_moves[num_moves] != -1) {
            num_moves++;
        }
        
        if(num_moves > 0) {
            // choose a random move
            chosen_move = rand() % num_moves;
            move(&curr_pos, valid_moves[chosen_move]);
            maze[curr_pos.row][curr_pos.col] = ' ';
        }
        else {
            // backtrack to the previous position
            maze[curr_pos.row][curr_pos.col] = 'B';
            move(&curr_pos, valid_moves[num_moves-1]);
        }
    }
}

// get an array of moves that are valid for a given position
void get_valid_moves(int row, int col, int valid_moves[]) {
    // initially assume all moves are invalid
    valid_moves[0] = -1;
    
    // check for up move
    if(row > 1 && maze[row-2][col] == '#') {
        valid_moves[0] = 0;
        valid_moves[1] = -1;
    }
    // check for down move
    else if(row < ROWS-2 && maze[row+2][col] == '#') {
        valid_moves[0] = 2;
        valid_moves[1] = -1;
    }
    // check for left move
    else if(col > 1 && maze[row][col-2] == '#') {
        valid_moves[0] = 3;
        valid_moves[1] = -1;
    }
    // check for right move
    else if(col < COLS-2 && maze[row][col+2] == '#') {
        valid_moves[0] = 1;
        valid_moves[1] = -1;
    }
}

// move in a given direction
int move(Position * pos, int direction) {
    switch(direction) {
        case 0: // up
            pos->row--;
            break;
        case 1: // right
            pos->col++;
            break;
        case 2: // down
            pos->row++;
            break;
        case 3: // left
            pos->col--;
            break;
    }
    return 0;
}

// print the maze
void print_maze() {
    int row, col;
    
    for(row = 0; row < ROWS; row++) {
        for(col = 0; col < COLS; col++) {
            printf("%c", maze[row][col]);
        }
        printf("\n");
    }
}