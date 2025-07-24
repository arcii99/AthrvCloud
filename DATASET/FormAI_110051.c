//FormAI DATASET v1.0 Category: Procedurally Generated Maze ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 20
#define COLS 20

void generate_maze(int maze[][COLS], int row, int col);
void print_maze(int maze[][COLS], int row, int col);
void dfs(int maze[][COLS], int row, int col, int visited[][COLS]);
int is_valid_move(int maze[][COLS], int row, int col, int visited[][COLS], int move);

int main()
{
    int maze[ROWS][COLS];
    int visited[ROWS][COLS] = { 0 };
    
    srand(time(NULL));
    
    generate_maze(maze, ROWS, COLS);
    
    dfs(maze, 0, 0, visited); // solve maze
    
    print_maze(maze, ROWS, COLS);
    
    return 0;
}

// generate maze using random walk algorithm 
void generate_maze(int maze[][COLS], int row, int col)
{
    int i, j, x, y;
    
    // initialize maze
    for(i = 0; i < row; i++) {
        for(j = 0; j < col; j++) {
            maze[i][j] = 1;
        }
    }
    
    // generate maze using random walk algorithm
    x = rand() % row;
    y = rand() % col;
    maze[x][y] = 0;
    
    while(1) {
        int r = rand() % 4;
        int dx = 0, dy = 0;
        
        if(r == 0) dx = 1;
        else if(r == 1) dx = -1;
        else if(r == 2) dy = 1;
        else dy = -1;
        
        if((x + dx) < 0 || (x + dx) >= row) continue;
        if((y + dy) < 0 || (y + dy) >= col) continue;
        
        if(maze[x+dx][y+dy] == 1) {
            maze[x+dx][y+dy] = 0;
            x += dx;
            y += dy;
        }
        
        if(rand() % 10 == 0) break; // exit random walk algorithm early 
    }
}

// solve maze using depth first search algorithm
void dfs(int maze[][COLS], int row, int col, int visited[][COLS])
{
    visited[row][col] = 1;
    if(row == ROWS-1 && col == COLS-1) return; // solved maze
    
    int moves[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}}; // possible moves
    
    int i;
    for(i = 0; i < 4; i++) {
        if(is_valid_move(maze, row + moves[i][0], col + moves[i][1], visited, i)) {
            dfs(maze, row + moves[i][0], col + moves[i][1], visited);
        }
    }
}

// check if move is valid 
int is_valid_move(int maze[][COLS], int row, int col, int visited[][COLS], int move)
{
    if(row >= 0 && row < ROWS && col >= 0 && col < COLS && !visited[row][col] && maze[row][col] == 0) {
        if(move == 0 && row == 0) return 0; // can't move up when on top row
        if(move == 1 && row == ROWS-1) return 0; // can't move down when on bottom row
        if(move == 2 && col == COLS-1) return 0; // can't move right when on rightmost column
        if(move == 3 && col == 0) return 0; // can't move left when on leftmost column
        return 1; // valid move
    }
    return 0; // invalid move
}

// print maze 
void print_maze(int maze[][COLS], int row, int col)
{
    int i, j;
    printf("+");
    for(i=0;i<col;i++) printf("--+");
    printf("\n");
    for(i=0;i<row;i++) {
        printf("|");
        for(j=0;j<col;j++) {
            if(maze[i][j] == 1) printf("##|");
            else if(i == 0 && j == 0) printf("##|"); // start position
            else if(i == row-1 && j == col-1) printf("##|"); // end position
            else printf("  |");
        }
        printf("\n");
        printf("+");
        for(j=0;j<col;j++) printf("--+");
        printf("\n");
    }
}