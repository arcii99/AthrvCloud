//FormAI DATASET v1.0 Category: Pathfinding algorithms ; Style: Romeo and Juliet
// Romeo and Juliet's Pathfinding
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#define ROW 8
#define COL 8

// data structure to hold the coordinates of a cell
typedef struct {
    int row;
    int col;
} Coordinate;

// stack to hold the visited cells
typedef struct {
    Coordinate coordinates[ROW * COL];
    int top;
} Stack;

// initialize the stack
void initStack(Stack* stack) {
    stack->top = -1;
}

// push an element onto the stack
void push(Stack* stack, Coordinate coord) {
    stack->top++;
    stack->coordinates[stack->top] = coord;
}

// pop an element from the stack
Coordinate pop(Stack* stack) {
    Coordinate coord = stack->coordinates[stack->top];
    stack->top--;
    return coord;
}

// check if the stack is empty
bool isEmpty(Stack* stack) {
    return stack->top == -1;
}

// find the path to Juliet
void findPath(char grid[ROW][COL], Coordinate start, Coordinate end) {
    Stack stack;
    initStack(&stack);
    push(&stack, start);

    while (!isEmpty(&stack)) {
        Coordinate current = pop(&stack);

        if (current.row == end.row && current.col == end.col) {
            // found Juliet
            printf("Romeo found Juliet!\n");
            return;
        }

        if (grid[current.row][current.col] == 'X') {
            continue;
        }

        // mark the current cell as visited
        grid[current.row][current.col] = 'X';

        // check adjacent cells
        int row, col;
        for (row = current.row - 1; row <= current.row + 1; row++) {
            for (col = current.col - 1; col <= current.col + 1; col++) {
                if ((row == current.row || col == current.col) &&
                    row >= 0 && row < ROW &&
                    col >= 0 && col < COL &&
                    grid[row][col] != 'X') {
                    Coordinate adjacent = {row, col};
                    push(&stack, adjacent);
                }
            }
        }
    }

    printf("Romeo could not find Juliet.\n");
}

int main() {
    char grid[ROW][COL] = {
        {'.', 'X', '.', '.', '.', '.', '.', '.'},
        {'.', '.', '.', '.', '.', 'X', 'X', '.'},
        {'.', '.', '.', 'X', '.', '.', '.', '.'},
        {'X', '.', '.', '.', '.', 'X', '.', '.'},
        {'.', '.', '.', '.', 'X', '.', '.', '.'},
        {'X', '.', '.', 'X', '.', '.', '.', '.'},
        {'.', '.', '.', '.', '.', '.', '.', '.'},
        {'.', '.', '.', '.', '.', 'X', '.', '.'}
    };

    Coordinate start = {0, 0};
    Coordinate end = {7, 5};

    printf("Romeo is searching for Juliet...\n");
    findPath(grid, start, end);

    return 0;
}