//FormAI DATASET v1.0 Category: Procedurally Generated Maze ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <pthread.h>

#define ROWS 14
#define COLS 20
#define WALL 1
#define PATH 0

int maze[ROWS][COLS];

int random_range(int lower, int upper) {
    return (rand() % (upper - lower + 1)) + lower;
}

void print_maze() {
    printf(" ");
    for(int i=0;i<COLS;i++) {
        printf("_");
    }
    printf("\n");
    
    for(int i=0;i<ROWS;i++) {
        printf("|");
        for(int j=0;j<COLS;j++) {
            if(maze[i][j] == WALL) {
                printf("#");
            } else {
                printf(".");
            }
        }
        printf("|\n");
    }
    
    printf(" ");
    for(int i=0;i<COLS;i++) {
        printf("_");
    }
    printf("\n");
}

void generate_maze() {
    for(int i=0;i<ROWS;i++) {
        for(int j=0;j<COLS;j++) {
            maze[i][j] = WALL;
        }
    }
    
    for(int i=0;i<ROWS;i++) {
        maze[i][0] = PATH;
        maze[i][COLS-1] = PATH;
    }
    
    for(int i=0;i<COLS;i++) {
        maze[0][i] = PATH;
        maze[ROWS-1][i] = PATH;
    }
    
    for(int i=1;i<ROWS-1;i++) {
        for(int j=1;j<COLS-1;j++) {
            if(i%2==0 && j%2==0) {
                maze[i][j] = PATH;
            }
        }
    }
    
    for(int i=1;i<ROWS-1;i+=2) {
        for(int j=1;j<COLS-1;j+=2) {
            int x = random_range(0, 3);
            if(x==0) {
                maze[i+1][j] = PATH;
            } else if(x==1) {
                maze[i][j+1] = PATH;
            } else if(x==2) {
                maze[i-1][j] = PATH;
            } else {
                maze[i][j-1] = PATH;
            }
        }
    }
}

void *generate_and_print_maze(void *arg) {
    generate_maze();
    print_maze();
    pthread_exit(NULL);
}

int main() {
    srand(time(NULL));
    pthread_t threads[5];
    
    for(int i=0;i<5;i++) {
        pthread_create(&threads[i], NULL, generate_and_print_maze, NULL);
    }
    
    for(int i=0;i<5;i++) {
        pthread_join(threads[i], NULL);
    }
    
    return 0;
}