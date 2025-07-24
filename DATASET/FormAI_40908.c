//FormAI DATASET v1.0 Category: Pathfinding algorithms ; Style: accurate
#include <stdio.h>

#define ROW 10
#define COL 10

int maze[ROW][COL] = { // Define a maze
    {1, 0, 1, 1, 1, 1, 0, 1, 1, 1},
    {1, 0, 1, 0, 1, 1, 1, 0, 1, 1},
    {1, 1, 1, 0, 1, 1, 0, 1, 0, 1},
    {0, 0, 0, 0, 1, 0, 0, 0, 0, 1},
    {1, 1, 1, 0, 1, 1, 1, 0, 1, 0},
    {1, 0, 1, 1, 1, 1, 0, 1, 0, 0},
    {1, 0, 0, 0, 0, 1, 0, 0, 0, 1},
    {1, 0, 1, 1, 1, 1, 0, 1, 1, 1},
    {1, 1, 0, 0, 0, 0, 1, 0, 0, 1},
    {1, 1, 1, 1, 1, 1, 1, 1, 1, 1}
};

typedef struct {
    int row;
    int col;
} Point;

typedef struct {
    Point data[ROW * COL];
    int top;
} Stack;

void initStack(Stack* s) { // Initializing a stack
    s->top = -1;
}

int isEmpty(Stack* s) { // Checking if the stack is empty
    if (s->top == -1) {
        return 1;
    }
    return 0;
}

void push(Stack* s, Point point) { // Push an element to the stack
    s->top++;
    s->data[s->top] = point;
}

Point pop(Stack* s) { // Removing the top element from the stack
    Point temp = s->data[s->top];
    s->top--;
    return temp;
}

Point getTop(Stack* s) { // Getting the top element from the stack
    return s->data[s->top];
}

int isEqual(Point a, Point b) { // Checking if two points are equal
    if (a.row == b.row && a.col == b.col) {
        return 1;
    }
    return 0;
}

void printValidPath(Stack* s) { // Printing a valid path from stack
    printf("Valid Path: ");
    Point temp;

    while (!isEmpty(s)) {
        temp = pop(s);
        printf("(%d,%d) ", temp.row, temp.col);
    }

    printf("\n");
}

void mazeTraversal() {
    Point start = {0, 0};
    Point end = {ROW - 1, COL - 1};
    Point temp = start;
    Stack stack;
    initStack(&stack);
    push(&stack, start); // Pushing start to the top of stack
    maze[start.row][start.col] = 0; // Marking start as visited

    while (!isEmpty(&stack)) {
        if (isEqual(getTop(&stack), end)) {
            printValidPath(&stack);
            return;
        }

        // Moving to right if possible
        if (temp.col + 1 < COL && maze[temp.row][temp.col + 1] == 1) {
            temp.col++;
            push(&stack, temp);
            maze[temp.row][temp.col] = 0;
            continue; // Checking next direction
        }

        // Moving to left if possible
        if (temp.col - 1 >= 0 && maze[temp.row][temp.col - 1] == 1) {
            temp.col--;
            push(&stack, temp);
            maze[temp.row][temp.col] = 0;
            continue; // Checking next direction
        }

        // Moving up if possible
        if (temp.row - 1 >= 0 && maze[temp.row - 1][temp.col] == 1) {
            temp.row--;
            push(&stack, temp);
            maze[temp.row][temp.col] = 0;
            continue; // Checking next direction
        }

        // Moving down if possible
        if (temp.row + 1 < ROW && maze[temp.row + 1][temp.col] == 1) {
            temp.row++;
            push(&stack, temp);
            maze[temp.row][temp.col] = 0;
            continue; // Checking next direction
        }

        pop(&stack); // If no direction is available, move back to previous position
        if (!isEmpty(&stack)) {
            temp = getTop(&stack);
        }
    }

    printf("No Valid Path Available!\n"); // If the stack is empty, there is no valid path
}

int main() {
    mazeTraversal();
    return 0;
}