//FormAI DATASET v1.0 Category: Maze Route Finder ; Style: sophisticated
#include<stdio.h>
#include<stdlib.h>

#define ROW 15
#define COL 25

typedef struct {
    int x, y;
}Position;

Position stacks[1000];
int top = -1;

void push(int x, int y) {
    top++;
    stacks[top].x = x;
    stacks[top].y = y;
}

Position pop() {
    Position temp = stacks[top];
    top--;
    return temp;
}

void search_maze(int maze[ROW][COL], Position entry, Position exit) {
    int visited[ROW][COL] = {0};
    push(entry.x, entry.y);
    visited[entry.x][entry.y] = 1;

    while (top >= 0) {
        Position current = pop();

        if (current.x == exit.x && current.y == exit.y) {
            printf("Maze Solved!\n");
            return;
        }

        //Look Up
        if ((current.x - 1) >= 0 && maze[current.x - 1][current.y] == 0 && visited[current.x - 1][current.y] == 0) {
            push(current.x - 1, current.y);
            visited[current.x - 1][current.y] = 1;
        }

        //Look Down
        if ((current.x + 1) < ROW && maze[current.x + 1][current.y] == 0 && visited[current.x + 1][current.y] == 0) {
            push(current.x + 1, current.y);
            visited[current.x + 1][current.y] = 1;
        }

        //Look Left
        if ((current.y - 1) >= 0 && maze[current.x][current.y - 1] == 0 && visited[current.x][current.y - 1] == 0) {
            push(current.x, current.y - 1);
            visited[current.x][current.y - 1] = 1;
        }

        //Look Right
        if ((current.y + 1) < COL && maze[current.x][current.y + 1] == 0 && visited[current.x][current.y + 1] == 0) {
            push(current.x, current.y + 1);
            visited[current.x][current.y + 1] = 1;
        }
    }

    printf("Maze has no solution.\n");
}

int main() {
    int maze[ROW][COL] = {
        {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
        {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
        {1,0,1,1,1,1,0,1,1,1,1,1,0,1,1,1,1,1,1,0,1,1,1,0,1},
        {1,0,1,0,0,0,0,0,0,0,1,1,0,1,0,0,0,0,0,0,0,0,0,0,1},
        {1,0,1,0,1,1,1,1,1,0,1,1,0,1,0,1,1,1,1,1,1,0,1,0,1},
        {1,0,1,0,1,0,0,0,1,0,1,1,0,1,0,1,0,0,0,0,1,0,1,0,1},
        {1,0,1,0,1,0,1,1,1,0,1,1,0,1,0,0,0,1,1,0,1,0,1,0,1},
        {1,0,1,0,1,0,1,0,0,0,0,0,0,1,0,1,0,0,0,0,1,0,1,0,1},
        {1,0,1,0,1,0,1,0,1,1,1,0,0,0,0,1,1,1,1,1,1,0,1,0,1},
        {1,0,1,0,1,0,1,0,0,0,1,1,1,1,1,1,0,0,0,0,1,0,1,0,1},
        {1,0,1,0,1,0,1,0,1,1,1,0,0,0,0,1,0,1,1,0,1,0,1,0,1},
        {1,0,1,0,1,0,1,0,0,0,0,0,1,1,0,0,0,0,0,0,1,0,1,0,1},
        {1,0,1,0,1,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,1,0,1},
        {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
        {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1}
    };

    Position entry = {1, 1};
    Position exit = {13, 23};

    search_maze(maze, entry, exit);
    return 0;
}