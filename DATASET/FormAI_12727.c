//FormAI DATASET v1.0 Category: Procedurally Generated Maze ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <pthread.h>
#include <unistd.h>

#define ROWS 10
#define COLS 10

bool visited[ROWS][COLS];
int maze[ROWS][COLS];
pthread_mutex_t lock;

void* generateMaze(void* arg)
{
    int i, j;
    int num_traps = 0;
    int num_treasure = 0;
    for(i=0; i<ROWS; i++){
        for(j=0; j<COLS; j++){
            maze[i][j] = rand() % 2; // Generate either 0 or 1
            if(maze[i][j] == 0 && num_traps < 3){ // Add traps randomly
                maze[i][j] = -1;
                num_traps++;
            }
            if(maze[i][j] == 0 && num_treasure < 1){ // Add treasure randomly
                maze[i][j] = 2;
                num_treasure++;
            }
        }
    }
    return NULL;
}

void printMaze()
{
    int i, j;
    for(i=0; i<ROWS; i++){
        for(j=0; j<COLS; j++){
            if(maze[i][j] == 1){
                printf(" "); // Empty space
            }
            else if(maze[i][j] == -1){
                printf("\033[31m*\033[0m"); // Trap
            }
            else if(maze[i][j] == 2){
                printf("\033[33m$\033[0m"); // Treasure
            }
        }
        printf("\n");
    }
}

void checkForTreasure(int * my_position)
{
    int i = my_position[0];
    int j = my_position[1];
    if(maze[i][j] == 2){
        printf("Congratulations! You have found the treasure!\n");
    }
}

void* moveCharacter(void* arg)
{
    int * my_position = (int *)arg;
    while(true){
        pthread_mutex_lock(&lock);
        int i = my_position[0];
        int j = my_position[1];
        visited[i][j] = true;
        if(maze[i][j] == -1){ // Trap found
            printf("Oh no! You have stepped on a trap and lost the game.\n");
            pthread_mutex_unlock(&lock);
            return NULL;
        }
        checkForTreasure(my_position);
        int dir = rand() % 4; // Move randomly
        if(dir == 0 && i > 0 && !visited[i-1][j] && maze[i-1][j] != -1){ // Move up
            my_position[0] = i-1;
        }
        else if(dir == 1 && j < COLS-1 && !visited[i][j+1] && maze[i][j+1] != -1){ // Move right
            my_position[1] = j+1;
        }
        else if(dir == 2 && i < ROWS-1 && !visited[i+1][j] && maze[i+1][j] != -1){ // Move down
            my_position[0] = i+1;
        }
        else if(dir == 3 && j > 0 && !visited[i][j-1] && maze[i][j-1] != -1){ // Move left
            my_position[1] = j-1;
        }
        pthread_mutex_unlock(&lock);
        sleep(1); // Delay movement
    }
    return NULL;
}

int main()
{
    srand(time(NULL));
    pthread_t maze_thread, character_thread_1;
    int startPosition[2] = {0, 0};
    generateMaze(NULL);
    pthread_create(&maze_thread, NULL, generateMaze, NULL);
    pthread_join(maze_thread, NULL);
    pthread_create(&character_thread_1, NULL, moveCharacter, startPosition);
    printMaze();
    pthread_join(character_thread_1, NULL);
    return 0;
}