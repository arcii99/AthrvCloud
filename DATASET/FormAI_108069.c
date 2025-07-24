//FormAI DATASET v1.0 Category: Procedurally Generated Maze ; Style: safe
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROW 10
#define COL 10
#define WALL '#'
#define PATH ' '
#define START 'S'
#define END 'E'

// create a struct to represent the cells in the maze
typedef struct {
    int r;
    int c;
    int visited;
    int in_maze;
    int walls[4]; // top, right, bottom, left
} Cell;

// helper function to get a random integer between min and max (inclusive)
int rand_int(int min, int max) {
    return rand() % (max - min + 1) + min;
}

// initialize the maze with all walls up and no cells in the maze
void init_maze(Cell maze[][COL]) {
    for (int i = 0; i < ROW; i++) {
        for (int j = 0; j < COL; j++) {
            maze[i][j].r = i;
            maze[i][j].c = j;
            maze[i][j].visited = 0;
            maze[i][j].in_maze = 0;
            for (int k = 0; k < 4; k++) {
                maze[i][j].walls[k] = 1;
            }
        }
    }
}

// print the maze to the console
void print_maze(Cell maze[][COL]) {
    for (int i = 0; i < ROW; i++) {
        for (int j = 0; j < COL; j++) {
            if (maze[i][j].in_maze == 0) {
                printf("%c%c%c", WALL, WALL, WALL);
            } else if (maze[i][j].visited == 1) {
                printf("%c%c%c", PATH, PATH, PATH);
            } else {
                printf("%c%c%c", WALL, WALL, WALL);
            }
        }
        printf("\n");
    }
}

// add a cell to the maze by breaking down the wall between the cell and a neighboring cell
void add_cell(Cell maze[][COL], int r, int c) {
    maze[r][c].in_maze = 1;
    if (r > 0 && maze[r-1][c].in_maze == 1) { // top neighbor
        maze[r][c].walls[0] = 0;
        maze[r-1][c].walls[2] = 0;
    }
    if (c < COL-1 && maze[r][c+1].in_maze == 1) { // right neighbor
        maze[r][c].walls[1] = 0;
        maze[r][c+1].walls[3] = 0;
    }
    if (r < ROW-1 && maze[r+1][c].in_maze == 1) { // bottom neighbor
        maze[r][c].walls[2] = 0;
        maze[r+1][c].walls[0] = 0;
    }
    if (c > 0 && maze[r][c-1].in_maze == 1) { // left neighbor
        maze[r][c].walls[3] = 0;
        maze[r][c-1].walls[1] = 0;
    }
}

// generate the maze using the randomized Prim's algorithm
void generate_maze(Cell maze[][COL]) {
    // choose a random starting cell
    int start_r = rand_int(0, ROW-1);
    int start_c = rand_int(0, COL-1);
    maze[start_r][start_c].visited = 1;
    add_cell(maze, start_r, start_c);
    
    // loop until all cells are in the maze
    while (1) {
        // find all frontier cells (i.e. cells with at least one neighbor in the maze)
        int frontier_count = 0;
        Cell frontier[ROW*COL];
        for (int i = 0; i < ROW; i++) {
            for (int j = 0; j < COL; j++) {
                if (maze[i][j].visited == 1 && maze[i][j].in_maze == 0) {
                    if (i > 0 && maze[i-1][j].in_maze == 1) { // top neighbor
                        frontier[frontier_count] = maze[i][j];
                        frontier[frontier_count].visited = 0;
                        frontier_count++;
                    }
                    if (j < COL-1 && maze[i][j+1].in_maze == 1) { // right neighbor
                        frontier[frontier_count] = maze[i][j];
                        frontier[frontier_count].visited = 0;
                        frontier_count++;
                    }
                    if (i < ROW-1 && maze[i+1][j].in_maze == 1) { // bottom neighbor
                        frontier[frontier_count] = maze[i][j];
                        frontier[frontier_count].visited = 0;
                        frontier_count++;
                    }
                    if (j > 0 && maze[i][j-1].in_maze == 1) { // left neighbor
                        frontier[frontier_count] = maze[i][j];
                        frontier[frontier_count].visited = 0;
                        frontier_count++;
                    }
                }
            }
        }
        // if there are no frontier cells, we're done
        if (frontier_count == 0) {
            break;
        }
        // choose a random frontier cell to add to the maze
        int index = rand_int(0, frontier_count-1);
        add_cell(maze, frontier[index].r, frontier[index].c);
        maze[frontier[index].r][frontier[index].c].visited = 1;
    }
}

int main(void) {
    // seed the random number generator
    srand(time(NULL));
    
    // create the maze
    Cell maze[ROW][COL];
    init_maze(maze);
    generate_maze(maze);
    
    // add the start and end points to the maze
    int start_r = rand_int(0, ROW-1);
    int start_c = rand_int(0, COL-1);
    int end_r, end_c;
    do {
        end_r = rand_int(0, ROW-1);
        end_c = rand_int(0, COL-1);
    } while ((start_r == end_r && start_c == end_c) || maze[end_r][end_c].in_maze == 0);
    maze[start_r][start_c].visited = 1;
    maze[start_r][start_c].in_maze = 1;
    maze[start_r][start_c].walls[3] = 0;
    maze[end_r][end_c].visited = 1;
    maze[end_r][end_c].in_maze = 1;
    maze[end_r][end_c].walls[1] = 0;
    
    // print the maze to the console
    print_maze(maze);
    
    return 0;
}