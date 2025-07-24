//FormAI DATASET v1.0 Category: Procedurally Generated Maze ; Style: irregular
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define ROW 10
#define COL 10
 
int maze[ROW][COL];
int visited[ROW][COL];
int size = ROW * COL;
int count = 0;
int end_row, end_col;
 
void createMaze() {
    srand(time(NULL));
    int rand_row = rand() % ROW;
    int rand_col = rand() % COL;
    maze[rand_row][rand_col] = 1;
    int current_row = rand_row;
    int current_col = rand_col;
 
    while(count<size){
        int r = rand() % 4;
        if (r == 0 && current_row > 0) {//up
            current_row -= 1;
            if (visited[current_row][current_col] == 0) {
                visited[current_row][current_col] = 1;
                maze[current_row][current_col] = 1;
                count++;
            } else {
                current_row += 1;
            }
        } else if (r == 1 && current_col < COL - 1) {//right
            current_col += 1;
            if (visited[current_row][current_col] == 0) {
                visited[current_row][current_col] = 1;
                maze[current_row][current_col] = 1;
                count++;
            } else {
                current_col -= 1;
            }
        } else if (r == 2 && current_row < ROW - 1) {//down
            current_row += 1;
            if (visited[current_row][current_col] == 0) {
                visited[current_row][current_col] = 1;
                maze[current_row][current_col] = 1;
                count++;
            } else {
                current_row -= 1;
            }
        } else if (r == 3 && current_col > 0) {//left
            current_col -= 1;
            if (visited[current_row][current_col] == 0) {
                visited[current_row][current_col] = 1;
                maze[current_row][current_col] = 1;
                count++;
            } else {
                current_col += 1;
            }
        }
    }
 
    end_row = rand() % ROW;
    end_col = rand() % COL;
    maze[end_row][end_col] = 1;
}
 
void printMaze() {
    int i, j;
    printf("+");
    for(i=0;i<COL;i++)
    printf("--+");
    printf("\n");
    for (i = 0; i < ROW; i++) {
        printf("|");
        for (j = 0; j < COL; j++) {
            if (i == end_row && j == end_col) {
                printf(" E ");
            } else if (maze[i][j] == 1) {
                printf("   ");
            } else {
                printf("| |");
            }
        }
        printf("\n+");
        for (j = 0; j < COL; j++) {
            printf("--+");
        }
        printf("\n");
    }
}
 
int main() {
    createMaze();
    printMaze();
    return 0;
}