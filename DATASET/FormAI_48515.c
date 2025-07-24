//FormAI DATASET v1.0 Category: Maze Route Finder ; Style: retro
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 15
#define COLS 27

int maze[ROWS][COLS] = {
    {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
    {1,0,0,1,0,0,0,1,0,0,0,1,0,0,0,1,1,1,0,0,0,0,0,0,0,1},
    {1,0,0,1,0,0,0,1,1,1,0,1,0,0,0,1,0,0,0,0,0,0,0,0,0,1},
    {1,0,0,0,0,0,0,0,0,0,0,1,0,0,0,1,0,0,0,0,0,0,0,0,0,1},
    {1,0,0,0,0,0,0,0,0,0,0,1,1,1,1,1,0,0,0,0,0,0,0,0,0,1},
    {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,1},
    {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,0,0,0,0,0,0,0,1},
    {1,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,0,0,0,0,0,0,0,0,0,1},
    {1,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,1},
    {1,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,1},
    {1,0,0,0,0,0,0,0,0,0,0,0,1,1,0,0,0,0,0,0,0,0,0,0,0,1},
    {1,0,0,0,0,0,0,0,0,0,0,1,1,0,0,0,0,0,0,0,0,0,0,0,0,1},
    {1,0,0,0,0,0,0,0,0,0,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
    {1,0,0,0,0,0,0,0,0,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
    {1,0,0,0,0,0,0,0,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
    {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1}
};

struct coord {
    int x;
    int y;
};

void setStartEndPoints(struct coord *start, struct coord *end) {
    srand(time(NULL));
    int startX, startY, endX, endY;
    do {
        startX = rand() % COLS;
        startY = rand() % ROWS;
    } while (maze[startY][startX]);

    do {
        endX = rand() % COLS;
        endY = rand() % ROWS;
    } while (maze[endY][endX] || (endX == startX && endY == startY));

    start->x = startX;
    start->y = startY;

    end->x = endX;
    end->y = endY;
}

int checkValidity(int row, int col) {
    if(row < 0 || col < 0 || row >= ROWS || col >= COLS) {
        return 0;
    }
    return maze[row][col] == 0;
}

int findPath(struct coord start, struct coord end) {
    struct coord stack[ROWS * COLS], curr;
    int visited[ROWS][COLS] = {0};
    int top = -1;
    stack[++top] = start;
    visited[start.y][start.x] = 1;
    while(top != -1) {
        curr = stack[top--];
        if(curr.x == end.x && curr.y == end.y) {
            return 1;
        }
        if(checkValidity(curr.y + 1, curr.x) && !visited[curr.y + 1][curr.x]) {
            visited[curr.y + 1][curr.x] = 1;
            stack[++top] = (struct coord) {curr.x, curr.y + 1};
        }
        if(checkValidity(curr.y, curr.x + 1) && !visited[curr.y][curr.x + 1]) {
            visited[curr.y][curr.x + 1] = 1;
            stack[++top] = (struct coord) {curr.x + 1, curr.y};
        }
        if(checkValidity(curr.y - 1, curr.x) && !visited[curr.y - 1][curr.x]) {
            visited[curr.y - 1][curr.x] = 1;
            stack[++top] = (struct coord) {curr.x, curr.y - 1};
        }
        if(checkValidity(curr.y, curr.x - 1) && !visited[curr.y][curr.x - 1]) {
            visited[curr.y][curr.x - 1] = 1;
            stack[++top] = (struct coord) {curr.x - 1, curr.y};
        }
    }
    return 0;
}

void printMaze(struct coord start, struct coord end) {
    printf(" ");
    for(int i = 0; i < COLS * 2 - 1; i++) {
        printf("_");
    }
    printf("\n");

    for(int i = 0; i < ROWS; i++) {
        printf("|");
        for(int j = 0; j < COLS; j++) {
            if(i == start.y && j == start.x) {
                printf("S");
            } else if(i == end.y && j == end.x) {
                printf("E");
            } else if(maze[i][j]) {
                printf("#");
            } else {
                printf(" ");
            }
            printf("|");
        }
        printf("\n");
    }
}

int main() {
    struct coord start, end;
    setStartEndPoints(&start, &end);
    printf("Welcome to the Retro Maze Game!\n");
    printf("Your goal is to find the route from 'S' to 'E'\n");
    printf("The '#' symbol represents obstacles that you cannot pass through.\n");
    printf("Good Luck!\n\n");
    while(!findPath(start, end)) {
        setStartEndPoints(&start, &end);
    }
    printMaze(start, end);
    printf("\nCongratulations! You have found the path from 'S' to 'E'\n");
    return 0;
}