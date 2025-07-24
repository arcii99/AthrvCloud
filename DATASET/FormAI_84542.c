//FormAI DATASET v1.0 Category: Procedurally Generated Maze ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAZE_HEIGHT 10  
#define MAZE_WIDTH 10
#define WALL 0
#define PATH 1
#define START 2
#define END 3

int maze[MAZE_HEIGHT][MAZE_WIDTH];

void printMaze() {
    for(int i=0; i<MAZE_HEIGHT; i++) {
        for(int j=0; j<MAZE_WIDTH; j++) {
            if(maze[i][j] == WALL) {
                printf("#");
            } else if(maze[i][j] == PATH) {
                printf(" ");
            } else if(maze[i][j] == START) {
                printf("S");
            } else if(maze[i][j] == END) {
                printf("E");
            }
        }
        printf("\n");
    }
}

int isWall(int x, int y) {
    if(x < 0 || x >= MAZE_HEIGHT || y < 0 || y >= MAZE_WIDTH) {
        // out of bounds
        return 1;
    }
    return maze[x][y] == WALL;
}

void createMaze(int start_x, int start_y, int end_x, int end_y) {
    // initialize maze
    for(int i=0; i<MAZE_HEIGHT; i++) {
        for(int j=0; j<MAZE_WIDTH; j++) {
            maze[i][j] = WALL;
        }
    }
    
    // set start and end
    maze[start_x][start_y] = START;
    maze[end_x][end_y] = END;
    
    // generate maze using a recursive algorithm
    int x, y;
    int checked[MAZE_HEIGHT][MAZE_WIDTH] = {0};
    int dx[] = {0, 0, 1, -1};
    int dy[] = {1, -1, 0, 0};
    
    checked[start_x][start_y] = 1;
    while(checked[end_x][end_y] == 0) {
        // choose a random cell
        do {
            x = rand() % MAZE_HEIGHT;
            y = rand() % MAZE_WIDTH;
        } while(checked[x][y] == 1);
        
        // mark cell as checked
        checked[x][y] = 1;
        
        // check neighbors
        int num_neighbors = 0;
        int neighbor_index[4] = {-1, -1, -1, -1};
        for(int i=0; i<4; i++) {
            int neighbor_x = x + dx[i];
            int neighbor_y = y + dy[i];
            if(!isWall(neighbor_x, neighbor_y) && checked[neighbor_x][neighbor_y] == 1) {
                neighbor_index[num_neighbors] = i;
                num_neighbors++;
            }
        }
        
        if(num_neighbors > 0) {
            // choose a random neighbor
            int neighbor = neighbor_index[rand() % num_neighbors];
            int nx = x + dx[neighbor];
            int ny = y + dy[neighbor];
            maze[nx][ny] = PATH;
        }
    }
}

int main() {
    srand(time(NULL));
    createMaze(0, 0, MAZE_HEIGHT-1, MAZE_WIDTH-1);
    printMaze();
    return 0;
}