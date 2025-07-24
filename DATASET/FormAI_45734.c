//FormAI DATASET v1.0 Category: Procedurally Generated Maze ; Style: expert-level
#include <stdio.h>
#include <time.h>
#include <stdlib.h>

#define MAZE_SIZE 10

int maze[MAZE_SIZE][MAZE_SIZE] = {0};
int visited[MAZE_SIZE][MAZE_SIZE] = {0};

void generate_maze(int x, int y) {
    visited[x][y] = 1;
    
    int directions[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
    int order[4] = {0, 1, 2, 3};
    int temp, rand_num;
    
    for (int i = 0; i < 4; i++) {
        rand_num = rand() % 4;
        temp = order[i];
        order[i] = order[rand_num];
        order[rand_num] = temp;
    }
    
    for (int i = 0; i < 4; i++) {
        int new_x = x + directions[order[i]][0];
        int new_y = y + directions[order[i]][1];
        
        if (new_x >= 0 && new_x < MAZE_SIZE && new_y >= 0 && new_y < MAZE_SIZE && visited[new_x][new_y] == 0) {
            if (order[i] == 0) {
                maze[x][y] |= 1;
                maze[new_x][new_y] |= 4;
            }
            else if (order[i] == 1) {
                maze[x][y] |= 4;
                maze[new_x][new_y] |= 1;
            }
            else if (order[i] == 2) {
                maze[x][y] |= 2;
                maze[new_x][new_y] |= 8;
            }
            else {
                maze[x][y] |= 8;
                maze[new_x][new_y] |= 2;
            }
            
            generate_maze(new_x, new_y);
        }
    }
}

void print_maze() {
    for (int y = MAZE_SIZE - 1; y >= 0; y--) {
        for (int x = 0; x < MAZE_SIZE; x++) {
            printf("%d%d%d%d ", (maze[x][y] & 1) ? 1 : 0, (maze[x][y] & 2) ? 1 : 0, (maze[x][y] & 4) ? 1 : 0, (maze[x][y] & 8) ? 1 : 0);
            if (x == MAZE_SIZE - 1) {
                printf("\n");
            }
        }
    }
}

int main(void) {
    srand(time(NULL));
    generate_maze(0, 0);
    print_maze();
    return 0;
}