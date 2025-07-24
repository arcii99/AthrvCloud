//FormAI DATASET v1.0 Category: Maze Route Finder ; Style: enthusiastic
// Are you ready to find your way through a maze? Let's go!
#include <stdio.h>
#include <stdbool.h>

#define ROWS 10
#define COLUMNS 10

// Define the maze
char maze[ROWS][COLUMNS] = {
    {'#', '#', '#', '#', '#', '#', '#', '#', '#', '#'},
    {'#', ' ', '#', ' ', ' ', ' ', '#', ' ', ' ', '#'},
    {'#', ' ', '#', '#', '#', ' ', '#', ' ', '#', '#'},
    {'#', ' ', ' ', ' ', '#', ' ', '#', ' ', '#', '#'},
    {'#', ' ', '#', ' ', '#', ' ', ' ', ' ', ' ', '#'},
    {'#', ' ', '#', ' ', '#', '#', '#', '#', ' ', '#'},
    {'#', ' ', '#', ' ', ' ', ' ', ' ', ' ', ' ', '#'},
    {'#', ' ', '#', '#', '#', ' ', '#', '#', '#', '#'},
    {'#', ' ', ' ', ' ', '#', ' ', ' ', ' ', ' ', '#'},
    {'#', '#', '#', '#', '#', '#', '#', '#', '#', '#'}
};

// Define a struct to hold cell coordinates
struct Cell {
    int row;
    int column;
};

// Define a struct to hold a stack of cells
struct Stack {
    int top;
    struct Cell cells[ROWS*COLUMNS];
};

void push(struct Stack* stack, struct Cell cell) {
    stack->top++;
    stack->cells[stack->top] = cell;
}

struct Cell pop(struct Stack* stack) {
    struct Cell cell = stack->cells[stack->top];
    stack->top--;
    return cell;
}

bool isEmpty(struct Stack* stack) {
    return (stack->top == -1);
}

bool isExit(struct Cell cell) {
    return (cell.row == ROWS-1 && cell.column == COLUMNS-1);
}

bool isInsideMaze(struct Cell cell) {
    return (cell.row >= 0 && cell.row < ROWS && cell.column >= 0 && cell.column < COLUMNS);
}

bool isPath(struct Cell cell) {
    return (maze[cell.row][cell.column] == ' ');
}

void printMaze() {
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLUMNS; j++) {
            printf("%c", maze[i][j]);
        }
        printf("\n");
    }
}

void printRoute(struct Stack* stack) {
    while (!isEmpty(stack)) {
        struct Cell cell = pop(stack);
        printf("-> (%d,%d)", cell.row, cell.column);
    }
    printf("\n");
}

void findRoute(struct Cell start) {
    struct Stack stack;
    stack.top = -1;
    push(&stack, start);

    while (!isEmpty(&stack)) {
        struct Cell current = pop(&stack);
        if (isExit(current)) {
            printf("Congratulations, you found the exit!\n");
            printf("Route: (%d,%d)", start.row, start.column);
            printRoute(&stack);
            return;
        } else {
            maze[current.row][current.column] = '.';
            struct Cell neighbor1 = {current.row-1, current.column};
            struct Cell neighbor2 = {current.row+1, current.column};
            struct Cell neighbor3 = {current.row, current.column-1};
            struct Cell neighbor4 = {current.row, current.column+1};
            if (isInsideMaze(neighbor1) && isPath(neighbor1)) {
                push(&stack, neighbor1);
            }
            if (isInsideMaze(neighbor2) && isPath(neighbor2)) {
                push(&stack, neighbor2);
            }
            if (isInsideMaze(neighbor3) && isPath(neighbor3)) {
                push(&stack, neighbor3);
            }
            if (isInsideMaze(neighbor4) && isPath(neighbor4)) {
                push(&stack, neighbor4);
            }
        }
    }

    printf("Sorry, there is no route to the exit.\n");
}

int main() {
    printf("Welcome to the maze route finder!\n");
    printf("The maze is marked with '#' for walls and ' ' for open spaces.\n");
    printf("Your starting position is (0,0) and the exit is (%d,%d).\n", ROWS-1, COLUMNS-1);

    printMaze();

    struct Cell start = {0, 0};
    findRoute(start);

    return 0;
}