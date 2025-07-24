//FormAI DATASET v1.0 Category: Maze Route Finder ; Style: retro
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 10
#define COLS 20

int maze[ROWS][COLS] = {
    {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
    {1, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
    {1, 0, 1, 1, 0, 0, 1, 1, 0, 1, 1, 1, 0, 1, 1, 1, 1, 0, 1, 1},
    {1, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0, 1, 0, 1, 0, 0, 0, 0, 0, 1},
    {1, 0, 1, 1, 0, 1, 1, 1, 0, 1, 0, 1, 0, 1, 0, 1, 1, 1, 0, 1},
    {1, 0, 0, 1, 0, 0, 0, 1, 0, 1, 0, 1, 0, 1, 0, 0, 0, 1, 0, 1},
    {1, 1, 0, 1, 1, 1, 0, 1, 1, 1, 0, 1, 0, 1, 1, 1, 1, 1, 0, 1},
    {1, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 1},
    {1, 0, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
    {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1}
};

struct Cell {
    int row;
    int col;
};

struct Stack {
    struct Cell *cells;
    int size;
    int top;
};

void printMaze();
void initStack(struct Stack *stack, int size);
void freeStack(struct Stack *stack);
void push(struct Stack *stack, int row, int col);
struct Cell pop(struct Stack *stack);
struct Cell peek(struct Stack *stack);
int isStackEmpty(struct Stack *stack);
int isWithinBounds(int row, int col);
int isRouteFound(struct Stack *stack, int endRow, int endCol);
void findRoute(struct Stack *stack, int startRow, int startCol, int endRow, int endCol);

int main() {
    srand(time(NULL));
    
    int startRow, startCol, endRow, endCol;
    do {
        startRow = rand() % ROWS;
        startCol = rand() % COLS;
        endRow = rand() % ROWS;
        endCol = rand() % COLS;
    } while (maze[startRow][startCol] || maze[endRow][endCol]);
    
    printf("Starting cell: (%d, %d)\n", startRow, startCol);
    printf("Destination cell: (%d, %d)\n\n", endRow, endCol);
    
    printMaze();
    
    struct Stack stack;
    initStack(&stack, ROWS * COLS);
    findRoute(&stack, startRow, startCol, endRow, endCol);
    freeStack(&stack);
    
    return 0;
}

void printMaze() {
    for (int row = 0; row < ROWS; row++) {
        for (int col = 0; col < COLS; col++) {
            char c = maze[row][col] ? '#' : ' ';
            printf("%c", c);
        }
        printf("\n");
    }
    printf("\n");
}

void initStack(struct Stack *stack, int size) {
    stack->cells = malloc(size * sizeof(struct Cell));
    stack->size = size;
    stack->top = 0;
}

void freeStack(struct Stack *stack) {
    free(stack->cells);
}

void push(struct Stack *stack, int row, int col) {
    struct Cell cell = {row, col};
    stack->cells[stack->top++] = cell;
}

struct Cell pop(struct Stack *stack) {
    return stack->cells[--stack->top];
}

struct Cell peek(struct Stack *stack) {
    return stack->cells[stack->top - 1];
}

int isStackEmpty(struct Stack *stack) {
    return stack->top == 0;
}

int isWithinBounds(int row, int col) {
    return row >= 0 && row < ROWS && col >= 0 && col < COLS;
}

int isRouteFound(struct Stack *stack, int endRow, int endCol) {
    return !isStackEmpty(stack) &&
           peek(stack).row == endRow &&
           peek(stack).col == endCol;
}

void findRoute(struct Stack *stack, int startRow, int startCol, int endRow, int endCol) {
    push(stack, startRow, startCol);
    
    while (!isStackEmpty(stack) && !isRouteFound(stack, endRow, endCol)) {
        // Check neighbors of top cell on stack
        int row = peek(stack).row;
        int col = peek(stack).col;
        int directions[4][2] = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}}; // up, right, down, left
        
        int found = 0;
        for (int i = 0; i < 4; i++) {
            int newRow = row + directions[i][0];
            int newCol = col + directions[i][1];
            if (isWithinBounds(newRow, newCol) && !maze[newRow][newCol]) {
                push(stack, newRow, newCol);
                maze[newRow][newCol] = 1; // mark as visited
                found = 1;
                break;
            }
        }
        
        if (!found) {
            // backtrack
            pop(stack);
        }
        
        // system("clear"); // uncomment for a more dynamic display
        // printMaze();       // uncomment for a more dynamic display
    }
    
    if (isRouteFound(stack, endRow, endCol)) {
        printf("Route found!\n");
        while (!isStackEmpty(stack)) {
            struct Cell cell = pop(stack);
            printf("(%d, %d) ", cell.row, cell.col);
        }
        printf("\n");
    } else {
        printf("Route not found.\n");
    }
}