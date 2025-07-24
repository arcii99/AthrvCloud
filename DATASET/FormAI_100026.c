//FormAI DATASET v1.0 Category: Maze Route Finder ; Style: systematic
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define ROWS 10
#define COLS 10

char maze[ROWS][COLS] = {
    {'#', '#', '#', '#', '#', '#', '#', '#', '#', '#'},
    {'#', '.', '.', '.', '.', '#', '.', '.', '.', '#'},
    {'#', '.', '#', '#', '.', '#', '.', '#', '.', '#'},
    {'#', '.', '.', '#', '.', '.', '.', '#', '.', '#'},
    {'#', '#', '.', '.', '.', '#', '.', '#', '.', '#'},
    {'#', '.', '.', '#', '.', '#', '.', '#', '.', '#'},
    {'#', '#', '.', '#', '.', '#', '.', '#', '.', '#'},
    {'#', '.', '.', '.', '.', '.', '.', '.', '.', '#'},
    {'#', '#', '#', '#', '#', '#', '#', '#', '.', '#'},
    {'#', '.', '.', '.', '.', '.', '.', '.', '.', '#'}
};

struct Coordinate {
    int x;
    int y;
};

struct Stack {
    struct Coordinate data[ROWS*COLS];
    int top;
};

void initializeStack(struct Stack* stack) {
    stack->top = -1;
}

bool isEmpty(struct Stack* stack) {
    return stack->top == -1;
}

bool isFull(struct Stack* stack) {
    return stack->top == ROWS*COLS - 1;
}

void push(struct Stack* stack, struct Coordinate coord) {
    if (isFull(stack)) {
        printf("Error: Stack is full\n");
        exit(EXIT_FAILURE);
    }
    stack->data[++(stack->top)] = coord;
}

struct Coordinate pop(struct Stack* stack) {
    if (isEmpty(stack)) {
        printf("Error: Stack is empty\n");
        exit(EXIT_FAILURE);
    }
    return stack->data[(stack->top)--];
}

bool isOnMaze(int x, int y) {
    return x >= 0 && x < ROWS && y >= 0 && y < COLS;
}

bool isPath(struct Coordinate coord) {
    return isOnMaze(coord.x, coord.y) && maze[coord.x][coord.y] == '.';
}

void printMaze() {
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            printf("%c ", maze[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

int main() {
    struct Stack stack;
    struct Coordinate start = {1, 1};
    struct Coordinate end = {ROWS-2, COLS-2};
    initializeStack(&stack);
    push(&stack, start);
    struct Coordinate current;
    while (!isEmpty(&stack)) {
        current = pop(&stack);
        if (current.x == end.x && current.y == end.y) {
            break;
        }
        maze[current.x][current.y] = '@'; //mark as visited
        struct Coordinate next;
        for (int i = -1; i <= 1; i++) {
            for (int j = -1; j <= 1; j++) {
                next.x = current.x + i;
                next.y = current.y + j;
                if ((i == 0 || j == 0) && isPath(next)) {
                    push(&stack, next);
                }
            }
        }
    }
    if (current.x == end.x && current.y == end.y) {
        printf("Path found!\n");
        maze[start.x][start.y] = 'S';
        maze[end.x][end.y] = 'E';
        printMaze();
    } else {
        printf("No path found\n");
    }
    return 0;
}