//FormAI DATASET v1.0 Category: Maze Route Finder ; Style: synchronous
#include <stdio.h>
#include <stdbool.h>

#define ROW 10
#define COL 10

// create a maze
int maze[ROW][COL] = {
    {1, 1, 1, 1, 1, 0, 0, 1, 1, 1},
    {0, 1, 1, 1, 1, 1, 0, 1, 0, 1},
    {0, 0, 1, 0, 1, 1, 1, 0, 0, 1},
    {1, 0, 1, 1, 1, 0, 1, 1, 0, 1},
    {0, 0, 0, 1, 0, 0, 0, 1, 0, 1},
    {1, 0, 1, 1, 1, 0, 0, 1, 1, 0},
    {0, 0, 0, 0, 1, 0, 0, 1, 0, 1},
    {0, 1, 1, 1, 1, 1, 1, 1, 0, 0},
    {1, 1, 1, 1, 1, 0, 0, 1, 1, 1},
    {0, 0, 1, 0, 0, 1, 1, 0, 0, 1}
};

// create a structure to store the position of each point
struct Point {
    int x;
    int y;
};

// create a stack to store the path
struct Stack {
    struct Point point[100];
    int top;
};

// initialize the stack
void initStack(struct Stack *stack) {
    stack->top = -1;
}

// check if the stack is empty
bool isEmpty(struct Stack *stack) {
    return stack->top == -1;
}

// push an element onto the stack
void push(struct Stack *stack, struct Point point) {
    stack->top++;
    stack->point[stack->top] = point;
}

// remove the top element from the stack
struct Point pop(struct Stack *stack) {
    struct Point point = stack->point[stack->top];
    stack->top--;
    return point;
}

// check if the current position is within the maze and is not blocked
bool isValid(int x, int y) {
    if (x < 0 || x >= ROW || y < 0 || y >= COL) {
        return false;
    }
    if (maze[x][y] == 0) {
        return false;
    }
    return true;
}

// find the path through the maze
void findPath() {
    struct Stack stack;
    initStack(&stack);

    struct Point startPoint = {0, 0};
    push(&stack, startPoint);

    while (!isEmpty(&stack)) {
        struct Point currentPoint = pop(&stack);

        if (currentPoint.x == ROW - 1 && currentPoint.y == COL - 1) {
            printf("Path found:\n");
            for (int i = 0; i <= stack.top; i++) {
                printf("(%d,%d)\n", stack.point[i].x, stack.point[i].y);
            }
            printf("(%d,%d)\n\n", ROW - 1, COL - 1);
            return;
        }

        struct Point nextPoint;

        // check north
        nextPoint.x = currentPoint.x - 1;
        nextPoint.y = currentPoint.y;
        if (isValid(nextPoint.x, nextPoint.y)) {
            push(&stack, nextPoint);
        }

        // check south
        nextPoint.x = currentPoint.x + 1;
        nextPoint.y = currentPoint.y;
        if (isValid(nextPoint.x, nextPoint.y)) {
            push(&stack, nextPoint);
        }

        // check east
        nextPoint.x = currentPoint.x;
        nextPoint.y = currentPoint.y + 1;
        if (isValid(nextPoint.x, nextPoint.y)) {
            push(&stack, nextPoint);
        }

        // check west
        nextPoint.x = currentPoint.x;
        nextPoint.y = currentPoint.y - 1;
        if (isValid(nextPoint.x, nextPoint.y)) {
            push(&stack, nextPoint);
        }
    }

    printf("No path found\n");
}

int main() {
    findPath();
    return 0;
}